// Jim Vargas
// CS162 Programming Assignment 5
// 6/??/2018

#include <limits>
#include <iostream>
#include "structs.hpp"

using namespace std;


int main()
{
    cout << "\nmain test\n";
    //ignoreBuffer();

    node * head = newQuestion();
    cout << head->q->topic << endl;
    cout << "\nall done\n";
    ignoreBuffer();
    cin.clear();

    
    delete head;

    return 0;
}





