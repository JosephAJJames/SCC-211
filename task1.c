#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/types.h>

#define numOfBytesToRead 8
int main()
{
    int byteOffset = 5;

    int file = open("text.txt", O_RDONLY | O_CREAT);
    
    if (file != -1) {
        off_t offset = lseek(file, byteOffset, SEEK_CUR);

        if (offset != -1) {
            char buffer[numOfBytesToRead];
            size_t readFile = read(file, buffer, numOfBytesToRead);
            printf("%s", buffer, numOfBytesToRead);

        } else {
            printf("Theres's been an error moving the file pointer.");
            return -1;
        }

    } else {
        printf("There's been an error opening the files");
        return -1;
    }
}