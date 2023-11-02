//---------------------------------------------------------------------
// Arquivo	: main.cpp
// Conteudo	: programa de avaliação do trabalho
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#include <iostream>
#include "../include/grafo.hpp"


void uso()
//Descrição:imprime as opções de uso
//A saída é a impressão das opções de linhas de comando no makefile 
{
    std::cout<<  "\t b  \t  bubble sort \n" << std::endl;
    std::cout<<  " \t s \t  Selection Sort \n "<< std::endl;
    std::cout<<  " \t i \t  insertion sort \n "<< std::endl;
    std::cout<<  " \t q \t  quicksort  \n "<< std::endl;
    std::cout<<  " \t m \t  merge sort \n "<< std::endl;
    std::cout<<  " \t p \t  heapsort \n "<< std::endl;
    std::cout<<  " \t y \t  método próprio \n "<< std::endl;
   
}



int main(){
    // montagem do grafo
    int v; // Número de vértice
    
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

   /* switch (uso)
    {
    case "b":
        grafo.bubbleSort();
        break;
    
    default:
        break;
    }*/


    //grafo.bubbleSort();
    //grafo.imprimirGrafo();

    // // escolhe o método utilizado
    // char metodo;
    // std:: cin >> metodo;

    // if( metodo == -b ){
    //     //implementação do bubble sort 
    // }

    // if(metodo == -s) {
    //     // implementação selection sort
    // }

    // if(metodo == -i){
    //     // implementação insertion sort
    // }

    

    return 0;

}