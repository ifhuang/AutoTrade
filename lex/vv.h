#ifndef VV_H
# define VV_H

#include <vector>

#define VVN(x) x(#x)

template <typename T>
struct VV
{
	std::vector<T> v;
	const char *n;

	VV(const char *n) :n(n){}

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
		int idx = v.size();
		v.push_back(x);
		return idx;
	}

	size_t putI(size_t s, int x)
	{
		if (x == -1)return s;
		v[s].push_back(x);
		return s;
	}

	T& operator[](const size_t s)
	{
		if (s < 0 || s >= v.size())
		{
			printf("VV error: %s size %d, read at %d", n, v.size(), s);
		}
		return v[s];
	}

	void clear()
	{
		v.clear();
	}
};

#endif