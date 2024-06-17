// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copies header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Reads samples from input file and write updated data to output file
    // a temporary state that has size of 16 bits (2 bytes) to store the data of each sample
    int16_t buffer;

    // reads 1 value the size of temporary from the input file and stores it in the location of
    // temporary
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // multiplies the temporary sample by the required scale factor and again stores it in
        // temporary
        buffer *= factor;

        // writes the updated temporary value to the output file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
