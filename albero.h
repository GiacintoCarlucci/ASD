#include <iostream>

#ifndef ALBERO_H_
#define ALBERO_H_

//=================================================
// DEFINIZIONE
//=================================================

template<class T>
struct NodoAN {
	T elemento = T();
	int livello = 0;
	NodoAN<T> * padre = nullptr;
	NodoAN<T> * primoFiglio = nullptr;
	NodoAN<T> * fratello = nullptr;

	~NodoAN() {
		if (primoFiglio)
			delete primoFiglio;
		primoFiglio = nullptr;
		if (fratello)
			delete fratello;
		fratello = nullptr;

	}

	NodoAN<T>& operator=(const NodoAN<T> &rhs) {
		elemento = rhs.elemento;
		livello = rhs.livello;
		padre = rhs.padre;
		primoFiglio = rhs.primoFiglio;
		fratello = rhs.fratello;
		return *this;
	}
};

//Overloading di << per stampare un nodo
template<typename T>
std::ostream &operator<<(std::ostream &output, const NodoAN<T> &n) {
	output << "{" << n.elemento << "," << n.livello << "}";
	return output;
}

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
  int altezza(NodoAN<T>*) const;

	//Modficatori
	void insRadice(T);
	void insFiglio(NodoAN<T>*, T);
	void insFratello(NodoAN<T>*, T);
	void insSottoAlberoFiglio(NodoAN<T>*, Albero);
	void insSottoAlberoFratello(NodoAN<T>*, Albero);
	void cancSottoAlbero(NodoAN<T>*);

	void stampaAlbero(NodoAN<T>*);
	void aggiornaLivelli(NodoAN<T>*);

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

template<class T> Albero<T>::~Albero() {//da rivedere
	/*this->cancSottoAlbero(this->albero);
	delete albero;
	albero=nullptr;*/
}

template<class T> bool Albero<T>::alberoVuoto() const {
	return ((albero->fratello == albero) && (albero->primoFiglio == albero)
			&& (albero->padre == albero) && (albero->livello == 0));
}

