#include <stdio.h>

#define IN	1	/* Inside a word */
#define OUT	0	/* Outside a word */

/* We will measure words that are from length 1 to 10+.
 * That is, the last slot will represent words that are length 10 or more. */
#define MAX_LENGTH 10

int main()
{
	int c, i, j, curlen, state;
	int lengths[MAX_LENGTH];
	int max;

	curlen = 0;
	state = OUT;
	for (i = 0; i < MAX_LENGTH; ++i)
		lengths[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (curlen > 0) {
				if (curlen > 10)
					++lengths[MAX_LENGTH - 1];
				else
					++lengths[curlen - 1];
			}
			state = OUT;
			curlen = 0;
		} else if (state == OUT) {
			state = IN;
			curlen = 1;
		} else {
			++curlen;
		}
	}

	max = lengths[0];
	for (i = 0; i < MAX_LENGTH; ++i)
		if (lengths[i] > max)
			max = lengths[i];

	for (i = max; 0 < i; --i) {
		printf("%d |", i);
		for (j = 0; j < MAX_LENGTH; ++j) {
			if (lengths[j] == i) {
				printf(" #");
				--lengths[j];
			} else
				printf("  ");
		}
		printf("\n");
	}

	printf("  ");
	for (i = 0; i < (2 * (MAX_LENGTH + 1)); ++i)
		printf("-");
	printf("\n");
	printf("   ");
	for (i = 0; i < MAX_LENGTH; ++i)
		printf(" %d", (i + 1));
	printf("+\n");
	return 0;
}

