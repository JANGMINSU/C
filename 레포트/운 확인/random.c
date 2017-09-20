#include <stdio.h>
void main()
{
	int age, luk;
	srand(time(NULL));  
	luk=(rand()%100)+1;

	printf("당신의 나이를 입력하여 주세요!\n");

	scanf("%d", &age);

	if(age<10)
	printf("오늘은 아주 행복한 일이 발생할 운입니다!\n");
	else if(age<20)
	printf("오늘은 바쁜날이 예상됩니다. 열심히 노력하세요!\n");
	else if(age<30)
	printf("자만하지 마세요. 큰 코 다쳐요!\n");
	else if(age<40)
	printf("오늘은 정말 위험한 날이니 모든 행동을 중지하세요!\n");
	else if(age<50)
	printf("오늘은 돈 쓸일이 많아질 거 같아요. 하지만 다시 돌아올테니 걱정말아요!\n");
	else if(age<60)
	printf("오늘은 손님이 찾아올 예정이군요. 그 손님을 잘 챙겨주세요!\n");
	else if(age<70)
	printf("오늘 뭔가 기분 좋지 않은 일이 발생할 예감이 드는군요 조심하세요!\n");
	else if(age<80)
	printf("뭔가 오늘따라 우울하시군요. 분위기 전환이 필요한 시기입니다!\n");
	else
	printf("오늘 야외 활동을 금하세요. 사고의 위험이 다가오고 있습니다!\n");

	printf("오늘의 금전운은 %d입니다.\n", luk);
}