all: trace

trace: LC4.o loader.o trace.c
	#
	# NOTE: CIS 240 students - this Makefile is broken, you must fix it before it will work!!
	# DONE
	clang -g LC4.o loader.o trace.c -o trace

LC4.o:
	#
	# CIS 240 TODO: update this target to produce LC4.o
	# DONE
	clang -g -c LC4.c -o LC4.o

loader.o:
	#
	# CIS 240 TODO: update this target to produce loader.o
	# DONE
	clang -g -c loader.c -o loader.o

clean:
	rm -rf *.o

clobber: clean
	rm -rf trace
