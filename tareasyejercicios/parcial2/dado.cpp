#include <iostream>
#include <cstdlib>
#include <ctime>

int main (void)
{
  int dado1[6]{1,2,3,4,5,6};
  int dado2[6]{1,2,3,4,5,6};
  int resultados [6][6]{{0}};
  int suma [2][11]{{0}};
  srand(time(0));

  for(int i=0; i<11; i++){
    suma[0][i] = i + 2;
      }

  for (int i=0; i<= 36000; i++){
    int j = rand()%6;
    int k = rand()%6;
    suma[1][dado1[j] + dado2[k] - 2] += 1;
    resultados [j][k] += 1;

  }
  std::cout << "tabla de resultados"<< "\n" << std::endl;
      for (int ii = 0; ii < 6; ++ii){
    for (int jj = 0; jj < 6; ++jj){
      std::cout << resultados[ii][jj] << "\t";
    }
    std::cout << "\n";
    }
      std::cout <<"\n" << "numero de valores obtenidos"<< "\n" << std::endl;
      for (int ii = 0; ii < 2; ++ii){
    for (int jj = 0; jj < 11; ++jj){
      std::cout << suma[ii][jj] << "\t";
    }
    std::cout << "\n";
    }
	    
  return 0;
}

 
