#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//打印棋盘
void show_board(char arr[re_row][re_col], int row, int col)	 
{
	int i = 0;
	int j = 0;
	system("clear");
	printf("\n");
	printf("#");
	for (j = 1; j < row + 1; j++)
	{
		printf("  %-2d", j);									
	}
	printf("  #\n");
						
	for (i = 0; i < row + 1; i++)
	{
		printf("  ");
		for (j = 0; j < col + 1; j++)
		{
			printf("*");
			if (j < col)
			{
				printf("---");
			}
		}
		printf("\n");
		if (i < row)
		{
			printf("%-2d", i + 1);
			for (j = 0; j < col + 1; j++)
			{
				printf("|");
				if (j < col)
				{
					printf(" %c ", arr[i + 1][j + 1]);
					//void Tag_Color(arr, i, j);
				}
			}
			printf("%2d", i + 1);
			printf("\n");
		}
	}
	printf("#");
	
	for (j = 1; j < row + 1; j++)
	{
		printf("  %-2d", j);
	}
	printf("  #\n");
}

void show_died(char arr[re_row][re_col], int row, int col)
{
	int i = 0;
	int j = 0;		
	printf("#");		
	for (j = 1; j < row + 1; j++)			
	{						
		printf("  %-2d", j);								
	}					
	printf("  #\n");
					
	for (i = 0; i < row + 1; i++)
	{
		printf("  ");						
		for (j = 0; j < col + 1; j++)			
		{						
			printf("*");
			if (j < col)			
			{		
				printf("---");				
			}					
		}	
		printf("\n");
		if (i < row)			
		{		
			printf("%-2d", i + 1);
			for (j = 0; j < col + 1; j++)					
			{						
				printf("|");
				if (j < col)			
				{		
					if (arr[i+1][j+1] == '0')
					{					
						printf("   ");				
					}			
					else 
					{
						printf(" %c ", arr[i+1][j+1]);	
					}
				}
			}
			printf("%2d", i + 1);
			printf("\n");
		}
	}
	printf("#");
	for (j = 1; j < row + 1; j++)
	{
		printf("  %-2d", j);
	}
	printf("  #\n");
}


void Init_board(char board[re_row][re_col], int row, int col, char set)		//初始化，用set的值初始化所有元素
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}


void Set_mine(char board[re_row][re_col], int row, int col)		//布置雷
{
	int count = Mine;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

char Count_nearby(char board[re_row][re_col], int row, int col, int x, int y)
{
	//	if (x >= 0 && x <= row && y >= 0 && y <= col)
	return 
		board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 7 * '0';
}

void Nearby_Is_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col, int x, int y)
{
	char ret;
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		ret = Count_nearby(board, ROW, COL, x, y);
		if (ret == '0')
		{
			arr[x][y] = ' ';
			if ((x - 1)>0 && (y - 1)>0 && (arr[x - 1][y - 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x - 1, y - 1);
			if ((x - 1)>0 && (y)>0 && (arr[x - 1][y] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x - 1, y);
			if ((x - 1)>0 && (y + 1)>0 && (arr[x - 1][y + 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x - 1, y + 1);
			if ((x)>0 && (y - 1)>0 && (arr[x][y - 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x, y - 1);
			if ((x)>0 && (y + 1)>0 && (arr[x][y + 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x, y + 1);
			if ((x + 1)>0 && (y - 1)>0 && (arr[x + 1][y - 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x + 1, y - 1);
			if ((x + 1)>0 && (y)>0 && (arr[x + 1][y] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x + 1, y);
			if ((x + 1)>0 && (y + 1)>0 && (arr[x + 1][y + 1] == '#'))
				Nearby_Is_mine(board, arr, ROW, COL, x + 1, y + 1);
		}
		else
			arr[x][y] = ret;
	}
}

int First_tip(char board[re_row][re_col], char arr[re_row][re_col],int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Which one is the real mine ?\n");
	printf("Input your choose(x, y):>_ ");
	scanf("%d%d", &x, &y);
	while ('\n' != getchar());
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		if (board[x][y] == '1')
		{
			// 刷新一遍图
			do 
			{
				Init_board(board, re_row, re_col, '0');
				Set_mine(board, ROW, COL);
				if (board[x][y] == '0')
					return 0;
			} while (1);
			//或者把棋子搬走
			//board[x][y] = '0';
			//do
			//{
			//	int X = rand() % row + 1;
			//	int Y = rand() % col + 1;
			//	if (board[X][Y] == '0')
			//	{
			//		if (X != x || Y != y)
			//		{
			//			board[X][Y] = '1';
			//			return 0;
			//		}
			//	}
			//} while (1);
		}		
		else 
		{
			arr[x][y] = Count_nearby(board, ROW, COL, x, y);
			if (arr[x][y] == '0')
			{
				Nearby_Is_mine(board, arr, row, col, x, y);
			}
			show_board(arr, ROW, COL);
			if (Game_end(arr, board, ROW, COL) == 0)
			{
				return 1;
			}
		}
	}
	else
	{
		printf("Input error! Enter again:>_ ");
	}
	return 0;
}
int Tag_mine(char arr[re_row][re_col])
{
	int  x = 0;
	int  y = 0;
	printf("Find a mine: which # is Mine ? Tag it: @");
	printf("\n<空格回车输入坐标，单击回车跳过>\n");
	if ('\n' == getchar())
	{
		return 0;
	}
	else
	{
		while ('\n' != getchar());
		printf("input your choose:>_ ");
		scanf("%d%d", &x, &y);
		while ('\n' != getchar());
		arr[x][y] = '@';
		show_board(arr, ROW, COL);
		return -1;
	}
}

int Game_end(char arr[re_row][re_col], char board[re_row][re_col], int row, int col)
{
	int i = 0;
	int j = 0;
	int t = 0;
	int count = row * col;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (arr[i][j] != '#'&& arr[i][j] != '@')
			{
				count--;
			}
			if (arr[i][j] == '#' || arr[i][j] == '@')
			{
				t++;
			}
		}
	}
	if (count != Mine)
	{
		while (-1 == Tag_mine(arr))
		{
			count--;
		};
		show_board(arr, ROW, COL);
		printf("num of \'# / @\'：%d\n", t);
	}
	if (count == Mine)
	{
		system("cls");
		show_died(board, ROW, COL);
		printf("\n\a  GOOD！\n");
		sleep(1);
		return 0;
	}			
	return 1;
}


int Sweep_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col)
{
	int x = 0;
	int y = 0;
	do 
	{
		printf("Which one is the real mine ?\n");
		printf("Input your choose(x, y):>_ ");
		scanf("%d%d", &x, &y);
		while ('\n' != getchar());
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x][y] == '1')
			{
				show_died(board, ROW, COL);
				printf("You have died!\n");
				return 0;
			}
			else
			{
				arr[x][y] = Count_nearby(board, ROW, COL, x, y);
				if (arr[x][y] == '0')
				{
					Nearby_Is_mine(board, arr, row, col, x, y);
					show_board(arr, ROW, COL);
				}
				else
				{
					if (Game_end(arr, board, ROW, COL) == 0)
					{
						return 0;
					}
				}
			}
		}
		else
		{
			printf("Input error! Enter again:>_ ");
		}
	} while (1);
}

