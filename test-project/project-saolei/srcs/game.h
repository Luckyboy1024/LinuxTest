#ifndef __GAME_H__
#define __GAME_H__ 

#define ROW 9
#define COL 9

#define Mine 2

#define re_row ROW+2
#define re_col COL+2

void show_board(char arr[re_row][re_col], int row, int col);
void show_died(char arr[re_row][re_col], int row, int col);				  //打印当前棋盘
void Init_board(char board[re_row][re_col], int row, int col, char set);		//初始化
void Set_mine(char board[re_row][re_col], int row, int col);					//设置雷

char Count_nearby(char board[re_row][re_col], int row, int col, int x, int y);
void Nearby_Is_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col, int x, int y);
int First_tip(char board[re_row][re_col], char arr[re_row][re_col], int row, int col);
int Sweep_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col);
int Game_end(char arr[re_row][re_col], char board[re_row][re_col], int row, int col);

int Tag_mine(char arr[re_row][re_col]);

void Tag_Color(char arr[re_row][re_col], int  x, int  y);

#endif // __GAME_H__
