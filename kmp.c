#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	PRERUN

	printf("kmp\n");
	int pattern_size = strlen(pattern);
	Border border = create_border(pattern);

	int pattern_index = 0;
	int text_index = 0;
	long long iteration = 0;
	while (text[text_index] != '\0') {
		while (pattern_index > 0 && pattern[pattern_index] != text[text_index]) {
			pattern_index = border[pattern_index];
			iteration += 1;
		}

		if (pattern[pattern_index] == text[text_index]) {
			pattern_index++;
		}

		if (pattern_index == pattern_size) {
			printf("Found at %d\n", (text_index + 1) - pattern_size);
			printf("Iteration count %lld\n", iteration);
			break;
		}

		text_index++;
		iteration += 1;
	}

	POSTRUN
}
