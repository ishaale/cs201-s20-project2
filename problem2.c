#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int n = 0;
	scanf("%d", &n);

	int reversed = 0;

	//filter each byte, then shift to opposite end
	//meaning, 4<->1, 3<->2
	reversed = (n & 0xFF000000) >> 24 |
			   (n & 0x00FF0000) >> 8 |
			   (n & 0x0000FF00) << 8|
			   (n & 0x000000FF) << 24;

	printf("%d converts to %d", n, reversed);

	return 0;
}
