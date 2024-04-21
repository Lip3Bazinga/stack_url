/*
 * TRABALHO 1 - Stack
 * Fernanda Sayuri Ikegami - 14570340
 * Filipe Pio Magalhães - 14756232
*/

#include <iostream>
#include <stack>

using namespace std;

class Url{
  private: 
    stack<string> previousPages;
    string currentPage;
    stack<string> posteriorPages;
  
  public: 
    void newPage(const string& newURL);
    void goBack();
    void goFoward();
    void getPage();
};
