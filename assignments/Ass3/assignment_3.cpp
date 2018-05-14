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


const int SIZE = 201;
const char OUTFILE[] = "animals.txt";

struct pet
{
	char type[SIZE];
	char breed[SIZE];
	char tempA;
	char tempC;
	char misc[SIZE];
	char miscP[SIZE];
	char miscC[SIZE];
};

void ignore(void);
pet newPet(void);
bool gui(void);
void newAnimal(void);
void searchGui(void);
void guiIn(int&, const char[]);


int main()
{
	//pet p = newPet();
	//cout << "Test: " << p.breed << endl;

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
	cin.getline(p.type, SIZE);
	//ignore();

	cout << "What is this animal's breed?\n>>>";
	cin.getline(p.breed, SIZE);
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
	cin.getline(p.misc, SIZE);
	//ignore();

	cout << "Miscellaneous pros?\n>>>";
	cin.getline(p.miscP, SIZE);
	//ignore();

	cout << "Miscellaneous cons?\n>>>";
	cin.getline(p.miscC, SIZE);
	//ignore();

	return p;
}



//General User Interface
bool gui()
{
	bool keepGoing = true;
	int choice = 0;
	guiIn(choice, "\n\nWelcome to the pet database. You have a few options. Enter a number for the corresponding option to your choice:\n[0/else] to quit\n[1] to add a new animal\n[2] to search existing animals\n>>>");
	switch (choice)
	{
		case 0:
			cout << "Quitting...\n";
			keepGoing = false;
			break;
		case 1: 
			newAnimal();
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
void newAnimal()
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
				cout << "\nwriting pet test\n";

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





