#include <stdio.h>
#include "mxcur_col.h"
#include "mxcur.h"

void pallet()
{
	for (int i = 0; i < 16; i++)
	{
		set_col_8bit(i, 1);
		if (i > 5)
			set_col_8bit(0, 0);
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 16; i < 232;)
	{
		set_col_8bit(0, 0);
		for (int j = 0; j < 36; j++)
		{
			if (i < 26 || (i > 51 &&
				i < 61) || (i > 88 &&
				i < 94))
				set_col_8bit(15, 0);
			else
				set_col_8bit(0, 0);
			set_col_8bit(i, 1);
			printf("%03d ", i++);
		}
		printf("\n");
	}
	set_col_8bit(15, 0);
	for (int i = 232; i < 256; i++)
	{
		set_col_8bit(i, 1);
		if (i == 242)
			set_col_8bit(0, 0);
		printf("%d ", i);
	}
	reset_col();
	printf("\n");
}
void cursor()
{
	clear_screen();
	printf("Move cursor up\n");
	printf("Move cursoe down\n");
	printf("             ");
	mov_cur_up(2);
	printf("s\n");
	mov_cur_forward(12);
	printf("left");
	mov_cur_backward(6);
	printf("r\n");
	mov_cur_xy(13, 1);
	printf("up, success\n");
	mov_cur_xy(13, 2);
	printf("down, left, right, success\n");
}

int main(int argc, char** argv)
{
	if (argc < 2)
		return -1;
	if (argv[1][0] == 'p')
		pallet();
	else if (argv[1][0] == 'c')
		cursor();
	else
		return -1;
	return 0;
}
