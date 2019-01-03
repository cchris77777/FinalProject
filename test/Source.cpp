#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
# include <time.h>
# pragma comment (lib, "Winmm.lib")
void drawMain();
void drawGame();
void drawGameH();
void keydown();
void keydownH();
void check();
void checkH();
void egg();
void mainKeydown();
void initMap();
void drawExplane();
void drawAbout();
void time();
void music();
int best[10] = { 101, 43, 90, 86, 48, 154, 201, 111, 98, 59 };
int map[10][10][10] =
{
	//0:空地  1:█牆壁  3:☆目的地  4:★箱子  5:※人  7:⊙箱子推到目的地  8:※人到目的 顯示人
  { { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
	{ 1, 1, 3, 1, 1, 4, 0, 1, 0, 0 },
	{ 1, 0, 3, 3, 4, 0, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 4, 0, 0, 1, 0, 0 },
	{ 1, 0, 0, 5, 0, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//2
  { { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 4, 4, 5, 1, 0, 0 },
	{ 1, 0, 0, 3, 0, 7, 3, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
	//3 90
  { { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 1, 1, 0, 5, 3, 0, 1, 1, 0, 0 },
	{ 1, 0, 4, 1, 0, 4, 0, 1, 0, 0 },
	{ 1, 0, 0, 3, 4, 3, 0, 1, 0, 0 },
	{ 1, 1, 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//4
  { { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },
	{ 0, 1, 3, 1, 0, 4, 0, 1, 0, 0 },
	{ 0, 1, 0, 0, 4, 1, 5, 1, 0, 0 },
	{ 0, 1, 0, 7, 3, 0, 0, 1, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//5 48
  { { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 4, 0, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 7, 0, 3, 0, 3, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 4, 0, 1, 0, 0 },
	{ 0, 1, 5, 0, 1, 1, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//6
   {{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 0, 0, 3, 3, 1, 0, 0, 1, 0 },
    { 1, 0, 1, 3, 3, 4, 0, 0, 1, 0 },
    { 1, 0, 0, 4, 0, 1, 0, 0, 1, 0 },
    { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 0, 4, 5, 4, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//7
  { { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 1, 5, 1, 0, 0, 1 },
	{ 0, 0, 1, 1, 1, 4, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 0, 0, 4, 4, 0, 1 },
	{ 1, 3, 0, 0, 0, 4, 0, 0, 1, 1 },
	{ 1, 3, 3, 0, 4, 1, 0, 0, 1, 0 },
	{ 1, 3, 1, 0, 0, 1, 1, 1, 1, 0 },
	{ 1, 3, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//8
  { { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
	{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 4, 3, 7, 3, 1, 0, 0, 0 },
	{ 1, 0, 1, 1, 0, 3, 1, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 3, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 4, 4, 0, 0, 0, 1 },
	{ 0, 0, 1, 4, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 1, 5, 1, 1, 1, 0, 0, 1 },
	{ 0, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
	//9
  { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 4, 3, 4, 3, 4, 3, 0, 1 },
	{ 1, 0, 3, 4, 3, 4, 3, 4, 0, 1 },
	{ 1, 0, 4, 3, 4, 8, 4, 3, 0, 1 },
	{ 1, 0, 3, 4, 3, 4, 3, 4, 0, 1 },
	{ 1, 0, 4, 3, 4, 3, 4, 3, 0, 1 },
	{ 1, 0, 3, 4, 3, 4, 3, 4, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
	//10
  { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 5, 0, 0, 3, 1 },
	{ 1, 0, 1, 0, 0, 1, 4, 3, 0, 1 },
	{ 1, 0, 0, 1, 0, 1, 3, 4, 0, 1 },
	{ 1, 0, 4, 0, 1, 3, 0, 4, 0, 1 },
	{ 1, 0, 4, 0, 3, 1, 0, 4, 0, 1 },
	{ 1, 0, 4, 3, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 3, 4, 1, 0, 0, 1, 0, 1 },
	{ 1, 3, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } }
};

int map1[10][10][10];
int quit = 0, end = 0;
int r = 0, r1 = 5, t = 0, k[500] = {0};
int main(void)
{
	for (int i = 0; i < 10; i++){ for (int j = 0; j < 10; j++){ for (int k = 0; k < 10; k++){ map1[i][j][k] = map[i][j][k]; } } }
	while (1){
		music();
		time();
		system("color b4");
		initMap();
		drawMain();
		mainKeydown();
		if (end == 1)break;
		//簡單遊戲
		if (quit == 1){
			music();
			system("cls");
			system("color 4f");
			t = 0, k[500] = {0};
			//遊戲中*******************
			while (1){
				time();
				if (r == 5){
					egg();
					break;
				}
				drawGame();
				keydown();
				check();
				if (quit == 0) break;
				system("cls");//清除原圖
			}
			//************************
		}
		//困難遊戲
		else if (quit == 2){
			music();
			system("cls");
			system("color 4f");
			t = 0, k[500] = { 0 };
			//遊戲中*******************
			while (1){
				time();
				if (r1 == 10){
					egg();
					break;
				}
				drawGameH();
				keydownH();
				checkH();
				if (quit == 0) break;
				system("cls");//清除原圖
			}
			//************************
		}

		system("cls");
	}
	printf("掰掰~~\n");
	system("pause");
	return 0;
}
//畫圖
void drawGame()
{
	printf("Easy mode  Stage %d\n\n", r + 1);
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			switch (map[r][i][j]){
			case 0:
				printf("  ");
				break;
			case 1:
				printf("█");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("★");
				break;
			case 5:
				printf("※");
				break;
			case 7:
				printf("⊙");
				break;
			case 8:
				printf("※");
				break;
			}
		}
		printf("\n");
	}
	printf("Best Step:%d\nCurrent Step :%d\n", best[r], t);
	printf("*Press R to reset stage\n");
	printf("*Press T to step back\n");
	printf("*Press Y to start from stage 1\n");
	printf("H\n");

}
void drawGameH()
{
	printf("Hard mode  Stage %d\n\n", r1-4);
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			switch (map[r1][i][j]){
			case 0:
				printf("  ");
				break;
			case 1:
				printf("█");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("★");
				break;
			case 5:
				printf("※");
				break;
			case 7:
				printf("⊙");
				break;
			case 8:
				printf("※");
				break;
			}
		}
		printf("\n");
	}
	printf("Best Step:%d\nCurrent Step :%d\n", best[r1], t);
	printf("*Press R to reset stage\n");
	printf("*Press T to step back\n");
	printf("*Press Y to start from stage 1\n");
	printf("H\n");

}
//按鍵處理
void keydown()
{
	int b = 0;
	int i, j;
	//確認當前玩家位置
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (map[r][i][j] == 5 || map[r][i][j] == 8)
				break;
		}
		if (map[r][i][j] == 5 || map[r][i][j] == 8)
			break;
	}
	char ch = _getch();
	switch (ch)
	{
		//上72 下80 左75 右77
		//0:空地  1:█牆壁  3:☆目的地  4:★箱子  5:※人  7:⊙箱子推到目的地  8:※人到目的 顯示人
	case 'W':
	case 'w':
	case 72:
		if (map[r][i - 1][j] == 0 || map[r][i - 1][j] == 3){//是否等於空地或目的地
			map[r][i][j] -= 5;//交換位置
			map[r][i - 1][j] += 5;
			t++;
			k[t] = 1;
		}
		else if (map[r][i - 1][j] == 4 || map[r][i - 1][j] == 7){//是否等於箱子或箱子在目的地
			if (map[r][i - 2][j] == 0 || map[r][i - 2][j] == 3){//箱子上是否等於空地或目的地
				map[r][i - 2][j] += 4;//箱子來
				map[r][i - 1][j] += 1;//箱子走-4 人來+5
				map[r][i][j] -= 5;
				t++;
				k[t] = 2;
			}
		}
		break;
	case 'S':
	case 's':
	case 80:
		if (map[r][i + 1][j] == 0 || map[r][i + 1][j] == 3){
			map[r][i][j] -= 5;
			map[r][i + 1][j] += 5;
			t++;
			k[t] = 3;
		}
		else if (map[r][i + 1][j] == 4 || map[r][i + 1][j] == 7){
			if (map[r][i + 2][j] == 0 || map[r][i + 2][j] == 3){
				map[r][i + 2][j] += 4;
				map[r][i + 1][j] += 1;
				map[r][i][j] -= 5;
				t++;
				k[t] = 4;
			}
		}
		break;
	case 'D':
	case 'd':
	case 77:
		if (map[r][i][j + 1] == 0 || map[r][i][j + 1] == 3){
			map[r][i][j] -= 5;
			map[r][i][j + 1] += 5;
			t++;
			k[t] = 5;
		}
		else if (map[r][i][j + 1] == 4 || map[r][i][j + 1] == 7){
			if (map[r][i][j + 2] == 0 || map[r][i][j + 2] == 3){
				map[r][i][j + 2] += 4;
				map[r][i][j + 1] += 1;
				map[r][i][j] -= 5;
				t++;
				k[t] = 6;
			}
		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map[r][i][j - 1] == 0 || map[r][i][j - 1] == 3){
			map[r][i][j] -= 5;
			map[r][i][j - 1] += 5;
			t++;
			k[t] = 7;
		}
		else if (map[r][i][j - 1] == 4 || map[r][i][j - 1] == 7){
			if (map[r][i][j - 2] == 0 || map[r][i][j - 2] == 3){
				map[r][i][j - 2] += 4;
				map[r][i][j - 1] += 1;
				map[r][i][j] -= 5;
				t++;
				k[t] = 8;
			}
		}
		break;
	case 'r':
	case 'R':
		for (int j = 0; j < 10; j++){ for (int k = 0; k < 10; k++){ map[r][j][k] = map1[r][j][k]; } }
		t = 0;
		break;
	case 'h':
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				if (map[r][j][k] == 3 && b == 0){
					map[r][j][k] = 0;
					b++;
				}
			}
		}
		break;
	//返回上一步 k為1~8值 分別代表八種狀況(各方向推到箱子或走到空地)
	case 't':
	case 'T':
		if (k[t] == 1){
			map[r][i][j] -= 5; 
			map[r][i + 1][j] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 2){
			map[r][i - 1][j] -= 4;
			map[r][i + 1][j] += 5;
			map[r][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 3){
			map[r][i][j] -= 5;
			map[r][i - 1][j] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 4){
			map[r][i + 1][j] -= 4;
			map[r][i - 1][j] += 5;
			map[r][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 5){
			map[r][i][j] -= 5;
			map[r][i][j - 1] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 6){
			map[r][i][j + 1] -= 4;
			map[r][i][j - 1] += 5;
			map[r][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 7){
			map[r][i][j] -= 5;
			map[r][i][j + 1] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 8){
			map[r][i][j + 1] += 5;
			map[r][i][j - 1] -= 4;
			map[r][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		break;
	case 'y':
	case 'Y':
		r = 0;
		initMap();
		t = 0;
		k[500] = { 0 };
		break;
	case 'q':
	case 'Q':
		quit = 0;
		break;
	}
	//設定上一個按鍵

}

void keydownH()
{
	int b = 0;
	int i, j;
	//確認當前玩家位置
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (map[r1][i][j] == 5 || map[r1][i][j] == 8)
				break;
		}
		if (map[r1][i][j] == 5 || map[r1][i][j] == 8)
			break;
	}
	char ch = _getch();
	switch (ch)
	{
		//上72 下80 左75 右77
		//0:空地  1:█牆壁  3:☆目的地  4:★箱子  5:※人  7:⊙箱子推到目的地  8:※人到目的 顯示人
	case 'W':
	case 'w':
	case 72:
		if (map[r1][i - 1][j] == 0 || map[r1][i - 1][j] == 3){//是否等於空地或目的地
			map[r1][i][j] -= 5;//交換位置
			map[r1][i - 1][j] += 5;
			t++;
			k[t] = 1;
		}
		else if (map[r1][i - 1][j] == 4 || map[r1][i - 1][j] == 7){//是否等於箱子或箱子在目的地
			if (map[r1][i - 2][j] == 0 || map[r1][i - 2][j] == 3){//箱子上是否等於空地或目的地
				map[r1][i - 2][j] += 4;//箱子來
				map[r1][i - 1][j] += 1;//箱子走-4 人來+5
				map[r1][i][j] -= 5;
				t++;
				k[t] = 2;
			}
		}
		break;
	case 'S':
	case 's':
	case 80:
		if (map[r1][i + 1][j] == 0 || map[r1][i + 1][j] == 3){
			map[r1][i][j] -= 5;
			map[r1][i + 1][j] += 5;
			t++;
			k[t] = 3;
		}
		else if (map[r1][i + 1][j] == 4 || map[r1][i + 1][j] == 7){
			if (map[r1][i + 2][j] == 0 || map[r1][i + 2][j] == 3){
				map[r1][i + 2][j] += 4;
				map[r1][i + 1][j] += 1;
				map[r1][i][j] -= 5;
				t++;
				k[t] = 4;
			}
		}
		break;
	case 'D':
	case 'd':
	case 77:
		if (map[r1][i][j + 1] == 0 || map[r1][i][j + 1] == 3){
			map[r1][i][j] -= 5;
			map[r1][i][j + 1] += 5;
			t++;
			k[t] = 5;
		}
		else if (map[r1][i][j + 1] == 4 || map[r1][i][j + 1] == 7){
			if (map[r1][i][j + 2] == 0 || map[r1][i][j + 2] == 3){
				map[r1][i][j + 2] += 4;
				map[r1][i][j + 1] += 1;
				map[r1][i][j] -= 5;
				t++;
				k[t] = 6;
			}
		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map[r1][i][j - 1] == 0 || map[r1][i][j - 1] == 3){
			map[r1][i][j] -= 5;
			map[r1][i][j - 1] += 5;
			t++;
			k[t] = 7;
		}
		else if (map[r1][i][j - 1] == 4 || map[r1][i][j - 1] == 7){
			if (map[r1][i][j - 2] == 0 || map[r1][i][j - 2] == 3){
				map[r1][i][j - 2] += 4;
				map[r1][i][j - 1] += 1;
				map[r1][i][j] -= 5;
				t++;
				k[t] = 8;
			}
		}
		break;
	case 'r':
	case 'R':
		for (int j = 0; j < 10; j++){ for (int k = 0; k < 10; k++){ map[r1][j][k] = map1[r1][j][k]; } }
		t = 0;
		break;
	case 'h':
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				if (map[r1][j][k] == 3 && b == 0){
					map[r1][j][k] = 0;
					b++;
				}
			}
		}
		break;
		//返回上一步 k為1~8值 分別代表八種狀況(各方向推到箱子或走到空地)
	case 't':
	case 'T':
		if (k[t] == 1){
			map[r1][i][j] -= 5;
			map[r1][i + 1][j] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 2){
			map[r1][i - 1][j] -= 4;
			map[r1][i + 1][j] += 5;
			map[r1][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 3){
			map[r1][i][j] -= 5;
			map[r1][i - 1][j] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 4){
			map[r1][i + 1][j] -= 4;
			map[r1][i - 1][j] += 5;
			map[r1][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 5){
			map[r1][i][j] -= 5;
			map[r1][i][j - 1] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 6){
			map[r1][i][j + 1] -= 4;
			map[r1][i][j - 1] += 5;
			map[r1][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 7){
			map[r1][i][j] -= 5;
			map[r1][i][j + 1] += 5;
			k[t] = 0;
			t--;
		}
		else if (k[t] == 8){
			map[r1][i][j + 1] += 5;
			map[r1][i][j - 1] -= 4;
			map[r1][i][j] -= 1;
			k[t] = 0;
			t--;
		}
		break;
	case 'y':
	case 'Y':
		r1 = 5;
		initMap();
		t = 0;
		k[500] = { 0 };
		break;
	case 'q':
	case 'Q':
		quit = 0;
		break;
	}
	//設定上一個按鍵

}

//勝利判斷
void check()
{
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (map[r][i][j] == 3)a++;
			if (map[r][i][j] == 8)c++;
		}
	}
	if (a == 0 && c == 0){
		r++;
		t = 0;
		k[10] = { 0 };
	}
}

void checkH()
{
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (map[r1][i][j] == 3)a++;
			if (map[r1][i][j] == 8)c++;
		}
	}
	if (a == 0 && c == 0){
		r1++;
		t = 0;
		k[10] = { 0 };
	}
}

void mainKeydown(){
	char mch = _getch();

	switch (mch){
	case 's':
	case 'S':
		quit = 1;
		break;
	case 'z':
	case 'Z':
		end = 1;
		break;
	case 'd':
	case 'D':
		quit = 2;
		break;
	case 'e':
	case 'E':
		drawExplane();
		break;
	case 'a':
	case 'A':
		drawAbout();
		break;

	}
}

void time()
{
	char * wday[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
	//長整數時間
	time_t t;
	struct tm *p;
	t = time(NULL);
	//獲取當前時間與日期
	p = gmtime(&t);
	printf("現在時間是：");
	printf("%d年%2d月%2d日", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %s ", wday[p->tm_wday]);
	printf("%02d:%02d:%02d\n\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);
}

void music()
{
	if (quit == 0)
	PlaySound(TEXT("C:\\ctest\\test\\doublebass.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else 
		PlaySound(TEXT("C:\\ctest\\test\\move.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void drawMain(){
	printf("███████████████\n");
	printf("█     經典糞game--推箱子   █\n█                          █\n");
	printf("█     開始簡單遊戲(s)      █\n");
	printf("█     開始困難遊戲(d)      █\n");
	printf("█         說明(e)          █\n");
	printf("█         關於(a)          █\n");
	printf("█       結束遊戲(z)        █\n█                          █\n█                          █\n█                          █\n█     作者:北科余文樂<3    █\n");
	printf("███████████████\n");
}

void initMap(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				map[i][j][k] = map1[i][j][k];
			}
		}
	}
}

void drawExplane(){
	system("color 4f");
	system("cls");//清除原圖
	time();
	printf("███████████████\n");
	printf("█ 經典的推箱子是一個來自日 █\n█ 本的古老游戲，目的是在訓 █\n");
	printf("█ 練你的邏輯思考能力。在一 █\n");
	printf("█ 個狹小的倉庫中，要求把木 █\n");
	printf("█ 箱放在指定的位置，稍不小 █\n");
	printf("█ 心就會卡住，所以需要巧妙 █\n");
	printf("█ 的利用有限的空間和通道， █\n█ 合理的安排移動的次序和位 █\n█ 置，才能順利的完成任務。 █\n█                          █\n█                          █\n");
	printf("███████████████\n");
	_getch();
	system("cls");//清除原圖
}

void drawAbout(){
	system("color 4f");
	system("cls");//清除原圖
	PlaySound(TEXT("C:\\ctest\\test\\thanku.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	time();
	printf("███████████████\n");
	printf("█ 107年度 上學期 期末專題  █\n█ 首先，能完成這次的專題， █\n");
	printf("█ 我想要先謝謝我的程式老師 █\n");
	printf("█ 黃士嘉教授先生，經過了他 █\n");
	printf("█ 一個學習的細心教導之後， █\n");
	printf("█ 原本連printf都有障礙的我 █\n");
	printf("█ 也可以獨力完成一個程式。 █\n█ 再來也要感謝熱心的助教們 █\n█ 總是盡心盡力替大家解答問 █\n█ 題，能擁有這堂程式課，是 █\n█ 是我萬分的榮幸，也希望未 █\n█ 來還可以繼續學習。       █\n█ Luv n peace <3           █\n");
	printf("███████████████\n");
	_getch();
	system("cls");//清除原圖
}

void egg(){
	r = 0;
	r1 = 5;
	quit = 0;
	printf("＿人人人人人人人人＿\n＞　　吃我GG? 　＜\n￣^Y^Y^Y^Y^Y^Y^Y￣\n／ ?  　　　(((?     \n(　 ?　　　　 ￣Ｙ＼\n|　(＼　(\      /)   ｜    )\n?　?` ( ??? ) _?    /\n　＼ |　?Ｙ?　/  /\n　 ｜?　 ｜　 ? ／\n　  ＼卜一全一?\n　　 ｜ 三土三/\n   ) \      °   /  \n      (     \ /  \n      /    / ?ΞΞΞΞΞΞD \n   /  /     /   \ \   \ \n   ( (    ).     ) ).  )\n   (      ).      ( |    | \n    |    /      \    |\n    nn.  ).        (  .nn\n");
	_getch();
}