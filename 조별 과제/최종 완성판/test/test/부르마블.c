#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <Windows.h>

struct user{
	int money;
	int site;
}P1, P2, *PPT1, *PPT2;
int conutry[20]={0};
void mainmap();
void map1();
int rank();
int dice(int a);
int luck(int c, int *m1, int *m2);
int respon(int *a, int b, int *m1, int *m2);
void trip(int *s, int b, int *m1, int *m2);
void realmap(int *a, int *b, int *m1, int *m2);
int main()
{
	int ra=0;
	int dic;

	struct user P1 = {200, 97};
	struct user P2 = {200, 97};

	PPT1=&P1;
	PPT2=&P2;

	mainmap();
	ra=rank();

	map1();

	for(;;)
	{
		if(P1.site>116)
		{
			puts("");
			printf("���� : 1P�� �ѹ����� �� ���Ƽ� ������ 20������ �޾ҽ��ϴ�!!\n");
			P1.money+=20;
			P1.site=P1.site-20;
		}
		else if(P2.site>116)
		{
			puts("");
			printf("���� : 2P�� �ѹ����� �� ���Ƽ� ������ 20������ �޾ҽ��ϴ�!!\n");
			P2.money+=20;
			P2.site=P2.site-20;
		}
		if(ra>1)
		{
			if(ra%2==1)
			{
				if((PPT1->site!=97)&&(PPT1->site!=102)&&(PPT1->site!=115))
				{
				realmap(&(PPT1->site), &(PPT2->site), &(PPT1->money), &(PPT2->money));
				}
				
				puts("");
				
				if(respon(&(PPT1->site), 1, &(PPT1->money), &(PPT2->money))==0)
				{
					return 0;
				}
			}
			else if(ra%2==0)
			{
				if((PPT2->site!=97)&&(PPT2->site!=102)&&(PPT2->site!=115))
				{
				realmap(&(PPT1->site), &(PPT2->site), &(PPT1->money), &(PPT2->money));
				}

				puts("");

				if(respon(&(PPT2->site), 2, &(PPT1->money), &(PPT2->money))==0)
				{
					return 0;
				}
			}

			if(P1.money<=0)
			{
				printf("�˼��մϴٸ� 1P���� ���� �Ļ��� �����Ƿ� ���ӿ��� �й��ϼ̽��ϴ�. �����ϼ̽��ϴ�.\n");
				printf("\n 2P�� ���ӿ��� �¸��� �������� ���ϵ帳�ϴ�. ���ӿ� ������ ��������.\n");
				return 0;
			}
			else if(P2.money<=0)
			{
				printf("�˼��մϴٸ� 2P���� ���� �Ļ��� �����Ƿ� ���ӿ��� �й��ϼ̽��ϴ�. �����ϼ̽��ϴ�.");
				printf("\n 1P�� ���ӿ��� �¸��� �������� ���ϵ帳�ϴ�. ���ӿ� ������ ��������.\n");
				return 0;
			}

			fflush(stdin);
			realmap(&(PPT1->site), &(PPT2->site), &(PPT1->money), &(PPT2->money));

		}

		if(ra%2==0)
		{
			dic=dice(1);
			P1.site=P1.site+dic;
			printf("1P�� %dĭ �̵��մϴ�.\n", dic);
		}
		else if(ra%2==1)
		{
			dic=dice(2);
			P2.site=P2.site+dic;
			printf("2P�� %dĭ �̵��մϴ�.\n", dic);
		}
		ra=ra+3;
	}
}
int luck(int c, int *m1, int *m2)
{
	int l;
	srand(time(NULL));
	l=(rand()%10+1);

	puts("");
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	puts("��                              ����    ��");
	puts("��        _____________________��    ��   ��");
	puts("��        �Ӥ�  �Ӥ�            ����    ��");
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	puts("");
	puts("ī�带 �������÷��� Enter�� �����ֽñ� �ٶ��ϴ�.");

	getchar();
	system("cls");

	switch(l)
	{
	case 1:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��     �踦 Ÿ�� ���� ������ �������ϴ�.  ��");
		puts("��                                        ��");
		puts("��            ���������� ���ÿ�!          ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		if (c==1)
		{
			PPT1->site = 102;
			respon(&(PPT1->site), 1, m1, m2);
			break;
		}
		else if (c==2)
		{
			PPT2->site = 102;
			respon(&(PPT2->site), 2, m1, m2);
			break;
		}
	case 2:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��   ���� �ȴٰ� �Ҹ�ġ�⸦ ���߽��ϴ�.   ��");
		puts("��                                        ��");
		puts("��               -5����                   ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		
		if (c==1)
			*m1=*m1-5;
		else if (c==2)
			*m2=*m2-5;

		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 3:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��   �̺�Ʈ�� ��÷�Ǿ� ����� �޾ҽ��ϴ�. ��");
		puts("��                                        ��");
		puts("��               +10����                  ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;


		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 4:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��     �װ��� �̺�Ʈ�� ��÷�Ǿ����ϴ�.    ��");
		puts("��                                        ��");
		puts("��         ���� �������� ���ÿ�.          ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		if (c==1)
		{
			getchar();
			system("cls");
			PPT1->site = 112;
			respon(&(PPT1->site), 1, m1, m2);
			break;
		}
		else if(c==2)
		{
			getchar();
			system("cls");
			PPT2->site = 112;
			respon(&(PPT2->site), 2, m1, m2);
			break;
		}
		break;
	case 5:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��   �ڿ����ذ� �Ͼ ���ε��� ���� ��� ��");
		puts("��                                        ��");
		puts("��               -10����                  ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		
		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 6:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��    ���� ������ �����ϴٰ� �׾����ϴ�.  ��");
		puts("��                                        ��");
		puts("��               game over                ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		printf("%dP���� ���������� %dP���� �й�� ������ ���� �����ϴ�.\n", c, c);
		return 0;
		break;
	case 7:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��      ��縦 �Ͽ��� ���� ������ϴ�.    ��");
		puts("��                                        ��");
		puts("��               +20����                  ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		if (c==1)
			*m1=*m1+20;
		else if (c==2)
			*m2=*m2+20;

		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 8:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��       ������ �˹ٸ� ���� �������ϴ�.   ��");
		puts("��                                        ��");
		puts("��               +10����                  ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;

		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 9:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("�� ǳ�亴�� �ɷ� ġ���� ���� ����մϴ�.��");
		puts("��                                        ��");
		puts("��                -10����                 ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n ��� �����Ͻ÷��� Enter�� �����ּ���.");
		getchar();
		system("cls");
		break;
	case 10:
		puts("");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		puts("��   �Ƴ��� �� ������Ȱ�� �ϰԵ˴ϴ�. ��");
		puts("��                                        ��");
		puts("��             happy ending!              ��");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		printf("%dP���� ���ڸ� �����ż� %dP���� �¸��� ������ ���� �����ϴ�.\n", c, c);
		return 0;
		break;
	}
	fflush(stdin);
	return 1;
}
int respon(int *a, int b, int *m1, int *m2)
{
	int r, y;
	if(*a==97)
	{
		printf("%dP�� ���� ��߼��Դϴ�.\n", b); 
	}
	else if(*a==98)
	{
		printf("%dP�� ���� ���ۿ� �����ϼ̽��ϴ�.\n", b);
		if(conutry[1]==0)
		{
			puts("");
			printf("���ۿ� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("������ �ü��� 3�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ������ ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[1]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[1]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 6������ 1P���� �ݴϴ�.\n");
				*m1=*m1+6;
				*m2=*m2-6;
			}

		}
		else if(conutry[1]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 6������ 2P���� �ݴϴ�.\n");
			*m2=*m2+6;
			*m1=*m1-6;
		}
		getchar();
	system("cls");
	}
	else if(*a==99)
	{
		printf("%dP�� ���� ī�̷ο� �����ϼ̽��ϴ�.\n", b);
		if(conutry[2]==0)
		{
			puts("");
			printf("ī�̷ο� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("ī�̷��� �ü��� 4�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ī�̷��� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[2]=b;
				if(b==1)
					*m1-=4;
				else
					*m2-=4;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[2]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 8������ 1P���� �ݴϴ�.\n");
				*m1=*m1+8;
				*m2=*m2-8;
			}

		}
		else if(conutry[2]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 8������ 2P���� �ݴϴ�.\n");
			*m2=*m2+8;
			*m1=*m1-8;
		}
		getchar();
	system("cls");
	}
	else if (*a==100)
	{
		printf("%dP�� ���� ����¡�� �����ϼ̽��ϴ�.\n", b);
		if(conutry[3]==0)
		{
			puts("");
			printf("����¡�� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("����¡�� �ü��� 5�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ����¡�� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[3]=b;
				if(b==1)
					*m1-=5;
				else
					*m2-=5;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[3]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 10������ 1P���� �ݴϴ�.\n");
				*m1=*m1+10;
				*m2=*m2-10;
			}

		}
		else if(conutry[3]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 10������ 2P���� �ݴϴ�.\n");
			*m2=*m2+10;
			*m1=*m1-10;
		}
		getchar();
	system("cls");
	}
	else if(*a==101)
	{
		printf("%dP�� ���� ��� ���迡 �����ϼ̽��ϴ�. ���ϵ帳�ϴ�!!!\n", b);
		return luck(b, m1, m2);
	}
	else if(*a==102)
	{
		printf("%dP�� ���� �������� �����ϼ̽��ϴ�.\n", b);
		printf("������ �� 20������ �Ұ� ������ �ʾҽ��ϴ�.\n");
		if(b==1)
			*m1 = *m1 - 20;
		else
			*m2 = *m2 - 20;

	}
	else if(*a==103)
	{
		printf("%dP�� ���� ���쿡 �����ϼ̽��ϴ�.\n",b);
		if(conutry[6]==0)
		{
			puts("");
			printf("���쿡 ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("������ �ü��� 8�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ������ ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[6]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[6]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 16������ 1P���� �ݴϴ�.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[6]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 16������ 2P���� �ݴϴ�.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==104)
	{
		printf("%dP�� ���� �̰����� �����ϼ̽��ϴ�.\n", b);
		if(conutry[7]==0)
		{
			puts("");
			printf("�̰����� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("�̰����� �ü��� 8�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. �̰����� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[7]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[7]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 16������ 1P���� �ݴϴ�.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[7]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 16������ 2P���� �ݴϴ�.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==105)
	{
		printf("%dP�� ���� �õ�Ͽ� �����ϼ̽��ϴ�.\n", b);
			if(conutry[8]==0)
			{
			puts("");
			printf("�õ�Ͽ� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("�õ���� �ü��� 10�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. �õ���� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[8]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[8]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 20������ 1P���� �ݴϴ�.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[8]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 20������ 2P���� �ݴϴ�.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==106)
	{
		printf("%dP�� ���� ��ũ�ٿ� �����ϼ̽��ϴ�.\n",b);
	if(conutry[9]==0)
		{
			puts("");
			printf("��ũ�ٿ� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("��ũ���� �ü��� 10�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ��ũ���� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[9]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[9]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 20������ 1P���� �ݴϴ�.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[9]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 20������ 2P���� �ݴϴ�.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==107)
	{
		srand(time(NULL));
		printf("%dP�� ���� ī���뿡 �����ϼ̽��ϴ�.\n", b);
		printf("������ ���ؼ� 5������ �����̽��ϴ�.\n");
		if(b==1)
			*m1 = *m1 - 5;
		else
			*m2 = *m2 - 5;
		printf("Ȯ���� ���� 5������ 0��~10�谡 �� �� �ֽ��ϴ�.\n");
		printf("��� ������ ���� �� Enter�� �����ֽñ� �ٶ��ϴ�.\n");
		getchar();
		printf("���� ��");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n");Sleep(1000);
		printf("���� ��� : %d(����)�� ȹ���ϼ̽��ϴ�.\n",r=(rand()%11)*5);

		if(b==1)
			*m1 = *m1 + r;
		else
			*m2 = *m2 + r;

		puts("");
		r=(rand()%2+1);
		if(r==1)
		{
			Sleep(2000);
			printf(" !");Sleep(300);printf(" !");Sleep(300);printf(" !");Sleep(300);printf(" !");Sleep(300);printf(" !");Sleep(300);printf(" !");Sleep(300);printf(" !");
			puts("");
			printf("ī���뿡 ������ ���̴�Ĩ�ϴ�. �������� ���ؼ� Enter�� �����ּ���.\n");
			printf("�� ����Ȯ���� ������ ������ �������� �� ���� �ֽ��ϴ�!\n");
			getchar();
			system("cls");
			printf("���� ��");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n\n");Sleep(1000);
			r=(rand()%2+1);
			if(r==1)
			{
				printf("%dP���� Ż�⿡ �������� ���ϰ� �������� ������ �������� ���� ���Խ��ϴ�.\n", b);
				printf("%dP���� ���������� 10������ �½��ϴ�.\n", b);
				if(b==1)
					*m1 = *m1 - 10;
				else
					*m2 = *m2 - 10;
			}
			if(r==2)
			{
				printf("%dP���� �ƽ��ƽ��ϰ� ������ �������µ� �����߽��ϴ�.\n", b);
			}
			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
		}
		else if(r==2)
			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");

		getchar();
		system("cls");
}

	else if(*a==108)
	{
		printf("%dP�� ���� �������� �����ϼ̽��ϴ�.\n", b);
	if(conutry[11]==0)
		{
			puts("");
			printf("�������� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("�������� �ü��� 16�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. �������� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[11]=b;
				if(b==1)
					*m1-=16;
				else
					*m2-=16;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[11]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 32������ 1P���� �ݴϴ�.\n");
				*m1=*m1+32;
				*m2=*m2-32;
			}

		}
		else if(conutry[11]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 32������ 2P���� �ݴϴ�.\n");
			*m2=*m2+32;
			*m1=*m1-32;
		}
		getchar();
	system("cls");
	}
	else if(*a==109)
	{
		printf("%dP�� ���� ��� ���迡 �����ϼ̽��ϴ�. ���ϵ帳�ϴ�!!!\n", b);
		 return luck(b, m1, m2);
	}
	else if(*a==110)
	{
		printf("%dP�� ���� ���帮�忡 �����ϼ̽��ϴ�.\n", b);
		if(conutry[13]==0)
		{
			puts("");
			printf("���帮�忡 ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("���帮���� �ü��� 18�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ���帮���� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[13]=b;
				if(b==1)
					*m1-=18;
				else
					*m2-=18;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[13]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 36������ 1P���� �ݴϴ�.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[13]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 36������ 2P���� �ݴϴ�.\n");
			*m2=*m2+36;
			*m1=*m1-36;
		}
	getchar();
	system("cls");
	}
	else if(*a==111)
	{
		printf("%dP�� ���� �ĸ��� �����ϼ̽��ϴ�.\n", b);
		if(conutry[14]==0)
		{
			puts("");
			printf("�ĸ��� ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("�ĸ��� �ü��� 18�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�.�ĸ��� ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[14]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[14]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 36������ 1P���� �ݴϴ�.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[14]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 36������ 2P���� �ݴϴ�.\n");
			*m2=*m2+36;
			*m1=*m1-36;
		}
		getchar();
	system("cls");
	}
	else if(*a==112)
	{
		system("cls");
		puts("");
		printf("  %dP�� ���� ���迩�࿡ �����ϼ̽��ϴ�.\n", b);
		puts("  ���� ������ �� �� �ִ� ����⸦ Ÿ�� �� �ֽ��ϴ�.");

		puts("\n");
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		printf("��");printf(" ������ �Ҥ�  �� �� �Ӥ� �̰��� �Ԥ� �õ�� �դӸ�ũ�٨֤� ī���� �פ�\n");
		printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==102) printf("�� ");else printf("   ");if(P2.site==102) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==103) printf("�� ");else printf("   ");if(P2.site==103) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==104) printf("�� ");else printf("   ");if(P2.site==104) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==105) printf("�� ");else printf("   ");if(P2.site==105) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==106) printf("�� ");else printf("   ");if(P2.site==106) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==107) printf("�� ");else printf("   ");if(P2.site==107) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");printf("   ");printf("   ");printf("  ��  ");if(conutry[6]==1) printf("�� ");else printf("   ");if(conutry[6]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[7]==1) printf("�� ");else printf("   ");if(conutry[7]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[8]==1) printf("�� ");else printf("   ");if(conutry[8]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[9]==1) printf("�� ");else printf("   ");if(conutry[9]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   ");printf("   "); printf("  ��\n");
		printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
		printf("��");printf("���ī��Ѥ�                                              �� �������� ��\n");
		printf("��");printf("�ѤѤѤѤѤ�    �ѤѤѤѤѤѤѤѤѤ�                      �ӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==101) printf("�� ");else printf("   ");if(P2.site==101) printf(" ��");else printf("   "); printf("  ��   ��                  ��                     ��  ");if(P1.site==108) printf("�� ");else printf("   ");if(P2.site==108) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");printf("   ");printf("   ");printf("  ��   ��  ��  ��  ī  ��  ��                     ��  ");if(conutry[11]==1) printf("�� ");else printf("   ");if(conutry[11]==2) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("�ѤѤѤѤѤ�   ��                  ��                     �ӤѤѤѤѤѤ�\n");
		printf("��");printf(" ����¡ �Ф�    �ѤѤѤѤѤѤѤѤѤ�                      �����ī��٤�\n");
		printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==100) printf("�� ");else printf("   ");if(P2.site==100) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(P1.site==109) printf("�� ");else printf("   ");if(P2.site==109) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");if(conutry[3]==1) printf("�� ");else printf("   ");if(conutry[3]==2) printf(" ��");else printf("   "); printf("  ��                                              ��  "); printf("   "); printf("   "); printf("  ��\n");
		printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
		printf("��");printf(" ī�̷� �Ϥ�                                              �Ӹ��帮��ڤ�\n");
		printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==99) printf("�� ");else printf("   ");if(P2.site==99) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(P1.site==110) printf("�� ");else printf("   ");if(P2.site==110) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");if(conutry[2]==1) printf("�� ");else printf("   ");if(conutry[2]==2) printf(" ��");else printf("   "); printf("  ��                   1P�� ���� ���Դϴ�.        ��  ");if(conutry[13]==1) printf("�� ");else printf("   ");if(conutry[13]==2) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("�ѤѤѤѤѤ�                   2P�� ���� ���Դϴ�.        �ӤѤѤѤѤѤ�\n");
		printf("��");printf("  �� �� �Τ�                                              �� �� �� �� ��\n");
		printf("��");printf("�ѤѤѤѤѤ�                   1P�� �ǹ��� ���Դϴ�.      �ӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==98) printf("�� ");else printf("   ");if(P2.site==98) printf(" ��");else printf("   "); printf("  ��                   2P�� �ǹ��� ���Դϴ�.      ��  ");if(P1.site==111) printf("�� ");else printf("   ");if(P2.site==111) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");if(conutry[1]==1) printf("�� ");else printf("   ");if(conutry[1]==2) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(conutry[14]==1) printf("�� ");else printf("   ");if(conutry[14]==2) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
		printf("��");printf(" START �� ��  �� �� ��� ����û �ߤ� �� �� �� ��  �� ���� �Ӽ��迩��ܤ�\n");
		printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
		printf("��");printf("  ");if(P1.site==97) printf("�� ");else printf("   ");if(P2.site==97) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==116) printf("�� ");else printf("   ");if(P2.site==116) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==115) printf("�� ");else printf("   ");if(P2.site==115) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==114) printf("�� ");else printf("   ");if(P2.site==114) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==113) printf("�� ");else printf("   ");if(P2.site==113) printf(" ��");else printf("   "); printf("  ��  ");if(P1.site==112) printf("�� ");else printf("   ");if(P2.site==112) printf(" ��");else printf("   "); printf("  ��\n");
		printf("��");printf("  ");if(conutry[0]==1) printf("�� ");else printf("   ");if(conutry[0]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[19]==1) printf("�� ");else printf("   ");if(conutry[19]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   ");printf("   "); printf("  ��  ");if(conutry[17]==1) printf("�� ");else printf("   ");if(conutry[17]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[16]==1) printf("�� ");else printf("   ");if(conutry[16]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   "); printf("   "); printf("  ��\n"); 
		puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		trip(a, b, m1, m2);
	}
	else if(*a==113)
	{
		printf("%dP�� ���� ������ �����ϼ̽��ϴ�.\n", b);
		if(conutry[16]==0)
		{
			puts("");
			printf("������ ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("������ �ü��� 20�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ������ ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[16]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[16]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 40������ 1P���� �ݴϴ�.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[16]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 40������ 2P���� �ݴϴ�.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==114)
	{
		printf("%dP�� ���� ���忡 �����ϼ̽��ϴ�.\n", b);
		if(conutry[17]==0)
		{
			puts("");
			printf("���忡 ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("������ �ü��� 20�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ������ ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[17]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[17]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 40������ 1P���� �ݴϴ�.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[17]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 40������ 2P���� �ݴϴ�.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==115)
	{
		printf("%dP�� ���� ����û�� �����ϼ̽��ϴ�. �Ʊ�����.. ������ ���ž� �մϴ�.\n", b);
		printf("10������ �������� ���̽��ϴ�.\n");
		if(b==1)
			*m1 = *m1 - 10;
		else
			*m2 = *m2 - 10;
	}
	else if(*a==116)
	{
		printf("%dP�� ���� ���￡ �����ϼ̽��ϴ�.\n", b);
		if(conutry[19]==0)
		{
			puts("");
			printf("���￡ ���Ű� ȯ���մϴ�.\n");Sleep(2000);
			printf("������ �ü��� 25�����Դϴ�. ��ðڽ��ϱ�?\n");
			printf("[YES��� 1�� �Է�, NO��� 0�� �Է����ֽñ� �ٶ��ϴ�.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP�� ���� �����Դϴ�. ������ ��Ű��� ���ϵ帳�ϴ�.\n", b);Sleep(2000);
				conutry[19]=b;
				if(b==1)
					*m1-=25;
				else
					*m2-=25;
			}
			else if(y==0)
			{
				printf("�ƽ����� ������ �������. �ȳ��� ���ñ� �ٶ��ϴ�.\n");Sleep(2000);
			}

			printf("\n�ٽ� ������ �����մϴ�. Enter�� �����ֽñ� �ٶ��ϴ�.");
			getchar();
		}
		else if(conutry[19]==1)
		{
			if(b==1)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
			{
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 50������ 1P���� �ݴϴ�.\n");
				*m1=*m1+50;
				*m2=*m2-50;
			}

		}
		else if(conutry[19]==2)
		{
			if(b==2)
				printf("�ڽ��� �� ���Դϴ�.\n");
			else
				printf("�ڽ��� ���� �ƴ� ���� �����߱� ������ �̿��� 50������ 2P���� �ݴϴ�.\n");
			*m2=*m2+50;
			*m1=*m1-50;
		}
		getchar();
		system("cls");
	}
	
	puts("");
	return 1;
}
void trip(int *s, int b, int *m1, int *m2)
{
	char a;
	puts("  ���� ���� ���� ���� ������ ���� �ִ� �ҹ��� ���ĺ��� ���� Enter�� �����ּ���.");
	scanf("%c",&a);
	
	if((a>='a')&&(a<='t'))
	{
		*s=((int)a);
		system("cls");
	}

	else if(a=='\n')
	{
		*s=112;
		system("cls");
	}
	else if((a<'a')&&(a>'t'))
	{
		*s=112;
		system("cls");
	}
	fflush(stdin);
	respon(s, b, m1, m2);
}
int dice(int a)
{
	int i=0,c=0;
	puts("");
	printf(" %dP�� �ֻ����� ������ �غ� �Ǽ̴ٸ� �������� Enter�� �����ֽñ� �ٶ��ϴ�!!!\n", a);
	getchar();
	for(c=1;c<=200;c++)
	{
		srand(time(NULL));
		i = (rand()%6)+1;
		puts("");
		printf(" �ֻ����� ������ ���Դϴ�...\n");
		puts("");
		system("cls");
		switch(i)
		{
		case 1:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  ��        ��");
			puts("  ��   ��   ��");
			puts("  ��        ��");
			puts("   �ѤѤѤѤ�");
			break;

		case 2:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  ��        ��");
			puts("  �� ��  �� ��");
			puts("  ��        ��");
			puts("   �ѤѤѤѤ�");;
			break;

		case 3:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  ��     �� ��");
			puts("  ��   ��   �� ");
			puts("  �� ��     ��");
			puts("   �ѤѤѤѤ�");
			break;

		case 4:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  �� ��  �� ��");
			puts("  ��        ��");
			puts("  �� ��  �� ��");
			puts("   �ѤѤѤѤ�");
			break;

		case 5:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  �� ��  �� ��");
			puts("  ��   ��   ��");
			puts("  �� ��  �� ��");
			puts("   �ѤѤѤѤ�");
			break;

		case 6:
			puts("");
			puts("   �ѤѤѤѤ�");
			puts("  �� ��  �� ��");
			puts("  �� ��  �� ��");
			puts("  �� ��  �� ��");
			puts("   �ѤѤѤѤ�");
			break;

		}
		if(c==200)
		{
			printf("\n %dP���� �ֻ����� ���� ����� %d�Դϴ�.\n", a, i);
			printf("\n�� �������� �����Ͻ÷��� Enter�� �����ֽñ� �ٶ��ϴ�");
			getchar();
			system("cls");
			return i;
		}
	}

}
int rank()
{
	int a=0, b=0;

	printf("\n �� �ִ� ���� ���� ������ �ο��� 2��;�Դϴ�.\n");
	printf("\n �� 1P�� ���� ���Դϴ�. \n");
	printf("    1P�� �ǹ��� ���Դϴ�.\n\n");
	printf(" �� 2P�� ���� ���Դϴ�.\n");
	printf("    2P�� �ǹ��� ���Դϴ�.\n\n");

	puts(" �� 1P�� 2P�� ���� ������ ������ ���ϱ� ���� �ֻ����� �����ڽ��ϴ�.\n");
	puts(" �� ��� �����Ͻ÷��� Enter�� �����ֽñ� �ٶ��ϴ�. ");
	getchar();
	system("cls");

RE:

	puts("");
	puts(" �� 1P ����ں��� �ֻ����� �����ڽ��ϴ�.");
	puts("");
	a=dice(1);

	puts("");
	puts(" �� 2P ����ڰ� �ֻ����� �����ڽ��ϴ�.");
	puts("");
	b=dice(2);

	if(a==b)
	{
		puts("");
		puts(" �� 1P�� 2P�� �ֻ����� ����� �����Ƿ� �ٽ� �����ڽ��ϴ�.");
		goto RE;
	}
	else if(a<b)
	{
		puts("");
		puts(" �� 2P�� �ֻ��� ����� �� �����Ƿ� 2P���� ������ �����մϴ�.");
		return 1;
	}
	else if(a>b)
	{
		puts("");
		puts(" �� 1P�� �ֻ��� ����� �� �����Ƿ� 1P���� ������ �����մϴ�.");
		return 0;
	}
}
void map1()
{
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	printf("��");printf(" ������ �Ҥ�  �� �� �Ӥ� �̰��� �Ԥ� �õ�� �դӸ�ũ�٨֤� ī���� �פ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("          ��   8����  ��   8����  ��  10����  ��  10����  ��          ��\n");
	printf("��");printf("  -20���� ��          ��          ��          ��          ��   ����   ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("���ī��Ѥ�                                              �� �������� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�    �ѤѤѤѤѤѤѤѤѤ�                      �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  good    ��   ��                  ��                     ��  16����  ��\n");
	printf("��");printf("    luck! ��   ��  ��  ��  ī  ��  ��                     ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤ�   ��                  ��                     �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ����¡ �Ф�    �ѤѤѤѤѤѤѤѤѤ�                      �����ī��٤�\n");
	printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   5����  ��                                              �� good     ��\n");
	printf("��");printf("          ��                                              ��    luck! ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ī�̷� �Ϥ�                                              �Ӹ��帮��ڤ�\n");
	printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   4����  ��                                              ��  18����  ��\n");
	printf("��");printf("          ��                   1P�� ���� ���Դϴ�.        ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                   2P�� ���� ���Դϴ�.        �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  �� �� �Τ�                                              �� �� �� �� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                   1P�� �ǹ��� ���Դϴ�.      �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   3����  ��                   2P�� �ǹ��� ���Դϴ�.      ��  18����  ��\n");
	printf("��");printf("          ��                                              ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf(" START �� ��  �� �� ��� ����û �ߤ� �� �� �� ��  �� ���� �Ӽ��迩��ܤ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("  �պ� �� ��  25����  ��          ��  20����  ��  20����  ��  go~     ��\n");
	printf("��");printf("  +20���� ��          �� -10����  ��          ��          ��      go~ ��\n");
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
}
void mainmap()
{
	puts("\n");
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	printf("��");printf(" ������ �Ҥ�  �� �� �Ӥ� �̰��� �Ԥ� �õ�� �դӸ�ũ�٨֤� ī���� �פ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("          ��   8����  ��   8����  ��  10����  ��  10����  ��          ��\n");
	printf("��");printf("  -20���� ��          ��          ��          ��          ��   ����   ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("���ī��Ѥ�                                              �� �������� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�         ��    ��         �����            �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  good    ��         ��    ��               ��            ��  16����  ��\n");
	printf("��");printf("    luck! ��         �����         �����            ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤ�         ��    ��         ��                  �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ����¡ �Ф�         �����         �����            �����ī��٤�\n");
	printf("��");printf("�ѤѤѤѤѤ�       �������     �������          �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   5����  ��            ��               ��               �� good     ��\n");
	printf("��");printf("          ��            ��               ��               ��    luck! ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                       ��        ��    ��     �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ī�̷� �Ϥ�             �����  ��        �����     �Ӹ��帮��ڤ�\n");
	printf("��");printf("�ѤѤѤѤѤ�             ��    ��  ����    ��    ��     �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   4����  ��             ��    ��  ��        �����     ��  18����  ��\n");
	printf("��");printf("          ��             �����  ��    ��������� ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                       ��        �����     �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  �� �� �Τ�                                       ��     �� �� �� �� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�      ver 1.0                    �����     �ӤѤѤѤѤѤ�\n");
	printf("��");printf("   3����  ��                                 ��           ��  18����  ��\n");
	printf("��");printf("          ��                                 �����     ��          ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf(" START �� ��  �� �� ��� ����û �ߤ� �� �� �� ��  �� ���� �Ӽ��迩��ܤ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("  �պ� �� ��  25����  ��          ��  20����  ��  20����  ��  go~     ��\n");
	printf("��");printf("  +20���� ��          ��  -10���� ��          ��          ��      go~ ��\n");
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	puts("");
	puts("		�η縶���� ���迡 ���Ű� ȯ���մϴ٤�����");
	puts("		�����Ͻ÷��� Enter�� �����ֽñ� �ٶ��ϴ�.");
	getchar();
	system("cls");
}
void realmap(int *a, int *b,int *m1, int *m2)
{
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	printf("��");printf(" ������ �Ҥ�  �� �� �Ӥ� �̰��� �Ԥ� �õ�� �դӸ�ũ�٨֤� ī���� �פ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==102) printf("�� ");else printf("   ");if(*b==102) printf(" ��");else printf("   "); printf("  ��  ");if(*a==103) printf("�� ");else printf("   ");if(*b==103) printf(" ��");else printf("   "); printf("  ��  ");if(*a==104) printf("�� ");else printf("   ");if(*b==104) printf(" ��");else printf("   "); printf("  ��  ");if(*a==105) printf("�� ");else printf("   ");if(*b==105) printf(" ��");else printf("   "); printf("  ��  ");if(*a==106) printf("�� ");else printf("   ");if(*b==106) printf(" ��");else printf("   "); printf("  ��  ");if(*a==107) printf("�� ");else printf("   ");if(*b==107) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");printf("   ");printf("   ");printf("  ��  ");if(conutry[6]==1) printf("�� ");else printf("   ");if(conutry[6]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[7]==1) printf("�� ");else printf("   ");if(conutry[7]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[8]==1) printf("�� ");else printf("   ");if(conutry[8]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[9]==1) printf("�� ");else printf("   ");if(conutry[9]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   ");printf("   "); printf("  ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("���ī��Ѥ�                                              �� �������� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�    �ѤѤѤѤѤѤѤѤѤ�                      �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==101) printf("�� ");else printf("   ");if(*b==101) printf(" ��");else printf("   "); printf("  ��   ��                  ��                     ��  ");if(*a==108) printf("�� ");else printf("   ");if(*b==108) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");printf("   ");printf("   ");printf("  ��   ��  ��  ��  ī  ��  ��                     ��  ");if(conutry[11]==1) printf("�� ");else printf("   ");if(conutry[11]==2) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("�ѤѤѤѤѤ�   ��                  ��                     �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ����¡ �Ф�    �ѤѤѤѤѤѤѤѤѤ�                      �����ī��٤�\n");
	printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==100) printf("�� ");else printf("   ");if(*b==100) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(*a==109) printf("�� ");else printf("   ");if(*b==109) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");if(conutry[3]==1) printf("�� ");else printf("   ");if(conutry[3]==2) printf(" ��");else printf("   "); printf("  ��                                              ��  "); printf("   "); printf("   "); printf("  ��\n");
	printf("��");printf("�ѤѤѤѤѤ�");printf("    1P money : %3d����", *m1);printf("   2P money : %3d����", *m2);printf("   �ӤѤѤѤѤѤ�\n");
	printf("��");printf(" ī�̷� �Ϥ�                                              �Ӹ��帮��ڤ�\n");
	printf("��");printf("�ѤѤѤѤѤ�                                              �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==99) printf("�� ");else printf("   ");if(*b==99) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(*a==110) printf("�� ");else printf("   ");if(*b==110) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");if(conutry[2]==1) printf("�� ");else printf("   ");if(conutry[2]==2) printf(" ��");else printf("   "); printf("  ��                   1P�� ���� ���Դϴ�.        ��  ");if(conutry[13]==1) printf("�� ");else printf("   ");if(conutry[13]==2) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                   2P�� ���� ���Դϴ�.        �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  �� �� �Τ�                                              �� �� �� �� ��\n");
	printf("��");printf("�ѤѤѤѤѤ�                   1P�� ���� ���Դϴ�.        �ӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==98) printf("�� ");else printf("   ");if(*b==98) printf(" ��");else printf("   "); printf("  ��                   2P�� ���� ���Դϴ�.        ��  ");if(*a==111) printf("�� ");else printf("   ");if(*b==111) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");if(conutry[1]==1) printf("�� ");else printf("   ");if(conutry[1]==2) printf(" ��");else printf("   "); printf("  ��                                              ��  ");if(conutry[14]==1) printf("�� ");else printf("   ");if(conutry[14]==2) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf(" START �� ��  �� �� ��� ����û �ߤ� �� �� �� ��  �� ���� �Ӽ��迩��ܤ�\n");
	printf("��");printf("�ѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤӤѤѤѤѤѤ�\n");
	printf("��");printf("  ");if(*a==97) printf("�� ");else printf("   ");if(*b==97) printf(" ��");else printf("   "); printf("  ��  ");if(*a==116) printf("�� ");else printf("   ");if(*b==116) printf(" ��");else printf("   "); printf("  ��  ");if(*a==115) printf("�� ");else printf("   ");if(*b==115) printf(" ��");else printf("   "); printf("  ��  ");if(*a==114) printf("�� ");else printf("   ");if(*b==114) printf(" ��");else printf("   "); printf("  ��  ");if(*a==113) printf("�� ");else printf("   ");if(*b==113) printf(" ��");else printf("   "); printf("  ��  ");if(*a==112) printf("�� ");else printf("   ");if(*b==112) printf(" ��");else printf("   "); printf("  ��\n");
	printf("��");printf("  ");if(conutry[0]==1) printf("�� ");else printf("   ");if(conutry[0]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[19]==1) printf("�� ");else printf("   ");if(conutry[19]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   ");printf("   "); printf("  ��  ");if(conutry[17]==1) printf("�� ");else printf("   ");if(conutry[17]==2) printf(" ��");else printf("   "); printf("  ��  ");if(conutry[16]==1) printf("�� ");else printf("   ");if(conutry[16]==2) printf(" ��");else printf("   "); printf("  ��  ");printf("   "); printf("   "); printf("  ��\n"); 
	puts(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
}