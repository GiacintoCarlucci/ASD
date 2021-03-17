#include "studente.h"

int main (void){
  std::cout<<"Creazione studente valido..."<<std::endl;

  Studente s1;

  s1.setMatricola(349318);
  s1.setNome("Giacinto");
  s1.setCognome("Carlucci");
  s1.setEta(24);

  std::cout<<"Stampa studente creato..."<<std::endl;
  s1.stampaStudente();
  
  std::cout<<"Creazione studente non valido..."<<std::endl;

  Studente s2;

  s2.setMatricola(123456);
  s2.setNome("Pablo Jose Maria Antonluca Piergiorgio");
  s2.setCognome("Picasso");
  s2.setEta(200);

  std::cout<<"Stampa studente creato..."<<std::endl;
  s2.stampaStudente();
  return 0;
}
