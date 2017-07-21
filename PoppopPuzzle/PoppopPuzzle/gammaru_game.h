#ifndef GAMMARU_GAME_H_
#define GAMMARU_GAME_H_
#include <stdio.h>
#include <assert.h>

#ifdef __unix__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define BLACK       30
#define RED         31
#define GREEN       32
#define YELLOW      33
#define BLUE        34
#define PINK        35
#define LIGHT_BLUE  36
#define WHITE       37
#elif _WIN32

#include <conio.h>
#include <windows.h>

#define BLACK       0
#define RED         12
#define GREEN       10
#define YELLOW      14
#define BLUE        9
#define PINK        13
#define LIGHT_BLUE  11
#define WHITE       15

#endif


#ifdef __unix__
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}
#endif

void gotoxy(int x, int y) {
#ifdef _WIN32
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
#elif __unix__
	printf("\033[%d;%df", y, x);
	fflush(stdout);
#endif
}

void letter_color(int code) {
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	SetConsoleTextAttribute(hConsole, code);
	
#elif __unix__
	assert(BLACK <= code && code <= WHITE);
	printf("\x1b[%dm", code);
#endif
}
void color_clear() {
#ifdef _WIN32
	fprintf(stderr, "you can not use color_clear method in windows");
#elif __unix__
	printf("\x1b[0m");
#endif
}
#endif