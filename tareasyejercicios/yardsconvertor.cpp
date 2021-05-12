//programa que convierte furlongs a yardas. 1 furlong = 220 yardas.
#include <iostream>
int main (void)
{
  double f = 0.0;
  std::cout << "furlongs = :\n";
  std::cin >> f;
  double y = f * 220;
  std::cout << "yardas =" <<y<< "\n";
  return 0;
  
}
