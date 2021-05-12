#include <iostream>
#include <cmath>


int pythagoras (int a, int b, int c);
int main (void)
{
  int a= 1;
  int b= 1;
  int c= 1;
  for (int i; i < 1000; i++ ){a += i; return a;}
  for(int k; k < 1000; k++){b += k; return b;}
  for(int j; j < 1000; j++){c += j; return c;}

  std::cout << pythagoras (a,b,c) << std::endl;
  return 0;
}

int pythagoras (int a, int b, int c)
{
  if ((a*a + b*b - c*c == 0) and (a+b+c == 1000)){
      return a*b*c;
  }
  else (int main)
  return a*b*c;
}
