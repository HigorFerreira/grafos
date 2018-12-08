#ifndef GRAFO_H
#define GRAFO_H

#include<list>

using namespace std;

//O c�digo do libro est� em javascript e � de dif�cil compreens�o.
//Tentaremos uma solu��o com um c�digo totalente desenvolvido por n�s.

class Grafo
{
	private:
		int numVertices;
		
	public:
		class Aresta{
			int v1, v2, peso;
			public:
				int getPeso(){ return this->peso; }
				int getV1(){ return this->v1; }
				int getV2(){ return this->v2; }
		};
		
		class Celula{
			public:
				int vertice, peso;
				
				Celula(int v, int p){ this->vertice = v; this->peso = p; }
				bool equals(Celula *obj){
					Celula *item = obj;
					return (this->vertice == item->vertice);
				}
		};
		
		list<int> *adj;
		int numVetices;
		
		Grafo(int numVertices){
			this->adj = new list<Celula>[numVertices];
			this->numVertices = numVertices;
			for(int i = 0; i < this->numVertices; i++){
				this->adj[i] = new list<Celula>;
			}
		}
		
		void insereAresta(int v1, int v2, int peso){
			Celula *item = new Celula(v2, peso);
			this->adj[v1].push_back(item);
		}
};

#endif
