#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<vector>

using namespace std;

//Estrutura de resposta ao se chamar a busca em profundidade
struct busca_response{
	int *cores;
	int *tempos;
	int nVertices;
};

class Grafo
{
	private:
		//Matriz de adjac�ncia
		int **matriz;
		//Array de cores dos v�rtices
		int *cores = 0;
		//N�mero total de v�rtices
		int numVertices;
		//Indica��o se o grafo � orientado
		bool digrafo = false;
		//Indica��o se o grafo � ponderado
		bool ponderado = false;
		
		//Cria��o de grafo
		criaGrafo(int numVertices){
			//Armazenando o n�mero total de v�rtices
			this->numVertices =  numVertices;
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
			
			//Alocando o array de cores
			int *cores = new int[this->numVertices];
			//Colorindo os v�rtices de branco
			for(int i = 0; i < this->numVertices; i ++)
				cores[i] = branco;
		}
		
		//Inserir aresta no grafo
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
		//Vari�vel para guardar o tempo atual para o algoritmo de busca em profundidade
		int *tempoAtual = new int(0);
		
		//Cores para os v�rtices
		const int branco = 0;
		const int cinza = 1;
		const int preto = 2;
		
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
		
		//Obter lista de adjacentes de um v�rtice
		vector<int> *adj(int vertice){
			vector<int> *adjs = new vector<int>;
			if(this->digrafo){
				for(int i = 0; i < this->numVertices; i++){
					if(this->matriz[vertice][i] != 0)
							adjs->push_back(i);
					}
			}
			else{
				//algoritmo do grafo n�o direcionado
				
				//** ------------------- TO DO --------------------- ******
			}
			
			return adjs;
		}
		
		//Obter a matriz de adjacencia
		int **getMatriz(){
			return this->matriz;
		}
		
		//Obter as cores dos v�rtices
		int *getCores(){
			return this->cores;
		}
		
		//Obter o n�mero de v�rtices da matriz
		int getNumVetices(){
			return this->numVertices;
		}
		
		//Busca em profundidade
		static busca_response *busca(Grafo *gr, int ini, int tempo){
			//Guardando o tempo atual
			*gr->tempoAtual = tempo;
			//Matriz de adjacencia do grafo
			int **matriz = gr->getMatriz();
			//Matriz com as cores dos v�rtices do grafo
			int *cores = gr->getCores();
			//Matriz de tempos
			int *tempos = new int[gr->getNumVetices()];
			
			if(cores[ini] == gr->branco){
				//Atribuindo tempo ao v�rtice
				tempos[ini] = ++(*gr->tempoAtual);
				//Pintando o v�rtice de cinza
				cores[ini] = gr->cinza;
				//Lista de adjacencia do v�rtice fornecido
				vector<int> *adjacentes = gr->adj(ini);
				//Obtendo o primeiro v�rtice branco
				int proximo = -1;
				for(int i = 0; i < adjacentes->size(); i++){
					if(cores[adjacentes->at(i)] == gr->branco){
						proximo = adjacentes->at(i);
						break;
					}
				}
				//Chamando o pr�ximo v�rtice ou pintando de preto
				if(proximo > -1){
					Grafo::busca(gr, proximo, tempo);
				}
				else{
					tempos[ini] = ++tempo;
					cores[ini] = gr->preto;
					
					//Encerrando o m�todo
						//Montando o objeto de resposta
						busca_response *res = new busca_response;
						//Colocando o vetor de tempos
						res->tempos = tempos;
						//Copiando o vetor de cores
						int *coresRes = new int[gr->getNumVetices()];
						for(int i = 0; i < gr->getNumVetices(); i++){
							coresRes[i] = cores[i];
						}
						//Colocando o vetor de cores
						res->cores = coresRes;
						//Colocando o n�mero de v�rtices
						res->nVertices = gr->getNumVetices();
				}
				
				//Buscando v�rtice adjacente branco
				int proximo2 = -1;
				for(int i = 0; i < adjacentes->size(); i++){
					if(cores[adjacentes->at(i)] == gr->branco){
						proximo2 = adjacentes->at(i);
						break;
					}
				}
				//Chamando o pr�ximo v�rtice ou pintando de preto
				if(proximo2 > -1){
					Grafo::busca(gr, proximo2, tempo);
				}
				else{
					tempos[ini] = ++(*gr->tempoAtual);
					cores[ini] = gr->preto;
					
					//Encerrando o m�todo
						//Montando o objeto de resposta
						busca_response *res = new busca_response;
						//Colocando o vetor de tempos
						res->tempos = tempos;
						//Copiando o vetor de cores
						int *coresRes = new int[gr->getNumVetices()];
						for(int i = 0; i < gr->getNumVetices(); i++){
							coresRes[i] = cores[i];
						}
						//Colocando o vetor de cores
						res->cores = coresRes;
						//Colocando o n�mero de v�rtices
						res->nVertices = gr->getNumVetices();
				}
			}
		}
};

#endif
