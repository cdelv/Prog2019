
#include <iostream>
#include <cmath>

void divisores (long long x);
long long primos (long long m);
long long print (long long x);

int main (void)
{
  long long x= 0;
  std:: cout << "Escribe un número para descomponer en factores primos: " << std::endl;
  std::cin >> x;
  std::cout << "Factores primos" << "\t" << "|Número de veces" << std::endl;
  divisores (x);
  return 0;
}

void divisores (long long x)
{
  for (long long k  = 2 ; k <= x; ++k){
    long long j;
    if (x%k == 0 and (primos(k)== 1)){
      for(long long  i=1;x%(int (pow(k,i)))==0; ++i){
        
	j = i;
      }
      std::cout  << k << "\t" << "\t" << j << "\n";
      
    }
  }
}
long long primos (long long m)
  {
  if (m == 1) return 0;
  int flag = 1;
  for(long long ii = 2; ii <= std::sqrt(m); ++ii) {
    if (m%ii==0) {
      flag = 0;
      break;
    }
  }
  return flag;}
