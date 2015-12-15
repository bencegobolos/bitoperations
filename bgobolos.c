int bitlength(int num) {
  int counter = 0;
  while (num > 0) {
    num >>= 1;
    counter++;
  }
  return counter;
}

long long  bgobolos_bitoperations(long a1, int a2) {
  if (!a2)
    return a1;

  while (!(a2 & 1))
    a2 >>= 1;

  const unsigned short int a2_bitlength = bitlength(a2);
  const unsigned short int a1_bitlength = bitlength(a1);
  unsigned short int mask_bitlength = const_bitlength;
  unsigned long long mask = a2; // The mask we need.

  while (mask_bitlength < a1_bitlength) {
    mask <<= a2_bitlength;
    mask += a2;
    mask_bitlength = bitlength(mask);
  }

  unsigned long long res = a1 | mask;
  return res;
}
