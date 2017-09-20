#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, k, m;			// 반복문에서 사용할 변수입니다.
	int ran[3], num[3];		// 랜덤 숫자와 사용자가 입력할 숫자입니다.
	int count=0;			// 스트라이크의 횟수를 세어주는 프로그램입니다.
	int sum1[10]={0},sum2[10]={0};		// 경기마다의 점수 및 총점을 나타내는 변수입니다.

	srand(time(NULL));

	printf("야구 게임입니다.\na팀과 b팀을 결정하여 주세요\n\n");

	for(m=1;m<19;m++)										// 모든 야구 경기를 하기 위해서 18번 반복하는 반복문 생성
	{
		if(m%2==1)												//만약 m을 2로 나누었을 경우 홀수일 경우 a팀의 공격
			printf("%d회 초 a팀의 공격 순서입니다.\n",m/2+1);
		else													//나머지는 b팀의 공격
			printf("%d회 말 b팀의 공격 순서입니다.\n",m/2);

		for(i=0;i<3;i++)									
		{
			ran[i]=(rand()%9)+1;								//랜덤 함수를 입력
			if(i==1)											//만약 2번째 자리를 결정할때 1번째 자리와 수가 같다면 i에서 1을 뺌으로서 다시 랜덤으로 2번째 자리의 수를 결정
			{
			if(ran[i]==ran[i-1])
				i--;
			}
			else if(i==2)										//만약 3번째 자리를 결정할때 1번째 자리와 2번째 자리와 같다면 i에서 1을 뺌으로서 다시 랜덤으로 3번째 자리의 수를 결정
			{
				if((ran[i]==ran[i-1])&&(ran[i]==ran[i-2]))
					i--;
			}
		}

		count=0;											//스트라이크의 횟수를 초기화

		for(k=1;k<=10;k++)									//공격 횟수는 총 10회로서 10번 도는 반복문을 생성
		{	
			printf("숫자 입력시 한칸씩 띄어쓰기를 하면서 하나씩 입력해주시기 바랍니다.\n%d번째 공격! 입력 숫자 :",k);
			for(i=0;i<3;i++)							//사용자의 수를 입력
			{
				scanf("%d",&num[i]);
			}

			for(i=0;i<3;i++)						// 컴퓨터가 입력한 랜덤 수와 사용자의 입력 수를 비교, 비교 후 맞을 경우 스트라이크를 증가
			{
				if(ran[i]==num[i])
					count++;
			}
			if(count<3)								//카운트의 횟수가 3회 미만일 경우 스트라이크의 횟수를 출력
			{
				printf("결과 : % d스트라이크\n", count);
			}
			else if(count>=3)						//스트라이크의 횟수가 3회 이상일 경우 스트라이크 횟수를 3회로 출력 후 수비를 교체 
			{
				printf("결과 : 3 스트라이크");
				printf("3점 획득 성공! 수비 교체\n");

			if(m%2==1)								//만약 m을 2로 나누었을 때 1이 남을 경우 a팀의 (m/2+1)-1회 경기에 3점을 더한다.
			sum1[(m/2+1)-1]+=3;
			else
			sum2[(m/2)-1]+=3;						//나머지의 경우는 b팀의 (m/2)-1회 경기에 3점을 더한다.
			break;
			}
		}
		if(count<3)									//스트라이크 3회를 실패한 경우
			printf("3점 획득 실패! 수비 교체\n");
	}
	for(i=0;i<9;i++)						// 모든 경기 후 1~9회까지의 a, b팀의 총점을 더함
	{
		sum1[9]+=sum1[i];
		sum2[9]+=sum2[i];
	}
	printf("	1  2  3  4  5  6  7  8  9  총점\n");					//a, b팀의 1~9회까지의 점수와 총점을 출력함
	printf("	-----------------------------------------\n");
	printf("a	");for(i=0;i<=9;i++){printf("%d  ",sum1[i]);}printf("\n");
	printf("b	");for(i=0;i<=9;i++){printf("%d  ",sum2[i]);}printf("\n");
}

