#include <stdio.h>
int dat[6];

void prin()
{
	static int i=0;
	printf("%d", dat[i]);
	switch(dat[i]/5)
	{
	case 19: printf("\t   A+\n"); break;
	case 18: printf("\t   A0\n");break;
	case 17: printf("\t   B+\n");break;
	case 16: printf("\t   B0\n");break;
	case 15: printf("\t   C+\n");break;
	case 14: printf("\t   C0\n");break;
	case 13: printf("\t   D+\n");break;
	case 12: printf("\t   D0\n");break;
	default: printf("\t   F \n");break;
	}
	i++;
	return;
}

int su()
{
	int i=0, sum=0;
	float suv=0;
	for(i=0; i<6; i++)
		sum=sum+dat[i];
	suv=(float)sum/6;
	printf("    %d       %.2f\n", sum, suv);
}

void main()
{
	int a, b;
	printf("������ �Է����ּ���.\n");
	printf("���� ǥ��     : ");
	scanf("%d", &dat[0]);
	printf("��ȸ�μ���    : ");
	scanf("%d", &dat[1]);
	printf("C������α׷��� : ");
	scanf("%d", &dat[2]);
	printf("�ǿ뿵��2       : ");
	scanf("%d", &dat[3]);
	printf("�������        : ");
	scanf("%d", &dat[4]);
	printf("�Ƹ��ٿ��    : ");
	scanf("%d", &dat[5]);
	printf("**********************************\n");
	printf("   �����       ����       ����\n");
	printf("**********************************\n");
	printf("���� ǥ��     ");
	prin();
	printf("----------------------------------\n");
	printf("��ȸ�μ���    ");
	prin();
	printf("----------------------------------\n");
	printf("C������α׷��� ");
	prin();
	printf("----------------------------------\n");
	printf("�ǿ뿵��2       ");
	prin();
	printf("----------------------------------\n");
	printf("�������        ");
	prin();
	printf("----------------------------------\n");
	printf("�Ƹ��ٿ��    ");
	prin();
	printf("----------------------------------\n");
	printf("   ����       ���\n");
	su();	
}