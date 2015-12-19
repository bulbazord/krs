#include <stdio.h>

/* I would test this by feeding the program nothing (EOF),
 * and other stupid or easy test cases and comparing it against
 * the output of wc.
 *
 * I would also feed it text containing no words, but no blanks either.
 * For example, the code would count "?!\\*&*" as a word, but humans would not.
 */

#define IN	1	/* Inside a word */
#define OUT	0	/* Outside a word */

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
