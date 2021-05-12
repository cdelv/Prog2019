#include <iostream>
#include <fstream>
#include <cmath>


const double v = 100.0;
const double R = 10.0;
const double L = 10.5;
const double c = 340.0;

using fptr = double(double , double);
double fx (double t, double x);
double d (double t, double w, fptr fx, double root);
double newton_raphson(double x0, double eps, fptr fx, fptr fderiv, int itermax, double t);
double deriv(double x, double t);
void error_itermax(double xr, double fxr, int itermax);
  int main (void)
{
  double root = newton_raphson( 0, 0.0001, fx, deriv, 10000, 1);
  std::cout << d (1, (v/2*3.14*R),fx,root ) << std::endl;

  return 0;
}

//funcion de la posicion
double fx (double t, double x)
{
 return std::pow(v*L/c*R, 2)+ std::pow(v/c, 2)+((2*v*v*L)/(R*c*c))*std::sin(t - x) - x*x;
}
//funcion discreta de la onda
double d (double t, double w, fptr fx , double root )
{
  return (std::cos(w*(t-fx(root, t*v/c*R))))/(fx(root, v*t/R));
}
// raiz por newton rapshon
double newton_raphson(double x0, double eps, fptr f, fptr fderiv, int itermax, double t)
{
  double xr = x0;
  int iter = 0;
  while(1) {
    if (std::fabs(fx(xr, t)) <= eps) {
      break;
    }
    xr = xr - fx(xr, t)/fderiv(xr, t);
    iter++;
    if (iter > itermax) {
      error_itermax(xr, fx(xr, t), itermax);
      break;
    }
  }
std::cout << "# newton-raphson niter = " << iter << "\n";
  
  return xr;
}
//derivada implicita de la funcion fx
double deriv(double x, double t)
{
  return ((2*v*v*L)/(R*c*c))*std::cos(t - x) - 2*x;
}
//funcion que detecta errores de convergencia en la raiz
void error_itermax(double xr, double fxr, int itermax)
{
  std::cerr << "############################################\n";
  std::cerr << "# ERROR: max number of iterations reached.\n";
  std::cerr << "# itermax = " << itermax << "\n";
  std::cerr << "# xr = " << xr << "\n";
  std::cerr << "# f(xr) = " << fxr << "\n";
  std::cerr << "############################################\n";
}
