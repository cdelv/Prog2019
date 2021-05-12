#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

const int N = 100;
double compute_dotproduct(const std::vector<double> & VA, const std::vector<double> & VB);
double compute_angle(const std::vector<double> & VA, const std::vector<double> & VB);
double compute_norm(const std::vector<double> & V);

int main(void)
{
  const int N = 100;
  
  std::vector<double> A(N), B(N);
  // fill vectors (you can use other ways to fill them just to test)
  std::fill(A.begin(), A.end(), 1); // Fill A with 1 on all places
  std::iota(B.begin(), B.end(), 0); // fill B as 0, 1, 2, 3, 4, ..., N-1
  // Compute the relative angle
  std::cout << compute_angle(A, B) << std::endl;
}
double compute_dotproduct(const std::vector<double> & VA, const std::vector<double> & VB)
{
  double dot=0.0;
  for (int i=0;i < N; i++)
    {dot += VA[i]*VB[i];}
  return dot;
}
double compute_angle(const std::vector<double> & VA, const std::vector<double> & VB)
{
  double angle = 0.0;
  angle = std::acos(compute_dotproduct(VA,VB)/(compute_norm(VA)*compute_norm(VB)));
    return angle;
}

double compute_norm(const std::vector<double> & V)
{
  double sum = 0.0;
  double norm = 0.0;
  for (auto x: V){
    sum += x*x;}
    norm = std::sqrt(sum);
    return norm;
}
