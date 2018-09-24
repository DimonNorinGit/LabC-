#include "InstructionFactory.h"



InstructionFactory::InstructionFactory()
{
}

Instruction* InstructionFactory::get_instruction(CmdName cmd) {
	switch (cmd)
	{
	case CmdName::DEFINE:
		return new DefineInst();
		break;
	case CmdName::DIV:
		return new DivInst();
		break;

	case CmdName::MINUS:
		return new MinusInst();
		break;

	case CmdName::MULTI:
		return new MultiInst();
		break;

	case CmdName::PLUS:
		return new PlusInst();
		break;

	case CmdName::POP:
		return new PopInst();
		break;


	case CmdName::PRINT:
		return new PrintInst();
		break;

	case CmdName::PUSH:
		return new PushInst();
		break;

	case CmdName::SQRT:
		return new SqrtInst();
		break;
}	

}

InstructionFactory::~InstructionFactory()
{
}
