//ESTE PROGRAMA APROXIMA LOS RESULTADOS DEL OSCILADOR ARMÓNICO POR MÉTODO DE EULER Y RUNGE-KUTTA DE CUARTO ORDEN.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <fstream>

const double W =  M_PI;
double x_sol(double tb, double x0);
void euler (double ta, double tb, double h, std::vector<double> &y);
double f(double t, const std::vector<double> &y, int id);
void rk4 (double ta, double tb, double h, std::vector<double> & y);
std::ofstream fout ("1.txt");

int main (void)
{

 fout.precision(16); fout.setf(std::ios::scientific);
				 
const double X0 = 3.21; 
const double V0 = 0.0;
const double TA = 0;
const double TB = 3*2*M_PI/W;
 
  double H = 0.0;
  std::vector<double> y = {X0, V0}; //x0, y0
  for (int ii = 0; ii <= 14; ii++){
  	H = std::pow(0.5, ii);
  	fout << H << "\t";
    euler(TA, TB, H, y);
 fout << std::fabs(y[0]-x_sol(TB, X0))/x_sol(TB, X0) << "\t";
  
  y = {X0, V0};
  
  rk4(TA, TB, H, y);
 fout << std::fabs(y[0]-x_sol(TB, X0))/x_sol(TB, X0) << "\n";
 
   y = {X0, V0};
  }

 fout.close();
  
  return 0;
}

//////////////////////////////////////////////////////////////

double x_sol(double tb, double x0)
{
  return x0*std::cos(M_PI*tb);
}


void euler (double ta, double tb, double h, std::vector<double> &y)
{
  const int N = (tb-ta)/h;
  std::vector<double> yaux(y.size());
  for (int nt = 0; nt < N; ++nt){
    double t = ta + h*nt;
    std::copy(y.begin(), y.end(), yaux.begin());
    for(int id = 0; id < y.size(); id++){
      y[id] = y[id] + h*f(t, yaux, id);//euler
    }
  }
}

void rk4 (double ta, double tb, double h, std::vector<double> & y)
{
  std::vector<double>  k1, k2, k3, k4, aux;
  k1.resize(y.size());
  k2.resize(y.size());
  k3.resize(y.size());
  k4.resize(y.size());
  aux.resize(y.size());

  const int N = (tb-ta)/h;
  for (int nt = 0; nt < N; ++nt){
    double t = ta + h*nt;
    for (int ii = 0; ii < y.size(); ++ii){
      k1[ii] = h*f(t, y, ii);
    }
    
    //k2 aux
    for (int ii = 0; ii < y.size(); ++ii){
      aux[ii] = y[ii] + k1[ii]/2;
    }
    
    //k2
    for (int ii = 0; ii < y.size(); ++ii){
      k2[ii] = h*f(t + h/2, aux, ii);
    }
    
    //k3 aux
    for (int ii = 0; ii < y.size(); ++ii){
      aux[ii] = y[ii] + k2[ii]/2;
    }
    
    //k3
    for (int ii = 0; ii < y.size(); ++ii){
      k3[ii] = h*f(t + h/2, aux, ii);
    }
    
    //k4 aux
    for (int ii = 0; ii < y.size(); ++ii){
      aux[ii] = y[ii] + k3[ii];
    }
    
    //k4
    for (int ii = 0; ii < y.size(); ++ii){
      k4[ii] = h*f(t + h, aux, ii);
    }
    
    //write new y
    for (int ii = 0; ii < y.size(); ++ii){
      y[ii] = y[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
  }
}

double f(double t, const std::vector<double> &y, int id)
{
  if(0 == id){
    return y[1];
  }
  else if (1 == id){
    return -W*W*y[0];
  }
  else{
    std::cerr << "ERROR!!!!! it does not exist -> " << id << std::endl;
    exit(1);
  }
}
