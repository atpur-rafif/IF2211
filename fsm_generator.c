#include "shared.h"
#include <stdio.h>
#include <string.h>

int main() {
	int pattern_size = strlen(pattern);

	printf("/*");
	Automata automata = create_automata(pattern);
	printf("*/");
	printf("#define transition(state,input) switch(state){");
	for (int state = 0; state < pattern_size; ++state) {
		printf("case(%d):{switch(input){", state);
		for (int c = 0; c < CHAR_SIZE; ++c) {
			int next = automata[state * CHAR_SIZE + c];
			if (next != 0) printf("case(%d):state=%d;break;", c, next);
		}
		printf("default:state=0;break;}};break;");
	}
	printf("}");
}
