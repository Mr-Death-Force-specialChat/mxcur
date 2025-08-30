#pragma once
#include <stdio.h>

void mov_cur_xy(int x, int y) // values start at 1, not 0
{
	printf("\033[%d;%dH", y, x);
}
void mov_cur_up(int n)
{
	printf("\033[%dA", n);
}
void mov_cur_down(int n)
{
	printf("\033[%dB", n);
}
void mov_cur_forward(int n)
{
	printf("\033[%dC", n);
}
void mov_cur_backward(int n)
{
	printf("\033[%dD", n);
}
void clear_screen()
{
	printf("\033[2J\033[H");
}
void save_cur_pos() // NOTE: Most terminal emulators do not support save/restore cursor position.
{
	printf("\033[s");
}
void restore_cur_pos()
{
	printf("\033[u");
}
