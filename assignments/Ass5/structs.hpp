// Jim Vargas
// this kind of node has forward and backwards traversibility

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
    node * previous;
    question * q;
};



void ignoreBuffer(void);
node *newQuestion(void);
node *newQuestion(const char t[], const char l[], const char p[], node *n, node *prev);
void connectNodes(node *, node *);
void displayQuestion(node*);
void fullQuiz(node*);
void killQuestion(node*, node*);
void washSingle(node *);
void newQProcedure(node*);
void commitQ(node*, node*);
void searchProcedure(node *);






