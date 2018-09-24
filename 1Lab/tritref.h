#pragma once
//enum TritType{False = -1, Unknown = 0, True = 1};

#include"trit.h"
#include<iostream>

enum { UN_INT_SIZE = sizeof(unsigned int) };
class TritRef {

private:
	friend class TritSet;
	unsigned char* data;
	size_t right_bit;
	Trit tr_type;
	void set_new_value(Trit type, unsigned char pointer);
	void set_true(unsigned char pointer);
	void set_false(unsigned char pointer);
	void set_unknown(unsigned char pointer);
	void set_trit(unsigned int* data, size_t diff);

public:
	Trit get_type() const;

	TritRef();

	TritRef& operator=(Trit type);

	operator Trit()const;

	friend std::ostream& operator<<(std::ostream& stream, TritRef const & trit);

	~TritRef();
};


std::ostream& operator<<(std::ostream& stream, TritRef const & trit);


