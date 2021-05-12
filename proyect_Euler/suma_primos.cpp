#include <iostream>
#include <cmath>

int primos (int m);
int sumatoria (int m);

int main (void)
{
  std::cout << sumatoria (10) << std::endl;
  std::cout << sumatoria (2000000) << std::endl; 
  return 0;
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

  
int sumatoria (int m)
{
  int sum = 0;
  for(int ii = 2; ii <= m; ++ii) {
    if (primos(ii)==1) {
      sum += ii;
    }
  }
  return sum;
}
