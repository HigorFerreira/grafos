#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>

using namespace std;

using namespace std;

class Grafo
{
	private:
		//Matriz de adjacência
		int **matriz;
		//Array de cores dos vértices
		int *cores = 0;
		//Número total de vértices
		int numVertices;
		//Indicação se o grafo é orientado
		bool digrafo = false;
		//Indicação se o grafo é ponderado
		bool ponderado = false;
		
		//Cores para os vértices
		const int branco = 0;
		const int cinza = 1;
		const int preto = 2;
		
		//Criação de grafo
		criaGrafo(int numVertices){
			//Armazenando o número total de vértices
			this->numVertices =  numVertices;
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
			
			//Alocando o array de cores
			int *cores = new int[this->numVertices];
			//Colorindo os vértices de branco
			for(int i = 0; i < this->numVertices; i ++)
				cores[i] = branco;
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
		
		//Insersão para grafos não ponderados
		bool inserirAresta(int origem, int destino){
			//Tratando inserção sem peso
			if(this->ponderado) return false;
			//Inserindo
			inserir(origem, destino, 1);
			
			return true;
		}
		
		//Inserção para grafos ponderados
		bool inserirAresta(int origem, int destino, int peso){
			//Tratando inserção incorreta em grafo
			if(this->ponderado) return false;
			//Inserindo
			inserir(origem, destino, peso);
			
			return true;
		}
		
		//Remoção de aresta
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
		
		//Busca em profundidade
		bool busca(){
		}
};

#endif
