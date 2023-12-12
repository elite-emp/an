#include<stdio.h>
int main()
{
	FILE *file=freopen("output2.txt", "w", stdout);
	if(file==NULL)
	{
		perror("freopen");
		return 1;
	}
	printf("This text will be written to the file.\n");
	fclose(file);
	return 0;
	
	
}

