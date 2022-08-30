/*
 * Program to encrypt/decrypt as well as encode and decode using the ceasar cipher\
 * Author: Sam Ghent
 */

#include <stdio.h>
#include <string.h>


//avoid implicate error by calling functions before main


//function to encrypt messages with ceasar cipher
int Encrypt() {
	
	char plainText[101];
	char cypherText[101];
	int key = 5;
	int i;

	printf("Please enter some text: ");
	fgets(plainText, sizeof(plainText), stdin);
	
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
		printf(cypherText, &cypherText);	
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
	printf(plainText, &plainText);
	return 0;
	}

int main() {

	char str[10];
	char *token;
	char *original;
	char *theRest;

	printf("\nPlease enter a command: "); 
	fgets(str, sizeof(str), stdin);

	original = strdup(str);
	theRest = original;

	const char s[2] = "(";
	const char s2[2] = ")";
	
	while ((token = strtok_r(theRest, , &theRest))) {
		printf("%s\n", token);
	} 
	
	return 0;
}
