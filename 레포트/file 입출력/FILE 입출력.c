#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	int i;
	char str[100]={0};

	printf("���Ͽ� �Է��Ͻ� ������ �Է����ֽñ� �ٶ��ϴ�.\n");
	gets(str);

	if((fp = fopen("hello.txt", "w"))==NULL)
	{
		printf("���� : ������ �� �� �����ϴ�.\n");
		return;
	}

	for(i=0;str[i];i++)
	{
		if(fputc(str[i], fp)==EOF)
		{
			printf("���� : ������ �� �� �����ϴ�.\n");
			return;
		}
	}

	fclose(fp);

	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		printf("���� : ������ �� �� �����ϴ�.\n");
		return;
	}
	printf("�Է� ��� ��� : ");
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