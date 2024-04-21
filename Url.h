/*
 * TRABALHO 1 - Stack
 * Fernanda Sayuri Ikegami - 14570340
 * Filipe Pio Magalhães - 14756232
*/

#include <iostream>
#include <stack>

using namespace std;

#ifndef URL_H
#define URL_H


class Url{ // Declaração/Interface para programa
  private: 
    stack<string> previousPages; // Pilha para armazenar as páginas anteriores
    string currentPage; // String para armazenar a página atual
    stack<string> posteriorPages; // Pilha para armazenar as páginas posteriores
  
  public: 
    void newPage(const string& newURL); // Método para adicionar uma nova página
    void goBack(); // Método para voltar para a página anterior
    void goFoward(); // Método para avançar para a página seguinte
    void getPage(); // Método para exibir a página atual
};

#endif // URL_H