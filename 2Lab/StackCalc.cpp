#include "StackCalc.h"

StackCalc::StackCalc(std::string argv)
{
	try {
		args_parser = new ArgsParser(argv);
		inp_handlr = new InputHandler();
		ins_factory = new InstructionFactory();
	}
	catch (std::bad_alloc& ex) {
		std::cerr << "Bad alloc";
		exit(1);
	}
}


void StackCalc::start() {

	std::istream* inp = args_parser->get_input_dv();


	std::string inp_line;
	double value = 0;
	std::string name;

	while(!inp->eof()){
		std::getline(*inp, inp_line);

		CmdName cmd = inp_handlr->identify_cmd(inp_line , &value , &name);

		if (cmd == CmdName::UNKNOWN || cmd == CmdName::COMMENT) {
			continue;
		}
		Instruction* inst = nullptr;
		try {
			inst = ins_factory->get_instruction(cmd);
		}
		catch(std::bad_alloc &ex){
			std::cerr << "Bad alloc" << std::endl;
		}

		try {
			inst->exec(variables , calc_stack , std::make_pair(value , name));
			delete inst;
		}
		catch(Exceptions::InstrException &ex){
			ex.what();
		}
		catch (std::bad_weak_ptr &ex) {
			std::cerr << "Bad delete" << std::endl;
			exit(1);
		}
		catch (...) {
			std::cerr << "Error!" << std::endl;
			exit(1);
		}
	}
}

StackCalc::~StackCalc()
{
	delete args_parser;
	delete inp_handlr;
	delete ins_factory;
}
