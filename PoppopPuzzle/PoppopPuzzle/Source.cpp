#include"gammaru_game.h"


struct block
{
	int color;
	char shape;
};

block map[HEIGHT][WIDTH] = {};
int colorSet[] = { RED, BLUE, GREEN, LIGHT_BLUE, PINK, YELLOW, WHITE };
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
			map[i][j].color = colorSet[rand() % 6];
			map[i][j].shape = 'O';
		}
	}
}
void startInput() {
	int count = 0;
	int x = 1, y = 1;
	while (1) {
		int c = kbhit();
		if (c != 0) {
			gotoxy(x, y);
			printf(" ");
			UpdateMap();
			c = getch();
			if (c == 'w') {
				y--;
			}
			else if (c == 'a') x--;
			else if (c == 's') y++;
			else if (c == 'd') x++;
			else if (c == ' ') {
				deleteBlock(x, y);
				//break;
			}
			gotoxy(x, y);
			printf("_");

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

void deleteBlock(int x, int y)
{
	int thisColor = map[y][x].color;
	if (y > 0 && y < HEIGHT)
	{

		if (thisColor == map[y - 1][x].color)
		{
			map[y][x].shape = ' ';
			map[y][x].color = BLACK;
			deleteBlock(x, y - 1);
		}
		if (thisColor == map[y + 1][x].color)
		{
			map[y][x].shape = ' ';
			map[y][x].color = BLACK;
			deleteBlock(x, y + 1);
		}
	}
	if (x > 0 && x < WIDTH)
	{
		if (thisColor == map[y][x - 1].color)
		{
			map[y][x].shape = ' ';
			map[y][x].color = BLACK;
			deleteBlock(x - 1, y);
		}
		if (thisColor == map[y][x + 1].color)
		{
			map[y][x].shape = ' ';
			map[y][x].color = BLACK;
			deleteBlock(x + 1, y);
		}
	}


}


void startFunc()
{

}

