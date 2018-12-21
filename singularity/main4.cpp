#include <vector>
#include <stdexcept>
#include <iostream>
#include <future>

#define THREADS_NUM 10
#define ll long long

template<typename T>
ll countLess(T p, T q, int lessThan)
{
	ll count = 0;
	if (*p < lessThan)
		count++;
	while (++p != q)
		if (*p < lessThan)
			count++;
	return (count);
}

class SortedSearch
{
public:
    static int countNumbers(const std::vector<int>& sortedVector, int lessThan)
    {
    	ll count = 0;
    	if (sortedVector.size() > 0)
    	{
    		if (sortedVector.back() < lessThan)
    			return (sortedVector.size());
    		else if (sortedVector.front() >= lessThan)
    			return (0);
    		int dif = std::distance(sortedVector.begin(), sortedVector.end());
    		std::future<ll> fut[THREADS_NUM];
    		for (int i = 0; i < THREADS_NUM; i++)
    		{
    			auto p = sortedVector.begin();
				auto q = sortedVector.begin();
				std::advance(p, static_cast<int>(i * dif / THREADS_NUM));
				std::advance(q, static_cast<int>((i + 1) * dif / THREADS_NUM));
				fut[i] = std::async(std::launch::async, &countLess<decltype(p)>, p, q, lessThan);
    		}
    		for (int i = 0; i < THREADS_NUM; i++)
    			count += fut[i].get();
    	}
        return (count);
    }
};

#ifndef RunTests
int main()
{
    std::vector<int> v;
    for (int i = 0; i < 100000000; i++)
    	v.push_back(i);
    std::cout << SortedSearch::countNumbers(v, -1);
}
#endif