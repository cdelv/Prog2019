//programa que recibe dos numeros enteros y reporta cual es el mayor, el menor, la suma, la diferencia, el producto y el cociente.
#include <iostream>
int main(void)
{
  int val1 = 0.0;
  int val2 = 0.0;
  std::cout << "Escribe un número :\n" ;
  std::cin >> val1;
  std::cout << "Escribe otro número :\n" ;
  std::cin >> val2; 
  if (val1>val2){ std::cout << "El mayor es:" <<val1<< "\n";}   
  else { std::cout << "El mayor es:" <<val2<< "\n";}
  if (val1<val2){ std::cout << "El menor es:" <<val1<< "\n";}   
  else { std::cout << "El menor es:" <<val2<< "\n";}
  std::cout << "La suma es: " <<val1+val2<< "\n";
  if (val1>val2){ std::cout << "La resta  es:" <<val1-val2<< "\n";}   
  else { std::cout << "La resta es:" <<val2-val1<< "\n";}
  std::cout << "El producto es : " <<val1 * val2<< "\n";
  if (val1>val2){ std::cout << "El cociente es:" <<val1/val2<< "\n";}   
  else { std::cout << "El cociente es:" <<val2/val1<< "\n";}
  return 0;
}
