#pragma once
#include <stdio.h>

#define MXCUR_GRP_RESET "0"
#define MXCUR_GRP_BOLD "1"
#define MXCUR_GRP_FAINT "2" // opposite of bold
#define MXCUR_GRP_ITALIC "3"
#define MXCUR_GRP_UNDERLINE "4"
#define MXCUR_GRP_FONT_DEFAULT "10"
#define MXCUR_GRP_FONT_ALT1 "11"
#define MXCUR_GRP_FONT_ALT2 "12"
#define MXCUR_GRP_FONT_ALT3 "13"
#define MXCUR_GRP_FONT_ALT4 "14"
#define MXCUR_GRP_FONT_ALT5 "15"
#define MXCUR_GRP_FONT_ALT6 "16"
#define MXCUR_GRP_FONT_ALT7 "17"
#define MXCUR_GRP_FONT_ALT8 "18"
#define MXCUR_GRP_FONT_ALT9 "19"
#define MXCUR_GRP_COL_BLACK "30"
#define MXCUR_GRP_COL_RED "31"
#define MXCUR_GRP_COL_GREEN "32"
#define MXCUR_GRP_COL_YELLOW "33"
#define MXCUR_GRP_COL_BLUE "34"
#define MXCUR_GRP_COL_MAGENTA "35"
#define MXCUR_GRP_COL_CYAN "36"
#define MXCUR_GRP_COL_WHITE "37"
#define MXCUR_GRP_COL_BRIGHT_BLACK "90"
#define MXCUR_GRP_COL_BRIGHT_RED "91"
#define MXCUR_GRP_COL_BRIGHT_GREEN "92"
#define MXCUR_GRP_COL_BRIGHT_YELLOW "93"
#define MXCUR_GRP_COL_BRIGHT_BLUE "94"
#define MXCUR_GRP_COL_BRIGHT_MAGENTA "95"
#define MXCUR_GRP_COL_BRIGHT_CYAN "96"
#define MXCUR_GRP_COL_BRIGHT_WHITE "97"

void reset_col()
{
	printf("\033[0m");
}
void set_col_rgb(int red, int green, int blue, int is_background)
{
	printf("\033[%d8;2;%d;%d;%dm", 3 + is_background, red, green, blue);
}
void set_col_8bit(int color, int is_background)
{
	printf("\033[%d8;5;%dm", 3 + is_background, color);
}
void set_col_4bit(int color, int is_background)
{
	printf("\033[%dm", color + (is_background ? 10 : 0));
}
void set_col_4bit_dual(int foreground, int background)
{
	printf("\033[%d;%dm", foreground, background + 10);
}
