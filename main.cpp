#include <string>
#include <iostream>

#include "lista.h"
#include "coda.h"
#include "pila.h"
#include "grafo.h"
#include "insieme.h"
#include "dizionario.h"
#include "albero.h"

int main(void) {
/*Lista
 *
	 std::cout<<"creazione della lista...\n";
	 Lista<int> l;
	 std::cout<<"la lista l è vuota: ";
	 l.listaVuota() ? std::cout<<"si\n" : std::cout<<"no\n";

	 std::cout<<"inserimento di valore nel primo nodo...\n";
	 Lista<int>::posizione indice = l.primoLista();
	 l.scriviLista(1,indice);//non inserisce
	 std::cout<<"la lista l è vuota: ";
	 l.listaVuota() ? std::cout<<"si\n" : std::cout<<"no\n";

	 std::cout<<"aggiunta di un nodo...\n";
	 l.insLista(2,indice=l.succLista(indice));
	 std::cout<<"abbiamo appena inserito: "<<l.leggiLista(indice)<<"\n";
	 std::cout<<"aggiunta di un nodo...\n";
	 l.insLista(3,indice=l.succLista(indice));
	 std::cout<<"abbiamo appena inserito: "<<l.leggiLista(indice)<<"\n";

	 std::cout<<"la lista l è vuota: ";
	 l.listaVuota() ? std::cout<<"si\n" : std::cout<<"no\n";

	 std::cout<<"esiste l'elemento 2: ";
	 l.esisteLista(2) ? std::cout<<"si\n" : std::cout<<"no\n";
	 std::cout<<"esiste l'elemento 3: ";
	 l.esisteLista(3) ? std::cout<<"si\n" : std::cout<<"no\n";
	 std::cout<<"esiste l'elemento 4: ";
	 l.esisteLista(4) ? std::cout<<"si\n" : std::cout<<"no\n";

	 l.stampaLista();
	 l.stampaNodo(indice);
	 */

/*Grafo
 *
	 Grafo<std::string> G;
	 Vertex<std::string> U, V, O,P;
	 U.label = "U";
	 V.label = "V";
	 O.label = "O";
	 P.label = "P";

	 std::cout << "creo il seguente grafo:\n";
	 std::cout << "      U"<<std::endl;
	 std::cout << "     / \\"<<std::endl;
	 std::cout << "    V   O"<<std::endl;
	 std::cout << "   /"<<std::endl;
	 std::cout << "  P"<<std::endl;

	 G.insNodo(U);
	 G.insNodo(V);
	 G.insNodo(O);
	 G.insNodo(P);

	 G.insArco(U, V);
	 G.insArco(U, O);
	 G.insArco(V, U);
	 G.insArco(O, U);
	 G.insArco(V, P);
	 G.insArco(P, V);

	 G.stampaGrafo();
	 std::cout<<"\nVisita BFS:\n";
	 G.BFS(V);
	 std::cout<<"\nVisita DFS:\n";
	 std::vector<Vertex<std::string>> vet;
	 G.DFS(O,vet);
	 */

/*Coda
 *
	 Coda<int> C;
	 C.inCoda(1);
	 C.inCoda(2);
	 C.inCoda(3);
	 C.inCoda(4);
	 C.stampaCoda();
	 */

/*Pila
 *
	 Pila<int> A;
	 std::cout<<"pila vuota: "<<A.pilaVuota()<<"\n";
	 A.stampaPila();
	 A.inPila(10);
	 std::cout<<"pila vuota dopo inserimento?: "<<A.pilaVuota()<<"\n";
	 std::cout<<"in testa alla pila c'è: "<<A.leggiPila()<<"\n";
	 A.inPila(20);
	 std::cout<<"in testa alla pila dopo inserimento c'è: "<<A.leggiPila()<<"\n";
	 A.fuoriPila();
	 std::cout<<"in testa alla pila dopo rimozione c'è: "<<A.leggiPila()<<"\n";
	 A.fuoriPila();
	 std::cout<<"in testa alla pila dopo rimozione c'è: "<<A.leggiPila()<<"\n";
	 A.fuoriPila();
	 std::cout<<"in testa alla pila dopo rimozione c'è: "<<A.leggiPila()<<"\n";
	 A.inPila(10);
	 A.inPila(40);
	 A.inPila(0);
	 A.inPila(-10);
	 A.inPila(760);
	 A.inPila(12340);
	 std::cout<<"stampa della pila dopo ripopolazione: \n";
	 A.stampaPila();
	 */

/*Insieme
 *
	Insieme<int> I;
	I.inserisci(1);
	I.inserisci(2);
	I.inserisci(3);
	I.inserisci(4);
	I.inserisci(5);

	Insieme<int> B;
	B.inserisci(1);
	B.inserisci(2);
	B.inserisci(3);
	B.inserisci(7);

	std::cout<<"I: ";I.stampaInsieme();
	std::cout<<"B: ";B.stampaInsieme();

	std::cout<<"I intersezione B:\n";
	I.intersezione(B);

	std::cout<<"I: ";I.stampaInsieme();
	std::cout<<"B: ";B.stampaInsieme();

	std::cout<<"I unione B:\n";
	I.unione(B);

	std::cout<<"I: ";I.stampaInsieme();
	std::cout<<"B: ";B.stampaInsieme();

	std::cout<<"I differenza B:\n";
	I.differenza(B);

	std::cout<<"I: ";I.stampaInsieme();
	std::cout<<"B: ";B.stampaInsieme();

	std::cout<<"I intersezione B:\n";
	I.intersezione(B);

	std::cout<<"I: ";I.stampaInsieme();
	std::cout<<"B: ";B.stampaInsieme();
*/

/*Dizionario
 *
	std::cout<<"Creazione Dizionario D...\n";
	Dizionario<std::string,int> D;
	std::cout<<"Dizionario D è vuoto: ";
	D.dizionarioVuoto() ? std::cout<<"si\n" : std::cout<<"no\n";
	std::cout<<"chiave 'sole' esiste: ";
	D.appartiene("sole") ? std::cout<<"si\n" : std::cout<<"no\n";
	std::cout<<"Inserimento di 'sole' con valore '1'...\n";
	D.inserisci("sole", 1);
	std::cout<<"chiave 'sole' esiste: ";
	D.appartiene("sole") ? std::cout<<"si\n" : std::cout<<"no\n";
	std::cout<<"cancellazione di 'sole'...\n";
	D.cancella("sole");
	std::cout<<"chiave 'sole' esiste: ";
	D.appartiene("sole") ? std::cout<<"si\n" : std::cout<<"no\n";
	D.stampa();
*/


	Albero<int> alb;
	std::cout<<"l'albero 'alb' è vuoto: ";
	alb.alberoVuoto() ? std::cout<<"si\n" : std::cout<<"no\n";

	//TODO: creare costruttore nodo
	NodoAN<int> u;
	u.elemento=5;
	u.padre=alb.radice();
	u.primoFiglio=nullptr;
	u.fratello=nullptr;

	alb.insRadice(u);
	std::cout<<"l'albero 'alb' è vuoto: ";
	alb.alberoVuoto() ? std::cout<<"si\n" : std::cout<<"no\n";

	alb.ultimoFratello(u) ? std::cout<<"u � l'ultimo fratello\n" : std::cout<<"u non � l'ultimo fratello\n" ;
	alb.radice()==nullptr ? std::cout<<"nessuna radice\n" : std::cout<<"elemento nella radice: "<<alb.radice()->elemento<<"\n";
	alb.padre(u)==nullptr ? std::cout<<"nessun padre di u\n" : std::cout<<"elemento del padre: "<<alb.padre(u)->elemento<<"\n";
	alb.primoFiglio(u)==nullptr ? std::cout<<"nessun figlio di u\n" : std::cout<<"elemento del figlio: "<<alb.primoFiglio(u)->elemento<<"\n";
	return 0;
}
