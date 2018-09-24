#pragma once
#include"cmdenum.h"
#include"Instruction.h"
class InstructionFactory
{
public:
	InstructionFactory();
	Instruction* get_instruction(CmdName cmd);
	~InstructionFactory();
};

