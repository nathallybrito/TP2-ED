#include <iostream>
#include "../include/grafo.hpp"

int main(){
    int v; // Número de vértices
    std::cin >> v;

    Grafo grafo(v);

    for (int i = 0; i < v; ++i) {
        int numVizinhos;
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; ++j) {
            int vizinho;
            std::cin >> vizinho;
            grafo.adicionarAresta(i, vizinho);
        }
    }
    for (int i = 0; i < v; ++i) {
        int cor;
        std::cin >> cor;
        grafo.defineCor(i, cor);
    }

    grafo.imprimirGrafo();

    return 0;

}