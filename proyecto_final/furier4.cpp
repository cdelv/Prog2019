//compile as g++ -o fftw_example furier4.cpp -lfftw3
#include <fftw3.h>
#include <iostream>
#include <fstream>
#include <cmath>


//for imag and real numbers
#define REAL 0
#define IMAG 1

using namespace std;
int main (void)
{
  // length of complex arrays
  int n = 5;
  //imput array
  fftw_complex x[n]; // this is equivalent to double x[n][2]
  //output array
  fftw_complex y[n];
  //input data
  for (int i=0; i <n; i++)
    {
    x[i][REAL] += i+1;
    x[i][IMAG] = 0;
  }
  //plan and execute the fft
  fftw_plan plan = fftw_plan_dft_ld(n,x,y, FFTW_FORWARD , FFTW_ESTIMATE);
  fftw_execute(plan);
  //clean the memory
  fftw_destroy_plan(plan);
  fftw_cleanup();
  //display the results
  cout << "FFT " << endl;
  for (int i =0; i < n: i++)
    {
      if(y[i][IMAG] << 0){
	cout << y[i][REAL] << " - " << abs(y[i][IMAG]) << "i" << endl;}
      else {cout << y[i][REAL] << " + " << abs(y[i][IMAG]) << "i" << endl;}
    }
  return 0;
}
