#include <iostream>
#include <cmath>

using fptr = double(double);  
double bisection(double xl, double xu, double eps, fptr f);
double regulafalsi(double xl, double xu, double eps, fptr f);
double fixedpoint (double x0, double eps, fptr f, fptr g);
double fun(double x);
double gaux (double x);

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  
  const double EPS = 1.0e-8;
  double root = 0;
  root = bisection (100, 200, EPS, fun);
  std::cout << root << "\n";
  root = regulafalsi(100, 200, EPS, fun);
  std::cout << root << "\n";
  root = fixedpoint( 100, EPS, fun, gaux);
  std::cout << root << "\n";
  
  return 0;
}

double bisection(double xl, double xu, double eps, fptr f, fptr g)
{
  double xr = xl;
  int iter = 0;
  while(1) {
    xr=(xl+xu)/2;
    if (std::fabs(f(xr)) <= eps) {
      break;
    }
    else if (f(xr)*f(xl) < 0) {
      xu = xr;
    }
    else {
      xl = xr;
    }
    iter++;
  }
  std::cout << "# bisection niter = " << iter << "\n";

  return xr;
}

double regulafalsi(double xl, double xu, double eps, fptr f)
{
  double xr = xl;
  int iter = 0;
  while(1) {
    xr = xu - (f(xu)*(xl-xu))/(f(xl) -f(xu));
    if (std::fabs(f(xr)) <= eps) {
      break;
    }
    else if (f(xr)*f(xl) < 0) {
      xu = xr;
    }
    else {
      xl = xr;
    }
    iter++;
  }
  std::cout << "# regula falsi niter = " << iter << "\n";

  return xr;
}



double fun(double x)
{
  return x + 10 - x*std::cosh(50.0/x);
}
double gaux (double x)
{
  return -10 + x*std::cosh(50.0/x);
}





double fixedpoint (double x0, double eps, fptr f, fptr g)
{
  double xr = x0;
  int iter= 0;
  while (1) {
    if (std::fabs(f(xr)) <= eps) {
      iter++;
      break;
    }
    xr = g(xr);
  }
  std::cout << "niter" << iter << "\n";
  return xr;
}
