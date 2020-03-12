#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {


	/*
	TODO: add your code here, or in the functions defined in this file
	and called from main
	*/
	int n = 0;
	scanf("%d", &n);

	//create array of 4 int, which will hold each byte of the int
	int bytes[4];
	bytes[0] = n & 0xFF;
	bytes[1] = (n>>8) & 0xFF;
	bytes[2] = (n>>16) & 0xFF;
	bytes[3] = (n>>24) & 0xFF;


	/*create array of 4 unsigned char
	  to which we will implicitly cast the int to char*/
	unsigned char uc[4];

	/*Fill array with each byte of the int
	  by filtering the ones for each byte.
	  Start with least significant bits
	  and shift next byte to the right
	  so that it won't be truncated in implicit casting*/
	uc[0] = n & 0xFF;
	uc[1] = (n>>8) & 0xFF;
	uc[2] = (n>>16) & 0xFF;
	uc[3] = (n>>24) & 0xFF;


	//same argument for unsigned short
	unsigned short us[2];
	us[0] = n & 0xFFFF;
	us[1] = (n>>16) & 0xFFFF;

	//same argument for signed short
	short s[2];
	s[0] = n & 0xFFFF;
	s[1] = (n>>16) & 0xFFFF;

	//simply cast signed int to unsigned int
	unsigned un = (unsigned)n;

	//cast pointer
	float * f = (float*)(&n);

	printf("bytes: %02x %02x %02x %02x\n", bytes[0], bytes[1], bytes[2], bytes[3]);
	printf("char: %c %c %c %c\n", uc[0], uc[1], uc[2], uc[3]);
	printf("ushort: %u %u\n", us[0], us[1]);
	printf("short: %d %d\n", s[0], s[1]);
	printf("uint: %u\n", un);
	printf("int: %d\n", n);
	printf("%s %g\n", "float:", *f);

	return 0;

}
