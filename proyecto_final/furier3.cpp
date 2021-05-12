#include <iostream>
#include <fstream>
#include <cmath>


using fptr = double(double,double); 
double root (double x0, double eps, double t, fptr f, fptr fderiv, int itermax);
double fun(double t, double x);
double deriv(double t, double x);
void error_itermax(double xr, double fxr, int itermax);
double onda (double t, double root1);

const double EPS = 1.0e-5;
const int ITERMAX = 1000000;
const double v = 100;
const double R = 10;
const double L = 10.5;
const double c = 340;

int main(void)
{
  std::ofstream fout("1.txt");
  double W = v/R;
  fout.precision(15); fout.setf(std::ios::scientific);
    for (double i; i <= 1.0; i += 0.01){
    double rt1 = root (0.34, EPS, W*i, fun, deriv, ITERMAX);
    double rt2 = root (0.34, EPS, W*i, fun, deriv, ITERMAX);
    fout << i << "\t" << onda(i, rt1) << "\n";
    }
  return 0;
}

double root (double x0, double eps, double t, fptr f, fptr fderiv, int itermax)
{
  double xr = x0;
  int iter = 0;
  while(1) {
    if (std::fabs(f(t,xr)) <= eps) {
      break;
    }
    xr = xr - f(t, xr)/fderiv(t, xr);
    iter++;
    if (iter > itermax) {
      //error_itermax(xr, f(t, xr), itermax);
      break;
    }
  }
  
  return xr;
}
double fun(double t, double x)
{
  return std::pow(v*L/R*c,2) + std::pow(v/c, 2) +2*(v*v*L/R*c*c)*std::sin(t - x) - x*x;
}

double deriv(double t, double x)
{
  return -2*(v*v*L/R*c*c)*std::cosh(t - x) - 2*x;
}
void error_itermax(double xr, double fxr, int itermax)
{
  std::cerr << "############################################\n";
  std::cerr << "# ERROR: max number of iterations reached.\n";
  std::cerr << "# itermax = " << itermax << "\n";
  std::cerr << "# xr = " << xr << "\n";
  std::cerr << "# f(t, xr) = " << fxr << "\n";
  std::cerr << "############################################\n";
}
double onda (double t, double root1)
{
  return std::cos((v*R*(t - (root1/c)))/root1);
}

