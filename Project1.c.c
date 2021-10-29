/*
	Name : project1.c
	Content : Diamond, SandGlass ��� �׸��� 
	Implementation : 202020259 ������
	Last modified : 2021/10/29	 
*/
#include <stdio.h>

void PrintMenu();
void Diamond(int c);
void SandGlass(int c);

int main()
{
	int shape, center;
	
	while(1)
	{
		PrintMenu();
		
		printf(">>> ����� ��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &shape);

		switch(shape)
		{
			case 1:
				printf(">>> �߽ɰ��� �Է��ϼ��� : ");
				scanf("%d", &center);
				Diamond(center);
				break;
			case 2:
				printf(">>> �߽ɰ��� �Է��ϼ��� : ");
				scanf("%d", &center);
				SandGlass(center);
				break;
			case 0:
				printf("���α׷��� �����մϴ�!\n");
				return 0;
			default:
				printf("���⿡ ���� ��ȣ�� �ԷµǾ����ϴ�!\n\n");
				break;
		}
	}
}

void PrintMenu()
{
	printf("[ ��� ��� ���α׷� ]\n");
	printf("[ ��� ��ȣ - 1 : ��+����ǥ ���̾Ƹ��, 2: ���� �𷡽ð� / 0 : ���α׷� ���� ]\n\n");
}

void Diamond(int c)
{
	int x, y;
	
	for(x=1; x<=c; x++){
		for(y=1; y<=c-x; y++){
			printf(" ");
		}
		if(x==1){
			printf("*");
		}else{
			printf("*");
			for(y=1; y<2*x-2; y++){
				printf("!");
			}
			printf("*");
		}
		for(y=1; y<=c-x; y++){
			printf(" ");
		}
		printf("\n");
	}
	for(x=c-1; x>0; x--){
		for(y=1; y<=c-x; y++){
			printf(" ");
		}
		if(x==1){
			printf("*");
		}else{
			printf("*");
			for(y=1; y<2*x-2; y++){
				printf("!");
			}
			printf("*");
		}
		for(y=1; y<=c-x; y++){
			printf(" ");
		}
		printf("\n");
	}
}

void SandGlass(int c)
{
	int x, y;
	
	for(x=1; x<=c; x++){
		if(x==1){
			for(y=1; y<2*c; y++){
				printf("%d", x);
			}
		}else{
			for(y=1; y<x; y++){
				printf(" ");
			}
			printf("%d", x % 10);
			for(y=0; y<2*(c-x)-1; y++){
				printf(" ");
			}
			if(x!=c)
				printf("%d", x % 10);
			for(y=1; y<x; y++){
				printf(" ");
			}
		}
		printf("\n");
	}
	for(x=c-1; x>0; x--){
		if(x==1){
			for(y=1; y<2*c; y++){
				printf("%d", x);
			}
		}else{
			for(y=1; y<x; y++){
				printf(" ");
			}	
			printf("%d", x % 10);
			for(y=0; y<2*(c-x)-1; y++){
				printf(" ");
			}
			if(x!=c)
				printf("%d", x % 10);
			for(y=1; y<x; y++){
				printf(" ");
			}
		}
		printf("\n");
	}
}

















