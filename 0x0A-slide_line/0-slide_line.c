#include "slide_line.h"


/**
 * slide_left - slides the array to the left
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	size_t i, tmp, position = 0;

	for (i = 0; i < size && position; i++)
	{
		while (line[position] == 0 && (position < size) && (position + 1 < size))
			position++;

		if (!line[i])
		{
			tmp = line[position];
			line[position] = line[i];
			line[i] = tmp;
		}
		position++;
	}
}

/**
 * slide_right - slides the array to the right
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	size_t i, tmp, position;

	position = size - 1;

	for (i = size - 1; (int)i >= 0 && (int)position >= 0; i--)
	{
		while (line[position] == 0 && position > 0)
			position--;

		if (!line[i])
		{
			tmp = line[position];
			line[position] = line[i];
			line[i] = tmp;
		}
		position--;
	}
}

/**
 * slide_line - reproduce the 2048 game in one line
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);

		for (i = size - 1; (int)i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}
