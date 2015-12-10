#include <stdio.h>
#include <stdlib.h>
#define u_int_max 4294967296

int bitlength(int num) {
	int counter = 0;
	while (num > 0) {
		num >>= 1;
		counter++;
	}
	return counter;
}

unsigned long long main(int argc, char *argv[]) {
	if (argc != 3){
		printf("2 input arguments needed!");
		return 1;
	}

	if (atoi(argv[1]) >= u_int_max || atoi(argv[2]) >= u_int_max) {
		printf("Inputs types are 'long'!");
		return 1;
	}

	unsigned short int i;

	const unsigned long number = atoi(argv[1]);
	unsigned int x = atoi(argv[2]);

	while (x % 2)
		x >>= 1;

	unsigned short int number_bitlength = bitlength(number);
	unsigned short int mask_bitlength = bitlength(x);

	unsigned int copy = x; // The variable we can edit.
	unsigned long long mask = copy; // The mask we need.
	const unsigned short int const_bitlength = bitlength(copy); // It's a constant of our "mask prototype".
	mask_bitlength = const_bitlength; // Mask's length.

	while (mask_bitlength < number_bitlength) {
		i = 0;
		for (i; i < const_bitlength; i++) {
			copy = pow(2, const_bitlength);
			mask <<= 1;
			if (mask & 1 != 0)
				mask++;
    }
  }

	unsigned long long res = number | mask;
	printf("Congrats, you made it! The number is %ull", res);

	return 0;
}
