#include <iostream>
#include <functional>
#include <vector>

template<class T>
std::function<T (T)> makePipeline(const std::vector<std::function<T (T)> >& funcs) {
	return [&funcs] (const T& value) {
        T res = value;
        for (auto f: funcs)
            res = f(res);
        return (res);
    };
}

#ifndef RunTests
int main()
{
    std::vector<std::function<int (int)> > functions;
    functions.push_back([] (int x) -> int { return x * 3; });
    functions.push_back([] (int x) -> int { return x + 1; });
    functions.push_back([] (int x) -> int { return x / 2; });
    
    std::function<int (int)> func = makePipeline(functions);
    std::cout << func(3); // should print 5
}
#endif