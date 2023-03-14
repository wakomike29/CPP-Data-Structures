#include "max_heap.h"
/* Basic Functions */


//find the min value in an array, same as peek
int max_heap::heap_find_max(){
	return peek();
}

int max_heap::pop(){
	if(heap_size == 0){
		//errno = -1;
		return -1;
	}
	int ans = heap_array[0];
	heap_array[0] = heap_array[heap_size-1];
	--heap_size;
	
	//DEBUG
	/*printf("\n-----\n");
	heap_print_array();
	printf("-----\n");*/
	
	heapify_down();
	
	return ans;
}


//remove and return min value from the heap,same as pop
int max_heap::extract_max(){return heap_pop();}

int max_heap::add(int item){
	heap_ensure_capacity();
	heap_array[heap_size] = item;
	++heap_size;
	heapify_up();
	return 1;
}


//sift-down moves a node down a tree as long as needed
void max_heap::heapify_down(){
	int index = 0;
	//int itr = 0; //DEBUGGING
	while(has_left_child(index)){
	
		//get valid Biggest value, 
		int larger_child_index = get_left_child_index(index);
		int rightIsBigger = right_child(index) > left_child(index) ;//compare the values
		if( has_right_child(index) && rightIsBigger){
			larger_child_index = get_right_child_index(index);
			//printf("(%d&&%d) R",has_right_child(index),rightIsSmaller);
		}/*DEBUG else{
			//printf("(%d&&%d) L",has_right_child(index),rightIsSmaller);
		}*/
		
		//DEBUGGING
		//printf(" Smaller in itr:%d child:%d =>",itr, smaller_child_index);
		
		
		//if the value is larger, break, else swap the value and continue.
		if(heap_array[index] > heap_array[larger_child_index]){
			//printf("Break %d %d\n", heap_array[index] , heap_array[smaller_child_index]);
			break;
		} else {
			heap_swap(index, larger_child_index);
			//printf("SWAP %d %d\n", index, smaller_child_index);
		}
		index = larger_child_index;
		//DEBUGGING
		//itr++;
	}
}


//sift-up moves a node up a tree as long as needed
void max_heap::heapify_up(){
	int index = heap_size -1;
	while(has_parent(index) && parent(index) < heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}

//sift-down moves a node down a tree as long as needed
void max_heap::heapify_down_index(int index){
	while(has_left_child(index)){
		int smaller_child_index = get_left_child_index(index);
		if( has_right_child(index) && right_child(index) < left_child(index) ){ //this line is sus, it looks like im comparing the values, not the indexes?
			smaller_child_index = get_right_child_index(index);
		}
		
		if(heap_array[index] < heap_array[smaller_child_index]){
			break;
		} else {
			heap_swap(index, smaller_child_index);
		}
		index = smaller_child_index;
	}
}

//sift-up moves a node up a tree as long as needed
void max_heap::heapify_up_index(int index){
	if( index > heap_size -1){
		
	}
	while(has_parent(index) && parent(index) < heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}


//remove the root node, no need to return anything
int max_heap::delete_max(){
	heap_pop();
	return 1;
}