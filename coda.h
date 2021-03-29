#include <iostream>
#ifndef _CODA_H_
#define _CODA_H_

template<class T>
struct NodoC {
	T elemento;
	NodoC<T> *succ;
};

template<typename T>
class Coda {
public:
	/* Definizioni*/
	typedef NodoC<T> * posizione;

	/* Costruttori*/
	// Default
	Coda();

	// Copia
	Coda(const Coda& origine);

	// Distruttore
	~Coda();

	/* Osservatori*/
	bool codaVuota() const;
	T leggiCoda() const;

	/* Modificatori*/
	void fuoriCoda();
	void inCoda(T elemento);

	/* Di Servizio*/
	void stampaCoda();

private:
	posizione testa;
	posizione fondo;
};

//=================================================
// IMPLEMENTAZIONE
//=================================================

/* Costruttori*/

// Default
template<typename T> Coda<T>::Coda() {
	T ElementoNullo;
	testa = new NodoC<T>;
	fondo = new NodoC<T>;
	testa->elemento = ElementoNullo;
	testa = nullptr;
	fondo = nullptr;
}

// Copia
template<typename T> Coda<T>::Coda(const Coda<T> &origine){
  testa= nullptr;
  fondo = nullptr;
  NodoC<T> *tempNode = origine.testa; 
  while(tempNode !=  nullptr){
    this->inCoda(tempNode->elemento);
    tempNode = tempNode->succ;
  }
}

// Distruttore
template<typename T> Coda<T>::~Coda() {
	while (testa != nullptr) {
		this->fuoriCoda();
	}
	delete testa;
}

/* Osservatori*/
template<typename T> bool Coda<T>::codaVuota() const {
  if(testa == nullptr){
    return true;
  }
	return false;
}

template<typename T> T Coda<T>::leggiCoda() const {
	if (testa != nullptr) {
		return testa->elemento;
	} else {
		std::cout << "vuota ";
		T obj = T(); // creo un oggetto di tipo T inizializzato con valore di Default
		return obj; //stampo il valore di default in caso di coda vuota
	}
}

/* Modificatori*/
template<typename T> void Coda<T>::fuoriCoda() {
	if (testa != nullptr) {
		Coda::posizione tmp;
		tmp = new NodoC<T>;
		tmp = testa;
		testa = testa->succ;
		delete (tmp);
	} else {
    std::cout<<"fuorivuota\n";
		return;
	}
}
template<typename T> void Coda<T>::inCoda(T elemento) {
	Coda::posizione nodo;
	nodo = new NodoC<T>;
	nodo->elemento = elemento;
	nodo->succ = nullptr;
	bool vuota = this->codaVuota();
	if (vuota) {
		testa = nodo;
		fondo = nodo;
	} else {
		Coda::posizione back;
		back = new NodoC<T>;
		back = fondo; //back prende l'indirizzo di fondo
		back->succ = nodo;
		fondo = nodo;
	}

}

template <typename T> void Coda<T>::stampaCoda(){
  NodoC<T> *tempNode = testa; 
	std::cout<<"[";
	while(tempNode != nullptr){
		std::cout<<tempNode->elemento;
    tempNode = tempNode->succ;
    if (tempNode != nullptr){
      std::cout << ", ";
    }
	}
	std::cout<<"]"<<std::endl;
}

#endif // _CODA_H_
