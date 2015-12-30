#include <stdio.h>

#define MAXLINE	1000

int mygetline(char s[], int lim);
void remove_trailing_space(char s[], int lim);

int main()
{
	int len;
	char line[MAXLINE];
	while ((len = mygetline(line, MAXLINE)) > 0) {
		remove_trailing_space(line, MAXLINE);
		printf("%s", line);
	}
	return 0;
}

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
	return i;
}

void remove_trailing_space(char s[], int lim)
{
	int i, last;

	last = -1;
	for (i = 0; i < lim - 1 && s[i] != '\n'; ++i) {
		if (s[i] != ' ' && s[i] != '\t')
			last = i;
	}

	if (last == -1)
		s[0] = '\0';
	else if (last < lim - 2) {
		s[last + 1] = '\n';
		s[last + 2] = '\0';
	}

}

