#include "test.h"

void game()
{
	char re_board[re_row][re_col] = { 0 };		//定义一个数组，存放棋子信息
	char print_board[re_row][re_col] = { 0 };	//定义一个数组用于打印
	
	//初始化
	Init_board(re_board, re_row, re_col, '0');	//数组元素全初始化为0，方便计算雷圈	
	Init_board(print_board, re_row, re_col, '#');	//数组元素全初始化为#
	
	//布置雷	
	Set_mine(re_board, ROW, COL);
	//re_board[3][3] = '1';
	//print_board[3][3] = '*';
	//show_board(re_board, ROW, COL);	
	show_board(print_board, ROW, COL);
	//排查雷	
	//第一步不死	
	if (1 == First_tip(re_board, print_board, ROW, COL))	
	{
		return;
	}	
	Sweep_mine(re_board, print_board, re_row, re_col);
}

int menu()
{
	int input = 0;
	printf("============================================\n");
	printf("   1.  play\n");
	printf("   0.  exit\n");
	printf("============================================\n");
	printf("$ Please input your choose :>_ "); 
	scanf("%d", &input); while('\n' != getchar());
	switch(input)
	{
		case 1:
			system("clear");
			game();
			break;
		case 0:
			printf("==========================================\n");
			printf("================= BAY BAY ================\n");
			printf("==========================================\n");
			sleep(1);
			break;
		default:
			printf("\nerror: Input error! Enter again\n\n");
			break;
	}
	return input;
}

void test()
{
	do {
		system("clear");
		srand((unsigned int)time(NULL));
	}while(menu());
}
