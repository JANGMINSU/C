#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	int a=0; //랜덤숫자(주사위 숫자)
	int total1=0, total2=0; //(전부 더해지는 값)
	int num1, num2;  //가위 바위 보

	for(;;)
	{
		srand(time(NULL));  //랜덤함수
		a=(rand()%6)+1;

		printf("! 1.가위 2.바위 3.보 !\n");
		printf("첫번째 사람 : ");
		scanf("%d", &num1);

		printf("두번째 사람 : ");
		scanf("%d", &num2);

		if((num1==1&&num2==3)||(num1==2&&num2==1)||(num1==3&&num2==2))
		{
			printf("첫번째 사람 승리이 승리하였습니다.\n\n");

			total1+=a;				//첫번재 플레이어
			printf("주사위를 굴려서 나온 숫자는 %d입니다.\n\n", a);

			switch(total1)
			{
			case 9:
				total1=31; printf("사다리를 타고 31로 이동합니다.\n"); break;
			case 4:
				total1=13; printf("사다리를 타고 13으로 이동합니다.\n"); break;
			case 21:
				total1=42; printf("사다리를 타고 42로 이동합니다.\n"); break;
			case 1:
				total1=38; printf("사다리를 타고 38로 이동합니다.\n"); break;
			case 28:
				total1=84; printf("사다리를 타고 84로 이동합니다.\n"); break;
			case 51:
				total1=67; printf("사다리를 타고 67로 이동합니다.\n"); break;
			case 73:
				total1=91; printf("사다리를 타고 91로 이동합니다.\n");  break;
			case 80:
				total1=100; printf("사다리를 타고 100으로 이동합니다.\n"); break;
			case 36:
				total1=44; printf("사다리를 타고 44로 이동합니다.\n"); break;
			case 16:
				total1=6; printf("뱀을 타고 6으로 이동합니다.\n"); break;
			case 49:
				total1=11; printf("뱀을 타고 11로 이동합니다.\n"); break;
			case 47:
				total1=26; printf("뱀을 타고 26으로 이동합니다.\n"); break;
			case 56:
				total1=53; printf("뱀을 타고 53으로 이동합니다.\n"); break;
			case 87:
				total1=24; printf("뱀을 타고 87로 이동합니다.\n"); break;
			case 64:
				total1=60; printf("뱀을 타고 60으로 이동합니다.\n"); break;
			case 62:
				total1=19; printf("뱀을 타고 19로 이동합니다.\n"); break;
			case 98:
				total1=78; printf("뱀을 타고 78로 이동합니다.\n"); break;
			case 95:
				total1=75; printf("뱀을 타고 75로 이동합니다.\n"); break;
			case 93:
				total1=73; printf("뱀을 타고 73으로 이동합니다.\n"); break;
			}
			if(total1>=100)
			{
				printf("축하합니다!!! 첫번째 플레이어가 승리하였습니다.\n");
				return;
			}
			printf("현재 첫번째 플레이어의 위치는 %d입니다.\n\n",total1);
		}

		else if((num2==1&&num1==3)||(num2==2&&num1==1)||(num2==3&&num1==2))
		{
			printf("두번째 사람 승리하였습니다.\n\n");

			total2+=a;						//두번재 플레이어
			printf("주사위를 굴려서 나온 숫자는 %d입니다.\n\n", a);

			switch(total2)
			{
			case 9:
				total2=31; printf("사다리를 타고 31로 이동합니다.\n"); break;
			case 4:
				total2=13; printf("사다리를 타고 13으로 이동합니다.\n"); break;
			case 21:
				total2=42; printf("사다리를 타고 42로 이동합니다.\n"); break;
			case 1:
				total2=38; printf("사다리를 타고 38로 이동합니다.\n"); break;
			case 28:
				total2=84; printf("사다리를 타고 84로 이동합니다.\n"); break;
			case 51:
				total2=67; printf("사다리를 타고 67로 이동합니다.\n"); break;
			case 73:
				total2=91; printf("사다리를 타고 91로 이동합니다.\n");  break;
			case 80:
				total2=100; printf("사다리를 타고 100으로 이동합니다.\n"); break;
			case 36:
				total2=44; printf("사다리를 타고 44로 이동합니다.\n"); break;
			case 16:
				total2=6; printf("뱀을 타고 6으로 이동합니다.\n"); break;
			case 49:
				total2=11; printf("뱀을 타고 11로 이동합니다.\n"); break;
			case 47:
				total2=26; printf("뱀을 타고 26으로 이동합니다.\n"); break;
			case 56:
				total2=53; printf("뱀을 타고 53으로 이동합니다.\n"); break;
			case 87:
				total2=24; printf("뱀을 타고 87로 이동합니다.\n"); break;
			case 64:
				total2=60; printf("뱀을 타고 60으로 이동합니다.\n"); break;
			case 62:
				total2=19; printf("뱀을 타고 19로 이동합니다.\n"); break;
			case 98:
				total2=78; printf("뱀을 타고 78로 이동합니다.\n"); break;
			case 95:
				total2=75; printf("뱀을 타고 75로 이동합니다.\n"); break;
			case 93:
				total2=73; printf("뱀을 타고 73으로 이동합니다.\n"); break;
			}
			if(total2>=100)
			{
				printf("축하합니다!!! 두번째 플레이어가 승리하였습니다.\n");
				return;
			}
			printf("현재 두번째 플레이어의 위치는 %d입니다.\n\n",total2);
		}
		else if((num1==1&&num2==1)||(num1==2&&num2==2)||(num1==3&&num2==3))
		{
			printf("비겼습니다. 다시 가위바위보를 입력해주시기 바랍니다.\n\n");
		}
		else
		{
			printf("오류입니다. 다시 가위바위보를 입력해주시기 바랍니다.\n\n");
		}
	}
}