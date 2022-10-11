int main(){
    int a=0x08765432;
    printf("%d\n",a);
    printf("%d",logicalShift(0x87654321,4));
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