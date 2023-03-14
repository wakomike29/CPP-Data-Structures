.PHONEY: all
all: min_heap

min_heap : main.o min_heap.h
	@echo "--Linking--  $@  --MIN HEAP--"
	g++ -o min main.o heap.o  min_heap.o
	
max_heap : main.o max_heap.h
	@echo "--Linking--  $@  --MAX HEAP--"
	g++ -o max main.o heap.o max_heap.o
	
	
	
	
min_heap.h: min_heap.o heap.h

max_heap.h: heap.o max_heap.o heap.h

heap.h: heap.o
	
#main.o: main.cpp
#	g++ -c main.cpp
	
#heap_test.o : heap_test.cpp min_heap.o
#	g++ -c heap_test.cpp

#min_heap.o : min_heap.cpp min_heap_helper.cpp
#	g++ -c $<
	

# % substitution creates a generic rule
# compiles for all files with a normal argument
%.o: %.cpp
	@echo "--compiling-- $< -> $@"
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