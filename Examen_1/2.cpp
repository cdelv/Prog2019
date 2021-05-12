#include <fstream> 
#include <cmath>

double potential(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h);
double electricfield(double x, double h);   
int main(void)
{
  // fill this
  
}

double potential(double x)
{
  // fill this

}

double dev_central(double x, double h)
{
  return (fun(x+h/2) - fun(x-h/2))/h;
}

double dev_central_richardson(double x, double h)
{
  // fill this

}

double electricfield(double x, double h)
{
  // fill this
}
