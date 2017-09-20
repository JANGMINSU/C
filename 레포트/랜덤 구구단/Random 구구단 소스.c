#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main() 
{
	int x=0,y=0,z=0;   //x, y는 랜덤으로 숫자 값을 받을 변수입니다.  z는 사용자가 생각하는 답을 입력하는 변수입니다.
	int a=0;		 //숫자를 입력받아 문제를 어떻게 출제할것인지 및 종료할 것인지 결정하는 변수입니다.

	while(1) 
	{
		printf("0을 누르면 단이 랜덤 구구단 문제가 나옵니다.\n10 미만의 수를 입력 시 입력 받은 수의 단 중에서 랜덤으로 문제가 나옵니다.\n!!10보다 큰수를 치면 프로그램을 종료합니다.\n");
		srand(time(NULL));  //랜덤함수 선언
		x=(rand()%9)+1;		//1~9자리의 랜덤 함수
		y=(rand()%9)+1;		//1~9자리의 랜덤 함수

		fflush(stdin);
		scanf("%d", &a);		//문제를 어떻게 출제할 것인지 및 종료할 것인지 입력 받습니다.

		if(a>=10)				//만약 입력받은 수가 10보다 크다면 프로그램을 종료합니다
		break;

		else if(a==0)			//만약 입력받은 수가 0이라면 랜덤으로 문제를 출제합니다. 
		{
			printf("%d단에 대한 문제입니다\n",x);
			printf("%d * %d =\n", x, y);
			scanf("%d",&z);
			if((x*y)==z){
				printf("정답입니다^_^\n");
			}
			else
				printf("틀렸습니다ㅠ_ㅠ\n");
		}

		else					//입력 받은 숫자를 사용하여 입력받은 단에서 랜덤으로 문제를 출제합니다.
		{	
			printf("%d단에 대한 문제입니다\n",a);
			printf("%d * %d =\n", a, y);
			scanf("%d",&z);
			if(((a)*y)==z){
				printf("정답입니다^_^\n");
			}
			else
				printf("틀렸습니다ㅠ_ㅠ\n");
		}

	}
}
