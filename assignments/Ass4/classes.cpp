#include "classes.h"


//constructor
animalList::animalList()
{
	length;
	
	return;
}



//real constructor
animalList::animalList(int size)
{
	length = size;
    list = new pet[size];
	return;
}



//destructor
animalList::~animalList()
{
	for (int i=0; i<length; ++i)
    {
        delete [] list[i].type;
        delete [] list[i].breed;
        delete list[i].tempA;
        delete list[i].tempC;
        delete [] list[i].misc;
        delete [] list[i].miscP;
        delete [] list[i].miscC;
    }
    delete [] list;

	return;
}



//copy constructor
/*animalList::animalList(const animalList & other):
    list(other.getList()), length(other.getLength)
{
    return;
}*/



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
		<< "type: " << list[x].type << endl
		<< "breed: " << list[x].breed << endl
		<< "friendly with animals: " << list[x].tempA << endl
		<< "friendly with children: " << list[x].tempC << endl
		<< "miscellaneous info: " << list[x].misc << endl
		<< "pros: " << list[x].miscP << endl
		<< "cons: " << list[x].miscC << endl
		<< endl;
	
	return;
}



//getter for length
int animalList::getLength(void)
{
	return this->length;
}



//getter for list
pet** animalList::getList(void)
{
	return &list;
}






