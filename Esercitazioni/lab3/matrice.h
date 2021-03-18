#ifndef _MATRICE_
#define _MATRICE_

#include <string>
#include <iostream>
#include <stdlib.h>

//=================================================
// DEFINIZIONE
//=================================================

typedef double tipoelem;

class Matrice {
  public:
    /*Costruttori*/
    Matrice(int r, int c);
    Matrice(const Matrice &m);

    /*Distruttori*/
    ~Matrice();

    /*Overloads*/
    Matrice & operator=(const Matrice &m);

    /*Osservatori*/
    tipoelem leggiMatrice(int r, int c);

    /*Modificatori*/
    bool scriviMatrice(int r, int c, tipoelem e);
    bool riempiMatrice(void);
    bool prodottoScalare(tipoelem e);
    Matrice trasposta(void);
    Matrice prodotto(Matrice &m);

    /*Di Servizio*/
    void stampaMatrice(void);

  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

//=================================================
// IMPLEMENTAZIONE
//=================================================

Matrice::Matrice(int r, int c){
  righe = r;
  colonne = c;
  //allocazione memoria
  int i;
  elementi = new tipoelem* [righe];
  for(i=0; i<righe; i++){
    elementi[i] = new tipoelem[colonne];
  }
  //inizializzazione
  int k;
  for(i=0; i<righe; i++){
    for(k=0; k<colonne; k++){
      elementi[i][k] = 0; 
    }
  }
}

Matrice::Matrice(const Matrice &m){
  righe = m.righe;
  colonne = m.colonne;
  int i,j;
  elementi = new tipoelem * [righe];

  for(i=0; i<righe; i++){
    elementi[i] = new tipoelem[colonne];
  }

  for(i=0; i<righe; i++){
    for(j=0; j<colonne; j++){
      elementi[i][j] = m.elementi[i][j];
    }
  }

}

Matrice::~Matrice(){
  for(int i = 0; i<colonne; i++){
    delete[] elementi[i];
  }
  delete[] elementi;
}

Matrice & Matrice::operator=(const Matrice &m){
  //evito autoassegnamenti
  if(this == &m){
    return *this;
  }else{
    int i,k;
    if(colonne != m.colonne || righe != m.righe){
      this->~Matrice();
      colonne = m.colonne;
      righe = m.righe;
      elementi = new tipoelem* [righe];
      for(i=0; i<righe; i++){
        elementi[i] = new tipoelem[colonne];
      }
    }
    for(i=0; i<righe; i++){
      for(k=0; k<colonne; k++){
        elementi[i][k] = m.elementi[i][k];
      }
    }
    return *this;
  }
}

tipoelem Matrice::leggiMatrice(int r, int c){
  return elementi[r][c];
}

bool Matrice::scriviMatrice(int r, int c, tipoelem e){
  elementi[r][c] = e;
  return true;
}

bool Matrice::riempiMatrice(void){
  int i;
  for(i=0; i<righe; i++){
    int k;
    for(k=0; k<colonne; k++){
      elementi[i][k] = rand() % 100;
    }
  }
  return true;
}

bool Matrice::prodottoScalare(tipoelem e){
  int i;
  for(i=0; i<righe; i++){
    int k;
    for(k=0; k<colonne; k++){
      elementi[i][k] *= e;
    }
  }
  return true;
}

Matrice Matrice::trasposta(void){
  Matrice trasposta(righe,colonne);
  int i;
  for(i=0; i<righe; i++){
    int k;
    for(k=0; k<colonne; k++){
     trasposta.scriviMatrice(i,k,elementi[k][i]);
    }
  }
  return trasposta;
}

Matrice Matrice::prodotto(Matrice &m){
  if(colonne == m.righe){
    //il prodotto tra due matrici  A e B produce una matrice con:
    //il numero di righe di A
    //il numero di colonne di B
    Matrice prodotto(righe,m.colonne);
    int i;
    for(i=0; i<righe; i++){
      int j;
      for(j=0; j<m.colonne; j++){
        int k;
        for(k=0; k<colonne; k++){
          prodotto.scriviMatrice(i,j, prodotto.leggiMatrice(i,j) + elementi[i][k] * m.leggiMatrice(k,j));
        }
      }
    }
    return prodotto;
  }else{
    std::cout<<"[ERR]\tprodotto non eseguibile."<<std::endl;
    std::cout<<"[INFO]\t#colonne della matrice A deve essere uguale a #righe matrice B."<<std::endl;
    return *this;
  }
}

void Matrice::stampaMatrice(void){
  int i;
  for(i=0; i<righe; i++){
    int k;
    for(k=0; k<colonne; k++){
      std::cout<<'\t'<<elementi[i][k];
    }
    std::cout<<std::endl;
  }

}

#endif //_MATRICE_
