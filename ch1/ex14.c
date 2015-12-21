#include <stdio.h>

#define NUM_CHARS	26

int main()
{
	int c, i, j;
	int characters[NUM_CHARS];
	int max;

	for (i = 0; i < NUM_CHARS; ++i)
		characters[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			++characters[c - 'a'];
		else if (c >= 'A' && c <= 'Z')
			++characters[c - 'A'];
	}

	max = characters[0];
	for (i = 0; i < NUM_CHARS; ++i)
		if (characters[i] > max)
			max = characters[i];

	for (i = max; 0 < i; --i) {
		printf("%d |", i);
		for (j = 0; j < NUM_CHARS; ++j) {
			if (characters[j] == i) {
				printf(" #");
				--characters[j];
			} else
				printf("  ");
		}
		printf("\n");
	}

	printf("  ");
	for (i = 0; i < (2 * (NUM_CHARS + 1)); ++i)
		printf("-");
	printf("\n");
	printf("   ");
	for (i = 0; i < NUM_CHARS; ++i)
		printf(" %c", (i + 'a'));
	printf("\n");
	return 0;
}

