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
		
	public:
		//O grafo padrão a ser criado será um não orientado e não ponderado
		Grafo(int numVertices){
			criaGrafo(numVertices);
		}
		
		//Pode-se escolher o tipo de grafo a ser utilizado passando-se um valor inteiro
		// ***   0  -  Grafo não orientado e não ponderado
		// ***   1  -  Grafo orientado e não ponderado
		// ***   2  -  Grafo não orientado e ponderado
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
