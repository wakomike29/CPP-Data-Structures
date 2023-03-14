#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"


/* init constructors */
heap::heap(){
	heap_array = new int[capacity];
	capacity = 100;
	initialized = 0;
	heap_size = 0;
	initialized = 1;
}

heap::~heap(){
	free(heap_array);
	heap_array=NULL;
	initialized = 0;
	heap_size = 0;
}


/* Basic */
int heap::heap_add(int item){
	heap_ensure_capacity();
	heap_array[heap_size] = item;
	++heap_size;
	heapify_up();
	return 1;
}


int heap::peek(){
	if(heap_size == 0){
		//errno = -1;
		return -1;
	}
	return heap_array[0];
}


//add a new key to the heap, same as add
int heap::insert(int new_value){return heap_add(new_value);}


//remove and return min value from the heap,same as pop
int heap::extract_min(){return heap_pop();}

//remove the root node, no need to return anything
int heap::heap_delete_min(){
	heap_pop();
	return 1;
}

int heap::heap_pop(){
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




/* Creation */

//creates a heap from a given array
int heap::create_heap(){return 1;}

//creates a heap from a given array
int heap::heap_heapify(){return 1;}

//union of two heaps
int heap::heap_merge(){return 1;}

//creates a new heap from two old heaps, destroys both original heaps
int heap::heap_meld(){return 1;}


/* Inspection */

int heap::size(){return heap_size;}

int heap::is_empty(){return heap_size == 0;}



//delete an arbitray node, then sift to maintain heap
void heap::index_delete(int index){
	heap_array[index] = heap_array[heap_size-1];
	--heap_size;
	//now, to rebalance
	if( parent(index) > heap_array[index]){
		heapify_up_index(index);
	}else{
		heapify_down_index(index);
	}
}

///////Debug and testing stuff below here
/* internal */

//increase or decrease key????

/*/increase-key or decrease-key: updating a key within a max- or min-heap, respectively
void heap_decrease_key(int key){

	heap_array[index] = heap_array[heap_size-1];
	--heap_size;
	//now, to rebalance
	heapify_up(index);
}*/


//sift-down moves a node down a tree as long as needed
void heap::heapify_down(){
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
void heap::heapify_up(){
	int index = heap_size -1;
	while(has_parent(index) && parent(index) > heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}

//sift-down moves a node down a tree as long as needed
void heap::heapify_down_index(int index){
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
void heap::heapify_up_index(int index){
	if( index > heap_size -1){
		
	}
	while(has_parent(index) && parent(index) > heap_array[index]){
		heap_swap(get_parent_index(index), index);
		index = get_parent_index(index);
	}
	
}





/*helper functions */

int heap::get_left_child_index(int parent_index){
	return parent_index*2+1;
}
int heap::get_right_child_index(int parent_index){
	return parent_index*2+2;
}
int heap::get_parent_index(int child_index){
	return (child_index -1) / 2;
}

int heap::has_left_child(int index){
	return get_left_child_index(index) < heap_size;
}
int heap::has_right_child(int index){
	return get_right_child_index(index) < heap_size;
}
int heap::has_parent(int index){
	return get_parent_index(index -1) >= 0;
}

int heap::left_child(int index){
	return heap_array[get_left_child_index(index)];
}
int heap::right_child(int index){
	return heap_array[get_right_child_index(index)];
}
int heap::parent(int index){
	return heap_array[get_parent_index(index)];
}

/* more helpful functions */
void heap::heap_swap(int index_one, int index_two){
	int temp = heap_array[index_one];
	heap_array[index_one] = heap_array[index_two];;
	heap_array[index_two] = temp;
}


//make this  better!!!!
void heap::heap_ensure_capacity(){
	/*if(size == capacity){
		items = Arrays.copyOf(items, capacity*2);//this will need to be made better
		capaity = capacity *2
	}*/
	//printf("NOT MADE< CURR CAP=%d\n",capacity);
}

/* DEBUG */
//print out the array
void heap::heap_print_array(){
	for(int i=0;i<heap_size; i++){
		printf(" %d \n",heap_array[i]);
	}
}

void heap::heap_print_array_tree(){
	int itr=0,power2=1, i;
	for(i=0;i<heap_size;i++ ){
		itr++;
		printf("%d ",heap_array[i]);
		if(itr >= power2 || i==0){
			// DEBUG printf(" - %d %d %d\n",itr,power2, i);
			printf("\n");
			power2 = power2*2;
			itr=0;
		}
		
		
		
	}
	// DEBUG printf(" - %d %d \n",itr,i);
	printf("\n");
}








//DEBUG
//test to make sure all the array is good
//parent must be larger then child in a min heap
//returns 1 if valid
//will output indexes of the incorrect values
int heap::heap_ensure(){
	int ok = 1;
	for(int i=0;i<heap_size;i++){
		int hlc = has_left_child(i);
		int hrc = has_right_child(i);
		int isValid;
		if(hlc){
			isValid = left_child(i) > heap_array[i];
			if(!isValid){
				ok=0;
				printf("\n e@%d - %d > %d ",i, left_child(i), heap_array[i]);
			}
		}
		if(hrc){
			isValid = right_child(i) > heap_array[i];
			if(!isValid){
				ok=0;
				printf("\n e@%d - %d > %d ",i, right_child(i), heap_array[i]);
			}
		}
	}
	return ok;

}













