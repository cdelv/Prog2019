#include <iostream>
#include <cmath>

int pares (int m);
int fibonacci (int N);
int main (void)
{
  std::cout << pares (4000000) << std::endl;
  return 0;
}

int fibonacci (int N)
{
  //std::cout << "# Fibonacci loop : \n";
  // if (N == 0) std::cout <<  "1\n";
  // if (N == 1 or N>= 2) std::cout <<  "1\n1\n";
  int aold1 = 1, aold2 = 1, a;
  for (int ii = 2 ; ii <= N; ++ii){
    a = aold1 + aold2;
    // std::cout << a << "\n";
    // intercambio
    aold2 = aold1;
    aold1 = a;
  }
  return a;
}

int pares (int m)
{
  int suma =0;
  for(int ii = 1; ii<m; ii++){
  if (fibonacci (ii)%2==0){
    suma += fibonacci (ii);}}
  return suma;
}
  
