#ifndef INSIEME_H_
#define INSIEME_H_

#include "lista.h"

template<class T>
class Insieme {
public:

	Insieme();
	~Insieme();
	bool insiemeVuoto() const;
	bool appartiene(T) const;

	void inserisci(T);
	void cancella(T);
	void unione(const Insieme<T>&);
	void intersezione(const Insieme<T>&);
	void differenza(const Insieme<T>&);

	void stampaInsieme();

private:
	Lista<T> *insieme;
};

template<class T> Insieme<T>::Insieme() {
	this->insieme = new Lista<T>();
}

template<class T> Insieme<T>::~Insieme() {
	this->insieme->~Lista();
}

template<class T> bool Insieme<T>::insiemeVuoto() const {
	return this->insieme->listaVuota();
}

template<class T> bool Insieme<T>::appartiene(T elem) const {
	return this->insieme->esisteLista(elem);
}

template<class T> void Insieme<T>::inserisci(T elem) {
	typename Lista<T>::posizione indice;
	indice = this->insieme->ultimoLista()->succ;
	this->insieme->insLista(elem, indice);
}

template<class T> void Insieme<T>::cancella(T elem) {
	this->insieme->cancLista(this->insieme->trovaLista(elem));
}

template<class T> void Insieme<T>::unione(const Insieme<T> &i) {
	typename Lista<T>::posizione indice;
	for (indice = i.insieme->primoLista(); !i.insieme->fineLista(indice);
			indice = i.insieme->succLista(indice)) {
		if (!this->appartiene(i.insieme->leggiLista(indice))) {
			this->inserisci(i.insieme->leggiLista(indice));
		}
	}
}

template<class T> void Insieme<T>::intersezione(const Insieme<T> &i) {
	typename Lista<T>::posizione indice;
	for (indice = this->insieme->primoLista(); !this->insieme->fineLista(indice);
			indice = this->insieme->succLista(indice)) {
		if (!i.appartiene(this->insieme->leggiLista(indice))) {
			this->cancella(this->insieme->leggiLista(indice));
		}
	}
}

template<class T> void Insieme<T>::differenza(const Insieme<T> &i) {
	typename Lista<T>::posizione indice;
	for (indice = i.insieme->primoLista(); !i.insieme->fineLista(indice);
			indice = i.insieme->succLista(indice)) {
		if (this->appartiene(i.insieme->leggiLista(indice))) {
			this->cancella(i.insieme->leggiLista(indice));
		}
	}
}

template<class T> void Insieme<T>::stampaInsieme() {
	this->insieme->stampaLista();
}

#endif /* INSIEME_H_ */
