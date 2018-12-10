#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<vector>

using namespace std;

//Estrutura de resposta ao se chamar a busca em profundidade
struct busca_response{
	int *cores;
	int *tempos;
};

class Grafo
{
	//Variáveis públicas
	public:
		int *tempoAtual;
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
		
		//Criação de grafo
		criaGrafo(int numVertices){
			this->tempoAtual = new int(0);
			//Armazenando o número total de vértices
			this->numVertices =  numVertices;
			//Criação da matriz de adjacência
			this->matriz = new int*[numVertices];
			for(int i = 0; i < numVertices; i++){
				this->matriz[i] = new int[numVertices];
			}
			//Populando a matriz com 0
			for(int i = 0; i < numVertices; i++){
				for(int j; j < numVertices; j++){
					this->matriz[i][j] = 0;
				}
			}
			
			//Alocando o array de cores
			this->cores = new int[this->numVertices];
			//Colorindo os vértices de branco
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
		//Cores para os vértices
		const int branco = 0;
		const int cinza = 1;
		const int preto = 2;
		
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
		
		//Obter lista de adjacentes de um vértice
		vector<int> *adj(int vertice){
			vector<int> *adjs = new vector<int>;
			if(this->digrafo){
				for(int i = 0; i < this->numVertices; i++){
					if(this->matriz[vertice][i] != 0)
							adjs->push_back(i);
					}
			}
			else{
				//algoritmo do grafo não direcionado
				
				//** ------------------- TO DO --------------------- ******
			}
			
			return adjs;
		}
		
		//Obter a matriz de adjacencia
		int **getMatriz(){
			return this->matriz;
		}
		
		//Obter as cores dos vértices
		int *getCores(){
			return this->cores;
		}
		
		//Obter o número de vértices da matriz
		int getNumVetices(){
			return this->numVertices;
		}
		
		//Busca em profundidade
		static busca_response *busca(Grafo *gr, int ini, int tempo){
			//Guardando o tempo atual
			*gr->tempoAtual = tempo;
			//Matriz de adjacencia do grafo
			int **matriz = gr->getMatriz();
			//Matriz com as cores dos vértices do grafo
			int *cores = gr->getCores();
			//Matriz de tempos
			int *tempos = new int[gr->getNumVetices()];
			
			if(cores[ini] == gr->branco){
				//Atribuindo tempo ao vértice
				tempos[ini] = ++(*gr->tempoAtual);
				//Pintando o vértice de cinza
				cores[ini] = gr->cinza;
				//Lista de adjacencia do vértice fornecido
				vector<int> *adjacentes = gr->adj(ini);
				//Obtendo o primeiro vértice branco
				int proximo = -1;
				for(int i = 0; i < adjacentes->size(); i++){
					if(cores[adjacentes->at(i)] == gr->branco){
						proximo = adjacentes->at(i);
						break;
					}
				}
				//Chamando o próximo vértice ou pintando de preto
				if(proximo > -1){
					Grafo::busca(gr, proximo, tempo);
				}
				else{
					tempos[ini] = ++tempo;
					cores[ini] = gr->preto;
					
					//Encerrando o método
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
				}
				
				//Buscando vértice adjacente branco
				int proximo2 = -1;
				for(int i = 0; i < adjacentes->size(); i++){
					if(cores[adjacentes->at(i)] == gr->branco){
						proximo2 = adjacentes->at(i);
						break;
					}
				}
				//Chamando o próximo vértice ou pintando de preto
				if(proximo2 > -1){
					Grafo::busca(gr, proximo2, tempo);
				}
				else{
					tempos[ini] = ++(*gr->tempoAtual);
					cores[ini] = gr->preto;
					
					//Encerrando o método
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
				}
			}
		}
};

#endif
