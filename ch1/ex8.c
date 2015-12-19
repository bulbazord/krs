#include <stdio.h>


int main()
{
	int c, bl, tb, nl;

	bl = tb = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++tb;
		if (c == ' ')
			++bl;
	}
	printf("Blanks: %d\n", bl);
	printf("Tabs: %d\n", tb);
	printf("Newlines: %d\n", nl);
	return 0;
}
