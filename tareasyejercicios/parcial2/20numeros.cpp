#include <iostream>
#include <cmath>
#include <vector>



int main (void)
{
  int N = 20;
  int numeros[N];
  std::cout << "Escribe 20 números del 10 al 100. Escríbelos dándole a la tecla enter cada vez que colocas un número." <<std::endl;
  for (int i=0; i < N; i++){
    std::cin >> numeros[i];
    if (numeros[i]>100 or numeros[i]<10){
      while (1){
      std::cout << "Recuerda, un número de 10 a 100." << std::endl;
      std::cin >> numeros[i];
      if ( numeros[i] >= 10 and numeros[i] <= 100){ break;}
      }
    }
  }
  std::cout << "Lista de los numeros no repetidos." << std::endl;
  int count = 0;
  
  for (int j=0; j<N; j++){
    int a=0;
    for (int k=0; k<N; k++){
      if (numeros[j] == numeros[k]){
	break;}
      else {a=2; count +=1;}
    }
    if (a == 2){std::cout << numeros[j] << std::endl;}
  }

 
  return 0;
}
