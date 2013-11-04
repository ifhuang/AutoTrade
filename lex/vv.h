#ifndef LEX_VV_H_
#define LEX_VV_H_

#include <string>
#include <vector>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include "global.h"

#define VVN(x) x(#x)

template <typename T>
class VV
{
public:
    VV() {}
	VV(const std::string &n) :n_(n) {}

	int create()
	{
		return put(T());
	}

	int createI(int x)
	{
		return putI(create(), x);
	}

	int put(T x)
	{
        int idx = v_.size();
		v_.push_back(x);
		return idx;
	}

    size_t putI(size_t s, int x)
    {
        if (x == -1)return s;
        v_[s].push_back(x);
        return s;
    }

	T& operator[](const size_t s)
	{
        check(s);
        return v_[s];
	}

    const T& operator[](const size_t s) const
    {
        check(s);
        return v_[s];
    }

	void clear()
	{
        v_.clear();
	}

private:
    void check(const size_t s) const
    {
        if (s < 0 || s >= v_.size())
        {
            printf("VV error: %s size %d, read at %d", n_.c_str(), v_.size(), s);
        }
    }

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & n_;
        ar & v_;
    }

    std::vector<T> v_;
    std::string n_;
};

#endif  // LEX_VV_H_
