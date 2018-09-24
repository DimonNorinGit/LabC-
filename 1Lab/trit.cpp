#include "trit.h"


namespace Tables {
	using namespace Types;
	const Trit AndTable[3][3] = {
	{ False , False , False },
	{ False , Unknown , Unknown },
	{ False , Unknown , True }
	};

	const Trit OrTable[3][3] = {
	{ False , Unknown , True },
	{ Unknown , Unknown , True },
	{ True , True , True }
	};
	const Trit NegTable[3] = { True , Unknown , False };
}

Trit::Trit()
{
	data = 1;
}

Trit::operator int()const {
	return data;
}

Trit::Trit(char d)
{
	data = d;
}

Trit operator&(Trit const & self, Trit const & obj) {
	return Tables::AndTable[self + 1][obj + 1];
}

Trit operator|(Trit const & self, Trit const & obj) {
	return Tables::OrTable[self + 1][obj + 1];
}

bool operator==(Trit const & self, Trit const & obj) {
	return self.data == obj.data;
}

Trit operator!(Trit const & self) {
	return Tables::NegTable[self + 1];
}

Trit::~Trit()
{
}
