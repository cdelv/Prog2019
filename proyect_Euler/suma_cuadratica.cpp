#include <iostream>

int main (void)
{
  int suma1=0;
  int suma2=0;
  double suma3=0;
  for (int k= 1; k<=100; ++k){
   suma1 += k*k;
   }
  for (int i= 1; i<=100; ++i ){
    suma2 += i;
  }
  suma3= suma1 - suma2*suma2;
    std::cout << suma3 << std::endl;
     std::cout << suma2 << std::endl;
      std::cout << suma2*suma2 << std::endl;
       std::cout << suma1 << std::endl;
    
    return 0;
}
