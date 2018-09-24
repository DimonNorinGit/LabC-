#include"run_time_exceptions.h"


Exceptions::InstrException::InstrException() {
	error_msg = "";
}


Exceptions::InstrException::InstrException(std::string msg) {
	error_msg = msg;
}

void Exceptions::InstrException::what() {
	std::cout << "Error: " << error_msg << "!" <<  std::endl;
}
