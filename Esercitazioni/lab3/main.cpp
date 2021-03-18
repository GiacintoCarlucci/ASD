#include "matrice.h"

int main(void){
  std::cout<<"Creazione Matrice..."<<std::endl;
  Matrice m1(3,3);
  std::cout<<"Stampa Matrice..."<<std::endl;
  m1.stampaMatrice();
  std::cout<<"Riempimento Matrice..."<<std::endl;
  m1.riempiMatrice();
  std::cout<<"Stampa Matrice..."<<std::endl;
  m1.stampaMatrice();
  std::cout<<"Prodotto scalare per 2.5 ..."<<std::endl;
  m1.prodottoScalare(2.5);
  std::cout<<"Stampa Matrice..."<<std::endl;
  m1.stampaMatrice();
  std::cout<<"Scrittura Matrice..."<<std::endl;
  m1.scriviMatrice(0,1,1);
  m1.scriviMatrice(1,1,1);
  m1.scriviMatrice(2,1,1);
  std::cout<<"Stampa Matrice..."<<std::endl;
  m1.stampaMatrice();
  std::cout<<"Trasposta Matrice..."<<std::endl;
  m1 = m1.trasposta();
  std::cout<<"Stampa Matrice..."<<std::endl;
  m1.stampaMatrice();
  std::cout<<"Creazione Matrici A e B..."<<std::endl;
  Matrice A(2,3);
  Matrice B(3,2);

  A.scriviMatrice(0,0,1);
  A.scriviMatrice(0,1,0);
  A.scriviMatrice(0,2,2);
  A.scriviMatrice(1,0,0);
  A.scriviMatrice(1,1,3);
  A.scriviMatrice(1,2,-1);

  B.scriviMatrice(0,0,4);
  B.scriviMatrice(0,1,1);
  B.scriviMatrice(1,0,-2);
  B.scriviMatrice(1,1,2);
  B.scriviMatrice(2,0,0);
  B.scriviMatrice(2,1,3);

  std::cout<<"Stampa Matrice A..."<<std::endl;
  A.stampaMatrice();
  std::cout<<"Stampa Matrice B..."<<std::endl;
  B.stampaMatrice();
  
  std::cout<<"prodotto delle matrici A e B:"<<std::endl;

  Matrice AB(0,0);

  AB = A.prodotto(B);
  AB.stampaMatrice();
  



  return 0;
}
