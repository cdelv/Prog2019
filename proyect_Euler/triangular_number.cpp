#include <iostream>
#include <cmath>

int terminos (int m);
int primos (int m);
int divisores (int m);
int main (void)
{
  std::cout << divisores (1) << std::endl;
  // std::cout << divisores (2) << std::endl;
  // std::cout << divisores (3) << std::endl;
  // std::cout << divisores (4) << std::endl;
  return 0;
}
int terminos (int m)
{
  int termino =0;
  for (int n = 1; n <= m; ++n){
    termino =(n*(n+1))/2;}
  return termino;
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
  return flag;
}
int divisores (int m)
{
  int divisor = 0;
  for (int ii = 1; ii <= m; ++ii){
    if ((primos (ii) == 0) and (std::min (terminos (m)%ii-2), terminos (m)%ii-1), terminos (m)%ii)) == 0)){
    divisor += 1;
    }
  }
return divisor;
}


