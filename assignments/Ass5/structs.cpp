// Jim Vargas


#include "structs.hpp"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;



//Convinient thing for ignoring the entire buffer
void ignoreBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}



//New Question from scratch
node *newQuestion()
{
    char temp[MAX];
    node *newOne = new node;
    question *newQ = new question;
    newOne->q = newQ;
    newOne->next = NULL;
    newOne->previous = NULL;

    //topic
    cout << "\nWhat is the topic?\n>>>";
    cin.get(temp, MAX, '\n');
    ignoreBuffer();

    newOne->q->topic = new char[strlen(temp)+1];
    strcpy(newOne->q->topic, temp);

    //location
    cout << "\nWhere is this information located in the text?\n>>>";
    cin.get(temp, MAX, '\n');
    ignoreBuffer();

    newOne->q->location = new char[strlen(temp)+1];
    strcpy(newOne->q->location, temp);

    //prompt
    cout << "\nWhat is the question prompt?\n>>>";
    cin.get(temp, MAX, '\n');
    ignoreBuffer();

    newOne->q->prompt = new char[strlen(temp)+1];
    strcpy(newOne->q->prompt, temp);


    return newOne;
}



//New Question, to append somewhere in an established LLL
node *newQuestion(
        const char givenTopic[],
        const char givenLocation[],
        const char givenPrompt[],
        node *givenNext, node *givenPrevious
    )
{
    //pointer fields
    node * newOne = new node;
    question * newQ = new question;
    newOne->q = newQ;
    newOne->next = givenNext;
    newOne->previous = givenPrevious;

    //question specific fields
    newOne->q->topic = new char[strlen(givenTopic)+1];
    strcpy(newOne->q->topic, givenTopic);

    newOne->q->location = new char[strlen(givenLocation)+1];
    strcpy(newOne->q->location, givenLocation);

    newOne->q->prompt = new char[strlen(givenPrompt)+1];
    strcpy(newOne->q->prompt, givenPrompt);


    return newOne;
}



//Connect two given nodes
void connectNodes(node * first, node * second)
{
    first->next = second;
    second->next = NULL;
    second->previous = first;


    return;
}



//Go through a full quiz over all questions in the LLL
void fullQuiz(node * head)
{
    if (head!=NULL)
    {
        node * current = head;
        int counter = 1;
        while (current != NULL)
        {
            cout << "\nQuestion " << counter << ":";
            displayQuestion(current);
            current = current->next;
            counter++;
        }
        cout << "\nEnd of test.\n";
    } else
        cout << "\nThe list is empty.\n";

    return;
}



//Displays one question
void displayQuestion (node * given)
{
    cout << "\nTopic: " << given->q->topic
        << "\nSee in the book: " << given->q->location
        << endl << given->q->prompt << endl;


    return;
}



//Remove given node from the list
//Needs a given node and a fundamental source pointer in order to kill the head node
void killQuestion(node * given, node * seed)
{
    //To way traversibility

    //this case is for the middle
    if (given->previous !=NULL  &&  given->next !=NULL)
    {
        //reconnect
        given->previous->next = given->next;
        given->next->previous = given->previous;

        //disconnect
        given->next = NULL;
        given->previous = NULL;

        washSingle(given);
    }

    //this case is for the end
    else if (given->previous !=NULL && given->next ==NULL)
    {
        given->previous->next = NULL;
        given->previous = NULL;

        washSingle(given);
    }

    //this case is for the beginning, head 
    else if (given->previous ==NULL && given->next !=NULL)
    {
        node * temp = seed; 
        //seed->next->previous = NULL;
        seed = seed->next;

        //wash the first question and node
        washSingle(temp);

        seed->previous = NULL;
    }

    //this case is for if there's only a head node
    else if(given->previous ==NULL && given->next ==NULL)
        washSingle(given);

    //remaining case is a null node, or something very spooky
    else
        cout << "This is a null node\n";

    return;
}



//clears all of the dynamic memory of a single node
void washSingle(node * given)
{
    delete [] given->q->topic;
    delete [] given->q->location;
    delete [] given->q->prompt;

    delete given->q;
    delete given;


    return;
}







