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


bool gui(node *&);
void guiIn(int&, const char[]);
node * generateSampleLLL(void);
void searchToKill(node*);
//void newQProcedure(node*);


int main()
{
    node * seed = generateSampleLLL();
	bool keepGoing = true;
    while (keepGoing)
	keepGoing = gui(seed);

    return 0;
}



//Main General User Interface
bool gui(node * &seed)
{
    bool keepGoing = true;
    int choice = 0;
    
    node * head = seed;

    guiIn(choice, 
            "\n\n\nWelcome to this Linear-Linked-List quiz repository. You have a few options. Enter a number corresponding to your choice:\n[0/else] to quit\n[1] to delete a question\n[2] to make a new question\n[3] to search questions by topic\n[4] to display the contents of all questions\n>>>"
         );

    switch(choice)
    {
        case 0:
            cout << "Quitting...\n";
            keepGoing = false;
            break;
        //delete a question
        case 1:
            searchToKill(head);
            break;
        //new question
        case 2:
            newQProcedure(head);
            break;
        //search questions by topic
        case 3:
            cout << "\nsearch\n";
            break;
        //display all questions
        case 4:
            cout << "\nget to here\n";
            if (head!=NULL)
                fullQuiz(head);
            else
                cout << "\nThe list is emptly.\n";
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
    node * head = newQuestion("A", "you can't find this anywhere in the book", "How is the word 'poop' spelled?", NULL, NULL);
    node * second = newQuestion("B", "good luck kid", "This is to demonstrate functionality not meet design detail specifics.", NULL, NULL);
    node * third = newQuestion("C", "read my mind --(the creator)", "Actual quesitons can be implemented or added by the user later. There is functionality for this.", NULL, NULL);

    connectNodes(head, second);
    connectNodes(second, third);
    //connectNodes(third, head);

    
    return head;
}
 


//Go through the list to delete one node
void searchToKill(node * head)
{
    node * current = head;
    int choice = 0;
    bool killedOne = false;

    while (current != NULL  && !killedOne)
    {
        displayQuestion(current);
        guiIn(choice, "\nDelete this question?\n[0/else] to keep\n[1] to delete\n>>>");

        //since both previous and next are kept track of, these will be preserved even though
        //I am iterating through the list with 'current'
        if (choice == 1)
        {
            killQuestion(current);
            killedOne = true;
        }
        if (!killedOne)
            current = current->next;
        else
            cout << "\nDeleted\n";
    }

    return;
}













