#include "max_heap.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int test1(){

	int pop, e1, e2;

	max_heap h;
	
	h.add(30);
	h.add(40);
	h.add(50);
	h.add(100);
	h.add(10);
	h.add(15);
	h.add(40);
	
	
	
	printf("\n");
	h.heap_print_array_tree();
	
	printf("ensure: %d\n", e1 = h.heap_ensure_max());
	
	printf("\npop\n");
	h.pop();
	h.heap_print_array_tree();
	
	
	printf("\npop\n");
	h.pop();
	h.heap_print_array_tree();
	
	
	printf("ensure: %d\n",e2 = h.heap_ensure_max());

	if( e1 & e2 ){
		printf("\nTest1--PASS--\n");
	}else{
		printf("\nTest1--FAIL--\n");
	}
	
	return 0;


}





int test2(){


	max_heap h;
	
	static int size = 10; 
	int e1, e2;
	//int ary[13] = {3,6,4,9,12,13,18,14,15,8,7,11,9};
	int ary[10] = {35,33,42,10,14,19,27,44,26,31};
	
	
	for(int i =0; i<size ;i++){
		h.add(ary[i]);
	}
	
	
	printf("ensure: %d\n",e1 = h.heap_ensure_max());
	
	printf("\n");
	h.heap_print_array_tree();
	
	printf("size:%d-",h.size());
	printf("ensure: %d\n",e2 = h.heap_ensure_max());
	
		
	printf("\npop\n");
	h.pop();
	h.heap_print_array_tree();
	
	
	printf("\npop\n");
	h.pop();
	h.heap_print_array_tree();
	
	
	
	if( e1 & e2 ){
		printf("\nTest2--PASS--\n");
	}else{
		printf("\nTest2--FAIL--\n");
	}
	
	return 0;


}

///idea: have the program catch a sig fault, then automatically find the most memory it can hold before crashing


#include <signal.h>
   

int max = 0;

int t_max = 100; //smallest while getting a fault
int t_min = 50; // hightest while not getting a fault
/*
void clean_exit_on_sig(int sig_num)
{
        printf ("\n Signal %d received",sig_num);
        printf("    %d \n",max);
        exit(0);
}


static void keep_going_on_sig(int sig_num)
{
	//if less then 10, STOP
	if(t_max - t_min < 10 ){
		 printf ("less then 10",sig_num);
        printf("    %d \n", t_min);
        exit(0);
	}
	
	t_max = max;
	test3();
	
        printf ("\n Signal %d received",sig_num);
        printf("    %d \n",max);
        exit(0);
}*/

int test3(){
	
	 
	
	//max ive gotten to so far is 21468750
	//int t_max = 256409; //smallest while getting a fault
	//int t_min = 252830; // hightest while not getting a fault
	
	int t_d = (t_max - t_min)/2;	
	int t_a = t_min + t_d;
	//t_a = 114750; // override the number of items to add
	//sleep(5);
	
	max = 100;
	int i,j,ans;
	
	max_heap h;
	
	//signal(SIGSEGV, clean_exit_on_sig); 
	
	//creates heap with 0 to the max number
	for(i=0;i<max;i++){
		h.add(i);
	}
	
	printf("%d \n",max);
	printf("%d \n",i);
	printf("%d \n",h.size());
	
	printf("\nensure: %d\n",h.heap_ensure_max());
	
	
	j=max-1;
	//removes each number, expects to count up by one each time
	while(!h.is_empty()){
		ans = h.pop();
		if(j != ans){
			printf("nope %d %d",ans,j);
		}
		j--;
	}
	
	
	int k = j==-1;
	
	//printf("did I Win??: %d %d %d\n",k, h.is_empty(), j);
	
	//printf("%d == %d\n",i,j);
	
	if( k & h.is_empty() ){
		printf("\nTest3--PASS--\n");
	}else{
		printf("\nTest3--FAIL--\n");
	}
	
	
	t_min = max;
	return 1;
}






int test4(){
	max_heap h;
	

	srand(time(NULL));
	int r;
	
	int max = 10000;
	int i,j,ans;
	
	//fill heap with random numbers
	for(i=0;i<max;i++){
		h.add(rand());
	}
	
	//make sure heap is good
	printf("ensure: %d\n",h.heap_ensure_max());
	
	
	//take each item out, and count to make sure we remove the right numbers
	j=0;
	while(!h.is_empty()){
		ans = h.pop();
		j++;
	}
	int k = i==j;
	
	//see if we pass
	if( k & h.is_empty() & i==j ){
		printf("\nTest4--PASS--\n");
	}else{
		printf("\nTest4--FAIL--\n");
	}
	

	return 1;
}




















































