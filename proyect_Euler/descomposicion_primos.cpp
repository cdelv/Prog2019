
#include <iostream>
#include <cmath>

int divisores (int x);
int primos (int m);
int print (int x);

int main (void)
{
  divisores (34320);
  return 0;
}

int divisores (int x)
{
  for (int k= 2; k <= x; ++k){
    if (x%k == 0 and (primos(k)== 1)) {
      std::cout << k << "\n";
     
    }
  }
}
int primos (int m)
  {
  if (m == 1) return 0;
  int flag = 1;
  for(int ii = 2; ii <= std::sqrt(m); ++ii) {
    if (m%ii==0) {
      flag = 0;
      break;
    }
  }
  return flag;}

