#include <iostream>


#include "baseClasses.h"




//because I need a main function to test...
int main(void){
	item a(10), b(27);
	int* ptr;
	
	ptr = a.get_ptr();
	
	std::cout << *ptr << std::endl;
	
	std::cout << a.hash() << std::endl;
	
	int i = a.compare(b);
	
	std::cout << i << std::endl;
	
	
	return 0;
}
