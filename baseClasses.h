#pragma once
#pragma GCC diagnostic ignored "-Wc++11-extensions"

class comparable {
protected:
	int value;
	void update_value(int);
	public:
	comparable();
	int get_value();
	virtual int compare(comparable c);

};


class hashable {
	public:
	hashable();
	virtual int hash();
	
};

class item : public hashable, public comparable{
	int data;
	public:
	int *get_ptr();
	int update(int);
	int hash() override;
	//int comparable() override;
	item(int);
	~item();

};