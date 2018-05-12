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
	//stuff	

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
	cin.get(p.type, SIZE, '\n');
	ignore();

	cout << "What is this animal's breed?\n>>>";
	cin.get(p.breed, SIZE, '\n');
	ignore();

	cout << "Is the animal friendly with other animals?\n>>>";
	p.tempA = cin.get();
	ignore();

	cout << "Is the animal friendly with children?\n>>>";
	p.tempC = cin.get();
	ignore();

	cout << "Miscellaneous information?\n>>>";
	cin.get(p.misc, SIZE, '\n');
	ignore();

	cout << "Miscellaneous pros?\n>>>";
	cin.get(p.miscP, SIZE, '\n');
	ignore();

	cout << "Miscellaneous cons?\n>>>";
	cin.get(p.miscC, SIZE, '\n');
	ignore();

	return p;
}






