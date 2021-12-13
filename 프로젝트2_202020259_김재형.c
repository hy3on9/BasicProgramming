/*
	Name : 프로젝트2_202020259_김재형.c
	Content : 좌석 예약 프로그램 
	Implementation : 202020259 김재형
	Last modified : 2021/12/13	 
*/

#include <stdio.h>

void print_seat(int seat[][4], int total);
int reserve_seat(int seat[][4], int total);
int cancel_seat(int seat[][4]);

int main()
{
	int opt, total = 0;
	char exit;
	int seat[5][4] = { 0 }; 
		
	printf("[ 좌석 예약 프로그램 ]\n");					// program start
	
	while(1)
	{
		printf("[ 서비스 번호 - 1:좌석 예약, 2:좌석 취소 ]\n");		
		printf(">>> 서비스 번호를 선택하세요 : ");
		scanf("%d", &opt); 								// 서비스 번호 입력 
		
		switch(opt){
			case 1:		// 좌석 예약 
				print_seat(seat, total);
				total += reserve_seat(seat, total);		//	예약한 좌석수만큼 total에서 더하기 
				print_seat(seat, total);
				break;
			case 2: 	// 좌석 취소 
				print_seat(seat, total);
				total -= cancel_seat(seat);				// 취소된 좌석수만큼 total에서 빼기 
				print_seat(seat, total);
				break;
			default:	// 메뉴 입력 오류 
				printf("서비스 번호를 잘못 입력했습니다.\n");
				break;
		}
		printf("계속 이용하시겠습니까?(y 또는 n) : ");	
		scanf(" %c", &exit);							// 프로그램 종료 여부 입력 
		
		if(exit == 'n')									// n 입력시 프로그램 종료 
			break;
		printf("\n");
	}
}

void print_seat(int seat[][4], int total)		//	좌석 현황 출력 함수 
{
	int m, n;
	printf("--- 현재 좌석 현황 ---\n");
	printf("----------------------\n");
	printf("%7c %3c %3c %3c\n",'A','B','C','D');
	printf("----------------------\n");
	for(m=0; m<5; m++){
		printf("%d |", m+1);
		for(n=0; n<4; n++){
			printf("%4d", seat[m][n]);
		}
		printf("\n");
	}
	printf("----------------------\n");
	printf("예약 좌석 수 : %d / 잔여 좌석 수 : %d\n\n", total, 20-total);
}

int reserve_seat(int seat[][4], int total)		// 좌석 예약 함수 	 
{
	int num, i, row, col;
	char s[2];
	
	while(1){
		printf(">>> 예약할 좌석 총 수량 입력 : ");
		scanf("%d", &num);
		
		if(num > 20-total){						// 예약 가능한 좌석수 체크 
			printf("예약 가능한 좌석 수를 초과했습니다.\n");
			continue;
		}
		
		for(i=0; i<num; i++){
			while(1){
				printf(">>> 예약할 좌석 번호 선택 : ");
				scanf("%s", s);
				row = s[1] - '\0' - 65;		// 예약 좌석 (char to int) 
				col = s[0] - '0' - 1;
				
				if(seat[col][row] == 1){	// 좌석 예약 여부 체크 
					printf("이미 예약된 좌석입니다.\n");
					continue;
				}
				
				seat[col][row] = 1;
				break;
			}
		}
		printf("\n예약되었습니다.\n\n");
		break;
	}
	
	return num;						// 예약한 좌석수 리턴 
}

int cancel_seat(int seat[][4])		//	좌석 취소 함수 
{
	char s[2];
	int row, col;
	
	while(1){
		printf("취소할 좌석 번호 입력 : ");
		scanf("%s", s);
		row = s[1] - '\0' - 65;			// 취소 좌석 (char to int) 
		col = s[0] - '0' - 1;
		
		if(seat[col][row] == 0){		// 좌석 예약 여부 체크 
			printf("예약되지 않은 좌석입니다.\n");
			continue;
		}
		
		seat[col][row] = 0;				
		break;
	}
	printf("\n취소되었습니다.\n\n");
	
	return 1;							// 취소한 좌석수 리턴 
}










