#include <fstream>
#include <vector>
#include <cmath>
int main (void)
{
  const int N = 10000;
  std::vector<double> data(N, 0.0);
  for (int i = 0; i <  N; i++)
    {
      data[i] = std::sin(i)+std::sin(4*i)+std::sin(7*i); 
    }
  
  std::ofstream fout("data.txt");
  for (const auto & x : data ) 
    {
      fout << x << "\n";
    }
  fout.close();
  return 0;
}
