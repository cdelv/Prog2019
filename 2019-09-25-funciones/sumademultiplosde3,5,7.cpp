// suma todos los numeros multiplos de 3,5 y 7 entre 200k y 300k
#include <iostream>
# include <cmath>

int suma (int m, int n);

int main (void)
{
  std::cout << suma(200000, 300000) << "\n";
  return 0;
}



int suma (int m, int n)
{
  int result = 0;
  for (int ii = m; ii <= n; ++ii){
    if ((ii%3==0) or ( ii%5== 0) or ( ii%7== 0))
      {
	result += ii;
      }
  }
  return result;
}
