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
node * generateSampleLLL(void);


int main()
{
    /*
    node * tempHead = newQuestion("poop", "nowhere", "how do you spell poop", NULL, NULL);
    node * tempSecond = newQuestion("test", "nowhere", "how do you spell test", NULL, NULL);
    connectNodes(tempHead, tempSecond);

    cout << "\ntest for null capabilities " << tempHead->q->topic << endl;
    cout << "\n here's johnny " << tempHead->next->q->prompt << endl;
    */

    bool gui();
    while (gui());

    return 0;
}



//Main General User Interface
bool gui()
{
    bool keepGoing = true;
    int choice = 0;
    node * head = generateSampleLLL();

    guiIn(choice, 
            "\n\nWelcome to this Linear-Linked-List quiz repository. You have a few options.Enter a number corresponding to your choice:\n[0/else] to quit\n[1] to delete a question\n[2] to make a new question\n[3] to search questions by topic\n[4] to display the contents of all questions\n>>>"
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
            fullQuiz(head);
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



//Generate a sample LLL with some built in questions.
//This will allow the user to start with a test instead of having to make some questions.
node * generateSampleLLL(void)
{
    node * head = newQuestion("A there is no topic", "you can't find this anywhere in the book", "How is the word 'poop' spelled?", NULL, NULL);
    node * second = newQuestion("B another test", "good luck kid", "This is to demonstrate functionality not meet design detail specifics.", NULL, NULL);
    node * third = newQuestion("B another test", "read my mind --(the creator)", "Actual quesitons can be implemented or added by the user later. There is functionality for this.", NULL, NULL);

    connectNodes(head, second);
    connectNodes(second, third);

    
    return head;
}






