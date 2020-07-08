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

// template<typename T>
// void remove(std::vector<T> v, T k){
//     // se l'array non è vuoto
//     if(!v.empty()){
//         // itero nell'array
//         for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
//             // se trovo l'elemento da rimuovere
//             if(*it == k){
//                 // shifto a sinistra a partire dalla posizione corrente
//                 for(typename std::vector<T>::iterator inner_it = it; inner_it != v.end(); inner_it++){
//                     *inner_it =  *++it;
//                 }
//                 *v.end() = 0;
//                 return;
//             }
//         }
//     }
// }

int main(void) {
    std::vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "array = {1,2,3,4,5,6,7,8,9,10}" << '\n';

    int k = 7;
    std::cout << "il numero di elementi dell'array maggiori di "<<k<<" e': "<<greaterThan(array,k)<< '\n';
    std::cout << k <<" presente nell'array: "<< member(array,k) <<'\n';
    std::cout << "l'elemento piu' grande dell'array e': " << largest(array).value<< '\n';
    std::cout << "rimozione di "<< k <<" dall'array..." << '\n';
    remove(array,k);
    std::cout << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << ", " << array[4] << ", " << array[5] << ", " << array[6] << ", " << array[7] << ", " << array[8] << ", " << array[9] << '\n';
    return 0;
}
