#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename1> <filename2> ... <filenameN>\n",argv[0]);
		return 1;
	}
	struct stat fileStat;
	for(int i=1;i<argc;i++)
	{
		if(stat(argv[i], &fileStat) == -1)
		{
			perror("stat");
			continue;
		}
		printf("File: %s\n",argv[i]);
		printf("Inode number: %ld\n",(long)fileStat.st_ino);
		
		if(S_ISREG(fileStat.st_mode))
		printf("File type: Regular file\n");
		else if(S_ISDIR(fileStat.st_mode))
		printf("File type: Directory\n");
		else if(S_ISLNK(fileStat.st_mode))
		printf("File type: Symbolic link\n");
		else if(S_ISCHR(fileStat.st_mode))
		printf("File type: Character device\n");
		else if(S_ISBLK(fileStat.st_mode))
		printf("File type: Block device\n");
		else if(S_ISFIFO(fileStat.st_mode))
		printf("File type: FIFO/pipe\n");
		else if(S_ISSOCK(fileStat.st_mode))
		printf("File type: Socket\n");
		else
			printf("File type: Unknown\n");
			
			printf("\n");
	}
	return 0;
}
