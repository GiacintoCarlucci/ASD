/*
 *
  Si scriva una procedura ricorsiva che data una lista L di interi, la modifichi
  eliminando ogni elemento pari e replicando ogni elemento dispari tante volte
  quanti sono gli elementi pari che lo precedono.
  (es: se L = 4,6,7,3,2,5, allora si ha L = 7,7,7,3,3,3,5,5,5,5).
 *
 * */
#include "../lista.h"

int main(void){

  Lista<int> lista;
  Lista<int>::posizione indice = lista.primoLista();
  lista.insLista(4,indice=lista.succLista(indice));
  lista.insLista(6,indice=lista.succLista(indice));
  lista.insLista(7,indice=lista.succLista(indice));
  lista.insLista(3,indice=lista.succLista(indice));
  lista.insLista(2,indice=lista.succLista(indice));
  lista.insLista(5,indice=lista.succLista(indice));
  lista.stampaLista();

  lista.pariDispari(lista.primoLista(),0,0);
  lista.stampaLista();

  std::cout<<std::endl;

  Lista<int> listaB;
  Lista<int>::posizione indiceB = listaB.primoLista();
  listaB.insLista(2,indiceB=listaB.succLista(indiceB));
  listaB.insLista(0,indiceB=listaB.succLista(indiceB));
  listaB.insLista(3,indiceB=listaB.succLista(indiceB));
  listaB.insLista(3,indiceB=listaB.succLista(indiceB));
  listaB.insLista(7,indiceB=listaB.succLista(indiceB));
  listaB.insLista(2,indiceB=listaB.succLista(indiceB));
  listaB.stampaLista();

  listaB.pariDispari(listaB.primoLista(),0,0);
  listaB.stampaLista();
  
  std::cout<<std::endl;

  Lista<int> listaC;
  Lista<int>::posizione indiceC = listaC.primoLista();
  listaC.insLista(9,indiceC=listaC.succLista(indiceC));
  listaC.insLista(0,indiceC=listaC.succLista(indiceC));
  listaC.insLista(3,indiceC=listaC.succLista(indiceC));
  listaC.insLista(2,indiceC=listaC.succLista(indiceC));
  listaC.insLista(7,indiceC=listaC.succLista(indiceC));
  listaC.insLista(0,indiceC=listaC.succLista(indiceC));
  listaC.stampaLista();

  listaC.pariDispari(listaC.primoLista(),0,0);
  listaC.stampaLista();
return 0;
}
