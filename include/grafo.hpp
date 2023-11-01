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
    Node** listaAdj;
    int* cores;
public:
Grafo(int v);
~Grafo();
void adicionarAresta(int origem,int destino);
void imprimirGrafo();
void defineCor(int vertice, int cor);
void boobleSort(Node** listaAadj,int cor);
};





#endif