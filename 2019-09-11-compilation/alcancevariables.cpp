//ver el alcance de las variables
#include<iostream>
const double X = 5.6;
int main(void)
{
  double x=7.4;
  std::cout << &x << "\n";
  {
    std::cout << &x << "\n";
    double x=7.4;
    std::cout << &x << "\n";
  }
  std::cout << &x << "\n";
  return 0;
}
