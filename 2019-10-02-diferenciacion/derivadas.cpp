#include <iostream>
#include <cmath>

double f (double x); // funcion en terminos de x
double derivada1_error_h (double x, double h);  //derivada fordward
//double derivada1_error_hh (double x, double h); //por alguna razon da muy mal
double derivada1_central (double x, double h); //
double derivada2 (double x, double h);
double richard_derivada (double x, double h);

int main (void)
{
std::cout.precision(16); std::cout.setf(std::ios::scientific);

  double x = M_PI/3.0; // M_PI defined inside cmath
  double h = 0.1;

  //std::printf(" %25.16e %25.16e %25.16e %25.16e %25.16e %25.16e", x, h,
  // std::cos(x), dev_forward(x, h),
  // dev_central(x, h), dev_forward_richardson(x, h));

  std::cout << x << "\t" << h << "\t"
	    << std::cos(x) << "\t"
	    << derivada1_error_h(x, h)<< "\t"
	    << derivada1_central(x, h) << "\t"
	    << richard_derivada(x, h) << "\n";
  
  return 0;
}
double f (double x)
{
 return std::sin(x);  
}
double derivada1_error_h (double x, double h)
{
  return ((f(x+h)-f(x))/h);
}
double derivada1_error_hh (double x, double h)
{
  return ((f(x+h)-f(x-h))/2*h);
}
double derivada1_central (double x, double h)
{
return (f(x+h/2) - f(x-h/2))/h;
}
double derivada2 (double x, double h)
{
  return ((f(x+h)-f(x))-(f(x)-f(x-h))/h*h);
}
double richard_derivada (double x, double h)
{
  double result1 = derivada1_error_h (x,h);
  double result2 = derivada1_error_h (x,h/2);
  return (4*result2 - result1)/3;
}
