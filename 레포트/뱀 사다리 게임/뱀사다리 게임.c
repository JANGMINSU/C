#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	int a=0; //��������(�ֻ��� ����)
	int total1=0, total2=0; //(���� �������� ��)
	int num1, num2;  //���� ���� ��

	for(;;)
	{
		srand(time(NULL));  //�����Լ�
		a=(rand()%6)+1;

		printf("! 1.���� 2.���� 3.�� !\n");
		printf("ù��° ��� : ");
		scanf("%d", &num1);

		printf("�ι�° ��� : ");
		scanf("%d", &num2);

		if((num1==1&&num2==3)||(num1==2&&num2==1)||(num1==3&&num2==2))
		{
			printf("ù��° ��� �¸��� �¸��Ͽ����ϴ�.\n\n");

			total1+=a;				//ù���� �÷��̾�
			printf("�ֻ����� ������ ���� ���ڴ� %d�Դϴ�.\n\n", a);

			switch(total1)
			{
			case 9:
				total1=31; printf("��ٸ��� Ÿ�� 31�� �̵��մϴ�.\n"); break;
			case 4:
				total1=13; printf("��ٸ��� Ÿ�� 13���� �̵��մϴ�.\n"); break;
			case 21:
				total1=42; printf("��ٸ��� Ÿ�� 42�� �̵��մϴ�.\n"); break;
			case 1:
				total1=38; printf("��ٸ��� Ÿ�� 38�� �̵��մϴ�.\n"); break;
			case 28:
				total1=84; printf("��ٸ��� Ÿ�� 84�� �̵��մϴ�.\n"); break;
			case 51:
				total1=67; printf("��ٸ��� Ÿ�� 67�� �̵��մϴ�.\n"); break;
			case 73:
				total1=91; printf("��ٸ��� Ÿ�� 91�� �̵��մϴ�.\n");  break;
			case 80:
				total1=100; printf("��ٸ��� Ÿ�� 100���� �̵��մϴ�.\n"); break;
			case 36:
				total1=44; printf("��ٸ��� Ÿ�� 44�� �̵��մϴ�.\n"); break;
			case 16:
				total1=6; printf("���� Ÿ�� 6���� �̵��մϴ�.\n"); break;
			case 49:
				total1=11; printf("���� Ÿ�� 11�� �̵��մϴ�.\n"); break;
			case 47:
				total1=26; printf("���� Ÿ�� 26���� �̵��մϴ�.\n"); break;
			case 56:
				total1=53; printf("���� Ÿ�� 53���� �̵��մϴ�.\n"); break;
			case 87:
				total1=24; printf("���� Ÿ�� 87�� �̵��մϴ�.\n"); break;
			case 64:
				total1=60; printf("���� Ÿ�� 60���� �̵��մϴ�.\n"); break;
			case 62:
				total1=19; printf("���� Ÿ�� 19�� �̵��մϴ�.\n"); break;
			case 98:
				total1=78; printf("���� Ÿ�� 78�� �̵��մϴ�.\n"); break;
			case 95:
				total1=75; printf("���� Ÿ�� 75�� �̵��մϴ�.\n"); break;
			case 93:
				total1=73; printf("���� Ÿ�� 73���� �̵��մϴ�.\n"); break;
			}
			if(total1>=100)
			{
				printf("�����մϴ�!!! ù��° �÷��̾ �¸��Ͽ����ϴ�.\n");
				return;
			}
			printf("���� ù��° �÷��̾��� ��ġ�� %d�Դϴ�.\n\n",total1);
		}

		else if((num2==1&&num1==3)||(num2==2&&num1==1)||(num2==3&&num1==2))
		{
			printf("�ι�° ��� �¸��Ͽ����ϴ�.\n\n");

			total2+=a;						//�ι��� �÷��̾�
			printf("�ֻ����� ������ ���� ���ڴ� %d�Դϴ�.\n\n", a);

			switch(total2)
			{
			case 9:
				total2=31; printf("��ٸ��� Ÿ�� 31�� �̵��մϴ�.\n"); break;
			case 4:
				total2=13; printf("��ٸ��� Ÿ�� 13���� �̵��մϴ�.\n"); break;
			case 21:
				total2=42; printf("��ٸ��� Ÿ�� 42�� �̵��մϴ�.\n"); break;
			case 1:
				total2=38; printf("��ٸ��� Ÿ�� 38�� �̵��մϴ�.\n"); break;
			case 28:
				total2=84; printf("��ٸ��� Ÿ�� 84�� �̵��մϴ�.\n"); break;
			case 51:
				total2=67; printf("��ٸ��� Ÿ�� 67�� �̵��մϴ�.\n"); break;
			case 73:
				total2=91; printf("��ٸ��� Ÿ�� 91�� �̵��մϴ�.\n");  break;
			case 80:
				total2=100; printf("��ٸ��� Ÿ�� 100���� �̵��մϴ�.\n"); break;
			case 36:
				total2=44; printf("��ٸ��� Ÿ�� 44�� �̵��մϴ�.\n"); break;
			case 16:
				total2=6; printf("���� Ÿ�� 6���� �̵��մϴ�.\n"); break;
			case 49:
				total2=11; printf("���� Ÿ�� 11�� �̵��մϴ�.\n"); break;
			case 47:
				total2=26; printf("���� Ÿ�� 26���� �̵��մϴ�.\n"); break;
			case 56:
				total2=53; printf("���� Ÿ�� 53���� �̵��մϴ�.\n"); break;
			case 87:
				total2=24; printf("���� Ÿ�� 87�� �̵��մϴ�.\n"); break;
			case 64:
				total2=60; printf("���� Ÿ�� 60���� �̵��մϴ�.\n"); break;
			case 62:
				total2=19; printf("���� Ÿ�� 19�� �̵��մϴ�.\n"); break;
			case 98:
				total2=78; printf("���� Ÿ�� 78�� �̵��մϴ�.\n"); break;
			case 95:
				total2=75; printf("���� Ÿ�� 75�� �̵��մϴ�.\n"); break;
			case 93:
				total2=73; printf("���� Ÿ�� 73���� �̵��մϴ�.\n"); break;
			}
			if(total2>=100)
			{
				printf("�����մϴ�!!! �ι�° �÷��̾ �¸��Ͽ����ϴ�.\n");
				return;
			}
			printf("���� �ι�° �÷��̾��� ��ġ�� %d�Դϴ�.\n\n",total2);
		}
		else if((num1==1&&num2==1)||(num1==2&&num2==2)||(num1==3&&num2==3))
		{
			printf("�����ϴ�. �ٽ� ������������ �Է����ֽñ� �ٶ��ϴ�.\n\n");
		}
		else
		{
			printf("�����Դϴ�. �ٽ� ������������ �Է����ֽñ� �ٶ��ϴ�.\n\n");
		}
	}
}