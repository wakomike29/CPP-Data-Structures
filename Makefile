.PHONEY: all
all: test

test : test.o baseClasses.h
	@echo "   --Linking--  $@  --TEST FILE EXE--"
	g++ -o test test.o item.o

	
baseClasses.h: item.o


# % substitution creates a generic rule
# compiles for all files with a normal argument
%.o: %.cpp
	@echo "   --compiling-- $< -> $@"
	g++ -c $< -o $@

#heap_test.o : heap_test.c 
#	gcc -o $@ -c $<
#
#heap_helper.o : min_heap_helper.c
#	gcc -o $@ -c $<

.PHONEY: clean
clean:
	rm *.o
	clear
	
	
# make -j(#) allows parallel compiling
# replace (#) with the max processors you wish to use 


#Anthony Writes Code Make File Basics (Beginner - intermediate) Anthony Explains #357