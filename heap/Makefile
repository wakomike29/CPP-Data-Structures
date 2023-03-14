.PHONEY: all
all: heap

heap : main.o min_heap.h
	@echo "--Linking-- $@"
	g++ -o heap main.o heap.o min_heap.o
	
min_heap.h: heap.o min_heap.o
	
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