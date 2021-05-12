// programa que imprime el mayor factor primo. Carlos Andres del Valle
#include <iostream>
#include <cmath>

int isprime(int m);
int largest_prime_factor(int m);

int main(void)
{
  std::cout << largest_prime_factor(9) << std::endl;
  std::cout << largest_prime_factor(97) << std::endl;
  std::cout << largest_prime_factor(100) << std::endl;
  std::cout << largest_prime_factor(12345) << std::endl;
  std::cout << largest_prime_factor(1000099) << std::endl;
  std::cout << largest_prime_factor(5412345) << std::endl;
  std::cout << largest_prime_factor(95412341) << std::endl;
  std::cout << largest_prime_factor(35412347) << std::endl;
  std::cout << largest_prime_factor(835412343) << std::endl;
  
  return 0;
}

int isprime(int m)
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


int largest_prime_factor(int m)
{
  int max_factor;
  for (int k= 2; k <= m; ++k){
    if (m%k == 0 and (isprime(k)== 1)) {
      max_factor =k;
     
    }
  }
  return max_factor;
}
