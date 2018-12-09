#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>

using namespace std;

using namespace std;

class Grafo
{
	private:
		int **matriz;
		bool digrafo = false;
		bool ponderado = false;
		
		criaGrafo(int numVertices){
			//Cria��o da matriz de adjac�ncia
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
		
	public:
		//O grafo padr�o a ser criado ser� um n�o orientado e n�o ponderado
		Grafo(int numVertices){
			criaGrafo(numVertices);
		}
		
		//Pode-se escolher o tipo de grafo a ser utilizado passando-se um valor inteiro
		// ***   0  -  Grafo n�o orientado e n�o ponderado
		// ***   1  -  Grafo orientado e n�o ponderado
		// ***   2  -  Grafo n�o orientado e ponderado
		// ***   3  -  Grafo orientado e ponderado
		Grafo(int numVertices, int options){
			digrafo = (bool)(options & 1);
			ponderado = (bool)(options & 2);
			
			criaGrafo(numVertices);
		}
		
		bool inserirAresta(int origem, int destino){
			if(digrafo){
				this->matriz[origem][destino] = 1;
			}
			else{
				this->matriz[origem][destino] = 1;
				this->matriz[destino][origem] = 1;
			}
		}
};

#endif
