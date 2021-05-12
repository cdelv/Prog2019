#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int cuenta (void);

int const N = cuenta ();

struct alumno{
  std::string name;
  std::string ID;
  double edad;
  double notas [1]{0};
};

int main (void)
{
  
  std::ifstream theFile;
  theFile.open("alumnos.txt");



  for (int i= 0; i<N; i++){
    while (theFile >> name >> ID  >> edad){
      std::cout << name << "\t" << ID << "\t" << edad << "\n" << notas[i] << std::endl;	       
    }
  }
  return 0;
}


int cuenta (void)
{
   std::ifstream theFile;
  theFile.open("alumnos.txt");
  
  std::string item;
  int count = 0;
  int N = 1;

  while (!theFile.eof()){
   theFile >> item;
   count++;
   }
 
  N = count - 3;
  return N;
}
