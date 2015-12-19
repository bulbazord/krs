#include <stdio.h>

#define OUT 0	/* Outisde of a word */
#define IN 1	/* Inside of a word */

int main()
{
	int c, status;
	status = IN;
	while ((c = getchar()) != EOF) {
		if (status == IN) {
			if (c == ' ')
				status = OUT;
			putchar(c);
		}
		if (status == OUT) {
			if (c != ' ') {
				status = IN;
				putchar(c);
			}
		}
	}
	return 0;
}
