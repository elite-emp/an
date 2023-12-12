#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	
	fd=open("output4.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	
	if(fd==-1)
	{
		perror("open");
		exit(1);
	}
	if(dup2(fd,1)==-1)
	{
		perror("dup2");
		close(fd);
		exit(1);
	}
	printf("This text will be written to the file.\n");
	return 0;
}
