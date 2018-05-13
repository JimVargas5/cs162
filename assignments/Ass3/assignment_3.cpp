//Jim Vargas
//CS162 Programming Assignment 3
//5/12/2018

//general stuff here

#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>

using namespace std;


const int SIZE = 201;
const char file[] = "animals.txt";

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



int main()
{
	pet p = newPet();
	cout << "Test: " << p.breed << endl;

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
	ignore();

	cout << "What is this animal's breed?\n>>>";
	cin.getline(p.breed, SIZE);
	ignore();

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
	ignore();

	cout << "Miscellaneous pros?\n>>>";
	cin.getline(p.miscP, SIZE);
	ignore();

	cout << "Miscellaneous cons?\n>>>";
	cin.getline(p.miscC, SIZE);
	ignore();

	return p;
}






