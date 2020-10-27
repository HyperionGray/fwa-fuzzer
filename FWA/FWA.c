#include "fwa.h"
#include <stdio.h>


char *read_file_to_memory(const char *filename[]) {

	char* buffer = 0;
	long length;
	FILE* f = fopen(filename, "rb");

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
	}
	if (buffer)
	{
		return buffer;
	}
}


int bit_flipper(char *arch[], unsigned int position) {

	if (arch == "x86") {
		BYTE byte = 0xFFFFFFFF;
	}


	if (arch == "x64") {
	BYTE byte = 0xFFFFFFFFFFFFFFFF;


	}

}

file_bit_flipper() {



}
