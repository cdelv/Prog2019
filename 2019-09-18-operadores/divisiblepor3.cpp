#include<iostream>

int main (void)
{
  int a = 0;
  std::cout << "Escribe un numero entero \n";
  std::cin >> a;
  if (a%3 == 0){
    std::cout << "El numero "<< a << " es divisible por 3 \n";}
  else {
    std::cout << "El numero "<< a << " no es divisible por 3 \n";};
  return 0;
}
