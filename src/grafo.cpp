#include "../include/grafo.hpp"

Grafo::Grafo(int v){
    this->v = v;
    listaAdj = new Node*[v];
    cores = new int[v];
    for( int i = 0; i < v ; i++){
        listaAdj[i] = nullptr;
        cores[i] = -1;
    }
}   

Grafo::~Grafo(){
    for(int i = 0; i < v; i++){
            Node* currentNode = listaAdj[i];
            while (currentNode) {
                Node* nextNode = currentNode->proximo;
                delete currentNode;
                currentNode = nextNode;
            }
        }
        delete[] listaAdj;
        delete[] cores;
}

void Grafo::adicionarAresta(int origem, int destino){
    Node* newNode = new Node;
    newNode->vertice = destino;
    newNode->proximo = listaAdj[origem];
    listaAdj[origem] = newNode; 
}

void Grafo::defineCor(int vertice, int cor){
    cores[vertice] = cor;
}

void Grafo::imprimirGrafo() {
     for (int i= 0; i < v; ++i) {
            std::cout << i << " ->";
            Node* currentNode = listaAdj[i];
            while (currentNode) {
                std::cout << " " << currentNode->vertice ;
                currentNode = currentNode->proximo;
            }
            std::cout << " Cor:" << cores[i]<< std::endl;
        }
    }

void Grafo::boobleSort(Node** listaAadj,int cor){
    int i, j;
    for(i = 0; i < cor -1; i++)
    for(j = 1; j < cor -i; j++)
      if (listaAadj[j].chave < v[j-1].chave) 
        Troca(v[j-1], v[j]);
}

    }



