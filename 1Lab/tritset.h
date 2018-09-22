#pragma once
#include<new>
#include"Trit.h"




//01 - True
//00 - Unknown
//10 - False
enum OperationType { And, Or };

class TritSet
{

private:
	unsigned int* data_array;
	size_t trits_capacity;//all
	size_t data_length;//all

	mutable size_t used_capacity;//settled
	mutable size_t used_length;//settled

	void set_used_capacity()const;
	void fill_unknown(size_t start, size_t end);
	void resize_data(size_t end, size_t tr_length);
	Trit execute_operation(Trit const & a, Trit const & b , OperationType type)const;
	TritSet& init_operation(TritSet const & obj, OperationType type)const;

public:
	TritSet();

	TritSet(size_t alloc_trits);

	size_t cardinality(Trit value)const;

	size_t capacity() const;

	size_t stated_capacity() const;

	TritSet(TritSet const& obj);

	void swap(TritSet & obj);

	void shrink_to_fit();

	void resize(size_t new_size);/////

	TritSet & operator=(TritSet const& obj);

	Trit operator[](size_t trit_i);

	Trit operator[](size_t trit_i)const;

	friend TritSet& operator&(TritSet const & self , TritSet const & obj);

	friend TritSet& operator|(TritSet const & self , TritSet const & obj);

	~TritSet();
};

