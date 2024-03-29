// from https://stackoverflow.com/questions/32276728/plotting-frequency-spectrum-with-c

// compile as: g++ -O3 furier6.cpp -lm -lfftw3


//parametros.

double const L = 10.5;
double const R = 10;
double const c = 340;
double const w = 1000;
double const v = w/R;
double const W = v/R;
double const l = W*R/c;
double const r = W*L/c;

#include <fftw3.h>
#include <iostream>
#include <cmath>
#include <fstream>


using fptr = double  (double, double);

double newton_raphson(double x0, double eps, fptr f, fptr fderiv, double t);
double fun(double x, double t);
double deriv(double x ,double t);
int test ( fptr fr, double pres, double x, double t);
double onda (double x0, double EPS, double t, double w);

int main(){
  
  const int N = 10000; // numero de datos
  double Fs = N/2; // intervalos de frecuencias
  double tf = 0.65;// escala de la grafica
  double  T = tf / Fs; // intervalos del tiempo  
  double x0 = 0;
  double EPS = 1.0e-13 ;

  // transformada real
  double *in;
  fftw_complex *out;
  double frecuencias[N];
  fftw_plan plan_forward;

  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

//datos de la onda para graficar
  std::ofstream fut ("onda.txt");
  std::ofstream fout ("data.txt");
  for (int ii=0; ii <= N; ii++){
   double t = ii*T;
       double xg =((t*2)/10)+0.3466;
       fut  << t << "\t" <<std::fabs(onda (xg, EPS, t, w))<<  "\n";
       fout  << std::fabs(onda (xg, EPS, t, w))<<  "\n";
       }
       fut.close();
        fout.close();
	//datos para la transformada
	std::ifstream fin("data.txt");
  for (int i = 0; i <= N; i++)
    {
      fin >> in[i];
    }
  fin.close();
 
  // tabla de frecuencias
  for(int i = 0; i <= ((N/2)-1); i++){
    frecuencias[i] = (Fs * i) / N;
  }
  // transformacion
  plan_forward = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
  fftw_execute(plan_forward);

  // imprimir el PSD
  double PSD[N];
  for(int i = 0; i <= ((N/2)-1); i++){
    PSD[i] = (out[i][0] * out[i][0] + out[i][1] * out[i][1]) / N;  
  }
  std::ofstream myfile("PSD.txt");
  for(int i = 0; i < ((N/2)-1); i++){ 
    myfile << frecuencias[i] << "\t" << PSD[i] << std::endl;
  }
  myfile.close();

  fftw_destroy_plan(plan_forward);
  fftw_free(in);
  fftw_free(out);

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
  return 0;
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
