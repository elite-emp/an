#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s <filename1> <filename2> ... <filenameN>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    char *temp;

    // Bubble sort implementation to sort filenames based on file size
    for (int i = 1; i < argc - 1; i++) 
    {
        for (int j = 1; j < argc - i; j++) 
        {
            stat(argv[j], &fileStat);
            off_t size1 = fileStat.st_size;

            stat(argv[j + 1], &fileStat);
            off_t size2 = fileStat.st_size;

            if (size1 > size2) 
            {
                 // Swap filenames
                temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }

    // Display filenames in ascending order according to their sizes
    printf("File sizes in ascending order:\n");
    for (int i = 1; i < argc; i++) 
    {
        stat(argv[i], &fileStat);
        printf("%s \t %lld\n", argv[i], (long long)fileStat.st_size);
    }

    return 0;
}

