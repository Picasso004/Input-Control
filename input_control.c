#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int input_control_int(char instruction[],int lower_limit,int upper_limit)
{
	int result = 0;
	float residue = 0;
	
	do
	{
		printf("%s",instruction);
		if (scanf("%d%[^\n]", &result, &residue))
		{
			if (residue != 0) //Case where the entered value contains non-numeric caracters
			{
				printf("\nThe value you typed in is not an integer. Try again:\n");
				residue = 0;
				continue;
			}
			else
			{
				if (result < lower_limit || result > upper_limit) //Check if the value is in the interval
				{
					printf("Please enter a value between %d and %d\n",lower_limit,upper_limit);
					continue;
				}
				else break;
			}
		}
		else
		{
			printf("The value you typed in is not an integer. Try again:\n");
			scanf ("%*[^\n]");
		}	
	}
	while(1);
	return result;

}


float input_control_float(char instruction[], float lower_limit, float upper_limit)
{
	float result = 0; 
	float residue = 0;
	
	do
	{
		printf("%s",instruction);
		if (scanf("%f%[^\n]", &result, &residue)) 
		{
			if (residue != 0) 
			{
				printf("\nThe value you typed in is not a float. Try again:\n");
				residue = 0;
				continue;
			}
			else
			{
				if (result < lower_limit || result > upper_limit)
				{
					printf("Please enter a value between %.1f and %.1f.\n",lower_limit,upper_limit);
					continue;
				}
				else break;
			}
		}	
		else 
		{
			printf("The value you typed in is not a float. Try again:\n");
			scanf ("%*[^\n]");
		}	
	}
	while(1);
	return result;
}


char* input_control_string(char instruction[])
{
	int input_is_corect = 0, i = 0;
	char c, string[100];
	
		
	do{
		printf("%s",instruction); 
		fgets(string,100,stdin);

		do
		{
			c = string[i];
			if (isalpha(c) == 0 && isblank(c) == 0 && c!='\n')
			{
				input_is_corect = 0;
				printf("Error. Please type in only letters. Try again:\n");
				i = 0;
				break;
			}
			else if(c == '\n' && input_is_corect) break;

			else if(isspace(c) && i == 0 ) break;

			else
			{		
				input_is_corect = 1;
				i++;
				continue;
			}			
		}
		while(c != '\n');
	}
	while(input_is_corect == 0);
	
	*(strchr(string, '\n')) = '\0';
	
	char* result = &string;
	return result;
				
}

void main()
{
	int test = 0;
	test = input_control_int("Just try it:",0,15);
	printf("%d\n",test);
	
	float test2 = 0;
	test2 = input_control_float("Just try it:",0,19.5);
	printf("%f\n",test2);
	
	char* string1;
	string1 = input_control_string("Yep enter a string :");
	printf("%s\n",string1);
	
}
