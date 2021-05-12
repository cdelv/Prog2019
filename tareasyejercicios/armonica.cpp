
// programa que imprime la suma armónica en una tabla y hace un pdf con la gráfica de los valores conseguidos.
#include <iostream>
#include <cmath>

using namespace std;

int main (void)
  double tabulador ( int terminos, double x)
{
 
  double sumatoria;
    for ( int i = 1; i <= terminos ; i++) {
      sumatoria += 1/i;
    }
  cout << "suma = " << sumatoria << endl;
  cout << endl;
  
  return 0;
}

double tabulador ( int terminos, double x)
{
  double sumatoria;
  for (int k = 1; k <= 1000 ; k++ ){
    sumatoria += 1/k;			     
}
 return sumatoria;
}
