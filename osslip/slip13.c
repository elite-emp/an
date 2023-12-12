#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() 
{
    char search[20];
    printf("Enter String: ");
    scanf("%19s", search); // Limit input to 19 characters to avoid buffer overflow

    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) 
    {
        perror("opendir");
        return 1;
    }
    printf("File starting with %s in the current directory:\n", search);
    while ((entry = readdir(dir)) != NULL) 
    {
        if (strncmp(entry->d_name, search, strlen(search)) == 0) 
        {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}

