#include"StackCalc.h"





int main(int  argv, char** argc) {
	std::string inp = "";
	if (argv > 1) {
		inp = argc[1];
	}
	StackCalc st(inp);
	st.start();

	system("pause");
	return 0;
}