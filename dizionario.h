#ifndef DIZIONARIO_H_
#define DIZIONARIO_H_

#include "lista.h"

template<class K,class V>
struct Element {
	K key;
	V value;

	//Overloading dell'operatore = per confrontare due tipi Element
	bool operator==(const Element<K,V>& rhs) const {
		return key == rhs.key;
	}

};

//Overloading di << per stampare un Element
template<typename K,typename V>
std::ostream &operator<<(std::ostream &output, const Element<K,V> &e) {
	output << "{" << e.key << "," << e.value << "}";
	return output;
}

template<class K, class V>
class Dizionario {
public:
	Dizionario();
	~Dizionario();

	bool dizionarioVuoto() const;
	bool appartiene(K) const;

	void inserisci(K,V);
	void cancella(K);
	V leggi(K);

	void stampa();

private:
	Lista<Element<K,V>> *dizionario;
};

template <class K, class V> Dizionario<K,V>::Dizionario(){
	Dizionario::dizionario = new Lista<Element<K,V>>();
}

template <class K, class V> Dizionario<K,V>::~Dizionario(){
	Dizionario::dizionario->~Lista();
}

template <class K, class V> bool Dizionario<K,V>::dizionarioVuoto() const{
	return Dizionario::dizionario->listaVuota();
}

template <class K, class V> bool Dizionario<K,V>::appartiene(K k) const{
	Element<K,V> E;
	E.key=k;
	return Dizionario::dizionario->esisteLista(E);
}

template <class K, class V> void Dizionario<K,V>::inserisci(K k,V v){
	Element<K,V> E;
	E.key=k;
	E.value=v;
	typename Lista<Element<K,V>>::posizione indice;
	indice=Dizionario::dizionario->ultimoLista();
	Dizionario::dizionario->insLista(E, indice);
}

template <class K, class V> void Dizionario<K,V>::cancella(K k){
	Element<K,V> E;
	E.key=k;
	Dizionario::dizionario->cancLista(Dizionario::dizionario->trovaLista(E));
}

template <class K, class V> V Dizionario<K,V>::leggi(K k){
	Element<K,V> E;
	E.key=k;
	return Dizionario::dizionario->leggiLista(Dizionario::dizionario->trovaLista(E));
}

template <class K, class V> void Dizionario<K,V>::stampa(){
	Dizionario::dizionario->stampaLista();
}


#endif /* DIZIONARIO_H_ */
