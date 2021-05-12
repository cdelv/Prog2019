#include <iostream>
#include <cmath>

using fptr = double(double, double);  

double newton_raphson(double x0, double eps,double t, fptr f, fptr fderiv, int itermax);
double fun(double t, double x);
double deriv(double t, double x);
void error_itermax(double xr, double fxr, int itermax);
const double EPS = 1.0e-14;
  const int ITERMAX = 100;
int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);

  for(double i= 0; i<= 100; i++){
  double root = (0,EPS, i/100, fun, deriv, ITERMAX); 
  std::cout << "\t" << i/100 << "\t" << root << std::endl;
  
  }
  
  return 0;
}


double newton_raphson(double x0, double eps,double t, fptr f, fptr fderiv, int itermax)
{
  double xr = x0;
  int iter = 0;
  while(1) {
    if (std::fabs(f(t, xr)) <= eps) {
      break;
    }
    xr = xr - f(t, xr)/fderiv(t, xr);
    iter++;
    if (iter > itermax) {
      error_itermax(xr, f(t,xr), itermax);
      break;
    }
  }
  
  return xr;
}


double fun(double t, double x)
{
  
    return std::sin(t-x) - x*x;
   
  }


double deriv(double t, double x)
{
  return -std::cos(t-x) - 2*x;
}


void error_itermax(double xr, double fxr, int itermax)
{
  std::cerr << "############################################\n";
  std::cerr << "# ERROR: max number of iterations reached.\n";
  std::cerr << "# itermax = " << itermax << "\n";
  std::cerr << "# xr = " << xr << "\n";
  std::cerr << "# f(xr) = " << fxr << "\n";
  std::cerr << "############################################\n";
}
