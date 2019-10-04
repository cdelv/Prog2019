
#include <iostream>
#include <cmath>

void divisores (int x);
int primos (int m);
int print (int x);

int main (void)
{
  int x= 0;
  std:: cout << "Escribe un número para descomponer en factores primos: " << std::endl;
  std::cin >> x;
  std::cout << "Factores primos" << "\t" << "|Número de veces" << std::endl;
  divisores (x);
  return 0;
}

void divisores (int x)
{
  for (int k  = 2 ; k <= x; ++k){
    int j;
    if (x%k == 0 and (primos(k)== 1)){
      for(int i=1;x%(int(pow(k,i)))==0; ++i){
	//	std::cout  << k << "\t"<< i << "\n";
	j = i;
      }
      std::cout  << k << "\t" << "\t" << j << "\n";
       
      //  std::cout << k <<"\n";
      
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
