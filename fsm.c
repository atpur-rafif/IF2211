#include "shared.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
	PRERUN

	printf("fsm\n");
	int pattern_size = strlen(pattern);
	Automata automata = create_automata(pattern);

	int state = 0;
	int text_index = 0;
	int iteration = 0;
	while (text[text_index] != '\0') {
		unsigned char c = text[text_index];
		state = automata[state * CHAR_SIZE + c];
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
