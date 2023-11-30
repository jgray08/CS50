#include "cs50.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Useage: ./recover <file>");
        return 1;
    }
    else
    {
        FILE *input = fopen(argv[1], "r");
        if (input == NULL)
        {
            printf("Could not open file.\n");
            return 1;
        }

        BYTE buffer[512];
        int amt = 0;
        FILE *output = NULL;
        char filename[8];

        while (fread(buffer, sizeof(BYTE), 512, input) == 512)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            { // HEADER OF FILE DTECTED
                if (amt != 0)
                {
                    fclose(output);
                }
                sprintf(filename, "%03i.jpg", amt);
                output = fopen(filename, "w");
                amt++;
            }
            if (amt > 0)
            {
                fwrite(buffer, sizeof(BYTE), 512, output);
            }
        }
        fclose(input);
        fclose(output);
    }
}