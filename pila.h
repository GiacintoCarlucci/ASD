#ifndef _PILA_H_
#define _PILA_H_

template<class T>
struct NodoP {
	T elemento;
	NodoP<T> *succ;
};

template <class T>
class Pila{
public:

  /* Definizioni*/
  typedef NodoP<T> * posizione;

  /* Costruttori*/
  // Default
  Pila();

  // Copia
  Pila(const Pila&);

  // Valore


  // Distruttore
  ~Pila();

  /* Osservatori*/
  bool pilaVuota() const;
  T leggiPila() const;

  /* Modificatori*/
  void fuoriPila();
  void inPila(T);

  /* Di Servizio*/
  void stampaPila();
private:
  posizione pila;
};

//=================================================
// IMPLEMENTAZIONE
//=================================================

/* Costruttori*/
// Default
template <class T> Pila<T>::Pila(){
  T ElementoNullo;
  pila = new NodoP<T>;
  pila->elemento = ElementoNullo;
  pila = nullptr;
}

// Copia
template <class T> Pila<T>::Pila(const Pila<T>& origin){
  auto originNode = origin.pila;
  T ElementoNullo;
  //pila di supporto
  Pila pilaSupp;
  pila = new NodoP<T>;
  pila->elemento = ElementoNullo;
  pila = nullptr;

  //copio i valori della pila originale in quella di supporto
  while(originNode){
    pilaSupp.inPila(originNode->elemento);
    originNode = originNode->succ;
  }

  //copio i valori dalla pila di supporto alla pila di output per rimettere gli elementi in ordine
  while(!(pilaSupp.pilaVuota())){
    this->inPila(pilaSupp.leggiPila());
    pilaSupp.fuoriPila();
  }
}

// Distruttore
template <class T> Pila<T>::~Pila(){
  while(pila != nullptr){
    this->fuoriPila();
  }
  delete pila;
}

/* Osservatori*/
template <class T> bool Pila<T>::pilaVuota() const{
  return pila == nullptr;
}

template <class T> T Pila<T>::leggiPila() const{
  if(pila != nullptr){
    return pila->elemento;
  }else{
    T obj = T();
    return obj;
  }
}

/* Modificatori*/
template <class T> void Pila<T>::fuoriPila(){
  // E SE CANCELLO QUANDO NON CI SONO PIU ELEMENTI?

  if(pila!=nullptr){
    Pila::posizione tmp;
    tmp = new NodoP<T>;
    tmp = pila;
    pila = pila->succ;
    delete(tmp);
  }else{
    return;
  }
}

template <typename T> void Pila<T>::inPila(T elemento){
  Pila::posizione nodo;
  nodo = new NodoP<T>;
  nodo->elemento=elemento;
  nodo->succ=nullptr;

  if(this->pilaVuota()){
    pila = nodo;
  }else{
    Pila::posizione tmp;
    tmp = new NodoP<T>;
    tmp = pila;
    nodo->succ=tmp;
    pila=nodo;
    //delete(tmp);
  }
}

/* Di Servizio*/
template <typename T> void Pila<T>::stampaPila(){
  Pila<T> tmp(*this);
  std::cout<<"[";
  while(!(tmp.pilaVuota())){
    std::cout<<tmp.leggiPila();
    if(tmp.pila->succ){
      std::cout<<",";
    }
    tmp.fuoriPila();
  }
  std::cout<<"]\n";
}


#endif //_PILA_H_
