#include <fstream>
#include <cmath>

using fptr = double(double);  
double bisection(double xl, double xu, double eps, fptr f, int itermax);
double regulafalsi(double xl, double xu, double eps, fptr f, int itermax);
double newton_raphson(double x0, double eps, fptr f, fptr fderiv, int itermax);
double fun(double x);
double deriv(double x);


int main(void)
{
  std::ofstream fout ("1.txt");
  fout.precision(16); fout.setf(std::ios::scientific);
  
   double EPS = 1;
  const int ITERMAX = 10000;

  fout << "        EPS_DELTA" << "\t" << "        Nbisect"
       << "\t" << "               NFalsePos" << "\t"
       << "             NNewton" << "\n";

  
  for (int i=1; i<=9 ; i++){
    EPS = pow(10,-i);
    fout << EPS << "\t";
  double root = bisection(0.1, 10, EPS, fun, ITERMAX);
  fout << root << "\t";
  root = regulafalsi(0.1, 10, EPS, fun, ITERMAX);
  fout << root << "\t";
  root = newton_raphson(0.1, EPS, fun, deriv, ITERMAX);
  fout << root << "\n";
  }
  fout.close();
  return 0;
}

double bisection(double xl, double xu, double eps, fptr f, int itermax)
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
    if (iter > itermax) {
      break;
    }
  }

  return iter;
}

double regulafalsi(double xl, double xu, double eps, fptr f, int itermax)
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
    if (iter > itermax) {
  
      break;
    }
  }
  return iter;
}


double newton_raphson(double x0, double eps, fptr f, fptr fderiv, int itermax)
{
  double xr = x0;
  int iter = 0;
  while(1) {
    if (std::fabs(f(xr)) <= eps) {
      break;
    }
    xr = xr - f(xr)/fderiv(xr);
    iter++;
    if (iter > itermax) {
      break;
    }
  }
  return iter;
}


double fun(double x)
{
  return 3*std::exp(-x) - x;
}

double deriv(double x)
{
  return -3*std::exp(-x)-1;
}



