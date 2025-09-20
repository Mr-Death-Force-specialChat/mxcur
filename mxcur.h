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
void clear_screen() // returns to home position
{
	printf("\033[2J\033[H");
}
void erase_eos() // from cursor to end of screen
{
	printf("\033[0J");
}
void erase_bos() // from cursor to beginning of screen
{
	printf("\033[1J");
}
void clear_line()
{
	printf("\033[2K");
}
void erase_eol() // from cursor to end of line
{
	printf("\033[0K");
}
void erase_bol() // from cursor to beginning of line
{
	printf("\033[1K");
}
void alternate_buffer(int enable)
{
	printf("\033[?1049%c", enable ? 'h' : 'l');
}
void save_cur_pos() // NOTE: Most terminal emulators do not support save/restore cursor position.
{
	printf("\033[s");
}
void restore_cur_pos()
{
	printf("\033[u");
}
