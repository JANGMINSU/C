#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i;

	struct stu{
		char name[10];
		int sid;
		int ko;
		int en;
		int ma;
		int sum;
		double avg;
	};

	struct stu peo[10];

	for(i=0;i<3;i++)
	{
		printf("����� �̸���? ");
		gets(peo[i].name);
		printf("����� �й���? ");
		scanf("%d", &peo[i].sid);
		printf("����� ���� ������? ");
		scanf("%d", &peo[i].ko);
		printf("����� ���� ������? ");
		scanf("%d", &peo[i].en);
		printf("����� ���� ������? ");
		scanf("%d", &peo[i].ma);
		peo[i].sum = peo[i].ko + peo[i].en + peo[i].ma;
		peo[i].avg = (peo[i].sum)/3.0;
		printf("\n");
		fflush(stdin);
	}
	for(i=0;i<3;i++)
	{
		puts("����� �̸� : ");
		puts(peo[i].name); printf("\n");
		printf("�й� : %d\n", peo[i].sid);
		printf("���� ���� : %d\n", peo[i].ko);
		printf("���� ���� : %d\n", peo[i].en);
		printf("���� ���� : %d\n", peo[i].ma);
		printf("���� : %d\n", peo[i].sum);
		printf("��� : %.2f\n", peo[i].avg);
		printf("\n");
	}
}
