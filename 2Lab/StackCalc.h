#pragma once
#include"ArgsParser.h"
#include"InputHandler.h"
#include"InstructionFactory.h"
#include"ExecValue.h"
#include<new>

class StackCalc
{

private:
	ArgsParser * args_parser;
	InputHandler* inp_handlr;
	InstructionFactory* ins_factory;
	std::map<std::string, double> variables;
	std::stack<ExecValue> calc_stack;

public:
	StackCalc(std::string argv);
	void start();	
	//StackCalk(StackCalc const & obj);
	//StackCalk & operator=(StackCalk const & obj);
	~StackCalc();
};

