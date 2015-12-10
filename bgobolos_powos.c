int bitlength(int num) {
  int counter = 0;
  while (num > 0) {
    num >>= 1;
    counter++;
  }
  return counter;
}

long bgobolos_bitoperations(long a1, int a2) {
  if (!a1)
    return a1;

  while (!(a2 & 1))
    a2 >>= 1;

  unsigned short int i;
  const unsigned short int const_bitlength = bitlength(a2); // It's a constant of our "mask prototype".
  unsigned short int number_bitlength = bitlength(a1);
  unsigned short int mask_bitlength = const_bitlength;
  unsigned long long mask = a2; // The mask we need.
  unsigned int bitmask; // A temp mask to get our mask we need.
  bitmask = 1 << const_bitlength;

  while (mask_bitlength < number_bitlength) {
    for (i = 0; i < const_bitlength; i++) {
      mask <<= 1;
      if ((mask & bitmask) != 0)
        mask++;
    }
    mask_bitlength = bitlength(mask);
  }

  unsigned long long res = a1 | mask;
  return res;
}
