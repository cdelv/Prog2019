#include <iostream>
using namespace std;
int main() {
  int divisor = 1, divisores = 0, num = 0;
  cout<<"Escribe un numero: ";
  cin>>num;
  do{
    if(num % divisor == 0){
      divisores++;
    }
    divisor++;
  }
  while(divisor <= num);
  if(divisores == 2){
    cout<<"n-> El numero "<<num<<" es primo \n.";
  }else{
    cout<<"n-> El numero "<<num<<" no es primo \n.";
  }
  return 0;
}
