#include "ExecValue.h"



ExecValue::ExecValue(double value)
{
	data = value;
}

ExecValue::ExecValue() {

}

double ExecValue::get_data() {
	return data;
}

ExecValue::~ExecValue()
{
}
