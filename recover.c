#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accepting only a single command line arguement
    if (argc != 2)
    {
        printf("./recover filename\n");
        return 1;
    }

    // opening the memory card
    FILE *src = fopen(argv[1], "r");

    // error handling if file doesnt exist
    if (src == NULL)
    {
        printf("File cant be opened\n");
        return -1;
    }

    // declaring a file pointer which copies the JPEG files
    FILE *jpegfile = NULL;

    // buffer that stores 512 bytes of data
    uint8_t buffer[512];

    // counts the number of JPEG files found and used to name the files as well
    int jpegnum = 0;

    // an array of size 8 to store the filename because ###.jpg'\0'
    char filename[8];

    // loop runs until there still remains data blocks of 512 bytes
    while (fread(buffer, sizeof(uint8_t), 512, src) == 512)
    {
        // checks if the block is a JPEG file
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {

            // if a jpeg has already been found before then closing it
            if (jpegfile != NULL)
            {
                fclose(jpegfile);
            }

            // since new jpeg file found so opening a new file
            sprintf(filename, "%03i.jpg", jpegnum);
            jpegfile = fopen(filename, "w");

            // increasing the jpegnumber by 1 because new file
            jpegnum++;
        }

        // continuously writing until new jpeg file is found
        if (jpegfile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, jpegfile);
        }
    }

    // closing the filepointers
    fclose(src);
    fclose(jpegfile);
}
