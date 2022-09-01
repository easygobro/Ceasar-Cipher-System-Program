/*
 * Program to encrypt/decrypt as well as encode and decode using the ceasar cipher\
 * Author: Sam Ghent
 */

#include <stdio.h>
#include <string.h>

//Call funcations
int Encrypt(char *token2);
int Decrypt(char *token2);
int Help();


int main() {
	
	char str[101];
	char *token;
	char *token2;
	char result;
	
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
		result = Encrypt(&*token2); //if the first token matches, exec Encrypt() --> line 15
	} else if (strcmp(token, "decrypt") == 0) {
		result = Decrypt(&*token2); // if the second token matches, exec Decrypt() --> line 49 
	} else {
		printf("Please enter a valid command!"); //print out error message if the syntax of tokens does not match either encrypt or decrypt 
	}

	return 0;
}

int Encrypt(char *token2) {	

	//Local Variables
	char cypherText[101];
	int key = 5;
	int i;

	//Encryption Loop
	for (i=0; i < strlen(token2); i++) {
		//check if it is a capital letter
		if(token2[i]>=65 && token2[i]<=90) {
			//loop each letter, encrypt with ceasar cipher
			cypherText[i]=((((token2[i]-65))+key)%26)+65;
			  //check if it a lowercase letter
		} else if(token2[i]>=97 && token2[i]<=122) {
			//loop each letter, encrypt with ceasar cipher
			cypherText[i]=((((token2[i]-97))+key)%26)+97;	
		} else {
			cypherText[i] = token2[i];
		}	
	
	}
		printf("Ciphered Text: %s\n", cypherText);
		return 0;
}

int Decrypt (char *token2) {
	//Local Variables
	char plainText[101];
	int key = 5;
	int i;
	//Decryption loop
	for (i=0; i < strlen(token2); i++) {
		//check if it a captial letter
		if(token2[i] >= 65 && token2[i]<=90) {
			//loop each letter, decrypt the ceasar cipher
			plainText[i]=((((token2[i]-65))-key)%26)+65;
			  //check if it a lowercase letter
		} else if(token2[i]>=97 && token2[i]<=122) {
			//loop each letter, encrypt with ceasar cipher
			plainText[i]=((((token2[i]-97))-key)%26)+97;	
		} else {
			plainText[i] = token2[i];
		}	
	}

	printf("Deciphered Text: %s\n ", plainText);
	return 0;
}


int Help() { 
	printf("**Welcome to Ceasar Cipher Encrypter/Decrypter**\n");
	printf("--Commands avaiable are: encrypt and decrypt--\n");
	printf("--syntax must be 'encrypt(message)' otherwise will result in error--\n");
	return 0;
}


	

