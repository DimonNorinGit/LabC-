#pragma once
#include"ExecValue.h"
#include"run_time_exceptions.h"


//������ ���������� ����� �������� ������ ���������� � ���� list ��� �������� ������������ "�����������" �����


class Instruction
{
public:
	Instruction();
	virtual void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
	virtual ~Instruction();
};

class DivInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};


class PopInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};

class PushInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};


class PlusInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};


class MinusInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};


class PrintInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};


class MultiInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);

};


class DefineInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);


};


class SqrtInst : public Instruction {
public:
	void exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data);
};





