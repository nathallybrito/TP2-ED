//---------------------------------------------------------------------
// Arquivo	: grafo.hpp
// Conteudo	: definicoes da Lista de Adjacencia e metodos de ordenação 
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>

struct Node{
    int vertice;
    Node* proximo;
};

class Grafo{
private: 
 int v; //Número de vértices
 int* cores;

public:
Node** listaAdj;

Grafo(int v);

~Grafo();

void adicionarAresta(int origem,int destino);

void imprimirGrafo(const int* indices);

void defineCor(int vertice, int cor);

int* matrizIndices();

void bubbleSort();

void selectionSort();

void insertionSort();

int  particao(int* indices,int esq,int dir);

void ordena_quick(int* indices,int esq, int dir);

void quicksort();

void merge(int* indices, int esq, int mid, int dir);

void mergeSort(int* indices, int esq, int dir);

void mergeSort();

void heapify(int* indices, int n, int i);

void heapsort();

void mysort();

bool algoritmoGuloso();
};

#endif