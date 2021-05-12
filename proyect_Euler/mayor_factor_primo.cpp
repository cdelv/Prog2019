#include <iostream>
#include <cmath>

int primos (int m);
double factores_primos (int m);
int main(void)
{
  int factor;
  std::cout << factores_primos (m) << std::endl;
  return 0;
}

int primos (int m)
{
  if ( m == 1) return 0;
  int flag = 1;
  for (int ii = 2; ii <= m;ii++ ){
    if (m%ii == 0){
      flag = 0;
      break;
    }
  }
  return flag;
}

double factores_primos (int m)
{
  int factor= 0;
  for (int ii= 2; ii <= 600851475143; ii++){
    if (m%primos(ii)==0) {
      factor = std::max (primos(ii), primos(ii-1));
	}
  }
  return factor;
}

