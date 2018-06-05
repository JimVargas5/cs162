// Jim Vargas
// CS162 Programming Assignment 5
// 6/??/2018

/*
   This program acts like a little quizzer thing;
   Questions on Linear-Linked-Lists can be taken, questions can be added, and so on.
   This program does not support permanent-database capabilities yet, but the idea lends itself to this sort of concept. 
 */


#include <limits>
#include <iostream>
#include "structs.hpp"

using namespace std;


bool gui(void);
void guiIn(int&, const char[]);


int main()
{
    bool gui();
    while (gui());

    return 0;
}



//Main General User Interface
bool gui()
{
    bool keepGoing = true;
    int choice = 0;

    guiIn(choice, 
            "\n\nWelcome to this Linear-Linked-List quiz repository. You have a few options.Enter a number corresponding to your choice:\n[0/else] to quit\n[1] to take a random question\n[2] to make a new question\n[3] to search questions by topic\n[4] to display all question prompts\n>>>"
         );

    switch(choice)
    {
        case 0:
            cout << "Quitting...\n";
            keepGoing = false;
            break;
            //random question
        case 1:
            cout << "\nrando questo\n";
            break;
            //new question
        case 2:
            cout << "\nnew questo\n";
            break;
            //search questions by topic
        case 3:
            cout << "\nsearch\n";
            break;
            //display all questions
        case 4:
            cout << "\ndisplay all\n";
            break;
        default:
            cout << "Quitting...\n";
            keepGoing = false;
            break;
    }

    return keepGoing;
}



//Read in an integer choice selection
void guiIn(int &c, const char s[])
{
    cout << s;

    if (isdigit(cin.peek()))
        cin >> c;
    else
        c = 0;

    ignoreBuffer();


    return;
}











