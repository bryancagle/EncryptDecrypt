/*
Author: Bryan Cagle (bryancagle@my.unt.edu)
Date: 4/11/2014
Purpose: This program reads a phrase inputted by the user, and asks for an offset to decrypt or encrypt the phrase. 
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char alphabetlo[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char alphabetup[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char userinput[500]={0};
	int menu,offset;

	printf("\nCSCE 1030\nHomework 5\nBryan Cagle (bryancagle@my.unt.edu)\nbmc0149\n");
	do{
		printf("\nPlease enter a word or sentence to encrpyt or decrpyt: ");
		gets(userinput); //stores user's input into char array
		printf("\nYou have input: %s\n\n",userinput); //Repeats what the user input
		printf("Would you like to encrypt or decrypt?\n\n");
		printf("Encrypt (Enter 0)\n");
		printf("Decrypt (Enter 1)\n");
		printf("Exit    (Enter 2)\n");
		scanf("%d",&menu);
		if(menu!=2)
		{
			printf("Enter the offset: ");
			scanf("%d",&offset);
		}
		switch(menu)
		{
			case 0: encrypt(alphabetlo,alphabetup,userinput,offset);getchar(); break;
			case 1: decrypt(alphabetlo,alphabetup,userinput,offset);getchar(); break;
			case 2: break;
		}
	}while(menu!=2); //The program will repeat forever until the user sleects they would like to exit the program at the initial menu
}

int encrypt(char alphabetlo[26],char alphabetup[26],char userinput[500],int offset)
{
	int i,j,count,length=strlen(userinput);
	char changed[500];
	strcpy(changed,userinput);
	for(i=0;i<=length-1;i++) //repeats look for as long as the user input string
	{
		for(j=0,count=0;j<26;j++,count++)
		{
			if((changed[i]==alphabetlo[j])||(changed[i]==alphabetup[j])) //this is so only letters are the ones changed, it is compared to the alphabet characters
			{
				changed[i]=changed[i]+offset; //changes the ASCII value
				if(count+offset>=26) //if the ASCII value goes above 26, then the program will subtract 26 from the value in order to create a wrap around effect
				{
					changed[i]-=26;
				}
				break;
			}
		}
}
	printf("Encrypted phrase: %s\n\n",changed);
}

int decrypt(char alphabetlo[26],char alphabetup[26],char userinput[500], int offset)
{
	int i,j,count,length=strlen(userinput);
	char changed[500];
	strcpy(changed,userinput);
	for(i=0;i<=length-1;i++)
	{
		for(j=0,count=0;j<26;j++,count++)
		{
			if((changed[i]==alphabetlo[j])||(changed[i]==alphabetup[j])) //this if statement makes only letters change
			{
				changed[i]=changed[i]-offset; //changes ASCII value based on the offset
				if(count-offset<0) //if the ASCII value goes below 0, then the program will add 26 to the value to wrap around
				{
					changed[i]+=26;
				}
				break;
			}
		}
	}
	printf("Decrypted phrase: %s\n\n",changed);
}
