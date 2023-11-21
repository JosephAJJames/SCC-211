#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


char * searchFile(int bytpeOffset, int numOofBytesToRead, char path[], char * buffer)
{
    int byteOffset = bytpeOffset;
    int numOfBytesToRead = numOofBytesToRead;
    buffer = buffer[numOfBytesToRead];

    int file = open(path, O_RDONLY | O_CREAT);
    
    if (file != -1) {
        off_t offset = lseek(file, byteOffset, SEEK_CUR);

        if (offset != -1) {
            size_t readFile = read(file, buffer, numOfBytesToRead);
            return buffer;

        } else {
            printf("Theres's been an error moving the file pointer.");
        }

    } else {
        printf("There's been an error opening the files");
    }
}


int main()
{
    char * buffer;
    char path[] = "fat16.img";
    char * values = searchFile(11, 2, "fat16.img", buffer);
    printf("%s", values);
}