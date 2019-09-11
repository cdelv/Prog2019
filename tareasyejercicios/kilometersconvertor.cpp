//programa que convierte millas  a kilometros. 1 milla  = 1.609 kilometros.
#include <iostream>
int main (void)
{
  double m = 0.0;
  std::cout << "millas = :\n";
  std::cin >> m;
  double km = m * 1.609;
  std::cout << "kilometros =" <<km<< "\n";
  return 0;
  
}
