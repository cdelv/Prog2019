#include <iostream>


float max ( float a, float b);
int main (void)
{
  std::cout << max(2.7,1) << "\n";
  return 0;
}

float max ( float a, float b)
{
  double result=0;
  if ( a>= b) {
    result = a;}
  else {
    result = b;}
  return result;
}
