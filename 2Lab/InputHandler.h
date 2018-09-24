#pragma once
#include<istream>
#include"cmdenum.h"
#include<regex>
#include<map>
#include"cmdenum.h"

class InputHandler
{

private:

	std::map<CmdName, std::regex> cmd_patterns;

public:
	

	InputHandler();
	CmdName identify_cmd(std::string& line, double * value, std::string * name);
	~InputHandler();
};

