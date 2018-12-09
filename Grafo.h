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
		
		//Cores para os v�rtices
		const int branco = 0;
		const int cinza = 1;
		const int preto = 2;
		
		//Cria��o de grafo
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
		
		inserir(int origem, int destino, int peso){
			if(digrafo){
				this->matriz[origem][destino] = peso;
			}
			else{
				this->matriz[origem][destino] = peso;
				this->matriz[destino][origem] = peso;
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
		
		//Insers�o para grafos n�o ponderados
		bool inserirAresta(int origem, int destino){
			//Tratando inser��o sem peso
			if(this->ponderado) return false;
			//Inserindo
			inserir(origem, destino, 1);
			
			return true;
		}
		
		//Inser��o para grafos ponderados
		bool inserirAresta(int origem, int destino, int peso){
			//Tratando inser��o incorreta em grafo
			if(this->ponderado) return false;
			//Inserindo
			inserir(origem, destino, peso);
			
			return true;
		}
		
		//Remo��o de aresta
		bool removerAresta(int origem, int destino){
			if(this->digrafo){
				if(this->matriz[origem][destino] == 0) return false;
				this->matriz[origem][destino] = 0;
			}
			else{
				if(this->matriz[origem][destino] == 0 || this->matriz[destino][origem] == 0) return false;
				this->matriz[origem][destino] = 0;
				this->matriz[destino][origem] = 0;
			}
			
			return true;
		}
		
		
};

#endif
