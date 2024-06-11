#ifndef SHARED_H
#define SHARED_H

#define CHAR_SIZE 255
typedef int *Border;
typedef int *Automata;

#define PRERUN \
	setup();     \
	clock_t begin = clock();

#define POSTRUN                                               \
	clock_t end = clock();                                      \
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; \
	printf("Time taken %lfs\n\n", time_spent);

Automata create_automata(char *pattern);
Border create_border(char *pattern);
char *read_file(char *path);

extern char *text;
extern char *pattern;
void setup();

#endif
