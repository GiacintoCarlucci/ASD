#include "../albero.h"

int main(void){

  //creo il seguente albero:
  //     1
  // 3   4   5
  //     6  7 8
  ///

  Albero<int> albero;
  albero.insRadice(1);
  albero.insFiglio(albero.radice(),5);
  albero.insFiglio(albero.radice()->primoFiglio,8);
  albero.insFiglio(albero.radice()->primoFiglio,7);
  albero.insFiglio(albero.radice(),4);
  albero.insFiglio(albero.radice()->primoFiglio,6);
  albero.insFiglio(albero.radice(),3);

  //creo il seguente albero:
  //       9
  //   10  12  13
  // 20 30
  ///
  Albero<int> alberoB;
  alberoB.insRadice(9);
  alberoB.insFiglio(alberoB.radice(),13);
  alberoB.insFiglio(alberoB.radice(),12);
  alberoB.insFiglio(alberoB.radice(),10);
  alberoB.insFiglio(alberoB.radice()->primoFiglio,30);
  alberoB.insFiglio(alberoB.radice()->primoFiglio,20);

  //ora provo a fondere i due alberi inserendo 'alberoB' come figlio
  //del nodo '3' di 'albero', avendo in output il seguente albero:
  //
  //                  1
  //         3        4         5
  //         9        6        7 8
  //     10  12  13
  //   20 30
  ///

  albero.insSottoAlberoFiglio(albero.radice()->primoFiglio,alberoB);

  //stampa
  std::cout<<"stampa di alberoB dopo l'inserimento in albero\n";
  albero.stampaAlbero(albero.radice());
  std::cout<<std::endl;


  albero.cancFiglio(albero.radice());
  albero.cancFratello(albero.radice());

  return 0;
}
