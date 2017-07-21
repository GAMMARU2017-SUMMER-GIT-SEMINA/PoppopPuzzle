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

			c = getch();
			if (c == 'w' && y > 1) y--;
			else if (c == 'a' && x > 1) x--;
			else if (c == 's' && y < HEIGHT) y++;
			else if (c == 'd' && x < WIDTH) x++;
			else if (c == ' ') {
				deleteBlock(x-1, y-1);
				//break;
			}
			UpdateMap();
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
	map[y][x].color = BLACK;
	if (y > 0 && y < HEIGHT)
	{

		if (thisColor == map[y - 1][x].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x, y - 1);
		}
		if (thisColor == map[y + 1][x].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x, y + 1);
		}
	}
	if (x > 0 && x < WIDTH)
	{
		if (thisColor == map[y][x - 1].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x - 1, y);
		}
		if (thisColor == map[y][x + 1].color)
		{
			map[y][x].shape = ' ';
			deleteBlock(x + 1, y);
		}

	}
}


void startFunc()
{

}