template<class T> bool Albero<T>::foglia(NodoAN<T> u) const {
	//pre: albero non vuoto, u esiste nell'albero
	//post: true se esiste un padre di u, non esiste figlio di u, livello di u = livello padre +1

	if (!this->alberoVuoto()) {
		//if (esiste u)
		if (u.padre != nullptr) {
			if (u.primoFiglio == nullptr) {
				//se l'albero che stiamo analizzando � composto dalla sola radice (u non  ha padre):
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
	//post: true se esiste il padre di u, non esistono altri fratelli di u, livello di u = livello padre +1
	//      false altrimenti

	if (!this->alberoVuoto()) {
		//if (esiste u)
		if (u.padre != nullptr) {
			if (u.fratello == nullptr) {
				//se l'albero che stiamo analizzando e' composto dalla sola radice (u non  ha padre):
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
	//post: v � padre di u, arco (v,u) appartiene all'albero, livello di u = livello di v + 1

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
	//      v � primo secondo la relazione d'ordine stabilita tra i figli di u
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
	//      v � il fratello che segue u nella relazione d'ordine

	if (!this->alberoVuoto()) {
		if (!this->ultimoFratello(u)) {
			if (u.padre == u.fratello->padre) {
				if (u.livello == u.fratello->livello) {
					return u.fratello;
				}
			}
		}
	}
	return nullptr;

}

template<class T> void Albero<T>::insRadice(T e) {
	if (this->alberoVuoto()) {
		albero->primoFiglio = new NodoAN<T>();
		albero->primoFiglio->elemento = e;
		albero->primoFiglio->padre = albero;
	}
}

template<class T> void Albero<T>::insFiglio(NodoAN<T> *u, T e) {
	if (!this->alberoVuoto() && u != nullptr) {
		if (u->primoFiglio == nullptr) {
			u->primoFiglio = new NodoAN<T>();
			u->primoFiglio->padre = u;
		} else {
			NodoAN<T> *frat = u->primoFiglio;
			u->primoFiglio = new NodoAN<T>();
			u->primoFiglio->padre = u;
			u->primoFiglio->fratello = frat;
		}
		u->primoFiglio->elemento = e;
		u->primoFiglio->livello = u->livello + 1;
	}
}

template<class T> void Albero<T>::insFratello(NodoAN<T> *u, T e) {

}

template<class T> void Albero<T>::insSottoAlberoFiglio(NodoAN<T> *u, Albero a) {//da testare*****
	//pre: alberi non vuoti, u appartiene all'albero
	//post: l'albero in output è ottenuto aggiungendo l'albero a
	//      la cui radice r e' il nuovo primofiglio di u

	if (!this->alberoVuoto() && !a.alberoVuoto()) {
		if (u->primoFiglio == nullptr) {
			u->primoFiglio = new NodoAN<T>();
			u->primoFiglio = a.albero->primoFiglio;
			u->primoFiglio->padre = u;
		} else {
			NodoAN<T> *frat = u->primoFiglio;
			u->primoFiglio = new NodoAN<T>();
			u->primoFiglio = a.albero->primoFiglio;
			u->primoFiglio->padre = u;
			u->primoFiglio->fratello = frat;
		}

	}
	this->aggiornaLivelli(u);
}

template<class T> void Albero<T>::insSottoAlberoFratello(NodoAN<T> *u,
		Albero a) {
	if (!this->alberoVuoto() && !a.alberoVuoto()) {
		if (u->fratello == nullptr) {
			u->fratello = new NodoAN<T>();
			u->fratello = a.albero->primoFilgio;
			u->fratello->padre = u->padre;
		} else {
			NodoAN<T> *frat = u->fratello;
			u->fratello = new NodoAN<T>();
			u->fratello = a.albero->primoFiglio;
			u->fratello->padre = u->padre;
			u->fratello->fratello = frat;
		}
	}
	this->aggiornaLivelli(u);
}

template<class T> void Albero<T>::cancSottoAlbero(NodoAN<T>* u) {
	if (u != nullptr) {
		if (u->fratello != nullptr) {
			this->cancSottoAlbero(u->fratello);
		}
		if (u->primoFiglio != nullptr) {
			this->cancSottoAlbero(u->primoFiglio);
		}
		delete u;
	}
}

template<class T> int Albero<T>::altezza(NodoAN<T> *u) const {
  int max = 0;
  u = u->primoFiglio;
    while(u != nullptr){
      int t  = altezza(u) + 1;
      if (t > max){
        max = t;
      }
      u = u->fratello;
    }
  return max;
}

template<class T> void Albero<T>::stampaAlbero(NodoAN<T> *u) {
	if (!this->alberoVuoto()) {
		//se il nodo passato come parametro ? una radice allora la stampa
		if (u->padre == this->albero)
			std::cout << *u;
		//se ha figli
		if (u->primoFiglio != nullptr) {
			u = u->primoFiglio;
			//serve per essere sicuri che tutti i livelli siano corretti (magari poi fare una funz apposita)
			u->livello = u->padre->livello + 1;
			//stampa il figlio
			std::cout << *u;
			//richiama la stampa sul figlio (DFS)
			this->stampaAlbero(u);
			//se ha fratelli
			if (u->fratello != nullptr) {
				while (u->fratello != nullptr) {
					u = u->fratello;
					u->livello = u->padre->livello + 1;
					//stampa i fratelli
					std::cout << *u;
					//richiama la stampa sui fratelli
					this->stampaAlbero(u);
				}
			}
		}
	}
}

template<class T> void Albero<T>::aggiornaLivelli(NodoAN<T> *u) {
	if (!this->alberoVuoto()) {
		if (u->primoFiglio != nullptr) {
			u = u->primoFiglio;
			u->livello = u->padre->livello + 1;
			this->aggiornaLivelli(u);
			if (u->fratello != nullptr) {
				while (u->fratello != nullptr) {
					u = u->fratello;
					u->livello = u->padre->livello + 1;
					this->aggiornaLivelli(u);
				}
			}
		}
	}
}

#endif /* ALBERO_H_ */
