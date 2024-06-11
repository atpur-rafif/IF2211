FLAG=-O3

run: kmp fsm fsm_compile combined
	@echo ""

combined:
	@gcc $(FLAG) fsm_generator.c shared.c
	@./a.out > automata.h
	@gcc $(FLAG) combined.c shared.c
	@./a.out

kmp:
	@gcc $(FLAG) kmp.c shared.c
	@./a.out

fsm:
	@gcc $(FLAG) fsm.c shared.c
	@./a.out

fsm_compile:
	@gcc $(FLAG) fsm_generator.c shared.c
	@./a.out > automata.h
	@gcc $(FLAG) fsm_compile.c shared.c
	@./a.out

generate_random:
	@gcc $(FLAG) generate_random.c
	@./a.out
