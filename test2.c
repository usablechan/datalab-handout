int main(){
  printf("%d",addOK(0x80000000,0x80000000));
}

int bitAnd(int x, int y) {
    int a=~x;
    int b=~y;
  return ~(a|b);
}

int anyOddBit(int x) {
    return !!(( x | x>>8 | x>>16 | x>>24) & 0xaa );
}

int allEvenBits(int x) {
  return !!(~( x & x>>8 & x>>16 & x>>24 ) & 0xaa );
}

int logicalShift(int x, int n) {
  return ~((~0 << (32 + ~n)) <<1) & x >> n ;
}

// int logicalNeg(int x) {
//   x= x | x>>16;
//   x= x | x>>8;
//   x= x | x>>4;
//   x= x | x>>2;
//   return ((x | x>>1)&1)^1;
// }

int logicalNeg(int x) {
    return ((x|(~x+1))>>31)+1;
}

int tmax(void) {
  return ~(1<<31);
}

int isPositive(int x) {
  return !(1<<31 & x) ^ !x;
}

int sign(int x) {
    return x>>31 | !!x;
}

// int addOK(int x, int y) {
//   return !!(x>>31 ^ y>>31) | (x>>31&y>>31) & (x+y)>>31;
// }

int addOK(int x, int y) {
  int a=x+y;
  return !((a ^ x) & (a ^ y))>> 31;
}


int isGreater(int x, int y) {
  return x+(~y+1);
}