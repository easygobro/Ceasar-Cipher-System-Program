/*
 * Program to encrypt/decrypt as well as encode and decode using the ceasar cipher\
 * Author: Sam Ghent
 */

#include <stdio.h>
#include <string.h>


//avoid implicate error by calling functions before main
char *token;
char *token2;

//function to encrypt messages with ceasar cipher || Uses plainText[i] as input and parses through each letter, needs to use token2
int Encrypt() {
	
	char plainText[sizeof(token2)];
	char cypherText[101];
	int key = 5;
	int i;

//	plainText[i] = *token2;
//- does not work, need to review more about arrays and storing pointers 

// 	ask for user input 	
//	printf("Please enter some text: ");
//	fgets(plainText, sizeof(plainText), stdin);
	
/*
 *	In order to turn the string into something we can use we must start out by detecting wheather or not it is a capital letter or a lowercase letter.
 *	Then if it is a capital letter that returns a value between 65 and 90, subtract 65 add the key, use mod26 (for 26 letters in the alpabet) and then finally add 65 back 		to the cyphered text.
 *	If it is a lowercase letter do the same but subtract 97, because lowercase letters are between 97 and 122.
 */
	for (i=0; i < strlen(plainText); i++) {
		//check if it is a capital letter
		if(plainText[i]>=65 && plainText[i]<=90) {
			//loop each letter, encrypt with ceasar cipher
			cypherText[i]=((((plainText[i]-65))+key)%26)+65;
			  //check if it a lowercase letter
		} else if(plainText[i]>=97 && plainText[i]<=122) {
			//loop each letter, encrypt with ceasar cipher
			cypherText[i]=((((plainText[i]-97))+key)%26)+97;	
		} else {
			cypherText[i] = plainText[i];
		}	
	
	}	
       		//print out the ciphered text	
		printf("\nCiphered Text: ");
		puts(cypherText);	
		return 0;
}

int Decrypt() {

	char cypherText[101];
	char plainText[101];
	int key = 5;
	int i;

	printf("Please Enter some ciphered text: ");
	fgets(cypherText, sizeof(cypherText), stdin);

	for (i=0; i < strlen(cypherText); i++) {
		//check if it a captial letter
		if(cypherText[i] >= 65 && cypherText[i]<=90) {
			//loop each letter, decrypt the ceasar cipher
			plainText[i]=((((cypherText[i]-65))-key)%26)+65;
			  //check if it a lowercase letter
		} else if(cypherText[i]>=97 && cypherText[i]<=122) {
			//loop each letter, encrypt with ceasar cipher
			plainText[i]=((((plainText[i]-97))-key)%26)+97;	
		} else {
			plainText[i] = cypherText[i];
		}	
	}

	//print out the decrypted text
	printf("\nCiphered Text: ");
	printf(cypherText, &cypherText);
	
	return 0;
	
}


//Help functoin to keep printf clutter out of the main function
int Help() { 
	printf("Welcome to Ceasar Cipher Encrypter/Decrypter\n");
	printf("Commands avaiable are: encrypt and decrypt\n");
	printf("syntax must be 'encrypt(message)' otherwise will result in error\n");
	return 0;
}

int main() {

	char str[101];
	//char *token;
	//char *token2;
	Help(); //gives a quick list of commands when starting
	printf("Please enter a command: "); 
	fgets(str, sizeof(str), stdin); // gether input of command and store it in an array called str
	
	token = strtok(str, "("); // break up the array using "(" and ")" as delimiters
	token2 = strtok(NULL, ")"); // second token for message

	//check tokens to make sure they break at partntheseis 
	printf("%s\n", token);	
	printf("%s\n", token2);


	//using strcmp (String compare) test is the first token is equal to either encrypt or decrypt.
	//if strcmp returns 0 then that means the two strings match
	if (strcmp(token, "encrypt") == 0) {
		Encrypt(); //if the first token matches, exec Encrypt() --> line 15
	} else if (strcmp(token, "decrypt") == 0) {
		Decrypt(); // if the second token matches, exec Decrypt() --> line 49 
	} else {
		printf("Please enter a valid command!"); //print out error message if the syntax of tokens does not match either encrypt or decrypt 
	}

	return 0;

	}

	

