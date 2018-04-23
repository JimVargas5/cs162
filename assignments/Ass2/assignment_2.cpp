//Jim Vargas
//CS162 Programming Assignment 2
//4/??/2018

//NOTE: Definition of terminology:
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

using namespace std;

const int MESSAGE_SIZE = 51;
const int BLOCK_SIZE = 501;

void prompt(int);
void seed(char, char);

int main()
{
	char message[MESSAGE_SIZE];
	char block[BLOCK_SIZE];
	
	prompt(0);
	cin.get(message, MESSAGE_SIZE, '\n');
	while (cin.peek() != '\n')
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Too many characters, try again.\n>>>";
		cin.get(message, MESSAGE_SIZE, '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nTEST: " << message << endl;

	prompt(1);
	cin.get(block, BLOCK_SIZE, '\n');
	while (cin.peek() != '\n')
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Too many characters, try again.\n>>>";
		cin.get(block, BLOCK_SIZE, '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nTEST: " << block << endl;

	return 0;
}



//
void prompt(int stage)
{
	switch (stage)
	{
		case 0:
			cout << "\n\n\nThis program encrypts a message. You will need to enter a message to be encrypted and a paragraph to encrypt the message.\n"
				<< "Your message cannot be greater than " << (MESSAGE_SIZE-1) << " charcters in length. Case and punctuation will not be preserved in the encryption.\n"
				<< "Your paragraph cannot be greater than " << (BLOCK_SIZE-1) << " characters in length.\n\n"
				<< "Enter your message.\n>>>";
			break;
		case 1:
			cout << "\n\nEnter your paragraph.\n>>>";
			break;	
	}
	return;
}



//
void seed(char m[], char* b[])
{
	return;
}




//
