//Jim Vargas
//CS162 Programming Assignment 4
//5/31/2018

//This program will function as a sort of 'proof of concept' databse via command line prompts and saving data to text documents. 
//The specific theme of this primitive database will involve pets; a user, wishing to store and retrieve information about various animals will be able to use this program to do so.


#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>
#include "classes.h"

using namespace std;

const int BIG = 201;
const int MED = 101;
const int SMALL = 41;
const char OUTFILE[] = "animals.txt";

/*struct pet
  {
  char type[SMALL];
  char breed[SMALL];
  char tempA;
  char tempC;
  char misc[BIG];
  char miscP[MED];
  char miscC[MED];
  };*/

void ignoreBuffer(void);
pet newPet(void);
bool gui(void);
void newAnimalGui(void);
void searchGui(pet [], int&);
int guiIn(const char []);
void commitAnimal(const char [], pet);
//void readFile(const char[], pet[], int&);
void prelim(const char [], int&);
//void displayAll(pet[], int);
//void searchType(pet[], int);
//void dynamicAlloc(char * a[], char b[], int);
void clearLetters(char []);


int main()
{
    bool gui();
    while (gui());

    return 0;
}



//Convinient way to ignore the entire buffer
void ignoreBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}



//Create a new pet with fields
pet newPet()
{
    pet p;
    char big[BIG] = {0};
    char med[MED] = {0};
    char small[SMALL] = {0};
    char anA, anC;

    cout << "\nWhat is this animal's type?\n>>>";
    cin.get(small, SMALL, '\n');
    ignoreBuffer();
    p.type = new char[strlen(small)];
    strcpy(p.type, small);

    cout << "What is this animal's breed?\n>>>";
    cin.get(med, SMALL, '\n');
    ignoreBuffer();
    p.breed = new char[strlen(med)];
    strcpy(p.breed, med);

    do
    {
        cout << "Is the animal friendly with other animals? Enter [Y/N]\n>>>";
        anA = cin.get();
        ignoreBuffer();
        p.tempA = &anA;
    } while (toupper(anA) != 'Y' && toupper(anA) != 'N');

    do
    {
        cout << "Is the animal friendly with children? Enter [Y/N]\n>>>";
        anC = cin.get();
        ignoreBuffer();
        p.tempC = &anC;
    } while (toupper(anC) != 'Y' && toupper(anC) != 'N');

    cout << "Miscellaneous information?\n>>>";
    cin.get(big, BIG, '\n');
    ignoreBuffer();
    p.misc = new char[strlen(big)];
    strcpy(p.misc, big);

    cout << "Miscellaneous pros?\n>>>";
    cin.get(med, MED, '\n');
    ignoreBuffer();
    p.miscC = new char[strlen(med)];
    strcpy(p.miscC, big);

    cout << "Miscellaneous cons?\n>>>";
    cin.get(med, MED, '\n');
    ignoreBuffer();
    p.miscP = new char[strlen(med)];
    strcpy(p.miscC, med);

    return p;
}



//General User Interface
bool gui()
{
    bool keepGoing = true;
    int choice = 0;

    int animalCount = 0;
    prelim(OUTFILE, animalCount);

    animalList masterList(animalCount);

    //cout << "\nTest for count: " << animalCount << " : " << masterList.getLength() << endl;

    cout << "\n\nWelcome. There are currently " << masterList.getLength() << " animal(s) already on record.\n";
    masterList.displayAll();

    choice = guiIn("\nYou have a few options. Enter a number for the corresponding option to your choice:\n[0/else] to quit\n[1] to add new animals\n[2] to search existing animals\n>>>");

    //cout << "\nmanually enter a switch choice\n";
    //ignoreBuffer();
    //cin >> choice;
    //ignoreBuffer();
    //cout << "\nchoice test: " << choice << " this happens right before the switch!\n";

    switch (choice)
    {
        case 0:
            cout << "Quitting...\n";
            keepGoing = false;
            break;
        case 1: 
            //add some new animals
            //cout << "new animal\n";
            newAnimalGui();
            break;
        case 2:
            //searchGui(masterList, animalCount);
            cout << "some stuff\n";
            break;
        default:
            cout << "Quitting...\n";
            keepGoing = false;
            break;
    }
    //cout << "did I get past the switch?";
    return keepGoing;
}



//Interface for creating a new animal
void newAnimalGui(void)
{
    bool keepGoing = true;
    int addCount = guiIn("\nEnter how many animals you want to enter in this one go. You can come back and enter more animals in on the next loop. How many animals to add?\n>>>");
    //int x;
    //cout << "\nEnter a number\n";
    //cin >> x;
    //ignoreBuffer();
    cout << "Here's the number: " << addCount << endl;

    //cout << "\nDid I make it out alive?\n";
    animalList additionList(addCount);

    //cout << "\nNow, a new animal. Please do not leave fields blank.";
    //pet p = newPet();

    while (keepGoing)
    {
        for (int i=0; i<additionList.getLength(); ++i)
        {
            cout << "\nAnimal number " << i+1 << ":";
            //&(  (*(additionList.getList()))[i]  ) = new pet;
            (*(additionList.getList()))[i] = newPet();
            /*memmove(
                &(
                    (*(additionList.getList()))[i]
                ), &p, sizeof(p)
            );*/
            
            cout << "\nseg test \n";
        }
        //int choice;

        cout << "\nThere are now animals in queue: " << additionList.getLength() << endl;
        int choice = guiIn("Do you want to commit these animals to the pet repository? Enter\n[0/else] to return to the main menu\n[1] to commit animals\n[2] to try again\n>>>");
        switch (choice)
        {
            case 0:
                keepGoing = false;
                break;
            case 1:
                cout << "\nWriting...\nAnimals committed:";
                //for (int i=0; i<additionList.getLength(); ++i)
                  //  cout << (*(additionList.getList()))[i].breed << endl;
                //commitAnimal(OUTFILE, p);
                //ml[count] = p;
                //++count;

                cout << " It is written. Returning to the main meu.";

                keepGoing = false;
                break;
            case 2:
                cout << "Doing it over...";
                break;
            default:
                keepGoing = false;
                break;
        }
    }

    cout << "\ndestroying additionList... \n";
    additionList.~animalList();

    return;
}




