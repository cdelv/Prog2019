//recibe un entero  
#include <iostream>


void numero (int);
int main (void)
{
  numero ();
  return 0;
}

void numero (int) 
{
  int m = 0;
  std::cout << "Escribe un número \n"; 
  std::cin >> m;
  std::cout << m << "\n";
}

