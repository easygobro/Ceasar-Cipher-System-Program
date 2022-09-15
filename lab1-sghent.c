#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int Encrypt(char *token2);
int Decrypt(char *token2);
int Help();

/**
 * Summary of the main function:
 * 	The main function begins by starting a loop (Command loop) that waits for user input 
 * 	in the correct syntax, then parses user input to determine which function is trying to be executed and what message inside your would like 
 * 	to encrypt/decrypt.
 */
int main() {
		
		char *str;
		str = (char*)malloc( 300 * sizeof(char) );
		char *token;
		char *token2;
		char result;
		bool valid = false;

		Help();

		while (valid != true) {
			printf("Please enter a command: "); 
			fgets(str, sizeof(str), stdin); 	
			token = strtok(str, "("); 		
			token2 = strtok(NULL, ")");	
			if (strcasecmp(token, "exit") == 0) {
				free(str);
				exit(0);
			} else if (strcasecmp(token, "help") == 0) {
				Help();
			} else if (strcasecmp(token, "encrypt") == 0) {
				result = Encrypt(&*token2); 		
			} else if (strcasecmp(token, "decrypt") == 0) {
				result = Decrypt(&*token2);  
			} else {
				printf("[Error]Please enter the command correctly!\n");  
			}
			continue;
		}	
}

/*
 * Summary of the Encrypt function: 
 * 	The Encrypt function takes the input of token2 to be the encrypted message. Inside the for loop we itterate through all the characters in the array 
 * 	and decide if they are a capital letter, lowercase letter, or a space and the encrypt each character by shifting it a value of 5 and returning the new character.
 *
 * Parameters : *token2
 *
 * Description : function to encrypt a message using a ceasar cipher with k=5
 */
int Encrypt(char *token2) {	

		char cypherText[101];
		int key = 5;
		int i;

		for (i=0; i < strlen(token2); i++) {
			if(token2[i]>=65 && token2[i]<=90) {
				cypherText[i]=((((token2[i]-65))+key)%26)+65;
			} else if(token2[i]>=97 && token2[i]<=122) {
				cypherText[i]=((((token2[i]-97))+key)%26)+97;
			} else if(token2[i] == 32) {
				cypherText[i]=((((token2[i]-32))+key)%26)+32;
		 
			} else if(token2[i] >= 48 && token2[i] <= 57) {
				cypherText[i]=((((token2[i]-48))+key)%26)+48;
			} else {
				printf("Error: Please use the appropriate characters\n");
			}
		}

		cypherText[i] = '\0';
		printf("Ciphered Text: %s\n", cypherText);
		return 0;
}

/*
 * Summary of the Decrypt function: 
 * 	The Decrypt function takes the input of token2 to be the encrypted message. Inside the for loop we itterate through all the characters in the array 
 * 	and decide if they are a capital letter, lowercase letter, or a space and the decrypt each character by shifting it a value of 5 and returning the new character.
 *
 * Parameters : *token2
 *
 * Description : function to decrypt a message using a ceasar cipher with k=5
 */
int Decrypt (char *token2) {
		char plainText[101];
		int key = 5;
		int i;
		for (i=0; i < strlen(token2); i++) {
			if(token2[i] >= 65 && token2[i]<=90) {
				plainText[i]=((((token2[i]-65))-key)%26)+65;
			} else if(token2[i]>=97 && token2[i]<=122) {
				plainText[i]=((((token2[i]-97))-key)%26)+97;	
			} else if(token2[i] == 37) {
				plainText[i]=((((token2[i]-37))-key)%26)+37;
			} else if(token2[i] >=22 && token2[i] <= 83) {
				plainText[i]=((((token2[i]-48))-key)%26)+48;
			}else {
				printf("Error: PLease use the appropriate characters\n");
			}
	
		}

		plainText[i] = '\0';

		printf("Deciphered Text: %s\n ", plainText);
		return 0;
}

/*
 * Summary of the Help function
 * 	Display a message at the begining of the program, as well as be able to be called 
 */
int Help() { 
		printf("\t**Welcome to Ceasar Cipher Encrypter/Decrypter**\n");
		printf("\t**Commands avaiable are: help(), encrypt(), decrypt(), and exit()**\n");
		printf("\t**Syntax must be 'encrypt(message)' 'decrypt(message) 'exit()' 'help()'**\n");
		return 0;
}

