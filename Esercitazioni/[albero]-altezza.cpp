/*
 *
  L'altezza di un albero ordinato è il massimo livello delle sue foglie.
  Si fornisca una funzione che calcoli in tempo ottimo l'altezza di un albero
  ordinato T di n nodi.
 *
 */

#include "../albero.h"

int main (void){

	//creo il seguente albero:
	//        9
	//    10  12  13
	//  20 30
  // 80

	Albero<int> alberoB;
	alberoB.insRadice(9);
	alberoB.insFiglio(alberoB.radice(),13);
	alberoB.insFiglio(alberoB.radice(),12);
	alberoB.insFiglio(alberoB.radice(),10);
	alberoB.insFiglio(alberoB.radice()->primoFiglio,30);
	alberoB.insFiglio(alberoB.radice()->primoFiglio,20);
	alberoB.insFiglio(alberoB.radice()->primoFiglio->primoFiglio,80);

	//stampa
  alberoB.stampaAlbero(alberoB.radice());
  std::cout<<std::endl;
  
  std::cout<<"altezza albero: "<<alberoB.altezza(alberoB.radice())<<std::endl;

  return 0;
}
