#include <stdexcept>
#include <iostream>
#include <list>

class TrainComposition
{
private:
    std::list<int> trains;
public:
    void attachWagonFromLeft(int wagonId)
    {
        trains.push_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        trains.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        if (trains.size() == 0)
            throw std::logic_error("no trains left");
        int wagonId = trains.front();
        trains.pop_front();
        return (wagonId);
    }

    int detachWagonFromRight()
    {
        if (trains.size() == 0)
            throw std::logic_error("no trains left");
        int wagonId = trains.back();
        trains.pop_back();
        return (wagonId);
    }
};

int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7 
    std::cout << tree.detachWagonFromLeft(); // 13
}