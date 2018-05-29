#include "classes.h"


//constructor
animalList::animalList()
{
	int length = 0;
	
	return;
}



//real constructor
animalList::animalList(int size)
{
	int length = size;
	pet *list = new pet[size];
	return;
}



//destructor
animalList::~animalList()
{
	for (int i=0; i<length; ++i)
		delete list[i];

	return;
}



//show all of the pets
void animalList::displayAll()
{
	for (int i=0; i<length; ++i)
		displayOne(i);

	return;
}



//show the pet at a given index
void animalList::displayOne(int x)
{
	cout << "\nAnimal " << (x+1) << ":\n"
		<< "type: " << list[x]->type << endl
		<< "breed: " << list[x]->breed << endl
		<< "friendly with animals: " << list[x]->tempA << endl
		<< "friendly with children: " << list[x]->tempC << endl
		<< "miscellaneous info: " << list[x]->misc << endl
		<< "pros: " << list[x]->miscP << endl
		<< "cons: " << list[x]->miscC << endl
		<< endl;
	
	return;
}




