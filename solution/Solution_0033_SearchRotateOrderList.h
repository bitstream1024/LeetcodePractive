#pragma

#include "SolutionBase.h"

class Solution_0033_SearchRotateOrderList : public SolutionBase
{
public:
    virtual void RunTest();

private:
    int search(std::vector<int>& nums, int target);
};

void Solution_0033_SearchRotateOrderList::RunTest()
{
    std::vector<int> list{ 2, 3, 4, 5, 1 };
    int index = search(list, 1);
    std::cout << "search indedx = " << index << std::endl;
}

static int binarySearch(std::vector<int> nums, int target, int left, int right)
{
    int mid = 0, resIndex = -1, Len = nums.size();
    while (left <= right)
    {
        mid = left + (right - left >> 1);
        if (nums[mid] == target)
        {
            resIndex = mid;
            break;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return resIndex;
}

static int findInflectionIndex(std::vector<int> nums)
{
    const int Len = nums.size();
    int left = 0, right = Len - 1, mid = 0, inflectionIndex = 0;
    // binary search to find the inflection point
    while (left <= right)
    {
        mid = left + (right - left >> 1);
        if ((Len -1 == mid && nums[mid] < nums[mid - 1]) 
            || (mid > 0 && nums[mid - 1] > nums[mid] && (mid < Len - 1) && nums[mid] < nums[mid + 1]))
        {
            inflectionIndex = mid;
            break;
        }
        if (nums[mid] >= nums[0])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return inflectionIndex;
}

int Solution_0033_SearchRotateOrderList::search(std::vector<int>& nums, int target) {

    const int Len = nums.size();
    if (Len < 4)
    {
        if (0 == nums.size())
            return -1;
        for (size_t i = 0; i < Len; ++i)
        {
            if (target == nums[i])
                return i;
        }
        return -1;
    }

    int resIndex = -1, left = 0, right = Len - 1, mid = 0, inflectionIndex = 0;
    inflectionIndex = findInflectionIndex(nums);

    if (0 != inflectionIndex)
    {
        if (target >= nums[0])
            right = inflectionIndex - 1;
        else
            left = inflectionIndex;
    }
    

    return binarySearch(nums, target, left, right);
}