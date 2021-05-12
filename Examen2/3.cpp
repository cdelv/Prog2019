  #include <iostream>
  #include <vector>
  #include <cmath>
  #include <algorithm>
  
  double mean(const std::vector<double> & data);
  double sigma(const std::vector<double> & data);
  double min(const std::vector<double> & data);
  double max(const std::vector<double> & data);
  
  int main(int argc, char **argv)
  {
    std::vector<double> data = {2.34, 3.76, 4.00, 1.98, -6.56, 9.09, -8.09};
    std::cout << mean(data) << std::endl;
    std::cout << sigma(data) << std::endl;
    std::cout << min(data) << std::endl;
    std::cout << max(data) << std::endl;
   
    
    return 0;
  }  
double mean(const std::vector<double> & data)
{
  double sum = 0.0;
  double mean = 0.0;
  for(auto x :data){
    sum+= x;}
  mean = sum/data.size();
  return mean;
}
double sigma(const std::vector<double> & data)
{
  double sum2= 0.0;
  double sigma = 0.0;

  for(auto x :data){
    sum2 += pow(x-mean(data), 2);
  }
  sigma = std::sqrt(sum2/(data.size()-1) );
  return sigma;
}

double min(const std::vector<double> & data)
{
  double max = 0.0;
  max = *std::max_element(data.begin(), data.end());
 return max;
}
double max(const std::vector<double> & data)
{
  double min = 0.0;
  min = *std::min_element(data.begin(), data.end());
 return min;
}
