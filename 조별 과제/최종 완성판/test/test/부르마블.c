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
			printf("공지 : 1P가 한바퀴를 다 돌아서 지원금 20만원을 받았습니다!!\n");
			P1.money+=20;
			P1.site=P1.site-20;
		}
		else if(P2.site>116)
		{
			puts("");
			printf("공지 : 2P가 한바퀴를 다 돌아서 지원금 20만원을 받았습니다!!\n");
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
				printf("죄송합니다만 1P님은 현재 파산이 났으므로 게임에서 패배하셨습니다. 수고하셨습니다.\n");
				printf("\n 2P님 게임에서 승리를 진심으로 축하드립니다. 게임에 소질이 있으세요.\n");
				return 0;
			}
			else if(P2.money<=0)
			{
				printf("죄송합니다만 2P님은 현재 파산이 났으므로 게임에서 패배하셨습니다. 수고하셨습니다.");
				printf("\n 1P님 게임에서 승리를 진심으로 축하드립니다. 게임에 소질이 있으세요.\n");
				return 0;
			}

			fflush(stdin);
			realmap(&(PPT1->site), &(PPT2->site), &(PPT1->money), &(PPT2->money));

		}

		if(ra%2==0)
		{
			dic=dice(1);
			P1.site=P1.site+dic;
			printf("1P가 %d칸 이동합니다.\n", dic);
		}
		else if(ra%2==1)
		{
			dic=dice(2);
			P2.site=P2.site+dic;
			printf("2P가 %d칸 이동합니다.\n", dic);
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
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	puts("ㅣ                              ■■■    ㅣ");
	puts("ㅣ        _____________________■    ■   ㅣ");
	puts("ㅣ        ㅣㅣ  ㅣㅣ            ■■■    ㅣ");
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	puts("");
	puts("카드를 뒤집으시려면 Enter를 눌러주시기 바랍니다.");

	getchar();
	system("cls");

	switch(l)
	{
	case 1:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ     배를 타고 가다 해적을 만났습니다.  ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ            해적섬으로 가시오!          ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
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
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ   길을 걷다가 소매치기를 당했습니다.   ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               -5만원                   ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		
		if (c==1)
			*m1=*m1-5;
		else if (c==2)
			*m2=*m2-5;

		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 3:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ   이벤트에 당첨되어 상금을 받았습니다. ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               +10만원                  ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;


		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 4:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ     항공기 이벤트에 당첨되었습니다.    ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ         세계 여행으로 가시오.          ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
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
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ   자연재해가 일어난 난민들을 위해 기부 ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               -10만원                  ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		
		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 6:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ    전쟁 지역을 여행하다가 죽었습니다.  ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               game over                ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		printf("%dP님이 죽으셨으니 %dP님의 패배로 게임이 끝이 났습니다.\n", c, c);
		return 0;
		break;
	case 7:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ      장사를 하여서 돈을 얻었습니다.    ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               +20만원                  ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		if (c==1)
			*m1=*m1+20;
		else if (c==2)
			*m2=*m2+20;

		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 8:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ       열심히 알바를 돈을 벌었습니다.   ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ               +10만원                  ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;

		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 9:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ 풍토병에 걸려 치료비로 돈을 사용합니다.ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ                -10만원                 ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n 계속 진행하시려면 Enter를 눌러주세요.");
		getchar();
		system("cls");
		break;
	case 10:
		puts("");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		puts("ㅣ   아내를 얻어서 정착생활을 하게됩니다. ㅣ");
		puts("ㅣ                                        ㅣ");
		puts("ㅣ             happy ending!              ㅣ");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		printf("%dP님이 여자를 얻으셔서 %dP님의 승리로 게임이 끝이 났습니다.\n", c, c);
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
		printf("%dP의 말이 출발선입니다.\n", b); 
	}
	else if(*a==98)
	{
		printf("%dP의 말이 방콕에 도착하셨습니다.\n", b);
		if(conutry[1]==0)
		{
			puts("");
			printf("방콕에 오신걸 환영합니다.\n");Sleep(2000);
			printf("방콕의 시세는 3만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 방콕을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[1]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[1]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 6만원을 1P에게 줍니다.\n");
				*m1=*m1+6;
				*m2=*m2-6;
			}

		}
		else if(conutry[1]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 6만원을 2P에게 줍니다.\n");
			*m2=*m2+6;
			*m1=*m1-6;
		}
		getchar();
	system("cls");
	}
	else if(*a==99)
	{
		printf("%dP의 말이 카이로에 도착하셨습니다.\n", b);
		if(conutry[2]==0)
		{
			puts("");
			printf("카이로에 오신걸 환영합니다.\n");Sleep(2000);
			printf("카이로의 시세는 4만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 카이로을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[2]=b;
				if(b==1)
					*m1-=4;
				else
					*m2-=4;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[2]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 8만원을 1P에게 줍니다.\n");
				*m1=*m1+8;
				*m2=*m2-8;
			}

		}
		else if(conutry[2]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 8만원을 2P에게 줍니다.\n");
			*m2=*m2+8;
			*m1=*m1-8;
		}
		getchar();
	system("cls");
	}
	else if (*a==100)
	{
		printf("%dP의 말이 베이징에 도착하셨습니다.\n", b);
		if(conutry[3]==0)
		{
			puts("");
			printf("베이징에 오신걸 환영합니다.\n");Sleep(2000);
			printf("베이징의 시세는 5만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 베이징을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[3]=b;
				if(b==1)
					*m1-=5;
				else
					*m2-=5;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[3]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 10만원을 1P에게 줍니다.\n");
				*m1=*m1+10;
				*m2=*m2-10;
			}

		}
		else if(conutry[3]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 10만원을 2P에게 줍니다.\n");
			*m2=*m2+10;
			*m1=*m1-10;
		}
		getchar();
	system("cls");
	}
	else if(*a==101)
	{
		printf("%dP의 말이 행운 열쇠에 도착하셨습니다. 축하드립니다!!!\n", b);
		return luck(b, m1, m2);
	}
	else if(*a==102)
	{
		printf("%dP의 말이 해적섬에 도착하셨습니다.\n", b);
		printf("다행히 돈 20만원만 잃고 죽지는 않았습니다.\n");
		if(b==1)
			*m1 = *m1 - 20;
		else
			*m2 = *m2 - 20;

	}
	else if(*a==103)
	{
		printf("%dP의 말이 도쿄에 도착하셨습니다.\n",b);
		if(conutry[6]==0)
		{
			puts("");
			printf("도쿄에 오신걸 환영합니다.\n");Sleep(2000);
			printf("도쿄의 시세는 8만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 도쿄을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[6]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[6]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 16만원을 1P에게 줍니다.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[6]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 16만원을 2P에게 줍니다.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==104)
	{
		printf("%dP의 말이 싱가폴에 도착하셨습니다.\n", b);
		if(conutry[7]==0)
		{
			puts("");
			printf("싱가폴에 오신걸 환영합니다.\n");Sleep(2000);
			printf("싱가폴의 시세는 8만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 싱가폴을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[7]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[7]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 16만원을 1P에게 줍니다.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[7]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 16만원을 2P에게 줍니다.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==105)
	{
		printf("%dP의 말이 시드니에 도착하셨습니다.\n", b);
			if(conutry[8]==0)
			{
			puts("");
			printf("시드니에 오신걸 환영합니다.\n");Sleep(2000);
			printf("시드니의 시세는 10만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 시드니을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[8]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[8]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 20만원을 1P에게 줍니다.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[8]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 20만원을 2P에게 줍니다.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==106)
	{
		printf("%dP의 말이 모스크바에 도착하셨습니다.\n",b);
	if(conutry[9]==0)
		{
			puts("");
			printf("모스크바에 오신걸 환영합니다.\n");Sleep(2000);
			printf("모스크바의 시세는 10만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 모스크바을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[9]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[9]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 20만원을 1P에게 줍니다.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[9]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 20만원을 2P에게 줍니다.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==107)
	{
		srand(time(NULL));
		printf("%dP의 말이 카지노에 도착하셨습니다.\n", b);
		printf("도박을 위해서 5만원을 걸으셨습니다.\n");
		if(b==1)
			*m1 = *m1 - 5;
		else
			*m2 = *m2 - 5;
		printf("확률에 따라 5만원이 0배~10배가 될 수 있습니다.\n");
		printf("대박 느낌이 오실 때 Enter를 눌러주시기 바랍니다.\n");
		getchar();
		printf("도박 중");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n");Sleep(1000);
		printf("도박 결과 : %d(만원)을 획득하셨습니다.\n",r=(rand()%11)*5);

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
			printf("카지노에 경찰이 들이닥칩니다. 도망가기 위해서 Enter를 눌러주세요.\n");
			printf("※ 일정확률로 경찰에 잡혀서 보석금을 낼 수도 있습니다!\n");
			getchar();
			system("cls");
			printf("도망 중");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n\n");Sleep(1000);
			r=(rand()%2+1);
			if(r==1)
			{
				printf("%dP님이 탈출에 성공하지 못하고 경찰에게 잡혀서 보석금을 내고 나왔습니다.\n", b);
				printf("%dP님이 보석금으로 10만원을 냈습니다.\n", b);
				if(b==1)
					*m1 = *m1 - 10;
				else
					*m2 = *m2 - 10;
			}
			if(r==2)
			{
				printf("%dP님이 아슬아슬하게 경찰을 따돌리는데 성공했습니다.\n", b);
			}
			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
		}
		else if(r==2)
			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");

		getchar();
		system("cls");
}

	else if(*a==108)
	{
		printf("%dP의 말이 베를린에 도착하셨습니다.\n", b);
	if(conutry[11]==0)
		{
			puts("");
			printf("베를린에 오신걸 환영합니다.\n");Sleep(2000);
			printf("베를린의 시세는 16만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 베를린을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[11]=b;
				if(b==1)
					*m1-=16;
				else
					*m2-=16;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[11]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 32만원을 1P에게 줍니다.\n");
				*m1=*m1+32;
				*m2=*m2-32;
			}

		}
		else if(conutry[11]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 32만원을 2P에게 줍니다.\n");
			*m2=*m2+32;
			*m1=*m1-32;
		}
		getchar();
	system("cls");
	}
	else if(*a==109)
	{
		printf("%dP의 말이 행운 열쇠에 도착하셨습니다. 축하드립니다!!!\n", b);
		 return luck(b, m1, m2);
	}
	else if(*a==110)
	{
		printf("%dP의 말이 마드리드에 도착하셨습니다.\n", b);
		if(conutry[13]==0)
		{
			puts("");
			printf("마드리드에 오신걸 환영합니다.\n");Sleep(2000);
			printf("마드리드의 시세는 18만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 마드리드을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[13]=b;
				if(b==1)
					*m1-=18;
				else
					*m2-=18;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[13]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 36만원을 1P에게 줍니다.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[13]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 36만원을 2P에게 줍니다.\n");
			*m2=*m2+36;
			*m1=*m1-36;
		}
	getchar();
	system("cls");
	}
	else if(*a==111)
	{
		printf("%dP의 말이 파리에 도착하셨습니다.\n", b);
		if(conutry[14]==0)
		{
			puts("");
			printf("파리에 오신걸 환영합니다.\n");Sleep(2000);
			printf("파리의 시세는 18만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다.파리을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[14]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[14]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 36만원을 1P에게 줍니다.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[14]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 36만원을 2P에게 줍니다.\n");
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
		printf("  %dP의 말이 세계여행에 도착하셨습니다.\n", b);
		puts("  세계 여행을 할 수 있는 비행기를 타실 수 있습니다.");

		puts("\n");
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		printf("ㅣ");printf(" 해적섬 ⓕㅣ  도 쿄 ⓖㅣ 싱가폴 ⓗㅣ 시드니 ⓘㅣ모스크바ⓙㅣ 카지노 ⓚㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==102) printf("● ");else printf("   ");if(P2.site==102) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==103) printf("● ");else printf("   ");if(P2.site==103) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==104) printf("● ");else printf("   ");if(P2.site==104) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==105) printf("● ");else printf("   ");if(P2.site==105) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==106) printf("● ");else printf("   ");if(P2.site==106) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==107) printf("● ");else printf("   ");if(P2.site==107) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");printf("   ");printf("   ");printf("  ㅣ  ");if(conutry[6]==1) printf("★ ");else printf("   ");if(conutry[6]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[7]==1) printf("★ ");else printf("   ");if(conutry[7]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[8]==1) printf("★ ");else printf("   ");if(conutry[8]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[9]==1) printf("★ ");else printf("   ");if(conutry[9]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   ");printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("행운카드ⓔㅣ                                              ㅣ 베를린ⓛ ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==101) printf("● ");else printf("   ");if(P2.site==101) printf(" ○");else printf("   "); printf("  ㅣ   ㅣ                  ㅣ                     ㅣ  ");if(P1.site==108) printf("● ");else printf("   ");if(P2.site==108) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");printf("   ");printf("   ");printf("  ㅣ   ㅣ  행  운  카  드  ㅣ                     ㅣ  ");if(conutry[11]==1) printf("★ ");else printf("   ");if(conutry[11]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ   ㅣ                  ㅣ                     ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf(" 베이징 ⓓㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣ행운카드ⓜㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==100) printf("● ");else printf("   ");if(P2.site==100) printf(" ○");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(P1.site==109) printf("● ");else printf("   ");if(P2.site==109) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");if(conutry[3]==1) printf("★ ");else printf("   ");if(conutry[3]==2) printf(" ☆");else printf("   "); printf("  ㅣ                                              ㅣ  "); printf("   "); printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf(" 카이로 ⓒㅣ                                              ㅣ마드리드ⓝㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==99) printf("● ");else printf("   ");if(P2.site==99) printf(" ○");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(P1.site==110) printf("● ");else printf("   ");if(P2.site==110) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");if(conutry[2]==1) printf("★ ");else printf("   ");if(conutry[2]==2) printf(" ☆");else printf("   "); printf("  ㅣ                   1P의 말은 ●입니다.        ㅣ  ");if(conutry[13]==1) printf("★ ");else printf("   ");if(conutry[13]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   2P의 말은 ○입니다.        ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  방 콕 ⓑㅣ                                              ㅣ 파 리 ⓞ ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   1P의 건물은 ★입니다.      ㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==98) printf("● ");else printf("   ");if(P2.site==98) printf(" ○");else printf("   "); printf("  ㅣ                   2P의 건물은 ☆입니다.      ㅣ  ");if(P1.site==111) printf("● ");else printf("   ");if(P2.site==111) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");if(conutry[1]==1) printf("★ ");else printf("   ");if(conutry[1]==2) printf(" ☆");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(conutry[14]==1) printf("★ ");else printf("   ");if(conutry[14]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf(" START ⓐ ㅣ  서 울 ⓣㅣ 국세청 ⓢㅣ 뉴 욕 ⓡ ㅣ  런 던ⓠ ㅣ세계여행ⓟㅣ\n");
		printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
		printf("ㅣ");printf("  ");if(P1.site==97) printf("● ");else printf("   ");if(P2.site==97) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==116) printf("● ");else printf("   ");if(P2.site==116) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==115) printf("● ");else printf("   ");if(P2.site==115) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==114) printf("● ");else printf("   ");if(P2.site==114) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==113) printf("● ");else printf("   ");if(P2.site==113) printf(" ○");else printf("   "); printf("  ㅣ  ");if(P1.site==112) printf("● ");else printf("   ");if(P2.site==112) printf(" ○");else printf("   "); printf("  ㅣ\n");
		printf("ㅣ");printf("  ");if(conutry[0]==1) printf("★ ");else printf("   ");if(conutry[0]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[19]==1) printf("★ ");else printf("   ");if(conutry[19]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   ");printf("   "); printf("  ㅣ  ");if(conutry[17]==1) printf("★ ");else printf("   ");if(conutry[17]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[16]==1) printf("★ ");else printf("   ");if(conutry[16]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   "); printf("   "); printf("  ㅣ\n"); 
		puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		trip(a, b, m1, m2);
	}
	else if(*a==113)
	{
		printf("%dP의 말이 런던에 도착하셨습니다.\n", b);
		if(conutry[16]==0)
		{
			puts("");
			printf("런던에 오신걸 환영합니다.\n");Sleep(2000);
			printf("런던의 시세는 20만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 런던을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[16]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[16]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 40만원을 1P에게 줍니다.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[16]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 40만원을 2P에게 줍니다.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==114)
	{
		printf("%dP의 말이 뉴욕에 도착하셨습니다.\n", b);
		if(conutry[17]==0)
		{
			puts("");
			printf("뉴욕에 오신걸 환영합니다.\n");Sleep(2000);
			printf("뉴욕의 시세는 20만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 뉴욕을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[17]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[17]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 40만원을 1P에게 줍니다.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[17]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 40만원을 2P에게 줍니다.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==115)
	{
		printf("%dP의 말이 국세청에 도착하셨습니다. 아깝지만.. 세금을 내셔야 합니다.\n", b);
		printf("10만원을 세금으로 내셨습니다.\n");
		if(b==1)
			*m1 = *m1 - 10;
		else
			*m2 = *m2 - 10;
	}
	else if(*a==116)
	{
		printf("%dP의 말이 서울에 도착하셨습니다.\n", b);
		if(conutry[19]==0)
		{
			puts("");
			printf("서울에 오신걸 환영합니다.\n");Sleep(2000);
			printf("서울의 시세는 25만원입니다. 사시겠습니까?\n");
			printf("[YES라면 1을 입력, NO라면 0을 입력해주시기 바랍니다.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP님 좋은 선택입니다. 서울을 사신것을 축하드립니다.\n", b);Sleep(2000);
				conutry[19]=b;
				if(b==1)
					*m1-=25;
				else
					*m2-=25;
			}
			else if(y==0)
			{
				printf("아쉽지만 다음을 기약하죠. 안녕히 가시기 바랍니다.\n");Sleep(2000);
			}

			printf("\n다시 여행을 시작합니다. Enter를 눌러주시기 바랍니다.");
			getchar();
		}
		else if(conutry[19]==1)
		{
			if(b==1)
				printf("자신이 산 땅입니다.\n");
			else
			{
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 50만원을 1P에게 줍니다.\n");
				*m1=*m1+50;
				*m2=*m2-50;
			}

		}
		else if(conutry[19]==2)
		{
			if(b==2)
				printf("자신이 산 땅입니다.\n");
			else
				printf("자신의 땅이 아닌 곳을 여행했기 때문에 이용료로 50만원을 2P에게 줍니다.\n");
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
	puts("  세계 여행 가고 싶은 나라의 옆에 있는 소문자 알파벳을 적고 Enter를 눌러주세요.");
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
	printf(" %dP님 주사위를 굴리실 준비가 되셨다면 언제든지 Enter를 눌러주시기 바랍니다!!!\n", a);
	getchar();
	for(c=1;c<=200;c++)
	{
		srand(time(NULL));
		i = (rand()%6)+1;
		puts("");
		printf(" 주사위를 굴리는 중입니다...\n");
		puts("");
		system("cls");
		switch(i)
		{
		case 1:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ        ㅣ");
			puts("  ㅣ   ●   ㅣ");
			puts("  ㅣ        ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");
			break;

		case 2:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ        ㅣ");
			puts("  ㅣ ●  ● ㅣ");
			puts("  ㅣ        ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");;
			break;

		case 3:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ     ● ㅣ");
			puts("  ㅣ   ●   ㅣ ");
			puts("  ㅣ ●     ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");
			break;

		case 4:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ ●  ● ㅣ");
			puts("  ㅣ        ㅣ");
			puts("  ㅣ ●  ● ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");
			break;

		case 5:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ ●  ● ㅣ");
			puts("  ㅣ   ●   ㅣ");
			puts("  ㅣ ●  ● ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");
			break;

		case 6:
			puts("");
			puts("   ㅡㅡㅡㅡㅡ");
			puts("  ㅣ ●  ● ㅣ");
			puts("  ㅣ ●  ● ㅣ");
			puts("  ㅣ ●  ● ㅣ");
			puts("   ㅡㅡㅡㅡㅡ");
			break;

		}
		if(c==200)
		{
			printf("\n %dP님이 주사위를 굴린 결과는 %d입니다.\n", a, i);
			printf("\n※ 다음으로 진행하시려면 Enter를 눌러주시길 바랍니다");
			getchar();
			system("cls");
			return i;
		}
	}

}
int rank()
{
	int a=0, b=0;

	printf("\n ※ 최대 게임 참여 가능한 인원은 2명;입니다.\n");
	printf("\n ※ 1P의 말은 ●입니다. \n");
	printf("    1P의 건물은 ★입니다.\n\n");
	printf(" ※ 2P의 말은 ○입니다.\n");
	printf("    2P의 건물은 ☆입니다.\n\n");

	puts(" ※ 1P와 2P를 먼저 진행할 순서를 정하기 위해 주사위를 굴리겠습니다.\n");
	puts(" ※ 계속 진행하시려면 Enter를 눌러주시기 바랍니다. ");
	getchar();
	system("cls");

RE:

	puts("");
	puts(" ※ 1P 사용자부터 주사위를 굴리겠습니다.");
	puts("");
	a=dice(1);

	puts("");
	puts(" ※ 2P 사용자가 주사위를 굴리겠습니다.");
	puts("");
	b=dice(2);

	if(a==b)
	{
		puts("");
		puts(" ※ 1P와 2P의 주사위의 결과가 같으므로 다시 돌리겠습니다.");
		goto RE;
	}
	else if(a<b)
	{
		puts("");
		puts(" ※ 2P의 주사위 결과가 더 높으므로 2P부터 게임을 시작합니다.");
		return 1;
	}
	else if(a>b)
	{
		puts("");
		puts(" ※ 1P의 주사위 결과가 더 높으므로 1P부터 게임을 시작합니다.");
		return 0;
	}
}
void map1()
{
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	printf("ㅣ");printf(" 해적섬 ⓕㅣ  도 쿄 ⓖㅣ 싱가폴 ⓗㅣ 시드니 ⓘㅣ모스크바ⓙㅣ 카지노 ⓚㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("          ㅣ   8만원  ㅣ   8만원  ㅣ  10만원  ㅣ  10만원  ㅣ          ㅣ\n");
	printf("ㅣ");printf("  -20만원 ㅣ          ㅣ          ㅣ          ㅣ          ㅣ   도박   ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("행운카드ⓔㅣ                                              ㅣ 베를린ⓛ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  good    ㅣ   ㅣ                  ㅣ                     ㅣ  16만원  ㅣ\n");
	printf("ㅣ");printf("    luck! ㅣ   ㅣ  행  운  카  드  ㅣ                     ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ   ㅣ                  ㅣ                     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 베이징 ⓓㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣ행운카드ⓜㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   5만원  ㅣ                                              ㅣ good     ㅣ\n");
	printf("ㅣ");printf("          ㅣ                                              ㅣ    luck! ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 카이로 ⓒㅣ                                              ㅣ마드리드ⓝㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   4만원  ㅣ                                              ㅣ  18만원  ㅣ\n");
	printf("ㅣ");printf("          ㅣ                   1P의 말은 ●입니다.        ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   2P의 말은 ○입니다.        ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  방 콕 ⓑㅣ                                              ㅣ 파 리 ⓞ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   1P의 건물은 ★입니다.      ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   3만원  ㅣ                   2P의 건물은 ☆입니다.      ㅣ  18만원  ㅣ\n");
	printf("ㅣ");printf("          ㅣ                                              ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" START ⓐ ㅣ  서 울 ⓣㅣ 국세청 ⓢㅣ 뉴 욕 ⓡ ㅣ  런 던ⓠ ㅣ세계여행ⓟㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  왕복 시 ㅣ  25만원  ㅣ          ㅣ  20만원  ㅣ  20만원  ㅣ  go~     ㅣ\n");
	printf("ㅣ");printf("  +20만원 ㅣ          ㅣ -10만원  ㅣ          ㅣ          ㅣ      go~ ㅣ\n");
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
}
void mainmap()
{
	puts("\n");
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	printf("ㅣ");printf(" 해적섬 ⓕㅣ  도 쿄 ⓖㅣ 싱가폴 ⓗㅣ 시드니 ⓘㅣ모스크바ⓙㅣ 카지노 ⓚㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("          ㅣ   8만원  ㅣ   8만원  ㅣ  10만원  ㅣ  10만원  ㅣ          ㅣ\n");
	printf("ㅣ");printf("  -20만원 ㅣ          ㅣ          ㅣ          ㅣ          ㅣ   도박   ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("행운카드ⓔㅣ                                              ㅣ 베를린ⓛ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ         ■    ■         ■■■■            ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  good    ㅣ         ■    ■               ■            ㅣ  16만원  ㅣ\n");
	printf("ㅣ");printf("    luck! ㅣ         ■■■■         ■■■■            ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ         ■    ■         ■                  ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 베이징 ⓓㅣ         ■■■■         ■■■■            ㅣ행운카드ⓜㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ       ■■■■■■     ■■■■■■          ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   5만원  ㅣ            ■               ■               ㅣ good     ㅣ\n");
	printf("ㅣ");printf("          ㅣ            ■               ■               ㅣ    luck! ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                       ■        ■    ■     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 카이로 ⓒㅣ             ■■■■  ■        ■■■■     ㅣ마드리드ⓝㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ             ■    ■  ■■■    ■    ■     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   4만원  ㅣ             ■    ■  ■        ■■■■     ㅣ  18만원  ㅣ\n");
	printf("ㅣ");printf("          ㅣ             ■■■■  ■    ■■■■■■■■ ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                       ■        ■■■■     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  방 콕 ⓑㅣ                                       ■     ㅣ 파 리 ⓞ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ      ver 1.0                    ■■■■     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("   3만원  ㅣ                                 ■           ㅣ  18만원  ㅣ\n");
	printf("ㅣ");printf("          ㅣ                                 ■■■■     ㅣ          ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" START ⓐ ㅣ  서 울 ⓣㅣ 국세청 ⓢㅣ 뉴 욕 ⓡ ㅣ  런 던ⓠ ㅣ세계여행ⓟㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  왕복 시 ㅣ  25만원  ㅣ          ㅣ  20만원  ㅣ  20만원  ㅣ  go~     ㅣ\n");
	printf("ㅣ");printf("  +20만원 ㅣ          ㅣ  -10만원 ㅣ          ㅣ          ㅣ      go~ ㅣ\n");
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	puts("");
	puts("		부루마블의 세계에 오신걸 환영합니다ㅇㅅㅇ");
	puts("		시작하시려면 Enter를 눌러주시기 바랍니다.");
	getchar();
	system("cls");
}
void realmap(int *a, int *b,int *m1, int *m2)
{
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	printf("ㅣ");printf(" 해적섬 ⓕㅣ  도 쿄 ⓖㅣ 싱가폴 ⓗㅣ 시드니 ⓘㅣ모스크바ⓙㅣ 카지노 ⓚㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==102) printf("● ");else printf("   ");if(*b==102) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==103) printf("● ");else printf("   ");if(*b==103) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==104) printf("● ");else printf("   ");if(*b==104) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==105) printf("● ");else printf("   ");if(*b==105) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==106) printf("● ");else printf("   ");if(*b==106) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==107) printf("● ");else printf("   ");if(*b==107) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");printf("   ");printf("   ");printf("  ㅣ  ");if(conutry[6]==1) printf("★ ");else printf("   ");if(conutry[6]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[7]==1) printf("★ ");else printf("   ");if(conutry[7]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[8]==1) printf("★ ");else printf("   ");if(conutry[8]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[9]==1) printf("★ ");else printf("   ");if(conutry[9]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   ");printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("행운카드ⓔㅣ                                              ㅣ 베를린ⓛ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==101) printf("● ");else printf("   ");if(*b==101) printf(" ○");else printf("   "); printf("  ㅣ   ㅣ                  ㅣ                     ㅣ  ");if(*a==108) printf("● ");else printf("   ");if(*b==108) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");printf("   ");printf("   ");printf("  ㅣ   ㅣ  행  운  카  드  ㅣ                     ㅣ  ");if(conutry[11]==1) printf("★ ");else printf("   ");if(conutry[11]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ   ㅣ                  ㅣ                     ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 베이징 ⓓㅣ    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ                      ㅣ행운카드ⓜㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==100) printf("● ");else printf("   ");if(*b==100) printf(" ○");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(*a==109) printf("● ");else printf("   ");if(*b==109) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");if(conutry[3]==1) printf("★ ");else printf("   ");if(conutry[3]==2) printf(" ☆");else printf("   "); printf("  ㅣ                                              ㅣ  "); printf("   "); printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ");printf("    1P money : %3d만원", *m1);printf("   2P money : %3d만원", *m2);printf("   ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" 카이로 ⓒㅣ                                              ㅣ마드리드ⓝㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                                              ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==99) printf("● ");else printf("   ");if(*b==99) printf(" ○");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(*a==110) printf("● ");else printf("   ");if(*b==110) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");if(conutry[2]==1) printf("★ ");else printf("   ");if(conutry[2]==2) printf(" ☆");else printf("   "); printf("  ㅣ                   1P의 말은 ●입니다.        ㅣ  ");if(conutry[13]==1) printf("★ ");else printf("   ");if(conutry[13]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   2P의 말은 ○입니다.        ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  방 콕 ⓑㅣ                                              ㅣ 파 리 ⓞ ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣ                   1P의 땅은 ★입니다.        ㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==98) printf("● ");else printf("   ");if(*b==98) printf(" ○");else printf("   "); printf("  ㅣ                   2P의 땅은 ☆입니다.        ㅣ  ");if(*a==111) printf("● ");else printf("   ");if(*b==111) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");if(conutry[1]==1) printf("★ ");else printf("   ");if(conutry[1]==2) printf(" ☆");else printf("   "); printf("  ㅣ                                              ㅣ  ");if(conutry[14]==1) printf("★ ");else printf("   ");if(conutry[14]==2) printf(" ☆");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf(" START ⓐ ㅣ  서 울 ⓣㅣ 국세청 ⓢㅣ 뉴 욕 ⓡ ㅣ  런 던ⓠ ㅣ세계여행ⓟㅣ\n");
	printf("ㅣ");printf("ㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣㅡㅡㅡㅡㅡㅣ\n");
	printf("ㅣ");printf("  ");if(*a==97) printf("● ");else printf("   ");if(*b==97) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==116) printf("● ");else printf("   ");if(*b==116) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==115) printf("● ");else printf("   ");if(*b==115) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==114) printf("● ");else printf("   ");if(*b==114) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==113) printf("● ");else printf("   ");if(*b==113) printf(" ○");else printf("   "); printf("  ㅣ  ");if(*a==112) printf("● ");else printf("   ");if(*b==112) printf(" ○");else printf("   "); printf("  ㅣ\n");
	printf("ㅣ");printf("  ");if(conutry[0]==1) printf("★ ");else printf("   ");if(conutry[0]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[19]==1) printf("★ ");else printf("   ");if(conutry[19]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   ");printf("   "); printf("  ㅣ  ");if(conutry[17]==1) printf("★ ");else printf("   ");if(conutry[17]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");if(conutry[16]==1) printf("★ ");else printf("   ");if(conutry[16]==2) printf(" ☆");else printf("   "); printf("  ㅣ  ");printf("   "); printf("   "); printf("  ㅣ\n"); 
	puts(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
}