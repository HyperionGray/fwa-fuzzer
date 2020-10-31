#define _CRT_RAND_S
#include <stdio.h>
#include "fwa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <time.h>
#include <limits.h>

FILE *read_file_to_memory(const char *filename) {

    FILE *f_buffer;
    long length;

    errno_t f = fopen_s(&f_buffer, filename, "rb");
    if (f != 0) {
        perror("The file failed to open for read.");
    }

    return f_buffer;
}


//return between 0 and 1, results here will be used as percent
//of file to mutate
float random_percent() {
    unsigned int    number;
    double          max = 100.0;
    errno_t         err;

    err = rand_s( &number );
    srand(number);
    float retval;
    float r = (float) rand();
    float rand_max = (float) RAND_MAX;
    retval = 1 - r / rand_max;
    //printf("%lf\n", retval);
    return retval;
}

unsigned char random_byte() {
    unsigned int    number;
    double          max = 100.0;
    errno_t         err;

    err = rand_s( &number );
    srand(number);
    unsigned char r = (unsigned char) rand();
    return r;
}

int random_file_position(filesize) {
    unsigned int    number;
    double          max = 100.0;
    errno_t         err;

    err = rand_s( &number );
    srand(number);
    return rand() % (filesize + 1);
}

FILE *mutate(char *mutate_file) {
    FILE *_file = read_file_to_memory(mutate_file);
    float percent_to_mutate = random_percent();
    float mutate_or_not = random_percent();
    fseek(_file, 0L, SEEK_END);
    int filesize = ftell(_file);
    printf("Filesize: %d\n", filesize);
    int num_bytes_to_change = (filesize * percent_to_mutate)/100;
    if (num_bytes_to_change < 1) {
        num_bytes_to_change = 1;
    }
    printf("Bytes that will change: %d\n", num_bytes_to_change);

    int i = 0;
    while(i < num_bytes_to_change) {
        int byte = random_byte();
        int position = random_file_position(filesize);
        i = i + 1;
        printf("Byte generated: %X\n", byte);
        printf("Writing to position: %d\n", position);

        fseek(_file, position, SEEK_SET);
        fwrite((unsigned char *) byte, 1, 1, _file);
    }
    return _file;
}

int main() {
    int iterations = 1000;
    int i = 0;
    char *filename;
    errno_t err;
    FILE *_file;
    filename = 

    while (i < iterations) {
        _file = mutate(filename);
        err = fopen_s( &_file, (char *) i, "w" );
        if (err != 0)
        {
            perror("");
        }
        i++;
    }
}
