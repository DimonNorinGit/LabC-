#pragma once
//False , Unknown , True



class Trit
{
private:
	char data;
public:

	friend class TritRef;

	explicit Trit(char d);

	Trit();

	operator int()const;

	friend Trit operator&(Trit const & self, Trit const & obj);

	friend Trit operator|(Trit const & self, Trit const & obj);

	friend bool operator==(Trit const & self, Trit const & obj);

	friend Trit operator!(Trit const & self);

	~Trit();
};

namespace Types {
	const Trit False(-1);
	const Trit True(1);
	const Trit Unknown(0);
}

Trit operator&(Trit const & self, Trit const & obj);

Trit operator|(Trit const & self, Trit const & obj);

bool operator==(Trit const & self, Trit const & obj);

Trit operator!(Trit const & self);