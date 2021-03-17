#ifndef _STUDENTE_
#define _STUDENTE_

#include <string>
#include <iostream>

//=================================================
// DEFINIZIONE
//=================================================

class Studente {
  public: 

    /*Costruttori*/
    Studente(void);

    /*Osservatori*/
    int getMatricola();
    std::string getNome();
    std::string getCognome();
    int getEta();

    /*Modificatori*/
    bool setMatricola(int matricola);
    bool setNome(std::string nome);
    bool setCognome(std::string cognome);
    bool setEta(int eta);

    /*Di Servizio*/
    void stampaStudente();

  private:
    int matricola;
    std::string nome;
    std::string cognome;
    int eta;
};

//=================================================
// IMPLEMENTAZIONE
//=================================================

Studente::Studente(void){
  matricola = 0;
  nome = "-";
  cognome = "-";
  eta = 0;
}

bool Studente::setMatricola(int _matricola){
  if (_matricola >= 255312 && _matricola <= 499999){
    matricola = _matricola;
    return true;
  }else{
    std::cout<<"[ERROR]\tnumero di matricola "<<_matricola<<" non ammesso."<<std::endl;
    std::cout<<"[INFO]\tinserire un numero di matricola compreso tra 255312 e 499999."<<std::endl;
  }
  return false;
}

bool Studente::setNome(std::string _nome){
  if (_nome.length() <= 30){
    nome = _nome;
    return true;
  }else{
    std::cout<<"[ERROR]\tnome troppo lungo."<<std::endl;
    std::cout<<"[INFO]\tinserire un nome non più lungo di 30 caratteri."<<std::endl;
  }
  return false;
}

bool Studente::setCognome(std::string _cognome){
  if (_cognome.length() <= 30){
    cognome = _cognome;
    return true;
  }else{
    std::cout<<"[ERROR]\tcognome troppo lungo."<<std::endl;
    std::cout<<"[INFO]\tinserire un cognome non più lungo di 30 caratteri."<<std::endl;
  }
  return false;
}

bool Studente::setEta(int _eta){
  if (_eta >= 12 && _eta <= 105){
    eta = _eta;
    return true;
  }else{
    std::cout<<"[ERROR]\teta non ammessa."<<std::endl;
    std::cout<<"[INFO]\tinserire un'eta compresa tra 12 e 105"<<std::endl;
  }
  return false;
}

int Studente::getMatricola(){
  return matricola;
}

std::string Studente::getNome(){
  return nome;
}

std::string Studente::getCognome(){
  return cognome;
}

int Studente::getEta(){
  return eta;
}

void Studente::stampaStudente(){
  std::cout<<"matricola:\t"<<this->getMatricola()<<'\n';
  std::cout<<"nome:\t\t"<<this->getNome()<<'\n';
  std::cout<<"cognome:\t"<<this->getCognome()<<'\n';
  std::cout<<"eta:\t\t"<<this->getEta()<<'\n';
}

#endif //_STUDENTE_
