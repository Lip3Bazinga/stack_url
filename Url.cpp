/*
 * TRABALHO 1 - Stack
 * Fernanda Sayuri Ikegami - 14570340
 * Filipe Pio Magalhães - 14756232
*/

#include <iostream>
#include "Url.h"
#include <cctype>

using namespace std;



void Url::newPage(const string& newUrl){ // Método para adicionar uma nova página.

  // Verifica se há uma página atual
  if(!currentPage.empty()){
    previousPages.push(currentPage); // Empilha a página atuaal nas páginas anteriores
    while(!posteriorPages.empty()){
      posteriorPages.pop(); // Limpa as páginas seguintes
    }
  }
  
  currentPage = newUrl; // Define a nova página como a página atual

}


void Url::goBack(){ // Método para voltar para a página anterior
  if(!previousPages.empty()){ // Verifica se há páginas anteriores
    posteriorPages.push(currentPage); // Empilha a página atual nas páginas seguintes
    currentPage = previousPages.top(); // Define a página anterior como a página atual
    previousPages.pop(); // Remove a página anterior da pilha de páginas anteriores
  }else{
    cout << "\nNão existem páginas anteriores\n";
  }
}

void Url::goFoward(){ // Método para avançar para a página seguinte
  if(!posteriorPages.empty()){
    previousPages.push(currentPage); // Empilha a página atual nas páginas anteriores
    currentPage = posteriorPages.top();  // Define a página seguinte como a página atual
    posteriorPages.pop();  // Remove a página seguinte da pilha de páginas seguintes
  }else{
    cout << "\nNão existem páginas posteriores\n";
  }
}

void Url::getPage(){ // Método para exibir a página atual
  cout << "Página atual: " << currentPage << endl;
}

int main(){ // Função principal

  string option; // Variável auxiliar para armazenar qual função o usuário quer chamar
  Url url; // Instanciação do objteto url da classe Url
    
  cout << "\n===== MENU ====\nDigite NEW para nova página)\nDigite BACK para voltar a página anterior)\nDigite FOWARD para avançar a página seguinte)\nDigite EXIT para sair)";

  while (true) { // Loop principal
    cout << "\n> ";    

    cin >> option;

    if(option == "NEW"){ // Verifica a opção escolhida pelo usuário
      string newUrl;
      cout << "Digite a nova página: ";
      cin >> newUrl;
      url.newPage(newUrl); // Chama o método para adicionar uma nova página
      url.getPage(); // Chama o método para exibir a página atual
    }else if(option == "BACK"){
      url.goBack(); // Chama o método para voltar página 
      url.getPage(); // Chama o método para exibir a página atual
    }else if(option == "FOWARD"){
      url.goFoward(); // Chama o método para avançar página
      url.getPage(); // Chama o método para exibir a página atual
    }else if(option == "EXIT"){
      cout << "\nObrigado por navegar conosco (: \nSaindo...";
      break;
    }else{
      cout << "Erro: entrada inválida. Por favor, entre com um dos comandos informados acima, em maiúscula.";
    }
  }

  return 0;

}
