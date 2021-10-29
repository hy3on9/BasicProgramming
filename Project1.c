/*
	Name : project1.c
	Content : Diamond, SandGlass 모양 그리기 
	Implementation : 202020259 김재형
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
		
		printf(">>> 출력할 모양 번호를 입력하세요 : ");
		scanf("%d", &shape);

		switch(shape)
		{
			case 1:
				printf(">>> 중심값을 입력하세요 : ");
				scanf("%d", &center);
				Diamond(center);
				break;
			case 2:
				printf(">>> 중심값을 입력하세요 : ");
				scanf("%d", &center);
				SandGlass(center);
				break;
			case 0:
				printf("프로그램을 종료합니다!\n");
				return 0;
			default:
				printf("보기에 없는 번호가 입력되었습니다!\n\n");
				break;
		}
	}
}

void PrintMenu()
{
	printf("[ 모양 출력 프로그램 ]\n");
	printf("[ 모양 번호 - 1 : 별+느낌표 다이아몬드, 2: 숫자 모래시계 / 0 : 프로그램 종료 ]\n\n");
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

















