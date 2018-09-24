#pragma once
#include<map>
#include<stack>
#include<string>
#include<iostream>
#include<cmath>

class ExecValue
{
	double data;
public:
	ExecValue(double value);
	ExecValue();
	double get_data();
	~ExecValue();
};

