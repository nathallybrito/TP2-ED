#include "../include/grafo.hpp"
#include <set>


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

int* Grafo::matrizIndices(){
    int* indices = new int[v];
    for (int i = 0; i < v; i++) {
        indices[i] = i;
    }
    return indices;
}

void Grafo::imprimirGrafo(const int* indices) {
     for (int i = 0; i < v; i++) {
        int vertexIndex = indices[i];
        std::cout << vertexIndex << " ";
     }
    std::cout << std::endl;
    }



void Grafo::bubbleSort() {
    int* indices = matrizIndices();

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

void Grafo :: selectionSort(){
    int* indices = matrizIndices();

    for(int i = 0; i < v -1; i++){
     int min = i;
     for (int j = i + 1; j < v; j++) {
            if (cores[indices[j]] < cores[indices[min]]) {
                min = j;
            }
        }
        if (min!= i) {
            std::swap(indices[i], indices[min]);
        }
    }

    imprimirGrafo(indices);
    delete[] indices;

    }

void Grafo :: insertionSort(){
    int* indices = matrizIndices();

    for (int i = 1; i < v; i++) {
        int aux = indices[i];
        int j = i - 1;

        // Move os elementos do array que são maiores do que a chave
        // para uma posição à frente da sua posição atual
        while ((j >= 0) && (cores[indices[j]] > cores[aux])) {
            indices[j + 1] = indices[j];
            j--;
        }
        indices[j + 1] = aux;
    }
    imprimirGrafo(indices);
    delete[] indices;
}

int Grafo::particao(int* indices, int esq, int dir) {
    int pivot = indices[dir]; // Use indices[dir] as the pivot
    int i = esq - 1;

    for (int j = esq; j <= dir; j++) { // Iterate from esq to dir
        // Compare colors first (less than)
        if (cores[indices[j]] < cores[pivot] || (cores[indices[j]] == cores[pivot] && indices[j] < pivot)) {
            i++;
            std::swap(indices[i], indices[j]);
        }
    }

    std::swap(indices[i + 1], indices[dir]);
    return i + 1;
}


void Grafo::ordena_quick(int* indices, int esq, int dir){
    if (esq < dir){
        int pivot = particao(indices, esq, dir);
        ordena_quick(indices, esq, pivot - 1);
        ordena_quick(indices, pivot + 1, dir);
    }
}


void Grafo::quicksort(){
    int* indices= matrizIndices();

    ordena_quick(indices,0,v-1);
    imprimirGrafo(indices);
    delete[] indices ;

}

// Função auxiliar para mesclar dois subarrays
void Grafo::merge(int* indices, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Crie arrays temporários para armazenar os elementos
    int* L = new int[n1];
    int* R = new int[n2];

    // Copie os elementos para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++) {
        L[i] = indices[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = indices[mid + 1 + j];
    }

    // Mesclar os arrays temporários de volta em indices[low..high]
    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (cores[L[i]] <= cores[R[j]]) {
            indices[k] = L[i];
            i++;
        } else {
            indices[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de L[], se houver algum
    while (i < n1) {
        indices[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[], se houver algum
    while (j < n2) {
        indices[k] = R[j];
        j++;
        k++;
    }

    // Libere a memória alocada para os arrays temporários
    delete[] L;
    delete[] R;
}

// Função principal para ordenar um subarray indices[low..high] usando MergeSort
void Grafo::mergeSort(int* indices, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(indices, low, mid);
        mergeSort(indices, mid + 1, high);
        merge(indices, low, mid, high);
    }
}

// Método para realizar o MergeSort
void Grafo::mergeSort() {
    int* indices = matrizIndices();

    mergeSort(indices, 0, v - 1);

    imprimirGrafo(indices);

    delete[] indices;
}


void Grafo::heapify(int* indices, int n, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Compare colors first (greater than)
    if (esquerda < n && (cores[indices[esquerda]] > cores[indices[menor]] || 
        (cores[indices[esquerda]] == cores[indices[menor]] && indices[esquerda] > indices[menor]))) {
        menor = esquerda;
    }

    if (direita < n && (cores[indices[direita]] > cores[indices[menor]] || 
        (cores[indices[direita]] == cores[indices[menor]] && indices[direita] > indices[menor]))) {
        menor = direita;
    }

    if (menor != i) {
        std::swap(indices[i], indices[menor]);
        heapify(indices, n, menor);
    }
}

void Grafo::heapsort(){
    int* indices = matrizIndices();
    int n = v;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(indices, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(indices[0], indices[i]);
        heapify(indices, i, 0);
    }
    imprimirGrafo(indices);
    delete[] indices;
}


















