#include <iostream>
#include"Grafo.h"

using namespace std;

int main(){
	
	Grafo *grafo = new Grafo(6, 1);
	grafo->inserirAresta(0, 1);
	grafo->inserirAresta(0, 4);
	grafo->inserirAresta(1, 4);
	grafo->inserirAresta(1, 2);
	grafo->inserirAresta(2, 3);
	grafo->inserirAresta(3, 1);
	grafo->inserirAresta(4, 3);
	grafo->inserirAresta(5, 4);
	grafo->inserirAresta(5, 0);
}
