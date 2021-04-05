#include "../../lista.h"
#include <string>
#include <algorithm>
#include <iostream>

#ifndef _EO_STRINGS_
#define _EO_STRINGS_

class eo_strings{
  public:
    eo_strings();
    void inserisci(std::string s);
    void rimuovi(std::string s);
    void rimuovi(char c);
    int freq_pari();
    void visualizza_dispari();
    void stampa();
  private:
    Lista<std::string> pari;
    Lista<std::string> dispari;
};

eo_strings::eo_strings(){
}

void eo_strings::inserisci(std::string s){
  int count = s.size();
  if(count % 2 == 0){
    pari.insLista(s, pari.primoLista()->succ->prec);
  }else{
    dispari.insLista(s, dispari.primoLista()->succ->prec);
  }
}
void eo_strings::rimuovi(std::string s){
  int count = s.size();
  if(count % 2 == 0){
    pari.cancLista(pari.trovaLista(s));
  }else{
    dispari.cancLista(dispari.trovaLista(s));
  }
}
void eo_strings::rimuovi(char c){
  Lista<std::string>::posizione indice = pari.primoLista();
  Lista<std::string>::posizione next = indice;
	while (!pari.fineLista(indice)) {
		if (c == pari.leggiLista(indice)[0]) {
      next = pari.succLista(indice);
      pari.cancLista(indice);
      indice = next;
		}else{
      indice = pari.succLista(indice);
    }
	}
}
void eo_strings::stampa(){
  std::cout<<"pari: \n";
  pari.stampaLista();
  std::cout<<"dispari: \n";
  dispari.stampaLista();
}
#endif//_EO_STRINGS__
