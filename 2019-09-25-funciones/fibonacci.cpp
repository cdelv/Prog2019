#include <iostream>

void fibonacci_loop(int N);
int fibonacci_recursive(int N);


int main(void)
{
  int N = 5;

  fibonacci_loop(N);
  std::cout << fibonacci_recursive(N) << "\n";

  return 0;
}

void fibonacci_loop(int N)
{
  std::cout << "# Fibonacci loop : \n";
  if (N == 0) std::cout <<  "1\n";
  if (N == 1 or N>= 2) std::cout <<  "1\n1\n";
  int aold1 = 1, aold2 = 1, a;
  for (int ii = 2 ; ii <= N; ++ii){
    a = aold1 + aold2;
    std::cout << a << "\n";
    // intercambio
    aold2 = aold1;
    aold1 = a;
  }
}

int fibonacci_recursive(int N)
{
  if (N==0) std::cout << "# Fibonacci recursive : \n";
  if (N==1 or N==0) return 1;
  return fibonacci_recursive(N-1) + fibonacci_recursive(N-2);
}
