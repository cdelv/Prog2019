#include <iostream>
#include <cmath>

int main(void)
{
  const int N = 10;
  // double data[N] = {1,1,1,1,1,1,1,1,1,1};
  // double data[N] = {0};
  double data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // average and std dev
  double sum = 0.0, sum2 = 0.0;
  // for(int ii = 0; ii < N; ++ii){
  //   sum  += data[ii];
  //   sum2 += data[ii]*data[ii];
  // }

  for(auto x : data){
    sum  += x;
    sum2 += x*x;
  }

  double average = sum/N;
  double stddev = std::sqrt(sum2/N - (average*average));

  std::cout << "# Average : " << average << "\n";
  std::cout << "# stddev  : " << stddev  << "\n";
  
  return 0;
}
