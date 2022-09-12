#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int Encrypt(char *token2);
int Decrypt(char *token2);
int Help();
int quit();

int main() {
		
		char str[101];
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
			if (strcmp(token, "exit") == 0) {
				exit(0);
			} else if (strcmp(token, "encrypt") == 0) {
				result = Encrypt(&*token2); 		
			} else if (strcmp(token, "decrypt") == 0) {
				result = Decrypt(&*token2);  
			} else {
				printf("[Error]Please enter the command correctly!\n");  
			}
			continue;
		}	
}

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
 * For encoding and decoding, must parse input into tokens and loop letter by letter, encoding to binary, --> have to add a zero in the begining in order to make it 8 bit unicode compatable. 
 *
 * 
 * /

int Help() { 
		printf("**Welcome to Ceasar Cipher Encrypter/Decrypter**\n");
		printf("**Commands avaiable are: encrypt(), decrypt(), and exit()**\n");
		printf("**Syntax must be 'encrypt(message)' 'decrypt(message) 'exit()'**\n");
		return 0;
}

