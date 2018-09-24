#include "InputHandler.h"
#include<string>
#include<iostream>
InputHandler::InputHandler()
{
	//linux and std::getline - check last simbol ATTENTION
	cmd_patterns[CmdName::COMMENT] = std::regex("[ ]*#.*");

	cmd_patterns[CmdName::PUSH] = std::regex("PUSH *(-?[0-9]{1,10}.?[0-9]{0,10}|[a-zA-Z_]{1,10})[ \n\r]*");
	//cmd_patterns[CmdName::PUSH] = std::regex("PUSH *((-?[0-9]{1,10}.?[0-9]{0,10})|([a-zA-Z_]{1,10}))[ \n\r]*");
	cmd_patterns[CmdName::PRINT] = std::regex("[ ]*PRINT[\n\r ]*");
	//set max variable size?
	cmd_patterns[CmdName::DEFINE] = std::regex("DEFINE[ ]*([a-zA-Z_0-9]{0,30}) *(-?[0-9]{1,10}.?[0-9]{1,10})[ \n\r]*");
	cmd_patterns[CmdName::SQRT] = std::regex("[ ]*SQRT[\n\r ]*");
	cmd_patterns[CmdName::MULTI] = std::regex("[ ]*[*][\n\r ]*");
	cmd_patterns[CmdName::DIV] = std::regex("[ ]*[/][\n\r ]*");
	cmd_patterns[CmdName::PLUS] = std::regex("[ ]*[+][\n\r ]*");
	cmd_patterns[CmdName::MINUS] = std::regex("[ ]*[-][\n\r ]*");
	cmd_patterns[CmdName::POP] = std::regex("[ ]*POP[\n\r ]*");
}


/*void  check_file_format(std::string txt, std::string csv) {

	

	std::smatch result;

	std::regex check_txt(" .txt $ ");
	std::regex ch;
	std::regex check_csv(" .csv $ ");
	std::regex_search(txt, result, check_txt);

}*/

CmdName InputHandler::identify_cmd(std::string& line , double* value , std::string* name) {
	std::cmatch result;
	//предотвращение переполнения при atof производиться за счет regex
	for (auto pat : cmd_patterns) {
		if (std::regex_match(line.c_str(), result, pat.second)) {
			if (pat.first == CmdName::DEFINE) {

				*name = std::string(result[1]);
				*value = atof(std::string(result[2]).c_str());

			}
			else if (pat.first == CmdName::PUSH) {

				std::string str = std::string(result[1]);

				double val = atof(str.c_str());
				
				if ((val == 0 && str.length() != 1) || (val == 0 && str.length() == 1 && !isdigit(str[0]))) {
					*name = str;
				}
				else {
					*value = val;
				}

			}

			return pat.first;
		}
	}
	return CmdName::UNKNOWN;
}

InputHandler::~InputHandler()
{

}
