#include "holberton.h"

/**
 * sigintHandler - signal hanlder
 * @sig_num: signal handler
 * Return: On success 1.
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
