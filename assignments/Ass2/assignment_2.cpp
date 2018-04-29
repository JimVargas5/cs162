//Jim Vargas
//CS162 Programming Assignment 2
//4/31/2018

//Definition of terminology:
/*
MESSAGE: the sentence to be encrypted
BLOCK: the paragraph in which the message is seeded
SEED(ED): the process of encrypting the message in the block, described below.
 */


/*
   This program scrambles a sentence (message) within a paragraph (block).
   The idea is to encrypt the message text by 'hiding' it in the block.
   The encryption works as follows:
   The first letter in each word in the block is replaced by a letter in the message.
   This replacement occurs sequentially; the first word in the block gets the first letter in the message, the second the second, etc.
   Additionally, the first letter of evey word in the message following the first (thus, not including the first), will be capitalized when replacing the corresponding letter in the block.
   The block's length, when returned having been seeded by the message, will be shortened to include only the necessary number of words to sufficienty seed the block.
   Here is an example:
message: "where does poop go"
unseeded block: "You may think this message is odd, but it is likely more original than this silly block."
seeded block: "wou hay ehink rhis eessage Ds odd, eut st Ps oikely oore Priginal Ghen ohis"
 */

#include <iostream>
#include <limits>
#include <cstring>
#include <cctype>
#include <stdlib.h>

using namespace std;

const int MESSAGE_SIZE = 51;
const int BLOCK_SIZE = 501;

void prompt(int);
void seed(char a[], char b[], char c[]);
bool runner(void);
void readIn(char a[], int);

int main()
{ 
	bool keepGoing = true;
	while (keepGoing)
	{
		bool runner();
		keepGoing = runner();
	}

	return 0;
}



//Runs the main functionality of the program. Loops in main().
bool runner(void)
{
	char message[MESSAGE_SIZE];
	char block[BLOCK_SIZE];
	char seededBlock[BLOCK_SIZE];
	char quitter;
	for (int i = 0; i < BLOCK_SIZE; ++i)
	{
		block[i] = ' ';
		seededBlock[i] = ' ';
	}

	//message
	prompt(0);
	readIn(message, MESSAGE_SIZE);
	//cout << "\nTEST: " << message << endl;

	//block
	prompt(1);
	readIn(block, BLOCK_SIZE);
	//cout << "\nTEST: " << block << endl;
	strcpy(seededBlock, block);

	//seed
	seed(message, block, seededBlock);

	//display
	cout << "seeding test:\n";
	for (int i = 0; i< BLOCK_SIZE; ++i)
		cout << seededBlock[i];

	//continue
	prompt(4);
	cin >> quitter;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (tolower(quitter) == 'y')
		return true;
	else
		return false;
}



//Displays the various terminal prompts.
void prompt(int stage)
{
	switch (stage)
	{
		case 0:
			cout << "\n\n\nThis program encrypts a message. You will need to enter a message to be encrypted and a paragraph to encrypt the message.\n"
				<< "Your message cannot be greater than " << (MESSAGE_SIZE-1) << " charcters in length. Punctuation will not be preserved in the encryption.\n"
				<< "Your paragraph cannot be greater than " << (BLOCK_SIZE-1) << " characters in length.\n\n"
				<< "Enter your message. Do not leave blank.\n>>>";
			break;
		case 1:
			cout << "\n\nEnter your paragraph. Do not leave blank.\n>>>";
			break;	
		case 4:
			cout << "\n\nDo you want to continue?\nEnter [y] to continue, otherwise, the program will quit.\n>>>";
			break;
		default:
			cout << "\n\nQuitting...\n";
			exit(1);
	}
	return;
}



//Seeds a block with a message. Uses a dummy block, sb, to retain the form of the inputted block.
void seed(char m[], char b[], char sb[])
{
	int viablePositions[MESSAGE_SIZE];
	for (int i = 0; i < MESSAGE_SIZE; ++i)
		viablePositions[i] = 0;

	int foundOne = 0;
	for (int i = 0; i < strlen(b); ++i)
	{
		//int foundOne = 0;
		if (b[i-1] == ' ' || (i == 0 && isalpha(b[i])))
		{
			viablePositions[foundOne] = i;
			++foundOne;
		}
	}
	
/*	int spaceSpots[MESSAGE_SIZE];
	int foundAnother = 0;
	for (int i = 0; i < strlen(m); ++i)
	{
		spaceSpots[i] = 0;
		if (m[i] == ' ')
		{
			spaceSpots[foundAnother] = i;
			++foundAnother;
			for (int j = i; j < strlen(m); ++j)
				m[j] = m[j+1]; 
			m[strlen(m)-1] = ' ';
		}
	}
	cout << "\nspace test: " << m << endl << endl;
	*/	

	//	cout << "\nprior spot test: nd first spot test:" << m[-1] << ", " << m[0] << endl;
	
	int offset = 0;
	for (int i = 0; i < strlen(m); ++i)
	{
//		cout << "\nsome tests " << m[i] << endl << endl;
		if (isalpha(m[i]))
		{ 
			if (m[i-1] == ' ')
				sb[viablePositions[i-offset]] = toupper(m[i]);
			else 
				sb[viablePositions[i-offset]] = m[i];
		} else
		{
			++offset;
		}
	}

		/*cout << "test for spots:\n";
		cout << "spot 0: " << viablePositions[0] << endl;
		for (int i = 0; i < MESSAGE_SIZE; ++i)
		{
		if (viablePositions[i] != 0)
		cout << "spot " << i << ": " << viablePositions[i] << "\n";
		}*/	

	return;
}



//Reads in an input relatively safely; this process takes place a few times. The library <limits> is used to clear the entire input buffer.
void readIn(char a[], int max)
{

	cin.get(a, max, '\n');
	while (cin.peek() != '\n')
	{
		//ignore the entire buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Too many characters, try again.\n>>>";
		cin.get(a, max, '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return;
}

//
//
//
