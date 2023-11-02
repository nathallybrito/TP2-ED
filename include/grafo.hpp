//---------------------------------------------------------------------
// Arquivo	: grafo.hpp
// Conteudo	: definicoes da Lista de Adjacencia que monta meu grafo
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef GRAFO_HPP
#define GRAFO_HPP
#include<iostream>

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
void bubbleSort();
};





#endif