#include "MyTestUtils.h"
#include "MyCommonHelper.h"

static void InsertNum(std::vector<int> &list, const int &insertIndex, const int &endIndex)
{
	int temp = 0;
	int tempDst = list[endIndex];
	for (int index = insertIndex; index <= endIndex; ++index)
	{
		temp = list[index];
		list[index] = tempDst;
		tempDst = temp;
	}
}

// 从 index = 0 开始找到需要插入的地方  插入并一次性挪动后面的数字
void MyTestUtils::MySortUtils::InsertSort(std::vector<int> &list)
{
    if (list.size() <= 1)
        return;

    int Len = list.size();
    for (int i = 1; i < Len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
			if (list[i] < list[j])
			{
                InsertNum(list, j, i);
				break;
			}
            else 
                continue;
        }   
    }
    
    return;
}

// 从 index = i - 1 开始，如果比 list[i] 大就交换，直到条件不满足 break
void MyTestUtils::MySortUtils::InsertSort2(std::vector<int> &list)
{
	if (list.size() <= 1)
		return;

	int Len = list.size();
	int temp = 0;
	for (int i = 1; i < Len; ++i)
	{
		for (int j = i- 1; j >= 0; --j)
		{
			if (list[j + 1] < list[j])
			{
				cg_tool::Exchange(list[j], list[j + 1]);
			}
			else
				break;
		}
	}

	return;
}

void MyTestUtils::MySortUtils::QuickSort(std::vector<int> &list)
{
	if (list.size() <= 1)
		return;

	const size_t Len = list.size();
	int tempMin = 0;
	for (size_t i = 0; i < Len - 1; ++i)
	{
		tempMin = list[i];
		bool bNeedExchange = false;
		size_t minIndex = 0;
		for (size_t j = i + 1; j < Len; j++)
		{
			if (list[j] < tempMin)
			{
				tempMin = list[j];
				minIndex = j;
				bNeedExchange = true;
			}
		}
		if (bNeedExchange)
		{
			cg_tool::Exchange(list[i], list[minIndex]);
		}
	}
}