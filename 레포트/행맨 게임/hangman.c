#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void man(int a)
{
	if(a>=1)
		printf("	 o\n");
	if(a>=2)
		printf("	r");
	if(a>=3)
		printf("l");
	if(a>=4)
		printf("ㄱ\n");
	if(a>=5)
		printf("	r");
	if(a>=6)
	{
		printf("ㄱ\n");
		printf("Game over\n");
	}
	printf("\n");
}

void main()
{
	char ap[100], cs;
	int a[100]={0}, b=0, k=0, l=0, i=0;

	printf("행맨 게임에 오신걸 환영합니다!\n");
	printf("문제 낼 단어를 입력해주세요!\n");

	gets(ap);
	b=strlen(ap);
	
	for(i=0;i<b;i++)
	{
		printf("_ ");
	}
	for(;;)
	{
		for(i=0;i<b;i++)
		{
			if(a[i]==0)
				break;
			if(i==b-1)
			{
			if(a[b-1]==1)
			{
				printf("You WIN!\n");
				return;
			}
			}
		}
	printf("\n빈칸에 들어갈 알파벳을 적어주세요!\n");
	fflush(stdin);
	scanf("%c", &cs);
	
	for(i=0;i<b;i++)
	{
		if(ap[i]==cs)
		{
			a[i]=1;
			l++;
		}
	}

	if(l<=0)
	{
	k++;
	}
	man(k);
	if(k==6)
	{
		return;
	}
	l=0;

	for(i=0;i<b;i++)
	{
		if(a[i]==1)
			printf("%c ",ap[i]);
		else
		printf("_ ");
	}
	printf("\n");
	}
}