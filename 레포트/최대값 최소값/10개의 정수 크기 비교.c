#include <stdio.h>
int max(int *a)
{
	int large,i=0;

	large=*a;
	for(i=0;i<10;i++)
	{
		if(large<*(a+i))
			large=*(a+i);
	}
	return large;

}

int min(int *a)
{
	int small,i=0;

	small=*a;
	for(i=0;i<10;i++)
	{
		if(small>*(a+i))
			small=*(a+i);
	}
	return small;
}

void main()
{
	int a[10], i;
	int *pa=a;
	printf("10���� ������ �Է� �Ͽ� �ּ���!\n");
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<10;i++)
	{
		printf("%d ", *(pa+i));
	}
	printf("\n");
	printf("�ִ밪�� %d �Դϴ�.\n",max(pa));
	printf("�ּҰ��� %d �Դϴ�.\n",min(pa));
}