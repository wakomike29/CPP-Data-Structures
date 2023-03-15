#include "baseClasses.h"




comparable::comparable(){

}

int comparable::get_value(){
	return value;
}

void comparable::update_value(int new_value){
	value = new_value;
}

int comparable::compare(comparable c){
	int ret;
	if(value > c.value){
		return 1;
	}else{
		return 0;
	}
}


hashable::hashable() {

}

int hashable::hash(){
	return 1;
}









/* init constructors */
item::item(int new_data){
	data=new_data;
	update_value(new_data+1);
}

item::~item(){
	
}


int *item::get_ptr(){
	return &data;
}


int item::update(int new_data){
	data=new_data;
	value = new_data+1;
	return 1;
}

int item::hash(){
	return data+2;
}

