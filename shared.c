#include "shared.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

Border create_border(char *pattern) {
	int pattern_size = strlen(pattern);
	Border result = malloc(pattern_size * sizeof(int));

	int suffix_size = 0;
	for (int i = 0; i < pattern_size; ++i) {
		if (i == 0) continue;

		if (pattern[i] != pattern[suffix_size]) suffix_size = 0;
		if (pattern[i] == pattern[suffix_size]) suffix_size += 1;

		result[i] = suffix_size;
	}

	return result;
}

Automata create_automata(char *pattern) {
	int pattern_size = strlen(pattern);
	Automata result = malloc(CHAR_SIZE * pattern_size * sizeof(int));
	Border border = create_border(pattern);

	for (int i = 0; i < pattern_size; ++i) {
		if (i == 0) {
			for (int j = 0; j < CHAR_SIZE; ++j) result[j] = 0;
			result[pattern[0]] = 1;
			continue;
		}

		memcpy(&result[i * CHAR_SIZE], &result[border[i - 1] * CHAR_SIZE], CHAR_SIZE * sizeof(int));
		result[i * CHAR_SIZE + pattern[i]] = i + 1;
	}

	// for (int i = 0; i < pattern_size; ++i) {
	// 	printf("%d: ", i);
	// 	for (int j = 0; j < CHAR_SIZE; ++j) {
	// 		int next = result[i * CHAR_SIZE + j];
	// 		if (next == 0) continue;
	// 		printf("(%c,%d) ", j, next);
	// 	}
	// 	printf("\n");
	// }

	free(border);
	return result;
}

char *read_file(char *path) {
	char *text = 0;
	long length;
	FILE *file = fopen(path, "rb");

	if (file) {
		fseek(file, 0, SEEK_END);
		length = ftell(file);
		fseek(file, 0, SEEK_SET);
		text = malloc(length);
		if (text) {
			fread(text, 1, length, file);
		}
		fclose(file);
	}

	if (text == NULL) {
		printf("Failed to read file\n");
		return 0;
	}

	return text;
}

char *pattern = "abacabadabacabaae";
char *text;
void setup() {
	text = read_file("tmp");
	long long idx = INT_MAX;
	memcpy(&text[idx - 100], pattern, strlen(pattern));
}
