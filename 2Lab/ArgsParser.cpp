#include "ArgsParser.h"


ArgsParser::ArgsParser(std::string file_name)
{
	std::streambuf *buf;
	inp_f  = new std::ifstream();
	if (file_name == "") {
		buf = std::cout.rdbuf();
	}
	else {
		inp_f->open(file_name , std::ios_base::in);
		if (!inp_f->is_open()) {
			std::cout << "File not exist" << std::endl;
			exit(1);
		}
		buf = inp_f->rdbuf();
	}
	try {
		inp = new std::istream(buf);
	}
	catch (std::bad_alloc &ex) {
		std::cerr << "Bad alloc";
		exit(1);
	}
}

std::istream* ArgsParser::get_input_dv() {
	return inp;
}


ArgsParser::~ArgsParser()
{
	delete inp;
	delete inp_f;
}
