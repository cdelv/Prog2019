// from https://stackoverflow.com/questions/32276728/plotting-frequency-spectrum-with-c
#include <fftw3.h>
#include <iostream>
#include <cmath>
#include <fstream>

int main(){
  // use meaningful names for all the variables
  const int N = 550; // number of points acquired inside the window
  double Fs = 200.0; // sampling frequency
  double  T = 1.0 / Fs; // sample time 
  double f = 50.0; // frequency

  // real transform
  double *in;
  fftw_complex *out;
  double ff[N];
  fftw_plan plan_forward;

  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

  for (int i = 0; i <= N; i++){
    double time = i*T;
    //in[i] = sin(2 * M_PI * f *t[i]); // simple signal
    in[i] = 0.4*sin(2 * M_PI * f *time) + 0.8*sin(0.2*2 * M_PI * f *time); // composed signal
  }
  // frequency table
  for(int i = 0; i <= ((N/2)-1); i++){
    ff[i] = (Fs * i) / N;
  }
  // transform
  plan_forward = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
  fftw_execute(plan_forward);

  // compute and print the PSD
  double v[N];
  for(int i = 0; i <= ((N/2)-1); i++){
    v[i] = (out[i][0] * out[i][0] + out[i][1] * out[i][1]) / N;  
  }
  std::ofstream myfile("PSD.txt");
  for(int i = 0; i < ((N/2)-1); i++){ 
    myfile << ff[i] << " " << v[i] << std::endl;
  }
  myfile.close();

  fftw_destroy_plan(plan_forward);
  fftw_free(in);
  fftw_free(out);

  return 0;
}
