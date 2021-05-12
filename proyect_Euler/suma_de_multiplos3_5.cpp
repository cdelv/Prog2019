#include <iostream>
#include <cmath>


int multiplos (int m);
int main (void)
{
  std::cout << multiplos (1000)<< std::endl;
  std::cout << multiplos (100)<< std::endl;
  std::cout << multiplos (10)<< std::endl;
  return 0;
}


int multiplos (int m)
{
  int result = 0;
  for (int ii = 1; ii < m; ++ii){
    if ((ii%3==0) or (ii%5==0)){
      result += ii;}}
  return result;
}


