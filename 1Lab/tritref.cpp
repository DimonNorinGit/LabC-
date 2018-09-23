#include "tritref.h"

TritRef::TritRef() {
	data = nullptr;
	right_bit = 2;
	tr_type = Types::Unknown;
}

void TritRef::set_true(unsigned char pointer) {
	*data = *data | pointer;
	pointer <<= (1);
	pointer = ~pointer;
	*data = *data & pointer;
}
void TritRef::set_false(unsigned char pointer) {
	pointer = ~pointer;
	*data = *data & pointer;
	pointer = ~pointer;
	pointer <<= (1);
	*data = *data | pointer;
}

void TritRef::set_unknown(unsigned char pointer) {
	unsigned int keep_p = ~pointer;
	*data = *data & keep_p;
	pointer <<= (1);
	pointer = ~pointer;
	*data = *data & pointer;
}

void TritRef::set_new_value(Trit type, unsigned char pointer) {
	if (type == Types::True) {
		set_true(pointer);
	}
	else if (type == Types::False) {
		set_false(pointer);
	}
	else if (type == Types::Unknown) {
		set_unknown(pointer);
	}

}

TritRef& TritRef::operator=(Trit type) {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - right_bit);
	set_new_value(type, pointer);
	this->tr_type = type;
	return *this;
}

TritRef::operator Trit()const {
	return this->tr_type;
}

void TritRef::set_trit(unsigned int* d, size_t diff) {
	size_t b_pos = (diff - 1) / 8;
	right_bit = diff - b_pos * 8;
	data = ((unsigned char*)d) + b_pos;
	this->tr_type = get_type();
}


Trit TritRef::get_type()const {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - right_bit);
	if (pointer & *data) {
		return Types::True;
	}
	else {
		pointer <<= (1);
		if (pointer & *data) {
			return Types::False;
		}
		else {
			return Types::Unknown;
		}
	}
}

std::ostream& operator<<(std::ostream& stream, TritRef const & trit) {
	stream << trit.tr_type;
	return stream;
}

TritRef::~TritRef()
{
}
