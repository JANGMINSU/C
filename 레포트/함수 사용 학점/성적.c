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
	printf("점수를 입력해주세요.\n");
	printf("사고와 표현     : ");
	scanf("%d", &dat[0]);
	printf("논리회로설계    : ");
	scanf("%d", &dat[1]);
	printf("C언어프로그래밍 : ");
	scanf("%d", &dat[2]);
	printf("실용영어2       : ");
	scanf("%d", &dat[3]);
	printf("전산수학        : ");
	scanf("%d", &dat[4]);
	printf("아름다운리더    : ");
	scanf("%d", &dat[5]);
	printf("**********************************\n");
	printf("   과목명       점수       학점\n");
	printf("**********************************\n");
	printf("사고와 표현     ");
	prin();
	printf("----------------------------------\n");
	printf("논리회로설계    ");
	prin();
	printf("----------------------------------\n");
	printf("C언어프로그래밍 ");
	prin();
	printf("----------------------------------\n");
	printf("실용영어2       ");
	prin();
	printf("----------------------------------\n");
	printf("전산수학        ");
	prin();
	printf("----------------------------------\n");
	printf("아름다운리더    ");
	prin();
	printf("----------------------------------\n");
	printf("   총점       평균\n");
	su();	
}