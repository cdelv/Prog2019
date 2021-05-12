#include <iostream>


float max ( float &a, float &b);
int main (void)
{
  float a;
  float b;
  std::cout << "escribe un número \n";
  std::cout << "no seas malvado, solo 6 decimales \n";
    std::cin >> float a;
    std::cout << "escribe otro numero \n";
    std::cin >> float b;

  std::cout << max(2.00001,2.01) << "\n";

  return 0;
}

float max ( float &a, float &b)
{
  double result=0;
  if ( a>= b) {
    result = a;}
  else {
    result = b;}
  return result;
}
