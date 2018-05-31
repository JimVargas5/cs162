
#include <iostream>
#include "classes.h"

using namespace std;

int blah()
{
    cout << "\n\nTo conduct a test\n";

    cout << "\nCreating an animalList object...";
    animalList testList(5);
    cout << "\nMade. Testing it's lenght: should be 5...";
    cout << endl << testList.getLength() << endl << "Now enter a number:\n";

    int temp;
    cin >> temp;
    cin.clear();
    cin.ignore(100,'\n');

    cout << "\nread in number. ";
    cout << temp << endl;

    cout << "\ncalling destructor...";

    testList.~animalList();
    cout << "\n called destructor on the testList";

    cout << "\nWe made it.\n";


    
    return 0;
}








