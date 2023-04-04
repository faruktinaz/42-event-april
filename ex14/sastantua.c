#include <unistd.h>
#include <stdlib.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

void put_line(int spaces)
{
	for (int i = 0; i < spaces; ++i) {
		ft_putchar(' ');
	}
	return;
}


int calc_base(int param_1)
{
	int iVar1;
	int local_14;
	int local_10;
	int local_c;

	local_c = 1;
	local_10 = 1;
	local_14 = 4;
	while (local_c <= param_1) {
		iVar1 = local_c + 2;
		++local_c;
		local_10 = local_10 + iVar1 * 2 + local_14;
		if (((local_c & 1) != 0) && ((int)local_c < param_1)) {
			local_14 = local_14 + 2;
		}
	}
	return local_10 - local_14;
}

void put_blocks(int param_1,int param_2,int param_3,int param_4)
{
	int iVar1;
	int local_c;

	iVar1 = ((param_2 + -1) / 2) * 2 + 1;
	for (local_c = 0; local_c < param_3; ++local_c) {
		if (local_c == 0) {
			ft_putchar('/');
		}
		else if (local_c == param_3 + -1) {
			ft_putchar('\\');
		}
		else if ((((param_2 == param_1) && ((param_3 - iVar1) / 2 <= local_c)) &&
					(local_c < (iVar1 + param_3) / 2)) && ((param_2 + 2) - param_4 <= iVar1)) {
			if (((iVar1 < 5) || (param_4 != (param_2 - iVar1 / 2) + 1)) ||
				(local_c != (iVar1 + param_3) / 2 + -2)) {
			ft_putchar('|');
			}
			else {
			ft_putchar('$');
			}
		}
		else {
			ft_putchar('*');
		}
	}
}

void sastantua(int size)
{
	int iVar1;
	int width;
	int local_10;
	int local_c;

	if (size > 0) {
		width = 1;
		for (local_c = 1; local_c <= size; ++local_c) {
			for (local_10 = 0; local_10 < local_c + 2; ++local_10) {
				width += 2;
				iVar1 = calc_base(size);
				put_line((iVar1 - width) / 2);
				put_blocks(size,local_c,width,local_10);
				ft_putchar('\n');
			}
			width = width + ((local_c + -1) / 2 + 2) * 2;
		}
	}
}


int main(int argc, char **argv)
{
	if (argc == 2) {
		sastantua(atoi(argv[1]));
	}
	return 0;
}
