#include<stdio.h>
#include<malloc.h>

/*
Anurag Rana, Dec 17, 2014

rotating a matrix left or right.
For left rotation, take transpose and swap rows,
for right rotation, take transpose and swap columns.
*/

int main()
{
	int arr[3][3] = {{ 1,2,3} ,{4,5,6},{7,8,9}};
	int len = 3;
	int i,j,temp;
	int dir;	
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	
	// Transpose Array.
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			//printf("\n%d %d %d %d",i,j, arr[i][j], arr[j][i]);
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	
	for(i=0;i<len;i++)
	{
		printf("\n");
		for(j=0;j<len;j++)
		{
			printf("%d ",arr[i][j]);
		}
		
	}
	
	printf("\n left rotate (Press 1) or right (press 2) ?");
	scanf("%d",&dir);
	
	if(dir==1)
	{
		//swap rows
		for(i=0;i<len/2;i++)
		{
			for(j=0;j<len;j++)
			{
				temp = arr[i][j];
				arr[i][j] = arr[len-i-1][j];
				arr[len-i-1][j] = temp;
			}
		}
				
	}
	else if(dir==2)
	{
		//swap columns
		for(i=0;i<len;i++)
		{
			for(j=0;j<len/2;j++)
			{
				temp = arr[i][j];
				arr[i][j] = arr[i][len-j-1];
				arr[i][len-j-1] = temp;
			}
		}
				
	}
	else
		printf("Wrong choice. Exiting....");
	
	
	for(i=0;i<len;i++)
	{
		printf("\n");
		for(j=0;j<len;j++)
		{
			printf("%d ",arr[i][j]);
		}
		
	}
	
	printf("\n");
	return 0;
}
