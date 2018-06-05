// Jim Vargas


#include "structs.hpp"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;



void ignoreBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}



node *newQuestion()
{
    char temp[MAX] = {0};
    node *newOne = new node;

    cout << "\nWhat is the topic?\n>>>";
    cin.get(temp, MAX, '\n');
    ignoreBuffer();
    newOne->q->topic = new char[strlen(temp)+1];
    strcpy(newOne->q->topic, temp);


    return newOne;
}






