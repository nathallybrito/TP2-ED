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


void Grafo::imprimirGrafo(const int* indices) {
    for (int i = 0; i < v; i++) {
        int vertexIndex = indices[i];
        std::cout << vertexIndex << " ";
    }
    std::cout << std::endl;
    }

void Grafo::bubbleSort() {
    
 // Crie uma matriz auxiliar para armazenar os índices dos vértices
    int* indices = new int[v];
    for (int i = 0; i < v; i++) {
        indices[i] = i;
    }

    // Implemente a ordenação Bubble Sort com base nas cores dos vértices
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < v - i - 1; j++) {
            if (cores[indices[j]] > cores[indices[j + 1]]) {
                std::swap(indices[j], indices[j + 1]);
            }
        }
    }

    // Chame a função para imprimir o grafo ordenado
    imprimirGrafo(indices);

    // Libere a memória alocada
    delete[] indices;

    
}













