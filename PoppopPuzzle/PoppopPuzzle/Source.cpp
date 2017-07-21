#include"gammaru_game.h"


struct block
{
	int color;
	char shape;
};

block map[HEIGHT][WIDTH] = {};
int colorSet[] = {LIGHT_BLUE, PINK, YELLOW};
int main()
{
	initialize();
	startInput();
}

void initialize()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			map[i][j].color = colorSet[rand() % 3];
			map[i][j].shape = 'O';
		}
	}
	UpdateMap();
}
void startInput() {
	int count = 0;
	int x = 0, y = 0;
	gotoxy(x, y);
	while (1) {
		int c = kbhit();
		if (c != 0) {
			gotoxy(x, y);
			printf(" ");

			c = getch();
			if (c == 'w' && y > 1) y--;
			else if (c == 'a' && x > 1) x--;
			else if (c == 's' && y < HEIGHT) y++;
			else if (c == 'd' && x < WIDTH) x++;
			else if (c == ' ') {
				deleteBlock(x-1, y-1, 0);
				//break;
			}
			UpdateMap();
			letter_color(map[y - 1][x - 1].color);
			gotoxy(x, y);
			printf("+");

		}
	}
	printf("space!");
	letter_color(RED);
	printf("hello world\n");
}
void UpdateMap()
{
	gotoxy(1, 1);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			letter_color(map[i][j].color);
			printf("%c", map[i][j].shape);
		}
		printf("\n");
	}
}

void deleteBlock(int x, int y, int startNum)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
	int thisColor = map[y][x].color;
	int sideBlockNum = 0;

	if (thisColor == BLACK) return;
	map[y][x].color = BLACK;
	if (y >= 0 && y < HEIGHT)
	{

		if (thisColor == map[y - 1][x].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x, y - 1,startNum + 1);
			sideBlockNum++;
		}
		if (thisColor == map[y + 1][x].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x, y + 1, startNum + 1);
			sideBlockNum++;
		}
	}
	if (x >= 0 && x < WIDTH)
	{
		if (thisColor == map[y][x - 1].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x - 1, y, startNum + 1);
			sideBlockNum++;
		}
		if (thisColor == map[y][x + 1].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x + 1, y, startNum + 1);
			sideBlockNum++;
		}

	}
	if (startNum == 0 && sideBlockNum == 0) map[y][x].color = thisColor;
}

