#include <stdio.h>

#define MAXLINE	1000	/* maximum input line size */

int mygetline(char line[], int maxline);
void mycopy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			mycopy(longest, line);
		}
	if (max > 0) {
		printf("Max length: %d\n", max);
		printf("%s", longest);
	}
	return 0;
}

/* mygetline:	read a line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	if (c != EOF && c != '\n')
		while ((c = getchar()) != EOF && c != '\n')
			++i;
	return i;
}

/* mycopy:	copy 'from' into 'to'; assume to is big enough */
void mycopy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
