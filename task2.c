#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
// #include <unistd.h> //for unix systems
#include <io.h> //for windows systems
#include <stdint.h>

/*http://www.maverick-os.dk/FileSystemFormats/FAT16_FileSystem.html#:~:text=The%20FAT16%20file%20system%20uses,volume%20(volume%20%3D%20partition).*/

unsigned char *searchFile(int byteOffset, int numOfBytesToRead, char *path)
{
    unsigned char *buffer = malloc(numOfBytesToRead);

    int file = open(path, O_RDONLY | O_CREAT);

    if (file != -1)
    {
        off_t offset = lseek(file, byteOffset, SEEK_CUR);

        if (offset != -1)
        {
            size_t readFile = read(file, buffer, numOfBytesToRead);
            return buffer;
        }
        else
        {
            buffer = "Theres's been an error moving the file pointer.";
        }
    }
    else
    {
        buffer = "There's been an error opening the files";
    }
    return buffer;
}

int main()
{
    int result = 0;
    char path[] = "fat16.img";
    unsigned char *values = searchFile(11, 2, path);
    for (int x = 0; x < 2; x++)
    {
        result |= (int)values[x] << (8 * x); // bit shifting
    }
    printf("Bytes Per Sector: %d\n", result);
    values = searchFile(13, 1, path);
    printf("Sectors Per Cluster: %d\n", result);
}