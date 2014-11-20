#include<stdio.h>
#include<string.h>
#include<malloc.h>
//this method will arrange the letters in string in increasing order.
char* findMinimum(char *str1,int length)
{
	//char str[length];
	char* str = (char*) malloc(sizeof(char)*length);
	//str = str1;
	int i = 0;
	int j = 0;
	
	for(i=0;i<length;i++)
		str[i] = str1[i];
	
	for(i=0;i<length;i++)
	{
		//printf("%d\n",i);
		
		for(j=0;j<length-i-1;j++)
		{
			if(str[j]>str[j+1])
			{
				//printf("swapping %d %d \n",i,j);
				char c = str[j];
				str[j] = str[j+1];
				str[j+1] = c;
			}
		}
	
	}

	return str;
}

char* sort(char* str1, int length, int index)
{
	//char str[length];
	char* str = (char*) malloc(sizeof(char)*length);
	//str = str1;
	int i = 0;
	int j = 0;
	
	for(i=0;i<length;i++)
		str[i] = str1[i];
	
	for(i=0;i<length-index;i++)
	{
//		printf("char at index  is %c %d\n",str[index], i);
		//printf("%d \n",i);
		//printf("index = %d , length-i-1 = %d\n",index, length-i-1);
		for(j=index;j<length-i-1;j++)
		{
			//printf("char at index  is %c %d\n",str[index], j);
			if(str[j]>str[j+1])
			{
				//printf("sorting %d %d \n",i,j);
				char c = str[j];
				str[j] = str[j+1];
				str[j+1] = c;
			}
		}
	
	}
	//printf("after sorting %s \n ",str);
	return str;
}

int findSmallest(char* str, int length, int index,char s)
{
	int i;
	int result=index;
	char min = str[index];
	for(i=index;i<length;i++)
	{
		if(str[i]<min && str[i]>s)
		{
			min = str[i];
			result = i;
		}
	}
	
	//printf("smallest is %c %d \n",min,result);
	return result;

}

	
char* findNext(char* str1, int length)
{
	int i=0;
	
	
	char* str = (char*)malloc(sizeof(char)*length);
	for(i=0;i<length;i++)
		str[i] = str1[i];
	
	int index=-1;
	for(i=length-1;i>0;i--)
	{
		if(str[i]>str[i-1])
		{
			int s = findSmallest(str,length,i,str[i-1]);
			char a = str[s];
			str[s] = str[i-1];
			str[i-1] = a;
			index = i;
			//printf("swapping %c %c \n",str[s],str[i-1]);
			break;
		}
	}
	
	if(index != -1)
		str = sort(str,length,index);
	else
		//printf("Some error \n");
		
	return str;
}



int main()
{
	char* str = malloc(sizeof(char)*10);
	scanf("%s",str);
	
	//char* str = "1243";
	//printf("entered %s\n", str);
	char* string2;
	char* string3;
	int length;
	length = strlen(str);
	//printf("length = %d\n", length);
	//printf("%lu\n",sizeof(str));
	//printf("%lu\n",sizeof(char));
	string2 = findMinimum(str,length);
	
	printf("%s\n",string2);
	string3 = findNext(string2,length);
	int count =2;
	while(strcmp(string2,string3)!=0)
	{
		
		printf("%s\n",string3);
		string2 = string3;
		string3 = findNext(string2,length);
		count++;
		//sleep(1);
	}
	
	printf("\n %d\n\n",count-1);
	
	return 0;
}
