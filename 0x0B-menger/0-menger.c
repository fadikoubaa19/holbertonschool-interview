#include "menger.h"

/**
 * menger - afichage 2D
 * @level: int
 *
 * Return: /0(mean true)
*/

void menger(int level)
{
	int h, w, size, height, width;
	char ch;

	h = 0;
	w = 0;
	if (level < 0)
	{
		return;
	}
	else if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level > 0)
	{
	size = pow(3, level);
	}

	while (h < size)
	{
		w = 0;
		while (w < size)
		{
			width = w;
			height = h;
			ch = '#';
			while (height > 0)
			{
				if (height % 3 == 1 && width % 3 == 1)
					ch = ' ';
				height = height / 3;
				width = width / 3;
			}
			printf("%c", ch);
			w++;
		}
		printf("\n");
		h++;
	}
}
