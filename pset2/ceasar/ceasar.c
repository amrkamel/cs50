#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLower(char c)
{
	return c >= 'a' && c <= 'z';
}

bool isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}

char* encrypt(char plain_text[], int k)
{	
	for(int i = 0; plain_text[i]; i++)
	{
		if(isLower(plain_text[i]))
			if(plain_text[i] + k < 'z')		
				plain_text[i] += k;
			else 
				plain_text[i] -= 26 - k;
		if(isUpper(plain_text[i]))
			if(plain_text[i] + k < 'Z')		
				plain_text[i] += k;
			else 
				plain_text[i] -= 26 -k ;
	}
	return plain_text;
}

int main(int args_count, char *args[])
{
	if(args_count == 2)
	{		
		int k = atoi(args[1]) % 26;			
		char plain_text[100];
		printf("plaintext: ");
		scanf("%[^\n]%*c", plain_text);		
		printf("ciphertext: %s\n", encrypt(plain_text, k));
		return 0;
	}
	else
	{
		printf("Invalid CLA\n");
		return 1;
	}
}