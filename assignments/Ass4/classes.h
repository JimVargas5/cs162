//Jim Vargas
//CS162 Programming Assignment 2
//May 2018

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
/*const int SMALL 41;
const int MED 101;
const int LARGE 201;*/


struct pet
{
    char *type = NULL;
	char *breed = NULL;
	char *tempA = NULL;
	char *tempC = NULL;
	char *misc = NULL;
	char *miscP = NULL;
	char *miscC = NULL;
};

class animalList
{
	public:
		animalList();
		animalList(int);
		~animalList();
        //animalList(const animalList& other);

		void displayAll();
		void displayOne(int);

		int getLength(void);
		pet** getList(void);
	private:
		int length;
		pet *list = NULL;
};






