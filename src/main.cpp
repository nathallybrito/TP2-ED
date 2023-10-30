#include<iostream>
#include "grafo.hpp"

int main(){
int v; // Número de vértices
    std::cout << "Digite o número de vértices: ";
    std::cin >> v;

    Grafo grafo(v);

    for (int i = 0; i < v; ++i) {
        int numVizinhos;
        std::cout << "Digite o número de vizinhos do vértice " << i << ": ";
        std::cin >> numVizinhos;

        std::cout << "Digite os vizinhos do vértice " << i << ": ";
        for (int j = 0; j < numVizinhos; ++j) {
            int vizinho;
            std::cin >> vizinho;
            grafo.adicionarAresta(i, vizinho);
        }
    }

    grafo.imprimirGrafo();

    return 0;

}