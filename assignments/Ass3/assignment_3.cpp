//Jim Vargas
//CS162 Programming Assignment 3
//5/12/2018

//This program will function as a sort of 'proof of concept' databse via command line prompts and saving data to text documents. 
//The specific theme of this primitive database will involve pets; a user, wishing to store and retrieve information about various animals will be able to use this program to do so.


#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>

using namespace std;


const int BIG = 201;
const int MED = 101;
const int SMALL = 41;
const char OUTFILE[] = "animals.txt";

struct pet
{
	char type[SMALL];
	char breed[SMALL];
	char tempA;
	char tempC;
	char misc[BIG];
	char miscP[MED];
	char miscC[MED];
};

void ignore(void);
pet newPet(void);
bool gui(void);
void newAnimal(pet[], int&);
void searchGui(void);
void guiIn(int&, const char[]);
void commitAnimal(const char[], pet);
void readFile(const char[], pet[], int&);
void displayAll(pet[], int);


int main()
{
	bool gui();
	while (gui());

	return 0;
}



//Convinient way to ignore the entire buffer
void ignore()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return;
}



//Create a new pet with fields
pet newPet()
{
	pet p;

	cout << "\nWhat is this animal's type?\n>>>";
	cin.getline(p.type, SMALL);
	//ignore();

	cout << "What is this animal's breed?\n>>>";
	cin.getline(p.breed, SMALL);
	//ignore();

	do
	{
		cout << "Is the animal friendly with other animals? Enter [Y/N]\n>>>";
		p.tempA = cin.get();
		ignore();
	} while (toupper(p.tempA) != 'Y' && toupper(p.tempA) != 'N');

	do
	{
		cout << "Is the animal friendly with children? Enter [Y/N]\n>>>";
		p.tempC = cin.get();
		ignore();
	} while (toupper(p.tempC) != 'Y' && toupper(p.tempC) != 'N');

	cout << "Miscellaneous information?\n>>>";
	cin.getline(p.misc, BIG);
	//ignore();

	cout << "Miscellaneous pros?\n>>>";
	cin.getline(p.miscP, MED);
	//ignore();

	cout << "Miscellaneous cons?\n>>>";
	cin.getline(p.miscC, MED);
	//ignore();

	return p;
}



//General User Interface
bool gui()
{
	bool keepGoing = true;
	int choice = 0;
	pet masterList[30];
	int animalCount = 0;
	readFile(OUTFILE, masterList, animalCount);

	displayAll(masterList, animalCount);

/*	cout << "\nCount test: " << animalCount;
	cout << "\nRead Test: " << masterList[0].type;
	cout << "\nAnother test: " << masterList[1].breed << " and " << masterList[1].miscC << endl;
	*/

	guiIn(choice, "\n\nWelcome to the pet database. You have a few options. Enter a number for the corresponding option to your choice:\n[0/else] to quit\n[1] to add a new animal\n[2] to search existing animals\n>>>");
	switch (choice)
	{
		case 0:
			cout << "Quitting...\n";
			keepGoing = false;
			break;
		case 1: 
			//if masterList not already full
			if (animalCount < 30)
				newAnimal(masterList, animalCount);
			else
				cout << "The master list is full, no more animals can be added to the database.\n";
			break;
		case 2:
			searchGui();
			break;
		default:
			cout << "Quitting...\n";
			keepGoing = false;
			break;
	}


	return keepGoing;
}



//Interface for creating a new animal
void newAnimal(pet ml[], int &count)
{
	bool keepGoing = true;
	cout << "\nNow, a new animal.";

	while (keepGoing)
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
	}

	return;
}




//Search interface
void searchGui()
{
	cout << "\nSearch test\n";
	return;
}



//Read in choice for GUI
void guiIn(int &c, const char s[])
{
	cout << s;
	if (isdigit(cin.peek()))
		cin >> c;
	else
		c = 0;
	//cout << "\nchoice test? " << c << endl;
	ignore();
	return;
}



//Commit an animal to the Master List
void commitAnimal(const char f[], pet p)
{
	ofstream out;
	out.open(f, ios::app);

	if (out)
	{
		out << p.type << ":" << p.breed << ":" << p.tempA << ":" << p.tempC << ":" << p.misc << ":" << p.miscP << ":" << p.miscC << endl;
		
		out.close();
		out.clear();
	}

	//add pet to the array of structs
	return;
}



//Read text file here
void readFile(const char f[], pet ml[], int &count)
{
	ifstream fileIn;
	fileIn.open(f);

	int i = 0;
	while (fileIn && !fileIn.eof())
	{
		pet temp;
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

		fileIn.get(ml[i].miscC, MED, ':');
		fileIn.ignore();
		++i;
	}
	count = i;
	fileIn.close();

	return;
}



//Display everything in the Master List
void displayAll(pet ml[], int count)
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
}




