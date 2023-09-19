#include "shell.h"

/**
 *_eputs - Function prints an input string
 *
 * @str: The string to be printed
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Function writes the character c to stderr
 *
 * @c: The character to print
 *
 * Return: 1 if successful,
 * or 0 if error, -1 is returned
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Function writes the character c to given fd
 *
 * @c: The character
 * @fd: The file descriptor to write to
 *
 * Return: 1 if successful,
 * or 0 if error, -1 is returned
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Function prints an input string
 *
 * @str: The string
 * @fd: The file descriptor to write to
 *
 * Return: The number of chars printed
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

