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
			printf("奢雖 : 1P陛 и夥襪蒂 棻 給嬴憮 雖錳旎 20虜錳擊 嫡懊蝗棲棻!!\n");
			P1.money+=20;
			P1.site=P1.site-20;
		}
		else if(P2.site>116)
		{
			puts("");
			printf("奢雖 : 2P陛 и夥襪蒂 棻 給嬴憮 雖錳旎 20虜錳擊 嫡懊蝗棲棻!!\n");
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
				printf("賸歎м棲棻虜 1P椒擎 ⑷營 だ骯檜 陬戲嘎煎 啪歜縑憮 ぬ寡ж樟蝗棲棻. 熱堅ж樟蝗棲棻.\n");
				printf("\n 2P椒 啪歜縑憮 蝓葬蒂 霞褕戲煎 蹴ж萄董棲棻. 啪歜縑 模韓檜 氈戲撮蹂.\n");
				return 0;
			}
			else if(P2.money<=0)
			{
				printf("賸歎м棲棻虜 2P椒擎 ⑷營 だ骯檜 陬戲嘎煎 啪歜縑憮 ぬ寡ж樟蝗棲棻. 熱堅ж樟蝗棲棻.");
				printf("\n 1P椒 啪歜縑憮 蝓葬蒂 霞褕戲煎 蹴ж萄董棲棻. 啪歜縑 模韓檜 氈戲撮蹂.\n");
				return 0;
			}

			fflush(stdin);
			realmap(&(PPT1->site), &(PPT2->site), &(PPT1->money), &(PPT2->money));

		}

		if(ra%2==0)
		{
			dic=dice(1);
			P1.site=P1.site+dic;
			printf("1P陛 %d蘊 檜翕м棲棻.\n", dic);
		}
		else if(ra%2==1)
		{
			dic=dice(2);
			P2.site=P2.site+dic;
			printf("2P陛 %d蘊 檜翕м棲棻.\n", dic);
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
	puts(" 天天天天天天天天天天天天天天天天天天天天天");
	puts("太                              ﹥﹥﹥    太");
	puts("太        _____________________﹥    ﹥   太");
	puts("太        太太  太太            ﹥﹥﹥    太");
	puts(" 天天天天天天天天天天天天天天天天天天天天天");
	puts("");
	puts("蘋萄蒂 菴餵戲衛溥賊 Enter蒂 揚楝輿衛晦 夥奧棲棻.");

	getchar();
	system("cls");

	switch(l)
	{
	case 1:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太     寡蒂 顫堅 陛棻 п瞳擊 虜陬蝗棲棻.  太");
		puts("太                                        太");
		puts("太            п瞳撰戲煎 陛衛螃!          太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
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
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太   望擊 務棻陛 模衙纂晦蒂 渡ц蝗棲棻.   太");
		puts("太                                        太");
		puts("太               -5虜錳                   太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		
		if (c==1)
			*m1=*m1-5;
		else if (c==2)
			*m2=*m2-5;

		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 3:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太   檜漸お縑 渡繩腎橫 鼻旎擊 嫡懊蝗棲棻. 太");
		puts("太                                        太");
		puts("太               +10虜錳                  太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;


		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 4:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太     о奢晦 檜漸お縑 渡繩腎歷蝗棲棻.    太");
		puts("太                                        太");
		puts("太         撮啗 罹ч戲煎 陛衛螃.          太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
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
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太   濠翱營п陛 橾橫陪 陪團菟擊 嬪п 晦睡 太");
		puts("太                                        太");
		puts("太               -10虜錳                  太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		
		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 6:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太    瞪爵 雖羲擊 罹чж棻陛 避歷蝗棲棻.  太");
		puts("太                                        太");
		puts("太               game over                太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");

		printf("%dP椒檜 避戲樟戲棲 %dP椒曖 ぬ寡煎 啪歜檜 部檜 陬蝗棲棻.\n", c, c);
		return 0;
		break;
	case 7:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太      濰餌蒂 ж罹憮 絲擊 橢歷蝗棲棻.    太");
		puts("太                                        太");
		puts("太               +20虜錳                  太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");

		if (c==1)
			*m1=*m1+20;
		else if (c==2)
			*m2=*m2+20;

		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 8:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太       翮褕�� 憲夥蒂 絲擊 弊歷蝗棲棻.   太");
		puts("太                                        太");
		puts("太               +10虜錳                  太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");

		if (c==1)
			*m1=*m1+10;
		else if (c==2)
			*m2=*m2+10;

		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 9:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太 Ё饜煽縑 勘溥 纂猿綠煎 絲擊 餌辨м棲棻.太");
		puts("太                                        太");
		puts("太                -10虜錳                 太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");

		if (c==1)
			*m1=*m1-10;
		else if (c==2)
			*m2=*m2-10;

		puts("\n 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿撮蹂.");
		getchar();
		system("cls");
		break;
	case 10:
		puts("");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");
		puts("太   嬴頂蒂 橢橫憮 薑雜儅�偯� ж啪腌棲棻. 太");
		puts("太                                        太");
		puts("太             happy ending!              太");
		puts(" 天天天天天天天天天天天天天天天天天天天天天");

		printf("%dP椒檜 罹濠蒂 橢戲敷憮 %dP椒曖 蝓葬煎 啪歜檜 部檜 陬蝗棲棻.\n", c, c);
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
		printf("%dP曖 蜓檜 轎嫦摹殮棲棻.\n", b); 
	}
	else if(*a==98)
	{
		printf("%dP曖 蜓檜 寞囂縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[1]==0)
		{
			puts("");
			printf("寞囂縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("寞囂曖 衛撮朝 3虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 寞囂擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[1]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[1]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 6虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+6;
				*m2=*m2-6;
			}

		}
		else if(conutry[1]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 6虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+6;
			*m1=*m1-6;
		}
		getchar();
	system("cls");
	}
	else if(*a==99)
	{
		printf("%dP曖 蜓檜 蘋檜煎縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[2]==0)
		{
			puts("");
			printf("蘋檜煎縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("蘋檜煎曖 衛撮朝 4虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 蘋檜煎擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[2]=b;
				if(b==1)
					*m1-=4;
				else
					*m2-=4;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[2]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 8虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+8;
				*m2=*m2-8;
			}

		}
		else if(conutry[2]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 8虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+8;
			*m1=*m1-8;
		}
		getchar();
	system("cls");
	}
	else if (*a==100)
	{
		printf("%dP曖 蜓檜 漆檜癒縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[3]==0)
		{
			puts("");
			printf("漆檜癒縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("漆檜癒曖 衛撮朝 5虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 漆檜癒擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[3]=b;
				if(b==1)
					*m1-=5;
				else
					*m2-=5;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[3]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 10虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+10;
				*m2=*m2-10;
			}

		}
		else if(conutry[3]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 10虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+10;
			*m1=*m1-10;
		}
		getchar();
	system("cls");
	}
	else if(*a==101)
	{
		printf("%dP曖 蜓檜 ч遴 翮潸縑 紫雜ж樟蝗棲棻. 蹴ж萄董棲棻!!!\n", b);
		return luck(b, m1, m2);
	}
	else if(*a==102)
	{
		printf("%dP曖 蜓檜 п瞳撰縑 紫雜ж樟蝗棲棻.\n", b);
		printf("棻ч�� 絲 20虜錳虜 檠堅 避雖朝 彊懊蝗棲棻.\n");
		if(b==1)
			*m1 = *m1 - 20;
		else
			*m2 = *m2 - 20;

	}
	else if(*a==103)
	{
		printf("%dP曖 蜓檜 紫瓖縑 紫雜ж樟蝗棲棻.\n",b);
		if(conutry[6]==0)
		{
			puts("");
			printf("紫瓖縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("紫瓖曖 衛撮朝 8虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 紫瓖擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[6]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[6]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 16虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[6]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 16虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==104)
	{
		printf("%dP曖 蜓檜 諒陛ィ縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[7]==0)
		{
			puts("");
			printf("諒陛ィ縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("諒陛ィ曖 衛撮朝 8虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 諒陛ィ擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[7]=b;
				if(b==1)
					*m1-=8;
				else
					*m2-=8;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[7]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 16虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+16;
				*m2=*m2-16;
			}

		}
		else if(conutry[7]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 16虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+16;
			*m1=*m1-16;
		}
		getchar();
	system("cls");
	}
	else if(*a==105)
	{
		printf("%dP曖 蜓檜 衛萄棲縑 紫雜ж樟蝗棲棻.\n", b);
			if(conutry[8]==0)
			{
			puts("");
			printf("衛萄棲縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("衛萄棲曖 衛撮朝 10虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 衛萄棲擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[8]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[8]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 20虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[8]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 20虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==106)
	{
		printf("%dP曖 蜓檜 賅蝶觼夥縑 紫雜ж樟蝗棲棻.\n",b);
	if(conutry[9]==0)
		{
			puts("");
			printf("賅蝶觼夥縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("賅蝶觼夥曖 衛撮朝 10虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 賅蝶觼夥擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[9]=b;
				if(b==1)
					*m1-=10;
				else
					*m2-=10;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[9]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 20虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+20;
				*m2=*m2-20;
			}

		}
		else if(conutry[9]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 20虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+20;
			*m1=*m1-20;
		}
		getchar();
	system("cls");
	}
	else if(*a==107)
	{
		srand(time(NULL));
		printf("%dP曖 蜓檜 蘋雖喻縑 紫雜ж樟蝗棲棻.\n", b);
		printf("紫夢擊 嬪п憮 5虜錳擊 勘戲樟蝗棲棻.\n");
		if(b==1)
			*m1 = *m1 - 5;
		else
			*m2 = *m2 - 5;
		printf("�捕�縑 評塭 5虜錳檜 0寡~10寡陛 腆 熱 氈蝗棲棻.\n");
		printf("渠夢 替釵檜 螃褒 陽 Enter蒂 揚楝輿衛晦 夥奧棲棻.\n");
		getchar();
		printf("紫夢 醞");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n");Sleep(1000);
		printf("紫夢 唸婁 : %d(虜錳)擊 �僱磈牳抻懂炴�.\n",r=(rand()%11)*5);

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
			printf("蘋雖喻縑 唳雞檜 菟檜款蘑棲棻. 紫蜂陛晦 嬪п憮 Enter蒂 揚楝輿撮蹂.\n");
			printf("≦ 橾薑�捕�煎 唳雞縑 濩⑵憮 爾戮旎擊 鳥 熱紫 氈蝗棲棻!\n");
			getchar();
			system("cls");
			printf("紫蜂 醞");Sleep(1000);printf(" .");Sleep(1000);printf(" .");Sleep(1000);printf(" .\n\n");Sleep(1000);
			r=(rand()%2+1);
			if(r==1)
			{
				printf("%dP椒檜 驍轎縑 撩奢ж雖 跤ж堅 唳雞縑啪 濩⑵憮 爾戮旎擊 頂堅 釭諮蝗棲棻.\n", b);
				printf("%dP椒檜 爾戮旎戲煎 10虜錳擊 麻蝗棲棻.\n", b);
				if(b==1)
					*m1 = *m1 - 10;
				else
					*m2 = *m2 - 10;
			}
			if(r==2)
			{
				printf("%dP椒檜 嬴蝸嬴蝸ж啪 唳雞擊 評給葬朝等 撩奢ц蝗棲棻.\n", b);
			}
			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
		}
		else if(r==2)
			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");

		getchar();
		system("cls");
}

	else if(*a==108)
	{
		printf("%dP曖 蜓檜 漆蒂萼縑 紫雜ж樟蝗棲棻.\n", b);
	if(conutry[11]==0)
		{
			puts("");
			printf("漆蒂萼縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("漆蒂萼曖 衛撮朝 16虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 漆蒂萼擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[11]=b;
				if(b==1)
					*m1-=16;
				else
					*m2-=16;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[11]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 32虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+32;
				*m2=*m2-32;
			}

		}
		else if(conutry[11]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 32虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+32;
			*m1=*m1-32;
		}
		getchar();
	system("cls");
	}
	else if(*a==109)
	{
		printf("%dP曖 蜓檜 ч遴 翮潸縑 紫雜ж樟蝗棲棻. 蹴ж萄董棲棻!!!\n", b);
		 return luck(b, m1, m2);
	}
	else if(*a==110)
	{
		printf("%dP曖 蜓檜 葆萄葬萄縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[13]==0)
		{
			puts("");
			printf("葆萄葬萄縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("葆萄葬萄曖 衛撮朝 18虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 葆萄葬萄擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[13]=b;
				if(b==1)
					*m1-=18;
				else
					*m2-=18;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[13]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 36虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[13]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 36虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+36;
			*m1=*m1-36;
		}
	getchar();
	system("cls");
	}
	else if(*a==111)
	{
		printf("%dP曖 蜓檜 だ葬縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[14]==0)
		{
			puts("");
			printf("だ葬縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("だ葬曖 衛撮朝 18虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻.だ葬擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[14]=b;
				if(b==1)
					*m1-=3;
				else
					*m2-=3;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[14]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 36虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+36;
				*m2=*m2-36;
			}

		}
		else if(conutry[14]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 36虜錳擊 2P縑啪 鄹棲棻.\n");
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
		printf("  %dP曖 蜓檜 撮啗罹ч縑 紫雜ж樟蝗棲棻.\n", b);
		puts("  撮啗 罹ч擊 й 熱 氈朝 綠ч晦蒂 顫褒 熱 氈蝗棲棻.");

		puts("\n");
		puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
		printf("太");printf(" п瞳撰 例太  紫 瓖 來太 諒陛ィ 侃太 衛萄棲 佰太賅蝶觼夥併太 蘋雖喻 侈太\n");
		printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==102) printf("≒ ");else printf("   ");if(P2.site==102) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==103) printf("≒ ");else printf("   ");if(P2.site==103) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==104) printf("≒ ");else printf("   ");if(P2.site==104) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==105) printf("≒ ");else printf("   ");if(P2.site==105) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==106) printf("≒ ");else printf("   ");if(P2.site==106) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==107) printf("≒ ");else printf("   ");if(P2.site==107) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");printf("   ");printf("   ");printf("  太  ");if(conutry[6]==1) printf("≠ ");else printf("   ");if(conutry[6]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[7]==1) printf("≠ ");else printf("   ");if(conutry[7]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[8]==1) printf("≠ ");else printf("   ");if(conutry[8]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[9]==1) printf("≠ ");else printf("   ");if(conutry[9]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   ");printf("   "); printf("  太\n");
		printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
		printf("太");printf("ч遴蘋萄供太                                              太 漆蒂萼佩 太\n");
		printf("太");printf("天天天天天太    天天天天天天天天天天                      太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==101) printf("≒ ");else printf("   ");if(P2.site==101) printf(" ∞");else printf("   "); printf("  太   太                  太                     太  ");if(P1.site==108) printf("≒ ");else printf("   ");if(P2.site==108) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");printf("   ");printf("   ");printf("  太   太  ч  遴  蘋  萄  太                     太  ");if(conutry[11]==1) printf("≠ ");else printf("   ");if(conutry[11]==2) printf(" ≧");else printf("   "); printf("  太\n");
		printf("太");printf("天天天天天太   太                  太                     太天天天天天太\n");
		printf("太");printf(" 漆檜癒 佬太    天天天天天天天天天天                      太ч遴蘋萄佻太\n");
		printf("太");printf("天天天天天太                                              太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==100) printf("≒ ");else printf("   ");if(P2.site==100) printf(" ∞");else printf("   "); printf("  太                                              太  ");if(P1.site==109) printf("≒ ");else printf("   ");if(P2.site==109) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");if(conutry[3]==1) printf("≠ ");else printf("   ");if(conutry[3]==2) printf(" ≧");else printf("   "); printf("  太                                              太  "); printf("   "); printf("   "); printf("  太\n");
		printf("太");printf("天天天天天太                                              太天天天天天太\n");
		printf("太");printf(" 蘋檜煎 使太                                              太葆萄葬萄侖太\n");
		printf("太");printf("天天天天天太                                              太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==99) printf("≒ ");else printf("   ");if(P2.site==99) printf(" ∞");else printf("   "); printf("  太                                              太  ");if(P1.site==110) printf("≒ ");else printf("   ");if(P2.site==110) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");if(conutry[2]==1) printf("≠ ");else printf("   ");if(conutry[2]==2) printf(" ≧");else printf("   "); printf("  太                   1P曖 蜓擎 ≒殮棲棻.        太  ");if(conutry[13]==1) printf("≠ ");else printf("   ");if(conutry[13]==2) printf(" ≧");else printf("   "); printf("  太\n");
		printf("太");printf("天天天天天太                   2P曖 蜓擎 ∞殮棲棻.        太天天天天天太\n");
		printf("太");printf("  寞 囂 佳太                                              太 だ 葬 佾 太\n");
		printf("太");printf("天天天天天太                   1P曖 勒僭擎 ≠殮棲棻.      太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==98) printf("≒ ");else printf("   ");if(P2.site==98) printf(" ∞");else printf("   "); printf("  太                   2P曖 勒僭擎 ≧殮棲棻.      太  ");if(P1.site==111) printf("≒ ");else printf("   ");if(P2.site==111) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");if(conutry[1]==1) printf("≠ ");else printf("   ");if(conutry[1]==2) printf(" ≧");else printf("   "); printf("  太                                              太  ");if(conutry[14]==1) printf("≠ ");else printf("   ");if(conutry[14]==2) printf(" ≧");else printf("   "); printf("  太\n");
		printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
		printf("太");printf(" START 侍 太  憮 選 兒太 措撮羶 兔太 景 踹 佺 太  楛 湍侑 太撮啗罹ч侏太\n");
		printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
		printf("太");printf("  ");if(P1.site==97) printf("≒ ");else printf("   ");if(P2.site==97) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==116) printf("≒ ");else printf("   ");if(P2.site==116) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==115) printf("≒ ");else printf("   ");if(P2.site==115) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==114) printf("≒ ");else printf("   ");if(P2.site==114) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==113) printf("≒ ");else printf("   ");if(P2.site==113) printf(" ∞");else printf("   "); printf("  太  ");if(P1.site==112) printf("≒ ");else printf("   ");if(P2.site==112) printf(" ∞");else printf("   "); printf("  太\n");
		printf("太");printf("  ");if(conutry[0]==1) printf("≠ ");else printf("   ");if(conutry[0]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[19]==1) printf("≠ ");else printf("   ");if(conutry[19]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   ");printf("   "); printf("  太  ");if(conutry[17]==1) printf("≠ ");else printf("   ");if(conutry[17]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[16]==1) printf("≠ ");else printf("   ");if(conutry[16]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   "); printf("   "); printf("  太\n"); 
		puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
		trip(a, b, m1, m2);
	}
	else if(*a==113)
	{
		printf("%dP曖 蜓檜 楛湍縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[16]==0)
		{
			puts("");
			printf("楛湍縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("楛湍曖 衛撮朝 20虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 楛湍擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[16]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[16]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 40虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[16]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 40虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==114)
	{
		printf("%dP曖 蜓檜 景踹縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[17]==0)
		{
			puts("");
			printf("景踹縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("景踹曖 衛撮朝 20虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 景踹擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[17]=b;
				if(b==1)
					*m1-=20;
				else
					*m2-=20;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[17]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 40虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+40;
				*m2=*m2-40;
			}

		}
		else if(conutry[17]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 40虜錳擊 2P縑啪 鄹棲棻.\n");
			*m2=*m2+40;
			*m1=*m1-40;
		}
		getchar();
	system("cls");
	}
	else if(*a==115)
	{
		printf("%dP曖 蜓檜 措撮羶縑 紫雜ж樟蝗棲棻. 嬴梆雖虜.. 撮旎擊 頂敷撿 м棲棻.\n", b);
		printf("10虜錳擊 撮旎戲煎 頂樟蝗棲棻.\n");
		if(b==1)
			*m1 = *m1 - 10;
		else
			*m2 = *m2 - 10;
	}
	else if(*a==116)
	{
		printf("%dP曖 蜓檜 憮選縑 紫雜ж樟蝗棲棻.\n", b);
		if(conutry[19]==0)
		{
			puts("");
			printf("憮選縑 螃褐勘 �紊腎桭炴�.\n");Sleep(2000);
			printf("憮選曖 衛撮朝 25虜錳殮棲棻. 餌衛啊蝗棲梱?\n");
			printf("[YES塭賊 1擊 殮溘, NO塭賊 0擊 殮溘п輿衛晦 夥奧棲棻.]\n");
			scanf("%d", &y);
			if(y==1)
			{
				printf("%dP椒 謠擎 摹鷗殮棲棻. 憮選擊 餌褐匙擊 蹴ж萄董棲棻.\n", b);Sleep(2000);
				conutry[19]=b;
				if(b==1)
					*m1-=25;
				else
					*m2-=25;
			}
			else if(y==0)
			{
				printf("嬴蔣雖虜 棻擠擊 晦擒ж轄. 寰喟�� 陛衛晦 夥奧棲棻.\n");Sleep(2000);
			}

			printf("\n棻衛 罹ч擊 衛濛м棲棻. Enter蒂 揚楝輿衛晦 夥奧棲棻.");
			getchar();
		}
		else if(conutry[19]==1)
		{
			if(b==1)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
			{
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 50虜錳擊 1P縑啪 鄹棲棻.\n");
				*m1=*m1+50;
				*m2=*m2-50;
			}

		}
		else if(conutry[19]==2)
		{
			if(b==2)
				printf("濠褐檜 骯 階殮棲棻.\n");
			else
				printf("濠褐曖 階檜 嬴棋 夠擊 罹чц晦 陽僥縑 檜辨猿煎 50虜錳擊 2P縑啪 鄹棲棻.\n");
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
	puts("  撮啗 罹ч 陛堅 談擎 釭塭曖 蕙縑 氈朝 模僥濠 憲だ漯擊 瞳堅 Enter蒂 揚楝輿撮蹂.");
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
	printf(" %dP椒 輿餌嬪蒂 掉葬褒 遽綠陛 腎樟棻賊 樹薯萇雖 Enter蒂 揚楝輿衛晦 夥奧棲棻!!!\n", a);
	getchar();
	for(c=1;c<=100;c++)
	{
		srand(time(NULL));
		i = (rand()%6)+1;
		puts("");
		printf(" 輿餌嬪蒂 掉葬朝 醞殮棲棻...\n");
		puts("");
		system("cls");
		switch(i)
		{
		case 1:
			puts("");
			puts("   天天天天天");
			puts("  太        太");
			puts("  太   ≒   太");
			puts("  太        太");
			puts("   天天天天天");
			break;

		case 2:
			puts("");
			puts("   天天天天天");
			puts("  太        太");
			puts("  太 ≒  ≒ 太");
			puts("  太        太");
			puts("   天天天天天");;
			break;

		case 3:
			puts("");
			puts("   天天天天天");
			puts("  太     ≒ 太");
			puts("  太   ≒   太 ");
			puts("  太 ≒     太");
			puts("   天天天天天");
			break;

		case 4:
			puts("");
			puts("   天天天天天");
			puts("  太 ≒  ≒ 太");
			puts("  太        太");
			puts("  太 ≒  ≒ 太");
			puts("   天天天天天");
			break;

		case 5:
			puts("");
			puts("   天天天天天");
			puts("  太 ≒  ≒ 太");
			puts("  太   ≒   太");
			puts("  太 ≒  ≒ 太");
			puts("   天天天天天");
			break;

		case 6:
			puts("");
			puts("   天天天天天");
			puts("  太 ≒  ≒ 太");
			puts("  太 ≒  ≒ 太");
			puts("  太 ≒  ≒ 太");
			puts("   天天天天天");
			break;

		}
		if(c==100)
		{
			printf("\n %dP椒檜 輿餌嬪蒂 掉萼 唸婁朝 %d殮棲棻.\n", a, i);
			printf("\n≦ 棻擠戲煎 霞чж衛溥賊 Enter蒂 揚楝輿衛望 夥奧棲棻");
			getchar();
			system("cls");
			return i;
		}
	}

}
int rank()
{
	int a=0, b=0;

	printf("\n ≦ 譆渠 啪歜 霤罹 陛棟и 檣錳擎 2貲;殮棲棻.\n");
	printf("\n ≦ 1P曖 蜓擎 ≒殮棲棻. \n");
	printf("    1P曖 勒僭擎 ≠殮棲棻.\n\n");
	printf(" ≦ 2P曖 蜓擎 ∞殮棲棻.\n");
	printf("    2P曖 勒僭擎 ≧殮棲棻.\n\n");

	puts(" ≦ 1P諦 2P蒂 試盪 霞чй 牖憮蒂 薑ж晦 嬪п 輿餌嬪蒂 掉葬啊蝗棲棻.\n");
	puts(" ≦ 啗樓 霞чж衛溥賊 Enter蒂 揚楝輿衛晦 夥奧棲棻. ");
	getchar();
	system("cls");

RE:

	puts("");
	puts(" ≦ 1P 餌辨濠睡攪 輿餌嬪蒂 掉葬啊蝗棲棻.");
	puts("");
	a=dice(1);

	puts("");
	puts(" ≦ 2P 餌辨濠陛 輿餌嬪蒂 掉葬啊蝗棲棻.");
	puts("");
	b=dice(2);

	if(a==b)
	{
		puts("");
		puts(" ≦ 1P諦 2P曖 輿餌嬪曖 唸婁陛 偽戲嘎煎 棻衛 給葬啊蝗棲棻.");
		goto RE;
	}
	else if(a<b)
	{
		puts("");
		puts(" ≦ 2P曖 輿餌嬪 唸婁陛 渦 堪戲嘎煎 2P睡攪 啪歜擊 衛濛м棲棻.");
		return 1;
	}
	else if(a>b)
	{
		puts("");
		puts(" ≦ 1P曖 輿餌嬪 唸婁陛 渦 堪戲嘎煎 1P睡攪 啪歜擊 衛濛м棲棻.");
		return 0;
	}
}
void map1()
{
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	printf("太");printf(" п瞳撰 例太  紫 瓖 來太 諒陛ィ 侃太 衛萄棲 佰太賅蝶觼夥併太 蘋雖喻 侈太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("          太   8虜錳  太   8虜錳  太  10虜錳  太  10虜錳  太          太\n");
	printf("太");printf("  -20虜錳 太          太          太          太          太   紫夢   太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf("ч遴蘋萄供太                                              太 漆蒂萼佩 太\n");
	printf("太");printf("天天天天天太    天天天天天天天天天天                      太天天天天天太\n");
	printf("太");printf("  good    太   太                  太                     太  16虜錳  太\n");
	printf("太");printf("    luck! 太   太  ч  遴  蘋  萄  太                     太          太\n");
	printf("太");printf("天天天天天太   太                  太                     太天天天天天太\n");
	printf("太");printf(" 漆檜癒 佬太    天天天天天天天天天天                      太ч遴蘋萄佻太\n");
	printf("太");printf("天天天天天太                                              太天天天天天太\n");
	printf("太");printf("   5虜錳  太                                              太 good     太\n");
	printf("太");printf("          太                                              太    luck! 太\n");
	printf("太");printf("天天天天天太                                              太天天天天天太\n");
	printf("太");printf(" 蘋檜煎 使太                                              太葆萄葬萄侖太\n");
	printf("太");printf("天天天天天太                                              太天天天天天太\n");
	printf("太");printf("   4虜錳  太                                              太  18虜錳  太\n");
	printf("太");printf("          太                   1P曖 蜓擎 ≒殮棲棻.        太          太\n");
	printf("太");printf("天天天天天太                   2P曖 蜓擎 ∞殮棲棻.        太天天天天天太\n");
	printf("太");printf("  寞 囂 佳太                                              太 だ 葬 佾 太\n");
	printf("太");printf("天天天天天太                   1P曖 勒僭擎 ≠殮棲棻.      太天天天天天太\n");
	printf("太");printf("   3虜錳  太                   2P曖 勒僭擎 ≧殮棲棻.      太  18虜錳  太\n");
	printf("太");printf("          太                                              太          太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf(" START 侍 太  憮 選 兒太 措撮羶 兔太 景 踹 佺 太  楛 湍侑 太撮啗罹ч侏太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("  諾犒 衛 太  25虜錳  太          太  20虜錳  太  20虜錳  太  go~     太\n");
	printf("太");printf("  +20虜錳 太          太 -10虜錳  太          太          太      go~ 太\n");
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
}
void mainmap()
{
	puts("\n");
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	printf("太");printf(" п瞳撰 例太  紫 瓖 來太 諒陛ィ 侃太 衛萄棲 佰太賅蝶觼夥併太 蘋雖喻 侈太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("          太   8虜錳  太   8虜錳  太  10虜錳  太  10虜錳  太          太\n");
	printf("太");printf("  -20虜錳 太          太          太          太          太   紫夢   太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf("ч遴蘋萄供太                                              太 漆蒂萼佩 太\n");
	printf("太");printf("天天天天天太         ﹥    ﹥         ﹥﹥﹥﹥            太天天天天天太\n");
	printf("太");printf("  good    太         ﹥    ﹥               ﹥            太  16虜錳  太\n");
	printf("太");printf("    luck! 太         ﹥﹥﹥﹥         ﹥﹥﹥﹥            太          太\n");
	printf("太");printf("天天天天天太         ﹥    ﹥         ﹥                  太天天天天天太\n");
	printf("太");printf(" 漆檜癒 佬太         ﹥﹥﹥﹥         ﹥﹥﹥﹥            太ч遴蘋萄佻太\n");
	printf("太");printf("天天天天天太       ﹥﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥﹥          太天天天天天太\n");
	printf("太");printf("   5虜錳  太            ﹥               ﹥               太 good     太\n");
	printf("太");printf("          太            ﹥               ﹥               太    luck! 太\n");
	printf("太");printf("天天天天天太                       ﹥        ﹥    ﹥     太天天天天天太\n");
	printf("太");printf(" 蘋檜煎 使太             ﹥﹥﹥﹥  ﹥        ﹥﹥﹥﹥     太葆萄葬萄侖太\n");
	printf("太");printf("天天天天天太             ﹥    ﹥  ﹥﹥﹥    ﹥    ﹥     太天天天天天太\n");
	printf("太");printf("   4虜錳  太             ﹥    ﹥  ﹥        ﹥﹥﹥﹥     太  18虜錳  太\n");
	printf("太");printf("          太             ﹥﹥﹥﹥  ﹥    ﹥﹥﹥﹥﹥﹥﹥﹥ 太          太\n");
	printf("太");printf("天天天天天太                       ﹥        ﹥﹥﹥﹥     太天天天天天太\n");
	printf("太");printf("  寞 囂 佳太                                       ﹥     太 だ 葬 佾 太\n");
	printf("太");printf("天天天天天太      ver 1.0                    ﹥﹥﹥﹥     太天天天天天太\n");
	printf("太");printf("   3虜錳  太                                 ﹥           太  18虜錳  太\n");
	printf("太");printf("          太                                 ﹥﹥﹥﹥     太          太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf(" START 侍 太  憮 選 兒太 措撮羶 兔太 景 踹 佺 太  楛 湍侑 太撮啗罹ч侏太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("  諾犒 衛 太  25虜錳  太          太  20虜錳  太  20虜錳  太  go~     太\n");
	printf("太");printf("  +20虜錳 太          太  -10虜錳 太          太          太      go~ 太\n");
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	puts("");
	puts("		睡瑞葆綰曖 撮啗縑 螃褐勘 �紊腎桭炴暀楔竣�");
	puts("		衛濛ж衛溥賊 Enter蒂 揚楝輿衛晦 夥奧棲棻.");
	getchar();
	system("cls");
}
void realmap(int *a, int *b,int *m1, int *m2)
{
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	printf("太");printf(" п瞳撰 例太  紫 瓖 來太 諒陛ィ 侃太 衛萄棲 佰太賅蝶觼夥併太 蘋雖喻 侈太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("  ");if(*a==102) printf("≒ ");else printf("   ");if(*b==102) printf(" ∞");else printf("   "); printf("  太  ");if(*a==103) printf("≒ ");else printf("   ");if(*b==103) printf(" ∞");else printf("   "); printf("  太  ");if(*a==104) printf("≒ ");else printf("   ");if(*b==104) printf(" ∞");else printf("   "); printf("  太  ");if(*a==105) printf("≒ ");else printf("   ");if(*b==105) printf(" ∞");else printf("   "); printf("  太  ");if(*a==106) printf("≒ ");else printf("   ");if(*b==106) printf(" ∞");else printf("   "); printf("  太  ");if(*a==107) printf("≒ ");else printf("   ");if(*b==107) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");printf("   ");printf("   ");printf("  太  ");if(conutry[6]==1) printf("≠ ");else printf("   ");if(conutry[6]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[7]==1) printf("≠ ");else printf("   ");if(conutry[7]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[8]==1) printf("≠ ");else printf("   ");if(conutry[8]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[9]==1) printf("≠ ");else printf("   ");if(conutry[9]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   ");printf("   "); printf("  太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf("ч遴蘋萄供太                                              太 漆蒂萼佩 太\n");
	printf("太");printf("天天天天天太    天天天天天天天天天天                      太天天天天天太\n");
	printf("太");printf("  ");if(*a==101) printf("≒ ");else printf("   ");if(*b==101) printf(" ∞");else printf("   "); printf("  太   太                  太                     太  ");if(*a==108) printf("≒ ");else printf("   ");if(*b==108) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");printf("   ");printf("   ");printf("  太   太  ч  遴  蘋  萄  太                     太  ");if(conutry[11]==1) printf("≠ ");else printf("   ");if(conutry[11]==2) printf(" ≧");else printf("   "); printf("  太\n");
	printf("太");printf("天天天天天太   太                  太                     太天天天天天太\n");
	printf("太");printf(" 漆檜癒 佬太    天天天天天天天天天天                      太ч遴蘋萄佻太\n");
	printf("太");printf("天天天天天太                                              太天天天天天太\n");
	printf("太");printf("  ");if(*a==100) printf("≒ ");else printf("   ");if(*b==100) printf(" ∞");else printf("   "); printf("  太                                              太  ");if(*a==109) printf("≒ ");else printf("   ");if(*b==109) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");if(conutry[3]==1) printf("≠ ");else printf("   ");if(conutry[3]==2) printf(" ≧");else printf("   "); printf("  太                                              太  "); printf("   "); printf("   "); printf("  太\n");
	printf("太");printf("天天天天天太");printf("    1P money : %3d虜錳", *m1);printf("   2P money : %3d虜錳", *m2);printf("   太天天天天天太\n");
	printf("太");printf(" 蘋檜煎 使太                                              太葆萄葬萄侖太\n");
	printf("太");printf("天天天天天太                                              太天天天天天太\n");
	printf("太");printf("  ");if(*a==99) printf("≒ ");else printf("   ");if(*b==99) printf(" ∞");else printf("   "); printf("  太                                              太  ");if(*a==110) printf("≒ ");else printf("   ");if(*b==110) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");if(conutry[2]==1) printf("≠ ");else printf("   ");if(conutry[2]==2) printf(" ≧");else printf("   "); printf("  太                   1P曖 蜓擎 ≒殮棲棻.        太  ");if(conutry[13]==1) printf("≠ ");else printf("   ");if(conutry[13]==2) printf(" ≧");else printf("   "); printf("  太\n");
	printf("太");printf("天天天天天太                   2P曖 蜓擎 ∞殮棲棻.        太天天天天天太\n");
	printf("太");printf("  寞 囂 佳太                                              太 だ 葬 佾 太\n");
	printf("太");printf("天天天天天太                   1P曖 階擎 ≠殮棲棻.        太天天天天天太\n");
	printf("太");printf("  ");if(*a==98) printf("≒ ");else printf("   ");if(*b==98) printf(" ∞");else printf("   "); printf("  太                   2P曖 階擎 ≧殮棲棻.        太  ");if(*a==111) printf("≒ ");else printf("   ");if(*b==111) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");if(conutry[1]==1) printf("≠ ");else printf("   ");if(conutry[1]==2) printf(" ≧");else printf("   "); printf("  太                                              太  ");if(conutry[14]==1) printf("≠ ");else printf("   ");if(conutry[14]==2) printf(" ≧");else printf("   "); printf("  太\n");
	printf("太");printf("天天天天天太天天天天天天天天天天天天天天天天天天天天天天天太天天天天天太\n");
	printf("太");printf(" START 侍 太  憮 選 兒太 措撮羶 兔太 景 踹 佺 太  楛 湍侑 太撮啗罹ч侏太\n");
	printf("太");printf("天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太天天天天天太\n");
	printf("太");printf("  ");if(*a==97) printf("≒ ");else printf("   ");if(*b==97) printf(" ∞");else printf("   "); printf("  太  ");if(*a==116) printf("≒ ");else printf("   ");if(*b==116) printf(" ∞");else printf("   "); printf("  太  ");if(*a==115) printf("≒ ");else printf("   ");if(*b==115) printf(" ∞");else printf("   "); printf("  太  ");if(*a==114) printf("≒ ");else printf("   ");if(*b==114) printf(" ∞");else printf("   "); printf("  太  ");if(*a==113) printf("≒ ");else printf("   ");if(*b==113) printf(" ∞");else printf("   "); printf("  太  ");if(*a==112) printf("≒ ");else printf("   ");if(*b==112) printf(" ∞");else printf("   "); printf("  太\n");
	printf("太");printf("  ");if(conutry[0]==1) printf("≠ ");else printf("   ");if(conutry[0]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[19]==1) printf("≠ ");else printf("   ");if(conutry[19]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   ");printf("   "); printf("  太  ");if(conutry[17]==1) printf("≠ ");else printf("   ");if(conutry[17]==2) printf(" ≧");else printf("   "); printf("  太  ");if(conutry[16]==1) printf("≠ ");else printf("   ");if(conutry[16]==2) printf(" ≧");else printf("   "); printf("  太  ");printf("   "); printf("   "); printf("  太\n"); 
	puts(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
}