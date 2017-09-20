#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	int i;
	char str[100]={0};

	printf("파일에 입력하실 문장을 입력해주시기 바랍니다.\n");
	gets(str);

	if((fp = fopen("hello.txt", "w"))==NULL)
	{
		printf("오류 : 파일을 열 수 없습니다.\n");
		return;
	}

	for(i=0;str[i];i++)
	{
		if(fputc(str[i], fp)==EOF)
		{
			printf("오류 : 파일을 쓸 수 없습니다.\n");
			return;
		}
	}

	fclose(fp);

	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		printf("오류 : 파일을 열 수 없습니다.\n");
		return;
	}
	printf("입력 결과 출력 : ");
	for(;;)
	{
		ch = fgetc(fp);
		if(ch == EOF) 
		{
			break;
		}
		putchar(ch);
	}
	fclose(fp);
	printf("\n");
}