#ifndef ALBERO_H_
#define ALBERO_H_

//=================================================
// DEFINIZIONE
//=================================================

template<class T>
struct NodoAN {
	T elemento;
	int livello;
	NodoAN<T> * padre;
	NodoAN<T> * primoFiglio;
	NodoAN<T> * fratello;

	~NodoAN() {
		//scrivere il distruttore, così termina inaspettatamente
		/*delete primoFiglio;
		 delete fratello;
		 delete padre;*/
	}
};

template<class T>
class Albero {
public:

	//Costruttori
	Albero();
	~Albero();

	//Osservatori
	bool alberoVuoto() const;
	bool foglia(NodoAN<T>) const;
	bool ultimoFratello(NodoAN<T>) const;
	NodoAN<T>* radice() const;
	NodoAN<T>* padre(NodoAN<T>) const;
	NodoAN<T>* primoFiglio(NodoAN<T>) const;
	NodoAN<T>* succFratello(NodoAN<T>) const;

	//Modficatori
	void insRadice(NodoAN<T>);
	void insSottoAlberoFiglio(NodoAN<T>, Albero);
	void insSottoAlberoFratello(NodoAN<T>, Albero);
	void cancSottoAlbero(NodoAN<T>);

private:
	NodoAN<T> * albero;
};

template<class T> Albero<T>::Albero() {
	albero = new NodoAN<T>();
	albero->elemento = T();
	albero->livello = 0;
	albero->fratello = albero;
	albero->padre = albero;
	albero->primoFiglio = albero;
}

template<class T> Albero<T>::~Albero() {
	//man mano che scorro l'albero cancello i nodi, ma dovrei partire dal basso per non perdere i riferimenti?
	//ho un distruttore in NodoAN che dovrebbe cancellare ricorsivamente tutto l'albero
	//delete albero;
}

template<class T> bool Albero<T>::alberoVuoto() const {
	return ((albero->fratello == albero) && (albero->primoFiglio == albero)
			&& (albero->padre == albero) && (albero->livello == 0));
}

template<class T> bool Albero<T>::foglia(NodoAN<T> u) const {
	//pre: albero non vuoto, u esiste nell'albero
	//post: true se esiste un padre di u, non esiste figlio di u, livello di u = livello padre +1

	if (!this->alberoVuoto()) {
		//if (esiste il nodo)
		if (u.padre != nullptr) {
			if (u.primoFiglio == nullptr) {
				//se l'albero che stiamo analizzando è composto dalla sola radice (u non  ha padre):
				if (u.padre == this->radice()) {
					if (u.livello == 0 && u.padre->livello == 0) {
						return true;
					}
				//se il nodo u ha un padre:
				} else if (u.livello == u.padre->livello + 1) {
					return true;
				}
			}
		}
	}
	return false;
}

template<class T> bool Albero<T>::ultimoFratello(NodoAN<T> u) const {
	//pre: albero non vuoto, u esiste nell'albero
	//post: vero se non esistono altri fratelli che lo seguono nella relazione d'ordine
	//      falso altrimenti

	if (!this->alberoVuoto()) {
		NodoAN<T> *temp; // = trovaNodo(u);
		//if temp non vuoto (esiste u)
		return u.fratello == nullptr;
	}

	return false;
}

template<class T> NodoAN<T>* Albero<T>::radice() const {
	//pre: albero non vuoto
	//post: ritorna u radice dell'albero, livello di u = 0

	if (!this->alberoVuoto()) {
		return Albero<T>::albero->primoFiglio;
	}
	return nullptr;
}

template<class T> NodoAN<T>* Albero<T>::padre(NodoAN<T> u) const {
	//pre: albero non vuoto, u appartiene all'albero, livello di u > 0
	//post: v è padre di u, arco (v,u) appartiene all'albero, livello di u = livello di v + 1

	if (!this->alberoVuoto()) {
		//if u appartiene all'albero
		if (u.livello > 0) {
			if (&u == u.padre->primoFiglio) {
				if (u.livello == u.padre->livello + 1) {
					return u.padre;
				}
			}
		}
	}
	return nullptr;
}

template<class T> NodoAN<T>* Albero<T>::primoFiglio(NodoAN<T> u) const {
	//pre: albero non vuoto, foglia(u)=falso
	//post: arco (u,v) appartiene all'albero, livello di v = livello di u + 1,
	//      v è primo secondo la relazione d'ordine stabilita tra i figli di u
	if (!this->alberoVuoto()) {
		if (!this->foglia(u)) {
			if (&u == u.primoFiglio->padre) {
				if (u.livello == u.primoFiglio->livello - 1) {
					return u.primoFiglio;
				}
			}
		}
	}
	return nullptr;
}

template<class T> NodoAN<T>* Albero<T>::succFratello(NodoAN<T> u) const {
	//pre: albero non vuoto, ultimoFratello()=falso
	//post: u e v(fratello) hanno lo stesso padre, livello di u = livello di v
	//      v è il fratello che segue u nella relazione d'ordine

	if (!this->alberoVuoto()) {

	}

}

template<class T> void Albero<T>::insRadice(NodoAN<T> u) {
	if (this->alberoVuoto()) {
		albero->primoFiglio = new NodoAN<T>();
		albero->primoFiglio->elemento = u.elemento;
		albero->primoFiglio->padre = albero;
		albero->primoFiglio->primoFiglio = nullptr;
		albero->primoFiglio->fratello = nullptr;
		albero->primoFiglio->livello = 0;
	}
}

#endif /* ALBERO_H_ */
