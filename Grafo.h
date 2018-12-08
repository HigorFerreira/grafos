#ifndef GRAFO_H
#define GRAFO_H

/*
class Aresta{
	int v1, v2, peso;
	public:
		Aresta(int v1, int v2, int peso){
			this->v1 = v1;
			this->v2 = v2;
			this->peso = peso;
		}
		
		int peso(){
			return this->peso;
		}
		
		int v1(){
			return this->v1;
		}
		
		int v2(){
			return this->v2;
		}
};

class Celula{
	int vertice, peso;
	public:
		Celula(int v, int p){
			this->vertice = v;
			this->peso = p;
		}
		
		bool equals (){
			
		}
};

*/

class Grafo
{
	private:
		int numVertices;
		
	public:
		class Aresta{
			int v1, v2, peso;
			public:
				int getPeso(){ return this->peso; }
		};
};

#endif
