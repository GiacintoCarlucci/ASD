#include "eo_strings.h"
#include <iostream>
#include <string>

int main(void){
  eo_strings a;
  a.inserisci("ciao");
  a.inserisci("questa");
  a.inserisci("è");
  a.inserisci("una");
  a.inserisci("prova");
  a.stampa();
  a.rimuovi("prova");
  a.stampa();
  a.rimuovi('q');
  a.stampa();

  return 0;
}
