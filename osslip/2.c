#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include <time.h> 

int main(int argc, char *argv[])
{
	struct dirent *de;
	struct stat sfile; 
	struct tm dt;

	int n;

	printf("Enter month ");
	scanf("%d",&n);

	DIR *cd=opendir("."); 
	while(de=readdir(cd))
{
	stat(de->d_name, &sfile);

	dt = *(gmtime(&sfile.st_ctime));
	if(dt.tm_mon==(n-1))
	printf("\n%s ",de->d_name);
	}
	return(0);
	}
