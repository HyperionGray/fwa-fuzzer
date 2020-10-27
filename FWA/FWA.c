#include "fwa.h"
#include <stdio.h>
#include <xkeycheck.h>
#include <time.h>
#include <stdlib.h>

struct FileWLength read_file_to_memory(const char *filename[]) {

	char* buffer = 0;
	long length;
	FILE* f = fopen(filename, "rb");
	struct FileWLength file_w_length;


	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length);
		if (buffer)
		{
			fread(buffer, 1, length, f);
		}
		fclose(f);
	};

	if (buffer)
	{
		file_w_length.file_buffer = buffer;
		file_w_length.length = length;
		return file_w_length;
	};
}

int random(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int file_bit_flipper(unsigned int byte) {

	//can probably be written in assembly
	rand() % (65 + 1 - 0) + 0;
	int mask = 0x90;
	int num = byte; // 11100011
	num ^= mask;

}

file_bit_flipper() {



}
