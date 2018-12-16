#include <iostream>
#include"Grafo.h"

using namespace std;

int main(){
	
    Grafo *grafo = new Grafo(4, 1);
	grafo->inserirAresta(0, 1);
    grafo->inserirAresta(0, 2);
	
	//Teste de busca em profundidade
	busca_response *res = Grafo::busca(grafo, 0, 0);
	
	//Impressão do vetor de tempos
	for(int i = 0; i < grafo->getNumVetices(); i++){
		cout<<res->tempos[i]<<" ";
	}
	cout<<endl;
	
	//Impressão do vetor de cores
	for(int i = 0; i < grafo->getNumVetices(); i++){
		cout<<res->cores[i]<<" ";
	}
	cout<<endl;
}
