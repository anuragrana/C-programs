#include<stdio.h>
#include<malloc.h>
#include<string.h>

void reset(char *t)
{
	int i;
	for(i=0;i<strlen(t);i++)
		t[i] = '\0';

}


void strrev(char *t)
{
	int i;
	for(i=0;i<strlen(t)/2;i++)
	{
		char tmp = t[i];
		t[i]  = t[strlen(t)-i-1];
		t[strlen(t)-i-1] = tmp;
	}
	
}


int main()
{
	char *str;
	int i;
	str = (char *) malloc(sizeof(char)*140);
	fgets(str,140,stdin);
	
	char *tmp = malloc(140);
	for(i=0;i<strlen(str);i++)
	{
		if((str[i] == ' ') || (i == strlen(str)-1))
		{
			strrev(tmp);
			printf("%s ",tmp);
			reset(tmp);
		}
		else
		{
			char str2[2];
			str2[0] = str[i];
			str2[1] = '\0';
			strcat(tmp,str2);
		}
	}
	
	printf("\n");
	return 0;
}
