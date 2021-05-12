#include <iostream>
#include <fstream>
#include <cmath>

double potential(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h);
double electricfield(double x, double h);   
int main(void)
{
  std::ofstream fout("campo.txt");
  fout.precision(16); fout.setf(std::ios::scientific);

  double x = 2.5;
  double h = 0.02;

  for(x=0; x <= 2.5; x += h) {
    double exact = -1*2*(std::sin(x)+x*std::cos(x));
    fout << x << "\t"
	 << (exact) << "\t"
	 << (electricfield(x, h)) << "\n";
  }
  fout.close();
  return 0;
}


double potential(double x)
{
  return 2*x*std::sin(x);
  
}

double dev_central(double x, double h)
{
  return (potential(x+h/2) - potential(x-h/2))/h;
  
}

double dev_central_richardson(double x, double h)
{
  double result1 = dev_central(x, h);
  double result2 = dev_central(x, h/2);
  return (4*result2 - result1)/3;
  
}

double electricfield(double x, double h)
{
  return -1*dev_central_richardson (x,h);
}
