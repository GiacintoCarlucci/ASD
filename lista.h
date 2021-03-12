#include <iostream>

#ifndef _LISTAP_H_
#define _LISTAP_H_

//=================================================
// DEFINIZIONE
//=================================================

template<class T>
struct Nodo {
	Nodo<T> *prec;
	Nodo<T> *succ;
	T elemento;
};

//classe Lista----------

template<class T>
class Lista {
public:

	/* Definizioni*/
	typedef T tipoelem;

	// posizione è un puntatore a Nodo
	typedef Nodo<T> * posizione;

	/* Costruttori*/
	// Default
	Lista(void);

	// Copia
	Lista(const Lista<T>&);

	// Distruttore
	~Lista();

	/* Osservatori*/
	bool listaVuota() const;
	Nodo<T>* ultimoLista() const;
	Nodo<T>* primoLista() const;
	posizione succLista(posizione) const;
	posizione precLista(posizione) const;
	bool fineLista(posizione) const;
	tipoelem leggiLista(posizione) const;
	bool esisteLista(tipoelem) const;
	posizione trovaLista(tipoelem) const;
	int contaLista() const;

	/* Modificatori*/
	void scriviLista(tipoelem, posizione);
	void insLista(tipoelem, posizione&);
	void cancLista(posizione);

	/* Di Servizio*/
	void stampaLista();
	void stampaNodo(posizione);

private:
	//la lista è un puntatore a Nodo
	posizione lista;
};

//=================================================
// IMPLEMENTAZIONE
//=================================================

template<class T> Lista<T>::Lista(void) {
	lista = new Nodo<T>;
	lista->succ = lista;
	lista->prec = lista;
}

template<class T> Lista<T>::Lista(const Lista<T> &copia){
  lista = new Nodo<T>;
  lista->succ = lista;
  lista->prec = lista;
  posizione p = copia.ultimoLista();
  posizione temp = this->primoLista();
  while(!copia.fineLista(p)){
    tipoelem elemento = copia.leggiLista(p);
    insLista(elemento,temp);
    p = copia.precLista(p);
  }
}

template<class T> Lista<T>::~Lista(void) {
	while (lista->succ != lista->prec) {
		cancLista(lista->succ);
	}
	delete lista;
}

template<class T> bool Lista<T>::listaVuota(void) const {
	return ((lista->succ == lista) && (lista->prec == lista));
}

template<class T> Nodo<T>* Lista<T>::primoLista() const {
	return lista->succ;
}

template<class T> Nodo<T>* Lista<T>::ultimoLista() const {
	return lista->prec;
}

template<class T> Nodo<T>* Lista<T>::succLista(Lista::posizione p) const {
	return p->succ;
}

template<class T> Nodo<T>* Lista<T>::precLista(Lista::posizione p) const {
	return p->prec;
}

template<class T> bool Lista<T>::fineLista(Lista::posizione p) const {
	return p == lista;
}

template<class T> T Lista<T>::leggiLista(Lista::posizione p) const {
	if (p != nullptr) {
		return p->elemento;
	}
	return T();
}

template<class T> bool Lista<T>::esisteLista(tipoelem t) const {
	if (this->trovaLista(t) != nullptr) {
		return true;
	} else {
		return false;
	}
}

template<class T> Nodo<T>* Lista<T>::trovaLista(tipoelem t) const {
	Lista::posizione indice = this->primoLista();
	while (!this->fineLista(indice)) {
		if (t == this->leggiLista(indice)) {
			return indice;
		}
		indice = this->succLista(indice);
	}
	return nullptr;
}

template<class T> int Lista<T>::contaLista() const {
	Lista::posizione indice = this->primoLista();
	int cont = 0;
	while (!this->fineLista(indice)) {
		cont++;
		indice = this->succLista(indice);
	}
	return cont;
}

template<class T> void Lista<T>::scriviLista(tipoelem a, Lista::posizione p) {
	if (p != lista) { //il primo nodo deve fungere solo da puntatore
		p->elemento = a;
	}
}

template<class T> void Lista<T>::insLista(tipoelem a, Lista::posizione &p) {
	Lista::posizione temp;
	temp = new Nodo<tipoelem>;
	temp->elemento = a;
	temp->prec = p->prec;
	temp->succ = p;
	p->prec->succ = temp;
	p->prec = temp;
	p = temp;
}

template<class T> void Lista<T>::cancLista(Lista::posizione p) {
	if (p != nullptr) {
		Lista::posizione temp;
		temp = p;
		p->succ->prec = p->prec;
		p->prec->succ = p->succ;
		p = p->succ;
		delete (temp);
	}
}

template<class T> void Lista<T>::stampaLista() {
	std::cout << "[";
	Lista::posizione indice;
	for (indice = this->primoLista(); (!this->fineLista(indice));
			indice = this->succLista(indice)) {
		std::cout << this->leggiLista(indice);
		if (!this->fineLista(this->succLista(indice))) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

template<class T> void Lista<T>::stampaNodo(Lista::posizione p) {

	std::cout << "<-- ";
	std::cout << p->prec->elemento << " | ";
	std::cout << p->elemento;
	std::cout << " | " << p->succ->elemento;
	std::cout << " -->\n";
}

#endif //_LISTAP_H_
