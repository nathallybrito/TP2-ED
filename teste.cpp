#include <iostream>

struct Node {
    int vértice;
    Node* próximo;
};

struct Grafo {
    int V;  // Número de vértices
    Node** listaAdj;

    Grafo(int V) {
        this->V = V;
        listaAdj = new Node*[V];
        for (int i = 0; i < V; ++i) {
            listaAdj[i] = nullptr;
        }
    }

    void adicionarAresta(int origem, int destino) {
        Node* newNode = new Node;
        newNode->vértice = destino;
        newNode->próximo = listaAdj[origem];
        listaAdj[origem] = newNode;
    }

    void imprimirGrafo() {
        for (int v = 0; v < V; ++v) {
            std::cout << v << " -> ";
            Node* currentNode = listaAdj[v];
            while (currentNode) {
                std::cout << currentNode->vértice;
                currentNode = currentNode->próximo;
                if (currentNode) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int V; // Número de vértices
    std::cout << "Digite o número de vértices: ";
    std::cin >> V;

    Grafo grafo(V);

    for (int i = 0; i < V; ++i) {
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
