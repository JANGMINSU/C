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
		printf("당신의 이름은? ");
		gets(peo[i].name);
		printf("당신의 학번은? ");
		scanf("%d", &peo[i].sid);
		printf("당신의 국어 성적은? ");
		scanf("%d", &peo[i].ko);
		printf("당신의 영어 성적은? ");
		scanf("%d", &peo[i].en);
		printf("당신의 수학 성적은? ");
		scanf("%d", &peo[i].ma);
		peo[i].sum = peo[i].ko + peo[i].en + peo[i].ma;
		peo[i].avg = (peo[i].sum)/3.0;
		printf("\n");
		fflush(stdin);
	}
	for(i=0;i<3;i++)
	{
		puts("당신의 이름 : ");
		puts(peo[i].name); printf("\n");
		printf("학번 : %d\n", peo[i].sid);
		printf("국어 성적 : %d\n", peo[i].ko);
		printf("영어 성적 : %d\n", peo[i].en);
		printf("수학 성적 : %d\n", peo[i].ma);
		printf("총점 : %d\n", peo[i].sum);
		printf("평균 : %.2f\n", peo[i].avg);
		printf("\n");
	}
}
