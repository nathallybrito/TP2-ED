#include "grafo.hpp"

Grafo::Grafo(int v){
    this->v = v;
    listaAdj = new Node*[v];
    for( int i = 0; i < v ; i++){
        listaAdj[i] = nullptr;
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
}

void Grafo::adicionarAresta(int origem, int destino){
    Node* newNode = new Node;
    newNode->vertice = destino;
    newNode->proximo = listaAdj[origem];
    listaAdj[origem] = newNode; 
}

void Grafo::imprimirGrafo() {
     for (int i= 0; i < v; ++i) {
            std::cout << i << " ->";
            Node* currentNode = listaAdj[i];
            while (currentNode) {
                std::cout << " " << currentNode->vertice;
                currentNode = currentNode->proximo;
            }
            std::cout << std::endl;
        }
    }



