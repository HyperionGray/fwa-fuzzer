// FWA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "flip.h"

unsigned int bitflip(BYTE byte, unsigned int position)
{
	if (position > 15) {
		printf("Invalid position for bit flip on byte %x", position);
		return 1;
	}

	byte = byte ^ (1 << position);

	return byte;
}

