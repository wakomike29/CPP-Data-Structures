// see main.c for more instructions
#pragma once

class heap {

protected:
int* heap_array;
int heap_size, capacity , initialized;


/* init constructors */
public: 
heap();
~heap();


/* Basic */
int heap_add(int item);
int peek();
int insert(int new_value);

int heap_pop();

/* Creation */
int create_heap();
int heap_heapify();
int heap_merge();
int heap_meld();

/* Inspection */
int size();
int is_empty();
void index_delete(int index);

/* Helper Functions*/
int get_left_child_index(int parent_index);
int get_right_child_index(int parent_index);
int get_parent_index(int child_index);
int has_left_child(int index);
int has_right_child(int index);
int has_parent(int index);
int left_child(int index);
int right_child(int index);
int parent(int index);
void heap_swap(int index_one, int index_two);
void heap_ensure_capacity();

/* Debug functions */
public:
void heap_print_array();
void heap_print_array_tree();
int heap_ensure();

/* must move */
	/* Helper Function */
	protected:
	void heapify_down();
	void heapify_up();
	void heapify_down_index(int index);
	void heapify_up_index(int index);
	int extract_min();
	int heap_delete_min();


};

class min_heap : public heap {

	public:
	//Basic
	// inher int peek();// find_min(); // find a maximum item of a max-heap, or a minimum item of a min-heap, respectively (a.k.a. peek)
	int insert(int new_value); // adding a new key to the heap (a.k.a., push[4])
	int extract_min(); // returns the node of maximum value from a max heap [or minimum value from a min heap] after removing it from the heap (a.k.a., pop[5])
	int delete_min(); //removing the root node of a max heap (or min heap), respectively
	//int extern_replace(int new_value);//extern replace: pop root and push a new key. More efficient than pop followed by push, since only need to balance once, not twice, and appropriate for fixed-size heaps.[6]
	int add(int new_value);
	
	
	//Creation
	int create_heap(); // create an empty heap
	int heapify(); // create a heap out of given array of elements
	int merge(); // or union joining two heaps to form a valid new heap containing all the elements of both, preserving the original heaps.
	int meld(); // joining two heaps to form a valid new heap containing all the elements of both, destroying the original heaps.

	//Inspection
	// inher int size(); // return the number of items in the heap.
	// inher int is_empty(); //return true if the heap is empty, false otherwise.

	//Internal
	protected:
	//  not imp  //increase-key or decrease-key: updating a key within a max- or min-heap, respectively
	int heap_delete(); //: delete an arbitrary node (followed by moving last node and sifting to maintain heap)
	void heapify_up(); //sift-up: move a node up in the tree, as long as needed; used to restore heap condition after insertion. Called "sift" because node moves up the tree until it reaches the correct level, as in a sieve.
	void heapify_down(); //sift-down: move a node down in the tree, similar to sift-up; used to restore heap condition after deletion or replacement.
	
	

	

	public :
	int heap_find_min();
	int pop();
	void heapify_down_index(int index);
	void heapify_up_index(int index);
	void index_delete(int index);
};


























