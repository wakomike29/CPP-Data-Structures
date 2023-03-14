#include "min_heap.h"
/* Basic Functions */


//find the min value in an array, same as peek
int min_heap::heap_find_min(){
	return peek();
}

int min_heap::pop(){
	return heap_pop();
}

//remove and return min value from the heap,same as pop
int min_heap::extract_min(){return heap_pop();}

int min_heap::add(int new_value){return heap_add(new_value);};


//sift-down moves a node down a tree as long as needed
void min_heap::heapify_down(){
	int index = 0;
	int itr = 0; //DEBUGGING
	while(has_left_child(index)){
		//get valid smallest value
		int smaller_child_index = get_left_child_index(index);
		int rightIsSmaller = right_child(index) < left_child(index) ;//compare the values
		if( has_right_child(index) && rightIsSmaller){
			smaller_child_index = get_right_child_index(index);
			//printf("(%d&&%d) R",has_right_child(index),rightIsSmaller);
		}/*DEBUG else{
			//printf("(%d&&%d) L",has_right_child(index),rightIsSmaller);
		}*/
		
		//DEBUGGING
		//printf(" Smaller in itr:%d child:%d =>",itr, smaller_child_index);
		
		//if the value is smaller, break, else swap the value and continue.
		if(heap_array[index] < heap_array[smaller_child_index]){
			//printf("Break %d %d\n", heap_array[index] , heap_array[smaller_child_index]);
			break;
		} else {
			heap_swap(index, smaller_child_index);
			//printf("SWAP %d %d\n", index, smaller_child_index);
		}
		index = smaller_child_index;
		//DEBUGGING
		itr++;
	}
}

//sift-up moves a node up a tree as long as needed
void min_heap::heapify_up(){
	int index = heap_size -1;
	while(has_parent(index) && parent(index) > heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}

//sift-down moves a node down a tree as long as needed
void min_heap::heapify_down_index(int index){
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
void min_heap::heapify_up_index(int index){
	if( index > heap_size -1){
		
	}
	while(has_parent(index) && parent(index) > heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}

//delete an arbitray node, then sift to maintain heap
void min_heap::index_delete(int index){
	heap_array[index] = heap_array[heap_size-1];
	--heap_size;
	//now, to rebalance
	if( parent(index) > heap_array[index]){
		heapify_up_index(index);
	}else{
		heapify_down_index(index);
	}
}


