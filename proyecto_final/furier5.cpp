/*
  From https://www.gnu.org/software/gsl/doc/html/fft.html

  Requires gnu gsl installed. 

  Compile as : g++ -std=c++11 furier5.cpp -lgsl -lgslcblas

  NOTE: 

  For physical applications it is important to remember that the index
  appearing in the DFT does not correspond directly to a physical
  frequency. If the time-step of the DFT is \Delta then the
  frequency-domain includes both positive and negative frequencies,
  ranging from -1/(2\Delta) through 0 to +1/(2\Delta). The positive
  frequencies are stored from the beginning of the array up to the
  middle, and the negative frequencies are stored backwards from the
  end of the array.
*/
//parameters.

double const L = 10.5;
double const R = 10;
double const c = 340;
double  w = 1000;
double  v = w/R;
double  W = v/R;
double  l = W*R/c;
double  r = W*L/c;



#include <iostream>
#include <fstream>
#include <cmath>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

using fptr = double  (double, double);

double newton_raphson(double x0, double eps, fptr f, fptr fderiv, double t);
double fun(double x, double t);
double deriv(double x ,double t);
int test ( fptr fr, double pres, double x, double t);
double onda (double x0, double EPS, double t, double w);


int main (void)
{


  //FFT
  int i, n = 10000;
  double delta = 0.01;
  double tf = 1.4;
  double x0 = 0;
  double EPS = 1.0e-13 ;
  double data[2*n]; // array to store the time signal, real and imag parts

   //datos de la onda para graficar
  std::ofstream fut ("onda.txt");
  std::ofstream fout ("data.txt");
  for (int ii=0; ii < n; ii++){
   double t = ((ii)*tf)/n;
       double xg =((t*2)/10)+0.3466;
       fut  << t << "\t" <<std::fabs(onda (xg, EPS, t, w))<<  "\n";
       fout  << std::fabs(onda (xg, EPS, t, w))<<  "\n";
       }
       fut.close();
        fout.close();
  
  //datos de la onda para la FFTW
	/* std::ofstream fout ("data.txt");
  for (int ii=0; ii < n; ii++){
   double t = ((ii)*tf)/n;
       double xg =((t*2)/10)+0.3466;
       fout  << std::fabs(onda (xg, EPS, t, w))<<  "\n";
       }
       fout.close();*/
  // initialize the computing infrastructure
  gsl_fft_complex_wavetable * wavetable;
  gsl_fft_complex_workspace * work;

  // read the time data : Square signal
  // index i represents each time step

  std::ifstream fin("data.txt");
  for (i = 0; i < n; i++)
    {
      fin >> REAL(data,i);
      IMAG(data, i) = 0.0;
    }
  fin.close();
  
  // get memory for the FFT
  work = gsl_fft_complex_workspace_alloc (n);
  wavetable = gsl_fft_complex_wavetable_alloc (n);
  // perform the fft transform (on real data)
  gsl_fft_complex_forward (data, 1, n, wavetable, work);
  // release memory
  gsl_fft_complex_wavetable_free (wavetable);

  
  // print the fftw. Regarding frequencies, check NOTE at the beginning
std::ofstream foout ("plot.txt");
  for (int ii = 0; ii < n/2; ii++)
    {
      double a = ii;
      foout <<ii/tf  << "\t" << REAL(data, ii) <<"\n";
    }
foout.close();
  gsl_fft_complex_workspace_free (work);
  return 0;
}

double newton_raphson(double x0, double eps, fptr f, fptr fderiv,  double t)
{
  double xr = x0;
  int iter = 0;
 
  do {
    xr=xr-f(xr,t)/fderiv(xr,t);

    if (test(f, eps,xr,t)==1)
      {
	return xr;
      }
  }
  while(test(f, eps,xr,t)==0);
  }


double fun(double x, double t)
{
  
  return l*l+ r*r + 2*r*l*std::sin(t-x)-x*x;
}

double deriv(double x, double t)
{
 
    return  -2*r*l*std::cos(t-x)-2*x;
}



int test ( fptr fr, double pres, double x , double t)
{
  if (std::fabs( fr(x,t)) <= pres){
    
    return 1;}

  else  {
      return 0; }
      }

double onda (double x0, double EPS, double t, double w)
{
  double x = newton_raphson (x0, EPS, fun, deriv, W*t);
  return std::cos(w*(t-x/c))/x;
}
