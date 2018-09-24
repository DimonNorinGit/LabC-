#include "Instruction.h"

Instruction::Instruction() {

}

void DivInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data) {
	if (calc_stack.size() < 2) {
		throw Exceptions::NeedArgs("Division needs two arguments");
	}
	ExecValue first = calc_stack.top();
	calc_stack.pop();
	ExecValue second = calc_stack.top();
	calc_stack.pop();
	if (second.get_data() == 0) {
		throw Exceptions::ZeroDiv("Division by zero");
	}
	calc_stack.push(ExecValue(first.get_data() / second.get_data()));
}

void PopInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data) {
	if (calc_stack.size() == 0) {
		throw Exceptions::NeedArgs("Not enough arguments");
	}
	calc_stack.pop();
}


void PrintInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data) {
	if (calc_stack.size() == 0) {
		throw Exceptions::NeedArgs("Not enough arguments");
	}
	ExecValue value = calc_stack.top();
	std::cout << value.get_data() << '\n';
}

void SqrtInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data) {
	if (calc_stack.size() == 0) {
		throw Exceptions::NeedArgs("Not enough arguments");
	}
	ExecValue value = calc_stack.top();
	calc_stack.pop();
	if (value.get_data() < 0) {
		throw Exceptions::NegValue("Negetive value to sqrt");
	}
	calc_stack.push(ExecValue(std::sqrt(value.get_data())));
}

void PushInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const & data) {
	if (data.second == "") {
		double value = data.first;
		calc_stack.push(ExecValue(value));
	}
	else {
		if (variables.find(data.second) == variables.end()) {
			throw Exceptions::VarNotFound("Variable not exist");
		}
		else {
			calc_stack.push(ExecValue(variables[data.second]));
		}
	}
}

void MultiInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const & data) {
	if (calc_stack.size() < 2) {
		throw Exceptions::NeedArgs("Multiplication needs two arguments");
	}
	ExecValue first = calc_stack.top();
	calc_stack.pop();
	ExecValue second = calc_stack.top();
	calc_stack.pop();
	calc_stack.push(ExecValue(first.get_data() * second.get_data()));
}

void DefineInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const & data) {
	if (variables.find(data.second) != variables.end()) {
		throw Exceptions::MultiDef("Variable is already exist");
	}
	variables[data.second] = data.first;
}

void PlusInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const & data) {
	if (calc_stack.size() < 2) {
		throw Exceptions::NeedArgs("Addition needs two arguments");
	}
	ExecValue first = calc_stack.top();
	calc_stack.pop();
	ExecValue second = calc_stack.top();
	calc_stack.pop();
	calc_stack.push(ExecValue(first.get_data() + second.get_data()));
}

void MinusInst::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const & data) {
	if (calc_stack.size() < 2) {
		throw Exceptions::NeedArgs("Subtraction needs two arguments");
	}
	ExecValue first = calc_stack.top();
	calc_stack.pop();
	ExecValue second = calc_stack.top();
	calc_stack.pop();
	calc_stack.push(ExecValue(first.get_data() - second.get_data()));
}


void Instruction::exec(std::map<std::string, double>& variables, std::stack<ExecValue>& calc_stack, std::pair<double, std::string> const& data) {

}
Instruction::~Instruction() {

}