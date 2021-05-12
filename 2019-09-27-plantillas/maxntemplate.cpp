#include <iostream>
// al compilar hay que declararlo.

template <typename T, typename S>
T max (T a, S b)
{
  if (a >= b){
    return a;}
  else {
    return b;}
}

int main (void)
{

  std::cout << max (1.000004, 1.000005) << "\n";
  std::cout << max (1.5, 1) << "\n";
  std::cout << max (2, 7) << "\n";
  return 0;
}




