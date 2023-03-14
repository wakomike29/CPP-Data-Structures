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
int heap_ensure_min();
int heap_ensure_max();


/* temp */
void heapify_up();
void heapify_down();
void heapify_down_index(int index);
void heapify_up_index(int index);


};