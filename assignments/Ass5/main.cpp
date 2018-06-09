// Jim Vargas
// CS162 Programming Assignment 5
// 6/7/2018

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
void searchToKill(node*, node *);


int main()
{
    node * seed = generateSampleLLL();
	bool keepGoing = true;
    while (keepGoing)
	keepGoing = gui(seed);

    return 0;
}
//'seed' is the ultimate source of the built in LLL, the prime head pointer.
//This prime pointer, seed, is passed downwards into the GUI continuously.
//Ideally, the prime pointer is to be left alone.
//However, if the head, or first, node in the built in LLL is to be removed, 
//  then seed here must be adjusted, not just its derivative copies.
//Likelwise, if a new node is to be placed at the front of the list, 
//  access to the prime pointer is necessary.
//As a consequence, seed must be passed all the way down.



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
            searchToKill(head, seed);
            break;
        //new question
        case 2:
            newQProcedure(head);
            break;
        //search questions by topic
        case 3:
            searchProcedure(head);
            break;
        //display all questions
        case 4:
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
    node * head = newQuestion("AAA", "you can't find this anywhere in the book", "How is the word 'poop' spelled?", NULL, NULL);
    node * second = newQuestion("ZZZ", "good luck kid", "This is to demonstrate functionality not meet design detail specifics.", NULL, NULL);
    node * third = newQuestion("ggg", "read my mind --(the creator)", "Actual quesitons can be implemented or added by the user later. There is functionality for this.", NULL, NULL);

    connectNodes(head, second);
    connectNodes(second, third);
    //connectNodes(third, head);

    
    return head;
}
 


//Go through the list to delete one node
void searchToKill(node * head, node * seed)
{
    node * current = head;
    int choice = 0;
    bool killedOne = false;

    //travers to the last node and go backwards
    while (current->next !=NULL)
        current = current->next;

    while (current->previous != NULL  && !killedOne)
    {
        displayQuestion(current);
        guiIn(choice, "\nDelete this question?\n[0/else] to keep\n[1] to delete\n>>>");

        //since both previous and next are kept track of, these will be preserved even though
        //I am iterating through the list with 'current'
        if (choice == 1)
        {
            killQuestion(current, seed);
            killedOne = true;
        }
        if (!killedOne)
            current = current->previous;
        else
            cout << "\nDeleted\n";
    }

    return;
}













