#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdlib.h>

typedef struct{
	int integer;
	char string[24];
}RECORD;

#define NRECORDS (100)

int main()
{
	//数据结构
	RECORD record, *mapped;
	int i, f;
	FILE *fp;
	//写入一些文件
	fp = fopen("records.dat", "w+");
	for (i = 1; i < NRECORDS; i++)
	{
		record.integer = i;
		sprintf(record.string, "RECORD-%d", record.integer);
		fwrite(&record, sizeof(record), 1, fp);
	}
	fclose(fp);

	//读取文件中43个数据
	fp = fopen("records.dat", "r+");
	fseek(fp, 43 * sizeof(record), SEEK_SET);
	fread(&record, sizeof(record), 1, fp);

	record.integer = 143;
	
	sprintf(record.string, "record-%d", record.integer);

	//写回文件中
	fseek(fp, 43 * sizeof(record), SEEK_SET);
	fwrite(&record, sizeof(record), 1, fp);
	fclose(fp);

	//打开底层文件描述符
	f = open("record.dat", O_RDWR);

	//共享方式映射到内存中
	mapped = (RECORD*)mmap(0, NRECORDS*sizeof(RECORD), PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);

	//修改文件内容
	mapped[43].integer = 243;
	sprintf(mapped[43].string,"RECORD-%d",mapped[43].integer);

	//将文件写回内存中
	msync((void*)mapped, NRECORDS*sizeof(RECORD), MS_ASYNC);
	//释放内存
	munmap((void*)mapped, NRECORDS*sizeof(RECORD));
	close(f);
	exit(0);
}
