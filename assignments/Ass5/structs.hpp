// Jim Vargas


const int MAX = 100;

struct question
{
    char * topic;
    char * location;
    char * prompt;
};



struct node
{
    node * next;
    question * q;
};



void ignoreBuffer(void);
node *newQuestion(void);