//Search general user interface
/*void searchGui(pet ml[], int &c)
  {
  int choice;
  bool keepGoing = true;

  while (keepGoing)
  {
  guiIn (choice, "\nYou can display all animals, or search for a specific animal by type. Enter\n[0/else] to return to the main menu\n[1] to display all animals\n[2] to search by animal type\n>>>");
  switch (choice)
  {
  case 0:
  keepGoing = false;
  break;
  case 1:
//displayAll(ml, c);
break;
case 2:
//searchType(ml, c);
break;
default:
keepGoing = false;
break;
}
}
return;
}*/



//Read in an integer choice for GUI
int guiIn(const char s[])
{
    int x = 0;
    cout << s;
    //cout << "\nseg test 1\n";
    if (isdigit(cin.peek()))
    {
        //cout << "\nseg test if\n";
        cin >> x;
        //cout <<"\nx test: " << x;
        //cout << "\nseg test if 2\n";
    }
    else
    {
        //cout << "\nseg test else\n";
        x = 0;
        //cout << "\nseg test else 2\n";
    }
    //cout << "\nseg test 2\n";
    //cin.clear();
    ignoreBuffer();
    //cin.ignore(100, '\n');
    //cout << "\nseg test 3\n";

    return x;
}



//Commit an animal to the Master List
/*void commitAnimal(const char f[], pet p)
  {
  ofstream out;
  out.open(f, ios::app);

  if (out)
  {
  out << endl 
  << p.type << ":" 
  << p.breed << ":" 
  << p.tempA << ":" 
  << p.tempC << ":" 
  << p.misc << ":" 
  << p.miscP << ":" 
  << p.miscC;

  out.close();
  out.clear();
  }
  return;
  }*/



//Preliminary count of how many animals are already in the repository
void prelim(const char f[], int &count)
{
    ifstream fileIn;
    fileIn.open(f);

    //int i = 0;
    while (fileIn && !fileIn.eof())
    {
        /*pet temp;
          ml[i] = temp;
          fileIn.get(ml[i].type, SMALL, ':');
          fileIn.ignore(200, ':');

          fileIn.get(ml[i].breed, SMALL, ':');
          fileIn.ignore(200, ':');

          fileIn >> ml[i].tempA;
          fileIn.ignore(200, ':');

          fileIn >> ml[i].tempC;
          fileIn.ignore(200, ':');

          fileIn.get(ml[i].misc, BIG, ':');
          fileIn.ignore(200, ':');

          fileIn.get(ml[i].miscP, MED, ':');
          fileIn.ignore(200, ':');

          fileIn.get(ml[i].miscC, MED, '\n');
          fileIn.ignore();*/
        if (fileIn.get() == '\n')
            ++count;
        //cout << "\ni test: " << i << endl;
        //++i;
    }
    //cout << "\ncount test when counting: " << count << endl;
    fileIn.close();

    return;
}



//Display everything in the Master List
/*void displayAll(pet ml[], int count)
  {
  for (int i=0; i<count; ++i)
  {
  cout << "\nAnimal " << (i+1) << ":\n"
  << "type: " << ml[i].type << endl
  << "breed: " << ml[i].breed << endl
  << "friendly with animals: " << ml[i].tempA << endl
  << "friendly with children: " << ml[i].tempC << endl
  << "miscellaneous info: " << ml[i].misc << endl
  << "pros: " << ml[i].miscP << endl
  << "cons: " << ml[i].miscC << endl
  << endl;
  }
  return;
  }*/



//Search Master List for pets by type
void searchType(pet ml[], int c)
  {
  char searchTerm[SMALL];
  cout << "\nThis is a manual search by animal TYPE. Enter your animal type search term, and be VERY specific.\n>>>";
  cin.getline(searchTerm, SMALL);

  cout << "\nMatches for search term " << searchTerm << endl << endl;
  for (int i=0; i<c; ++i)
  {
  if (strcmp(searchTerm, ml[i].type) == 0)
  {
  cout << "Animal " << (i+1) << ": " << endl 
  << "breed: " << ml[i].breed << endl
  << "friendly with animals: " << ml[i].tempA << endl
  << "friendly with children: " << ml[i].tempC << endl
  << "miscellaneous info: " << ml[i].misc << endl
  << "pros: " << ml[i].miscP << endl
  << "cons: " << ml[i].miscC << endl
  << endl;
  }	
  }
  return;
  }



//Dynamically allocate an array of characters
/*void dynamicAlloc(char *given[], char dest[], int max)
{
    //given is the temporary string, dest is the string to dynamically allocate
    cin.get(*given, max, '\n');
    ignoreBuffer();

    dest = new char[strlen(*given)];

    for (int i=0; i<strlen(*given); ++i)
        given[i] = 0;

    return;
}*/










