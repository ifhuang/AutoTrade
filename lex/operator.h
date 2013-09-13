#ifndef OPERATOR_H
# define OPERATOR_H

#include "execution.h"
#include "tree.h"

namespace Execution{

	struct add_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
		Value operator()(const std::string & lhs, const std::string & rhs) const;
	};

	struct sub_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
	};

	struct mul_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
	};

	struct div_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
	};

	struct and_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(bool lhs, bool rhs) const;
	};

	struct or_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(bool lhs, bool rhs) const;
	};

	struct not_visitor : public boost::static_visitor<Value>
	{
		template <typename T>
		Value operator()(const T &) const { throw InternalException(); }

		Value operator()(bool lhs) const;
	};

	struct uminus_visitor : public boost::static_visitor<Value>
	{
		template <typename T>
		Value operator()(const T &) const { throw InternalException(); }

		Value operator()(double lhs) const;
	};

	struct eq_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		template <typename T>
		Value operator()(const T & lhs, const T & rhs) const
		{
			return lhs == rhs;
		}
	};

	struct ne_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		template <typename T>
		Value operator()(const T & lhs, const T & rhs) const
		{
			return lhs != rhs;
		}
	};

	struct gt_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
		Value operator()(const std::string & lhs, const std::string & rhs) const;
	};

	struct ge_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
		Value operator()(const std::string & lhs, const std::string & rhs) const;
	};

	struct ca_visitor : public boost::static_visitor<Value>
	{
		template <typename T, typename U>
		Value operator()(const T &, const U &) const { throw InternalException(); }

		Value operator()(double lhs, double rhs) const;
	};
}

#endif