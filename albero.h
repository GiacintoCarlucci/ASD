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

	~NodoAN(){
		//scrivere il distruttore, cos� termina inaspettatamente
		/*delete primoFiglio;
		delete fratello;
		delete padre;*/
	}
};

template <class T>
class Albero{
public:

	//Costruttori
	Albero();
	~Albero();

	//Osservatori
	bool alberoVuoto() const;
	bool foglia(NodoAN<T>) const;
	bool ultimoFratello(NodoAN<T>) const;
	NodoAN<T>* radice() const;
	NodoAN<T> padre(NodoAN<T>) const;
	NodoAN<T> primoFiglio(NodoAN<T>) const;
	NodoAN<T> succFratello(NodoAN<T>) const;

	//Modficatori
	void insRadice(NodoAN<T>);
	void insSottoAlberoFiglio(NodoAN<T>,Albero);
	void insSottoAlberoFratello(NodoAN<T>,Albero);
	void cancSottoAlbero(NodoAN<T>);

private:
	NodoAN<T> * albero;
};

template <class T> Albero<T>::Albero(){
	albero = new NodoAN<T>();
	albero->elemento = T();
	albero->livello = 0;
	albero->fratello = albero;
	albero->padre = albero;
	albero->primoFiglio = albero;
}

template <class T> Albero<T>::~Albero(){
	//man mano che scorro l'albero cancello i nodi, ma dovrei partire dal basso per non perdere i riferimenti?
	//ho un distruttore in NodoAN che dovrebbe cancellare ricorsivamente tutto l'albero
	//delete albero;
}

template <class T> bool Albero<T>::alberoVuoto() const{
	return ((albero->fratello == albero) && (albero->primoFiglio == albero) && (albero->padre == albero) && (albero->livello == 0));
}

template <class T> bool Albero<T>::foglia(NodoAN<T> u)const{
	//pre: albero non vuoto, u esiste nell'albero
	//post: true se esiste un padre di u, non esiste figlio di u, livello di u è di un unità maggiore del padre

	if(!this->alberoVuoto()){
		NodoAN<T> *temp; // = trovaNodo(u);
		//if temp non vuoto (esiste il nodo)
			// controllo padre e figlio
			//controllo il livello
			//restituisco true o false
	}

	return false; //da togliere
}

template <class T> bool Albero<T>::ultimoFratello(NodoAN<T> u)const{
	//pre: albero non vuoto, u esiste nell'albero
	//post: vero se non esistono altri fratelli che lo seguono nella relazione d'ordine
	//      falso altrimenti

	if(!this->alberoVuoto()){
		NodoAN<T> *temp; // = trovaNodo(u);
		//if temp non vuoto (esiste u)
			return u.fratello == nullptr;
	}

	return false;
}

template <class T> NodoAN<T>* Albero<T>::radice() const{
	//pre : albero non vuoto
	//post: ritorna u radice dell'albero, livello di u = 0

	if(!this->alberoVuoto()){
		return Albero<T>::albero->primoFiglio;
	}else{
		return nullptr;
	}
}

template <class T> void Albero<T>::insRadice(NodoAN<T> u){
	if(this->alberoVuoto()){
		albero->primoFiglio = new NodoAN<T>();
		albero->primoFiglio->elemento=u.elemento;
		albero->primoFiglio->padre=albero;
		albero->primoFiglio->primoFiglio=nullptr;
		albero->primoFiglio->fratello=nullptr;
		albero->primoFiglio->livello=0;
	}
}

#endif /* ALBERO_H_ */
