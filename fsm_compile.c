#include "automata.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	PRERUN

	printf("fsm_compile\n");

	int pattern_size = strlen(pattern);
	int state = 0;
	int text_index = 0;
	int iteration = 0;
	while (text[text_index] != '\0') {
		unsigned char c = text[text_index];
		transition(state, c);
		if (state == pattern_size) {
			printf("Found at %d\n", (text_index + 1) - pattern_size);
			printf("Iteration count %d\n", iteration);
			break;
		}
		text_index += 1;
		iteration += 1;
	}

	POSTRUN
}
