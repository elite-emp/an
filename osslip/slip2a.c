#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) 
    {
        perror("stat");
        return 1;
    }

    printf("File Properties:\n");
    printf("------------------------------------\n");

    // Display file type
    if (S_ISREG(fileStat.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO/Named pipe\n");
    else
        printf("Unknown\n");

    printf("Inode of file: %ld\n", (long)fileStat.st_ino);
    printf("File size (Bytes): %lld\n", (long long)fileStat.st_size);
    printf("Block allocated: %lld\n", (long long)fileStat.st_blocks);
    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);
    printf("Last status changed time: %s", ctime(&fileStat.st_ctime));
    printf("Last file access time: %s", ctime(&fileStat.st_atime));

    // File permissions
    printf("\nFile access: ");
    if (fileStat.st_mode & S_IRUSR)
        printf("read ");
    if (fileStat.st_mode & S_IWUSR)
        printf("write ");
    if (fileStat.st_mode & S_IXUSR)
        printf("execute");

    printf("\n");

    return 0;
}

