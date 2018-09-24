#pragma once
#include<fstream>
#include<streambuf>
#include<iostream>
#include<istream>

class ArgsParser
{

private:
	std::istream *inp;
	std::ifstream *inp_f;
public:
	ArgsParser(std::string file_name);
	std::istream* get_input_dv();
	~ArgsParser();
};

