#include"TritSet.h"
/*#include"gtest/gtest.h"

class TestTritSet : public ::testing::Test
{
protected:
	void SetUp()
	{
		foo = new Foo;
		foo->i = 5;
	}
	void TearDown()
	{gi
		delete foo;
	}
	Foo *foo;
};


*/


int main() {
	TritSet set1(10);
	TritSet set2(10);
	for (size_t i = 0; i < set1.capacity(); ++i) {
		set1[i] = TritType::True;
	}
	set1.resize(20);//не работает
	for (size_t i = 0; i < set2.capacity(); ++i) {
		set2[i] = TritType::False;
	}
	for (size_t i = 0; i < set1.capacity(); ++i) {
		std::cout << set1[i];
	}
	set2 = (set2 | set1);

	std::cout<<set2.cardinality(TritType::False);
	system("pause");
	return 0;
}