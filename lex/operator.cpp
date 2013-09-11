#include "operator.h"

using namespace std;

namespace Execution{

	Value add_visitor::operator()(double lhs, double rhs) const
	{
		return lhs + rhs;
	}

	Value add_visitor::operator()(const string & lhs, const string & rhs) const
	{
		return lhs + rhs;
	}

	Value sub_visitor::operator()(double lhs, double rhs) const
	{
		return lhs - rhs;
	}

	Value mul_visitor::operator()(double lhs, double rhs) const
	{
		return lhs * rhs;
	}

	Value div_visitor::operator()(double lhs, double rhs) const
	{
		return lhs / rhs;
	}

	Value and_visitor::operator()(bool lhs, bool rhs) const
	{
		return lhs && rhs;
	}

	Value or_visitor::operator()(bool lhs, bool rhs) const
	{
		return lhs || rhs;
	}

	Value not_visitor::operator()(bool lhs) const
	{
		return !lhs;
	}

	Value uminus_visitor::operator()(double lhs) const
	{
		return -lhs;
	}

	Value gt_visitor::operator()(double lhs, double rhs) const
	{
		return lhs > rhs;
	}

	Value gt_visitor::operator()(const string & lhs, const string & rhs) const
	{
		return lhs > rhs;
	}

	Value ge_visitor::operator()(double lhs, double rhs) const
	{
		return lhs >= rhs;
	}

	Value ge_visitor::operator()(const string & lhs, const string & rhs) const
	{
		return lhs >= rhs;
	}


	Execution::Value ca_visitor::operator()(double lhs, double rhs) const
	{
		//
		return false;
	}

}