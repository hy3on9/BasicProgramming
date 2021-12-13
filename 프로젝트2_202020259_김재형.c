/*
	Name : ������Ʈ2_202020259_������.c
	Content : �¼� ���� ���α׷� 
	Implementation : 202020259 ������
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
		
	printf("[ �¼� ���� ���α׷� ]\n");					// program start
	
	while(1)
	{
		printf("[ ���� ��ȣ - 1:�¼� ����, 2:�¼� ��� ]\n");		
		printf(">>> ���� ��ȣ�� �����ϼ��� : ");
		scanf("%d", &opt); 								// ���� ��ȣ �Է� 
		
		switch(opt){
			case 1:		// �¼� ���� 
				print_seat(seat, total);
				total += reserve_seat(seat, total);		//	������ �¼�����ŭ total���� ���ϱ� 
				print_seat(seat, total);
				break;
			case 2: 	// �¼� ��� 
				print_seat(seat, total);
				total -= cancel_seat(seat);				// ��ҵ� �¼�����ŭ total���� ���� 
				print_seat(seat, total);
				break;
			default:	// �޴� �Է� ���� 
				printf("���� ��ȣ�� �߸� �Է��߽��ϴ�.\n");
				break;
		}
		printf("��� �̿��Ͻðڽ��ϱ�?(y �Ǵ� n) : ");	
		scanf(" %c", &exit);							// ���α׷� ���� ���� �Է� 
		
		if(exit == 'n')									// n �Է½� ���α׷� ���� 
			break;
		printf("\n");
	}
}

void print_seat(int seat[][4], int total)		//	�¼� ��Ȳ ��� �Լ� 
{
	int m, n;
	printf("--- ���� �¼� ��Ȳ ---\n");
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
	printf("���� �¼� �� : %d / �ܿ� �¼� �� : %d\n\n", total, 20-total);
}

int reserve_seat(int seat[][4], int total)		// �¼� ���� �Լ� 	 
{
	int num, i, row, col;
	char s[2];
	
	while(1){
		printf(">>> ������ �¼� �� ���� �Է� : ");
		scanf("%d", &num);
		
		if(num > 20-total){						// ���� ������ �¼��� üũ 
			printf("���� ������ �¼� ���� �ʰ��߽��ϴ�.\n");
			continue;
		}
		
		for(i=0; i<num; i++){
			while(1){
				printf(">>> ������ �¼� ��ȣ ���� : ");
				scanf("%s", s);
				row = s[1] - '\0' - 65;		// ���� �¼� (char to int) 
				col = s[0] - '0' - 1;
				
				if(seat[col][row] == 1){	// �¼� ���� ���� üũ 
					printf("�̹� ����� �¼��Դϴ�.\n");
					continue;
				}
				
				seat[col][row] = 1;
				break;
			}
		}
		printf("\n����Ǿ����ϴ�.\n\n");
		break;
	}
	
	return num;						// ������ �¼��� ���� 
}

int cancel_seat(int seat[][4])		//	�¼� ��� �Լ� 
{
	char s[2];
	int row, col;
	
	while(1){
		printf("����� �¼� ��ȣ �Է� : ");
		scanf("%s", s);
		row = s[1] - '\0' - 65;			// ��� �¼� (char to int) 
		col = s[0] - '0' - 1;
		
		if(seat[col][row] == 0){		// �¼� ���� ���� üũ 
			printf("������� ���� �¼��Դϴ�.\n");
			continue;
		}
		
		seat[col][row] = 0;				
		break;
	}
	printf("\n��ҵǾ����ϴ�.\n\n");
	
	return 1;							// ����� �¼��� ���� 
}










