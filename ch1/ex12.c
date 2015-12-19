#include <stdio.h>

#define IN	1	/* Inside a word */
#define OUT	0	/* Outside a word */

int main()
{
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			putchar(c);
		} else {
			putchar(c);
		}
	}
	return 0;
}
