/* 
  Dato un albero ordinato i cui nodi contengono valori interi, se ne vogliono
  cancellare tutte le foglie per le quali il percorso radice-foglia ha somma
  complessiva dei valori uguale a k. Fornire una procedura di complessità
  ottima.
*/

#include "../albero.h"

int main(void){

  // costruisco il seguente albero:
  //
  //     3
  //   5 7 13
  // 20    40  50
  //            70
  //
  // k = 136
  // 3+13+50+70 = 136
  // dovrei rimuovere l'ultimo nodo = 70

  const int k = 136;
  Albero<int> albero;

	albero.insRadice(3);
	albero.insFiglio(albero.radice(),13);
	albero.insFiglio(albero.radice(),7);
	albero.insFiglio(albero.radice(),5);
	albero.insFiglio(albero.radice()->primoFiglio,20);
	albero.insFiglio(albero.radice()->primoFiglio->fratello->fratello,50);
	albero.insFiglio(albero.radice()->primoFiglio->fratello->fratello,40);
	albero.insFiglio(albero.radice()->primoFiglio->fratello->fratello->primoFiglio->fratello,70);

  albero.stampaAlbero(albero.radice());
  std::cout<<std::endl;

  albero.leafk(albero.radice(),k,0);

  albero.stampaAlbero(albero.radice());
  std::cout<<std::endl;

  return 0;
}
