// hello world pero con funciones
#include <iostream>


void palabra (void); //declarar la funcion para definirla después 
int main (void)
{
  palabra();
  return 0;
}

void palabra (void) //para que main no quede tan lejos, implementacion
{
  std::cout << "Hello world from a function! \n"; 
}
// cuidado con el punto y coma de la función.
