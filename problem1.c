#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(unsigned * a, unsigned * b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {

	//scan the unsigned integer
	unsigned n = 0;
	scanf("%d", &n);

    //filter the bits into three unsigned ints, 10 bits at a time
    //0x3F gives a bit vector with the right most 10 bits as ones
	unsigned s1 = n & 0x3F;
	unsigned s2 = (n>>10) & 0x3F;
	unsigned s3 = (n>>20) & 0x3F;

    //order from least greatest
    if (s1 > s3) swap(&s1, &s3);
    if (s1 > s2) swap(&s1, &s2);
    if (s2 > s3) swap(&s2, &s3);

    //check if valid
    if((s1 + s2) > s3){
    	printf("valid");
    }
    else{
    	printf("invalid");
    }

	return 0;
}