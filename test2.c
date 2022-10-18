unsigned floatAbsVal(unsigned uf) {
  unsigned exp=uf>>23&0xFF;
  unsigned frac=uf<<9;
  if((( exp^0xff ) | !frac))
    return ~(1<<31) & uf;
  return uf;
}

int main(){
  printf("%d",floatIsEqual(0x7f800000,0x7f800000));
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
  return !(((a ^ x) & (a ^ y))>> 31);
}


int isGreater(int x, int y) {
  int a=x>>31;
  int b=y>>31;
  int c=a^b;
  return !!((c&b) | (!c & ((y+(~x+1))>>31))) ;
}


int floatFloat2Int(unsigned uf) {
  int exp=((~(1<<31)) & uf) >>23;
  int e=exp-150;
  int sign=!(uf>>31);
  int frac=!((-1)<<23) & uf;
  int m=1<<23+frac;
  int result;
  if (e>7)
    return 0x80000000u;
  else if (e<-23)
    return 0;
  else if(e>=0)
    result=m<<e;
  else
    result=m>>-e;
  if (sign ==1)
    return result;
  return -result;
}

int floatIsEqual(unsigned uf, unsigned ug) {
  unsigned exp=uf>>23&0xFF;
  unsigned frac=uf<<9;
  unsigned exp2=uf>>23&0xFF;
  unsigned frac2=uf<<9;
  if(!((( exp^0xff ) | !frac) | (( exp2^0xff ) | !frac2)))
    return 0;
  else if( uf==0 && (uf<<1)^(ug<<1)==0 )
    return 1;
  return !(uf^ug);
}