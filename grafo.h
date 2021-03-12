#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "lista.h"
#include "coda.h"
#include <vector>
#include <algorithm>

//=================================================
// DEFINIZIONE
//=================================================

template<class T>
struct Vertex {
	T label = T();
	int mark = int();
	Lista<Vertex<T>> *adj = nullptr;

	//Overloading dell'operatore = per confrontare due tipi Vertex
	bool operator==(const Vertex<T>& rhs) const {
		return label == rhs.label;
	}

};

//Overloading di << per stampare un vertex
template<typename T>
std::ostream &operator<<(std::ostream &output, const Vertex<T> &v) {
	output << "{" << v.label << "," << v.mark << "}";
	return output;
}

template<class T>
class Grafo {
public:

	/* Costruttori*/
	// Default
	Grafo();

	// Copia
	Grafo(const Grafo&);

	// Distruttore
	~Grafo();

	/* Osservatori*/
	bool grafoVuoto() const;
	bool esisteNodo(Vertex<T>) const;
	bool esisteArco(Vertex<T>, Vertex<T>) const;
	Vertex<T> leggiNodo(Vertex<T>) const;
	Lista<Vertex<T>>* adiacenti(Vertex<T>) const;

	/* Modificatori*/
	void insNodo(Vertex<T>);
	void insArco(Vertex<T>, Vertex<T>);
	void cancNodo(Vertex<T>);
	void cancArco(Vertex<T>, Vertex<T>);
	void scriviNodo(T, Vertex<T>);

	/* Di Servizio*/
	void stampaGrafo();
	void BFS(Vertex<T>);
	void DFS(Vertex<T>,std::vector<Vertex<T>>);

private:
	Lista<Vertex<T>> *grafo;

};

//=================================================
// IMPLEMENTAZIONE
//=================================================

template<class T> Grafo<T>::Grafo() {
	Grafo::grafo = new Lista<Vertex<T>>();
}

template<class T> Grafo<T>::~Grafo() {
	Grafo::grafo->~Lista();
}

template<class T> bool Grafo<T>::grafoVuoto() const {
	return Grafo::grafo->listaVuota();
}

template<class T> bool Grafo<T>::esisteNodo(Vertex<T> u) const {
	return Grafo::grafo->esisteLista(u);
}

template<class T> bool Grafo<T>::esisteArco(Vertex<T> u, Vertex<T> v) const {
	if (this->esisteNodo(u) && this->esisteNodo(u)) {
		if (Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u)).adj->esisteLista(
				v)) {
			return true;
		}
	}
	return false;
}

template<class T> Vertex<T> Grafo<T>::leggiNodo(Vertex<T> u) const {
	if (this->esisteNodo(u)) {
		return Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u));
	}
	return Vertex<T>();
}

template<class T> Lista<Vertex<T>>* Grafo<T>::adiacenti(Vertex<T> u) const {
	if (this->esisteNodo(u)) {
		return Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u)).adj;
	}
	return new Lista<Vertex<T>>();
}

template<class T> void Grafo<T>::insNodo(Vertex<T> u) {
	if (!this->esisteNodo(u)) {
		typename Lista<Vertex<T>>::posizione indice =
				Grafo::grafo->ultimoLista()->succ;
		Grafo::grafo->insLista(u, indice);
	}
}

template<class T> void Grafo<T>::insArco(Vertex<T> u, Vertex<T> v) {

	//se i due nodi già esistono
	if (this->esisteNodo(u) && this->esisteNodo(v)) {
		typename Lista<Vertex<T>>::posizione indiceU = Grafo::grafo->trovaLista(
				u);
		//se adj è vuoto e stiamo inserendo il primo adiacente creo una nuova lista
		if (indiceU->elemento.adj == nullptr) {
			indiceU->elemento.adj = new Lista<Vertex<T>>();
		}
		typename Lista<Vertex<T>>::posizione indiceV =
				indiceU->elemento.adj->primoLista()->succ;
		indiceU->elemento.adj->insLista(v, indiceV);
	}
}

template<class T> void Grafo<T>::cancNodo(Vertex<T> u) {
	if (this->esisteNodo(u)) {
		typename Lista<Vertex<T>>::posizione indice = Grafo::grafo->trovaLista(
				u);
		Grafo::grafo->leggiLista(indice).adj->~Lista();
		Grafo::grafo->cancLista(indice);
	}
}

template<class T> void Grafo<T>::cancArco(Vertex<T> u, Vertex<T> v) {

	//se esiste u ad ha come adiacente v
	if (this->esisteNodo(u) && this->esisteArco(u, v)) {
		typename Lista<Vertex<T>>::posizione indiceU = Grafo::grafo->trovaLista(
				u);
		indiceU->elemento.adj->cancLista(indiceU->elemento.adj->trovaLista(v));

	}
}

// Stampa del grafo:
// {vertex} ----> [adiacenti]
template<class T> void Grafo<T>::stampaGrafo() {
	typename Lista<Vertex<T>>::posizione indice;
	Lista<Vertex<T>> adiacenti;
	for (indice = Grafo::grafo->primoLista();
			(!Grafo::grafo->fineLista(indice)); indice =
					Grafo::grafo->succLista(indice)) {
		std::cout << Grafo::grafo->leggiLista(indice) << " --adj--> ";
		if (Grafo::grafo->leggiLista(indice).adj != nullptr) {
			Grafo::grafo->leggiLista(indice).adj->stampaLista();
		} else {
			std::cout << std::endl;
		}
	}
}

template<class T> void Grafo<T>::BFS(Vertex<T> r) {
	typename Lista<Vertex<T>>::posizione indice;
	std::vector<Vertex<T>> visitati;

	//std::queue<Vertex<T>> Q;
	Coda<Vertex<T>> Q;
	//Q.push(Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(r)));
	Q.inCoda(Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(r)));
	visitati.push_back(r);
	while(!Q.codaVuota()){
		Vertex<T> u = Q.leggiCoda();
		std::cout<<u<<" ";
		for (indice = Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u)).adj->primoLista();
				!Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u)).adj->fineLista(indice);
				indice = Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(u)).adj->succLista(indice)){

			Vertex<T> v = u.adj->leggiLista(indice);
			if(!(std::find(visitati.begin(), visitati.end(),v) != visitati.end())){
				visitati.push_back(v);
				Q.inCoda(v);
			}
		}
		Q.fuoriCoda();
	}
}

template<class T> void Grafo<T>::DFS(Vertex<T> r,std::vector<Vertex<T>> visitati) {
	typename Lista<Vertex<T>>::posizione indice;
	visitati.push_back(r);
	std::cout<<r<<" ";
		for (indice = Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(r)).adj->primoLista();
			!Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(r)).adj->fineLista(indice);
			indice = Grafo::grafo->leggiLista(Grafo::grafo->trovaLista(r)).adj->succLista(indice)){

			Vertex<T> v = r.adj->leggiLista(indice);
			if(!(std::find(visitati.begin(), visitati.end(),v) != visitati.end())){
				this->DFS(v,visitati);
			}
		}
}

#endif //_GRAFO_H_
