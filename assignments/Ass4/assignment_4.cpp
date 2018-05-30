//Jim Vargas
//CS162 Programming Assignment 3
//5/12/2018

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
void newAnimalGui(const char []);
void searchGui(pet [], int&);
void guiIn(int&, const char[]);
void commitAnimal(const char[], pet);
//void readFile(const char[], pet[], int&);
void prelim(const char[], int&);
//void displayAll(pet[], int);
//void searchType(pet[], int);


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
/*pet newPet()
{
	pet p;

	cout << "\nWhat is this animal's type?\n>>>";
	cin.get(p.type, SMALL, '\n');
	ignoreBuffer();

	cout << "What is this animal's breed?\n>>>";
	cin.get(p.breed, SMALL, '\n');
	ignoreBuffer();

	do
	{
		cout << "Is the animal friendly with other animals? Enter [Y/N]\n>>>";
		p.tempA = cin.get();
		ignoreBuffer();
	} while (toupper(p.tempA) != 'Y' && toupper(p.tempA) != 'N');

	do
	{
		cout << "Is the animal friendly with children? Enter [Y/N]\n>>>";
		p.tempC = cin.get();
		ignoreBuffer();
	} while (toupper(p.tempC) != 'Y' && toupper(p.tempC) != 'N');

	cout << "Miscellaneous information?\n>>>";
	cin.get(p.misc, BIG), '\n';
	ignoreBuffer();

	cout << "Miscellaneous pros?\n>>>";
	cin.get(p.miscP, MED, '\n');
	ignoreBuffer();

	cout << "Miscellaneous cons?\n>>>";
	cin.getline(p.miscC, MED, '\n');
	ignoreBuffer();

	return p;
}*/



//General User Interface
bool gui()
{
	bool keepGoing = true;
	int choice = 0;

	int animalCount = 0;
	prelim(OUTFILE, animalCount);

	animalList masterList(animalCount);

//	cout << "\nTest for count: " << animalCount << " : " << masterList.getLength() << endl;

	guiIn(choice, "\nYou have a few options. Enter a number for the corresponding option to your choice:\n[0/else] to quit\n[1] to add new animals\n[2] to search existing animals\n>>>");
	switch (choice)
	{
		case 0:
			cout << "Quitting...\n";
			keepGoing = false;
			break;
		case 1: 
			//add some new animals
            newAnimalGui("\nEnter how many animals you want to enter in this one go. You can come back and enter more animals in on the next loop. How many animals to add?\n>>>");
			break;
		case 2:
			//searchGui(masterList, animalCount);
			break;
		default:
			cout << "Quitting...\n";
			keepGoing = false;
			break;
	}
	return keepGoing;
}



//Interface for creating a new animal
void newAnimalGui(const char m[] )
{
	bool keepGoing = true;
    int animalCount = 0;
    guiIn(animalCount, m);

    animalList additionList(animalCount);

	cout << "\nNow, a new animal. Please do not leave fields blank.";
    //pet p = newPet();

	/*while (keepGoing)
	{
		pet p = newPet();
		int choice;

		cout << "\nAnimal in queue: " << p.breed << endl;
		guiIn(choice, "Do you want to commit this animal to the pet repository? Enter\n[0/else] to return to the main menu\n[1] to commit animal\n[2] to try again\n>>>");
		switch (choice)
		{
			case 0:
				keepGoing = false;
				break;
			case 1:
				cout << "\nWriting...";
				commitAnimal(OUTFILE, p);
				ml[count] = p;
				++count;
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
	}*/
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
/*void searchType(pet ml[], int c)
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
}*/












