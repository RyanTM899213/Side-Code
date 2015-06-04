
char a[] = "Mary had a little lamb";
char* p=a;
int count = 0;
while(*p != '\0') //While the char p is not null
{
	count++; // increase count by 1
	while(*p ! = '' && *p != '\0') // while char p is not white space and is not null 
	{
		p++; //increase p by 1
	}
	
	while(*p == '') // while char p is not white space
	{
		p++; // increase p by 1
	}
}

//The count is equal to 5, it counts the number of words in a.
