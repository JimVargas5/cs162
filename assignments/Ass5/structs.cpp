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
    node * newOne = new node;
    question * newQ = new question;
    newOne->q = newQ;
    newOne->next = givenNext;
    newOne->previous = givenPrevious;

    newOne->q->topic = new char[strlen(givenTopic)+1];
    strcpy(newOne->q->topic, givenTopic);

    newOne->q->location = new char[strlen(givenLocation)+1];
    strcpy(newOne->q->location, givenLocation);

    newOne->q->prompt = new char[strlen(givenPrompt)+1];
    strcpy(newOne->q->prompt, givenPrompt);


    return newOne;
}






