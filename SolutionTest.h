#include <iostream>

#include "SolutionBase.h"
#include "MyTestUtils.h"

class SolutionTest: public SolutionBase
{
private:
    /* data */
public:
    SolutionTest(/* args */);
    ~SolutionTest();

    virtual void RunTest();
};

SolutionTest::SolutionTest(/* args */)
{
}

SolutionTest::~SolutionTest()
{
}

void SolutionTest::RunTest()
{
    std::vector<int> list{4, 5, 6, 1, 7, 8, 9, 2};
    std::cout << "before sort: ------" << std::endl;
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    MyTestUtils::MySortUtils::QuickSort(list);
    std::cout << "after sort: ------" << std::endl;
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    
}
