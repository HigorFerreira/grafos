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
	//Vari�veis p�blicas
	public:
		int *tempoAtual;
	private:
		//Matriz de adjac�ncia
		int **matriz;
		//Array de cores dos v�rtices
		int *cores = 0;
        //Array de tempos dos v�rtices
        int *tempos = 0;
		//N�mero total de v�rtices
		int numVertices;
		//Indica��o se o grafo � orientado
		bool digrafo = false;
		//Indica��o se o grafo � ponderado
		bool ponderado = false;
		
		//Cria��o de grafo
        void criaGrafo(int numVertices){
			this->tempoAtual = new int(0);
			//Armazenando o n�mero total de v�rtices
			this->numVertices =  numVertices;
			//Cria��o da matriz de adjac�ncia
			this->matriz = new int*[numVertices];
			for(int i = 0; i < numVertices; i++){
				this->matriz[i] = new int[numVertices];
			}
			//Populando a matriz com 0
			for(int i = 0; i < numVertices; i++){
                for(int j = 0; j < numVertices; j++){
					this->matriz[i][j] = 0;
				}
			}
			
			//Alocando o array de cores
			this->cores = new int[this->numVertices];
			//Colorindo os v�rtices de branco
			for(int i = 0; i < this->numVertices; i ++)
				cores[i] = branco;
            //Alocando o array de tempos
            this->tempos = new int[this->numVertices];
            //Setando os tempos para zero
            for(int i = 0; i < this->numVertices; i++)
                tempos[i] = 0;
		}
		
		//Inserir aresta no grafo
        void inserir(int origem, int destino, int peso){
			if(digrafo){
				this->matriz[origem][destino] = peso;
			}
			else{
				this->matriz[origem][destino] = peso;
				this->matriz[destino][origem] = peso;
			}
		}
		
	public:		
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

        //Obter os tempos dos v�rtices
        int *getTempos(){
            return this->tempos;
        }
		
		//Obter o n�mero de v�rtices da matriz
		int getNumVetices(){
			return this->numVertices;
		}
		
		//*********** BUSCA EM PROFUNDIDADE N�O EST� FUNCIONANDO ********************************
		
		//Busca em profundidade
		static busca_response *busca(Grafo *gr, int ini, int tempo){
			//Guardando o tempo atual
			*gr->tempoAtual = tempo;
			//Matriz de adjacencia do grafo
			int **matriz = gr->getMatriz();
			//Matriz com as cores dos v�rtices do grafo
			int *cores = gr->getCores();
			//Matriz de tempos
            int *tempos = gr->getTempos();
			
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
                    Grafo::busca(gr, proximo, *gr->tempoAtual);
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
                        return res;
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
                    Grafo::busca(gr, proximo2, *gr->tempoAtual);
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
                        return res;
				}

                //Testando se o vertice atual ainda e cinza
                if(cores[ini] == gr->cinza){
                    tempos[ini] = ++(*gr->tempoAtual);
                    cores[ini] = gr->preto;
                }

                //Buscando vertices brancos
                for(int brancoRestante = 0; brancoRestante < gr->getNumVetices(); brancoRestante++){
                    if(cores[brancoRestante] == gr->branco){
                        Grafo::busca(gr, brancoRestante, *gr->tempoAtual);
                        break;
                    }
                }

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
                    return res;
			}
		}
};

#endif
