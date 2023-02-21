#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(){
	uint8_t a = 0, b = 6;
	int i;

	printf("a\ta == b\ta < b\ta > b\n\n");

	for(i = 0; i < 512; i++){
		printf("%u\t%u\t%u\t%u\n", a, a == b, a < b, a > b);

		a++;
	}
	
	return 0;
}
