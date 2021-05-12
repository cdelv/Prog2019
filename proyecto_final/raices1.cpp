#include <iostream>
#include <cmath>
#include <vector>
using fptr = double  (double, double, double, double );


double newton_raphson(double x0, double eps, fptr f, fptr fderiv, double tr,
		      double lo, double ro);
double fun(double x, double l0, double r0,double t);
double deriv(double x,double l0, double r0,double t);
int test ( fptr fr, double pres, double x,double l0, double r0, double t);


int main(void)
{  
  

  const double EPS = 1.0e-8;
  const double R=10.0;
  const double L=10.5;
  const double c=340.0;
  const double v=100.0;
  const double N=2;

  std::vector <double> roots(N);
  double o=v/R;
  double l=(o*L)/c;
  double r=(o*R)/c;
  double delta_t=1/(o*N);

    for (int ii=0; ii<N; ii++)
    {
      double tt =ii*o*delta_t;
      double xg =((tt*2)/10)+0.3466;
      roots[ii]=newton_raphson(xg, EPS,  fun,  deriv, tt,l,r);
    }
  
    for ( int jj; jj<roots.size(); jj++)
      {
	std::cout<< roots[jj]<<"\n";
      }
    

   
  return 0;
}

 


double newton_raphson(double x0, double eps, fptr f, fptr fderiv,  double tr, double lo, double ro)
{
  double xr = x0;
  int iter = 0;
 
  do {
    xr=xr-f(xr,lo,ro,tr)/fderiv(xr,lo,ro,tr);

    if (test(f, eps,xr,lo,ro,tr)==1)
      {
	return xr;
      }
  }
  while(test(f, eps,xr,lo,ro,tr)==0);
  }


double fun(double x, double l0, double r0,double t)
{
  
  return l0*l0+ r0*r0 + 2*r0*l0*std::sin(t-x)-x*x;
}

double deriv(double x,double l0, double r0, double t)
{
 
    return  -2*r0*l0*std::cos(t-x)-2*x;
}



int test ( fptr fr, double pres, double x,double l0, double r0, double t)
{
  if ( fr(x,l0,r0,t) <= pres){
    
    return 1;}

  else  {
      return 0; }
      }
