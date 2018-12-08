#ifndef GRAFO_H
#define GRAFO_H

#include<list>

using namespace std;

class Grafo
{
	private:
		int **matriz;
	public:
		Grafo(int numVertices){
			//Criação da matriz de adjacência
			this->matriz = new int*[numVertices];
			for(int i = 0; i < numVertices; i++){
				this->matriz[i] = new int[numVertices];
			}
			//Populando a matriz com 0
			for(int i; i < numVertices; i++){
				for(int j; j < numVertices; j++){
					this->matriz[i][j] = 0;
				}
			}
		}
};

#endif
