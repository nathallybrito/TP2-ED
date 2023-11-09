//---------------------------------------------------------------------
// Arquivo	: main.cpp
// Conteudo	: programa de avaliação do trabalho
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#include <iostream>
#include "../include/grafo.hpp"

int main(){
    // montagem do grafo
    int v; // Número de vértices
    char metodo; // escolha do método de ordenação.
    std::cin >> metodo >> v;

    if (v <= 0) {
        std::cerr << "Erro: Número de vértices inválido." << std::endl;
        return 1; // Código de erro
    }

    Grafo grafo(v);

    for (int i = 0; i < v; ++i) {
        int numVizinhos;
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; ++j) {
            int vizinho;
            std::cin >> vizinho;

            if (vizinho < 0 || vizinho >= v) {
                std::cerr << "Erro: Vizinho inválido para o vértice " << i << std::endl;
                return 1; 
            }

            grafo.adicionarAresta(i, vizinho);
        }
    }

    for (int i = 0; i < v; ++i) {
        int cor;
        std::cin >> cor;

        if (cor < 1) {
            std::cerr << "Erro: Cor inválida para o vértice " << i << std::endl;
            return 1; // Código de erro
        }

        grafo.defineCor(i, cor);
    }

    if (grafo.algoritmoGuloso()) {
        std::cout << "1 ";

        switch (metodo)
        {
        case 'b':
            grafo.bubbleSort();
            break;
        case 's':
            grafo.selectionSort();
            break;
        case 'i':
            grafo.insertionSort();
            break;
        case 'q':
            grafo.quicksort();
            break;
        case 'm':
            grafo.mergeSort();
            break;
        case 'p':
            grafo.heapsort();
            break;
        case 'y':
            grafo.mysort();
            break;
        default:
            std::cerr << "Erro: Escolha inválida." << std::endl;
            return 1; 
        }
    } else {
        std::cout << "0";
    }

    return 0;
}
