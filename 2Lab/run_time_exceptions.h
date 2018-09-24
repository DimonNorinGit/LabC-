#pragma once
#include<iostream>
#include<string>


namespace Exceptions{

	class InstrException {
	private:
		std::string error_msg;
	public:
		InstrException();
		InstrException(std::string msg);
		virtual void what();
	};

	class NeedArgs : public InstrException {
	public:
		NeedArgs(std::string msg) :InstrException(msg) {}
	};

	class ZeroDiv : public InstrException {
	public:
		ZeroDiv(std::string msg) :InstrException(msg) {}
	};

	class NegValue : public InstrException {
	public:
		NegValue(std::string msg) :InstrException(msg) {}
	};

	class VarNotFound : public InstrException {
	public:
		VarNotFound(std::string msg) :InstrException(msg) {}
	};

	class MultiDef : public InstrException {
	public:
		MultiDef(std::string msg) :InstrException(msg) {}
	};

}