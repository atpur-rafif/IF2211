#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *file = fopen("tmp", "w");

	int count = INT_MAX;

	srand(time(NULL));
	for (long long i = 0; i < count; ++i) {
		char c = (rand() % (255 - 1)) + 1;
		fputc(c, file);

		if (i % (100 * 1000 * 1000) == 0) {
			printf("Progress: %f%%\n", i / (float)count);
			fflush(stdout);
		}
	}
}
