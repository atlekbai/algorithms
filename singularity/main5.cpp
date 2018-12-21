#include <iostream>
#include <string>

class MultipleChoiceTest
{
protected:
    int questionsCount;

private:
    int* answers;
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
    }

    virtual ~MultipleChoiceTest(void)
    {
        delete[] answers;
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }

};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
private:
    int* times;
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }

    ~TimedMultipleChoiceTest(void)
    {
        delete[] times;
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
        test.setAnswer(i, i);

    for (int i = 0; i < 5; i++)
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif