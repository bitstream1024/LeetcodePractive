#pragma once

#include <vector>
#include <iostream>

#include "SolutionBase.h"

class Solution_0034_SearchRange : public SolutionBase
{
public:
	virtual void RunTest();
	
private:
	int findNum(const std::vector<int> orderList, const int &num, bool bFirst = true);
};

void Solution_0034_SearchRange::RunTest()
{
	std::vector<int> orderList{ 1 };
	const int target = 1;
	int firstIndex = findNum(orderList, target);
	int lastIndex = findNum(orderList, target, false);
	std::cout << "RunTest: firstIndex:" << firstIndex << ", lastIndex is:" << lastIndex << std::endl;
}

int Solution_0034_SearchRange::findNum(const std::vector<int> orderList, const int &num, bool bFirst)
{
	if (0 == orderList.size())
		return -1;

	// use binary search, not recursion
	int head = 0;
	int tail = orderList.size() - 1;
	int middle = 0;
	int resIndex = -1;
 	while (head <= tail && tail >= 0)
	{
		middle = head + ((tail - head) >> 1);
		if (num < orderList[middle])
		{
			tail = middle - 1;
		}
		else if (num > orderList[middle])
		{
			head = middle + 1;
		}
		else
		{
			if (bFirst)
			{
				if (0 == middle || num != orderList[middle - 1])
				{
					resIndex = middle;
					break;
				}
				else
				{
					tail = middle - 1;
				}
			}
			else
			{
				if (middle == orderList.size() - 1 || num != orderList[middle + 1])
				{
					resIndex = middle;
					break;
				}
				else
				{
					head = middle + 1;
				}
			}
			
		}
	}

	return resIndex;
}
