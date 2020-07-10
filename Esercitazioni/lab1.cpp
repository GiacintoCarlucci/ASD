/*
    Scrivere in C/C++ in un file array.c l'implementazione delle seguenti funzioni che operano su array di elementi di tipo integer.

    greaterThan: ha in input un array A ed un intero k e restituisce il numero di elementi di A che sono maggiori di k;
    member: ha in input un array A ed un intero k e restituisce true se k Ã¨ presente in A;
    largest: ha in input un array A e restutuisce il valore del piÃ¹ grande elemento presente in A e la sua posizione;
    remove: ha in input un array A ed un intero k e elimina la prima occorrenza di k in A facendo uno shift a sinistra di tutti gli elementi che seguono k e scrivendo zero alla fine dell'array;
    ordering: ha in input un array A ed stabilisce se gli elementi in A sono in ordine crescente, descrescente o costante;
    reverse: ha in input un array A e lo modifca invertendone gli elementi.
*/

#include <iostream>
#include <vector>

template <typename T>
struct item{
    T value;
    int pos;
};

template <typename T>
int greaterThan(std::vector<T> v, T k){
    int counter = 0;
    for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
        if(*it > k){counter++;}
    }
    return counter;
}

template<typename T>
bool member(std::vector<T> v, T k){
    for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
        if(*it == k){
            return true;
        }
    }
    return false;
}

template<typename T>
item<T> largest(std::vector<T> v){
    item<T> max;
    if (!v.empty()){
        max.value = v[0];
        max.pos = 0;
        int i = 0;
        for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
            if(*it > max.value){
                max.value = *it;
                max.pos = i;
            }
            i++;
        }
    }else{
        max.pos = -1;
    }
    return max;
}

template<typename T>
std::vector<T> remove(std::vector<T> v, T k){
    std::vector<T> temp;
    // se l'array non è vuoto
    if(!v.empty()){
        // itero nell'array
        for(typename std::vector<T>::iterator it = v.begin(); it < v.end(); it++){
            // se trovo l'elemento lo salto
            if(*it == k){  *++it; }
            // inserisco nell'array temporaneo
            temp.push_back(*it);
        }
        // alla fine inserisco 0
        temp.push_back(0);
    }
    // restituisco l'array shiftato
    return temp;
}

/*
    1: crescente
    2: decrescente
    3: costante
    -1: non ordinato
*/
template <typename T>
int ordering(std::vector<T> v){
    if(!v.empty()){
        if(v.size() == 1){return -1;}
        if (v.size() == 2){
            if(*v.begin() < *(v.begin() + 1)){return 1;}
            if(*v.begin() > *(v.begin() + 1)){return 2;}
            if(*v.begin() == *(v.begin() + 1)){return 3;}
        }

        int ordering = -1;
        T first = *v.begin();
        T second = *(v.begin() + 1);
        if(v.size() > 2){
            if(first < second){ordering = 1;}
            if(first > second){ordering = 2;}
            if(first == second){ordering = 3;}
        }

        T last = second;
        for(typename std::vector<T>::iterator it = v.begin() + 2; it < v.end(); it++){
            if (last < *it && ordering == 1){
                last = *it;
                continue;
            }else{
                if (last > *it && ordering == 2){
                    last = *it;
                    continue;
                }else{
                    if (last == *it && ordering == 3){
                        last = *it;
                        continue;
                    }else{
                        return -1;
                    }
                }
            }
        }
        return ordering;
    }
    return -1;
}

template<typename T>
std::vector<T> reverse(std::vector<T> v){
    std::vector<T> temp;
    // se l'array non è vuoto
    if(!v.empty()){
        // itero al contrario nell'array
        for(typename std::vector<T>::iterator it = v.end() - 1; it >= v.begin(); it--){
            // inserisco nell'array temporaneo
            temp.push_back(*it);
        }
    }
    // restituisco l'array invertito
    return temp;
}

template<typename T>
void print(std::vector<T> v){
    std::cout << "{ ";
    for (typename std::vector<T>::iterator it = v.begin(); it < v.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << "}" << '\n';
}

int main(void) {
    std::vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    print(array);
    int k = 7;
    std::cout << "ordinamento array: " << ordering(array) << '\n';
    std::cout << "il numero di elementi dell'array maggiori di "<<k<<" e': "<<greaterThan(array,k)<< '\n';
    std::cout << k <<" presente nell'array: "<< member(array,k) <<'\n';
    std::cout << "l'elemento piu' grande dell'array e': " << largest(array).value << '\n';
    std::cout << "rimozione di "<< k <<" dall'array..." << '\n';
    array = remove(array,k);
    print(array);
    std::cout << "ordinamento array dopo la rimozione: " << ordering(array) << '\n';
    std::cout << "inversione dell'array..." << '\n';
    array = reverse(array);
    print(array);

    return 0;
}
