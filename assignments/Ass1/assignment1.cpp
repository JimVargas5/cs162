//Jim Vargas
//CS162 Programming Assignment 1
//4/14/2018

/*
   This program will calculate the dimensions for a package given a package type and a fluid volume.
   It begins by prompting for a volume amount in fluid ounces, then for a packaging type. Four total types are available:
   'Cube,' 'Sphere,' 'Regular Cylinder,' 'Custom Cylinder.' Note that there are two 'cylinder' types.
   The program first converts the input volume from fluid ounces to cubed inches, and then calculates the corresponding one dimensional dimensions from that.
 */

#include <iostream>
#include <stdlib.h>
#include <tgmath.h>
using namespace std;

int runner(void);

int main()
{
	bool keepGoing = true;
	while (keepGoing)
	{
		int runner();
		if (runner() != 1)
		{
			keepGoing = false;
		}
	}		
	return 0;
}



//runner: runs the main functionality of the program. Contains all prompts, takes in all inputs, prints all outputs.
//This is run on a loop in main(). Returns condition for the loop.
int runner(void)
{
	/*
	   finalSay is the 'final say' the user gets, for whether they want the program to terminate or not or complete another loop. 
	   vol is inputted volume, convertDim is the converted volume. outputDim is a dimension that will be printed to the terminal.
	   customRadius and cylinderHeight are additional variables for cylindrical calculations.
	   inputChoice and inputChoice2 correspond to the user's choice given prompted options. Two are used to avoid overlap.
	   flCi is the conversion constant from fluid ounces to cubic inches.
	 */
	int finalSay;
	float vol, outputDim, convertDim, customRadius, cylinderHeight;
	int inputChoice, inputChoice2;
	const float PI = 3.1415925635897;
	const float FL_CI = 1.80469;

	cout << "\n\n\nWelcome. Enter a liquid amount, in fluid ounces, and this program will determine the packaging dimensions needed to contain that fluid."
		<< " This program uses inches and fluid ounces."  
		<< " You will get to choose between three package types: cubic, cylindric and spheric." 
		<< " Please follow the instructions that follow.\n\n";

	cout << "Enter the amount of fluid, in fluid ounces, that you need to package. Enter a number only:\n\n>>>";
	cin >> vol;
	if (cin)
	{
		//convert to apropriate units
		convertDim = vol * FL_CI;
		cin.ignore();

		cout << "\nNow, choose a package type. Enter a corresponding number:\n" 
			<< "Enter [1] for a cube type.\n"
			<< "Enter [2] for a cylinder type.\n"
			<< "Enter [3] for a sphere type.\n"
			<< "Enter anything else to quit.\n\n>>>";

		cin >> inputChoice;
		cin.ignore();

		//switch cases for various package types
		switch (inputChoice)
		{
			//Cube
			case 1: 
				cout << "\nCube Type with " << vol << " fl oz.";
				outputDim = cbrtf(convertDim);
				cout << "\n\nFinal dimensions: " << outputDim << " inches on each length.\n";
				break;
			//Cylinder
			case 2:
				cout << "\nNow, choose your type of cylinder. "
					<< "'Regular' cylinders are twice as tall as they are wide; height is twice diameter. "
					<< "'Custom' cylinders are those which you enter a radius, and height will be calculated\n"
					<< "Enter [1] for a regular cylinder.\n"
					<< "Enter [2] for a custom cylinder.\n"
					<< "Enter anything else to quit.\n\n>>>";

				cin >> inputChoice2;
				cin.ignore();
				switch (inputChoice2)
				{
					//Regular Cylinder
					case 1:
						cout << "\nRegular cylinder with " << vol << " fl oz.";
						outputDim = cbrtf((convertDim / (4.0*PI)));
						cylinderHeight = outputDim * 4.0;
						cout << "\n\nFinal dimensions: " << outputDim << " inch radius with a " << cylinderHeight << " inch height.\n";		
						break;
					//Custom Cylinder
					case 2:
						cout << "\nEnter a radius for the custom cylinder. n\n>>>";
						cin >> customRadius;
						cin.ignore();
						cout << "\nCusom cylinder with " << vol << " fl oz and a " << customRadius << " inch radius.";
						cylinderHeight = convertDim / (PI * powf(customRadius, 2.0));
						cout << "\n\nFinal dimensions: " << customRadius << " inch radius with a " << cylinderHeight << " inch height.\n";
						break;
					default:
						exit(0);
						break;
				}
				break;
			//Sphere
			case 3: 
				cout << "\nSphere Type with "<< vol << " fl oz.";
				outputDim = cbrtf((.75*(convertDim/PI)));
				cout << "\n\nFinal dimensions: " << outputDim << " inch radius for the sphere.\n";
				break;
			default:
				exit(0);
				break;
		}
	}
	else
	{
		//TODO: Input validation? Difficult to do without strings
		cout << "There was a problem with your input." << endl;
		cin.clear();
		cin.ignore();
	}
	
	//loop in main() conditional; loop repeats iff next input == 1
	cout << "\nDo another round? Enter[1] to continue, otherwise the program will quit.\n\n>>>";
	cin >> finalSay;
	return finalSay;		
}





//poop
