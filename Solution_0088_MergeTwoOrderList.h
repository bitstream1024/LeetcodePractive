#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>

class Solution_0088_MergeTwoOrderList : public SolutionBase
{
public:

    virtual void RunTest()
    {
		std::vector<int> list0{1, 0};
		std::vector<int> list1{2};
		//cg_tool::PrintList(list0, "list0");
		//cg_tool::PrintList(list1, "list1");
		mergeWithList(list0, 1, list1, 1);
		//cg_tool::PrintList(list0, "list res");
    }

    // 使用 list 空间复杂度为 O(n)
	void mergeWithList(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		if (m == 0)
			nums1 = nums2;

		size_t index_0 = 0;
		size_t index_1 = 0;
		size_t index_res = 0;

		std::vector<int> resList(m + n);
		do
		{
			if (nums1[index_0] <= nums2[index_1])
			{
				resList[index_res++] = nums1[index_0];
				++index_0;
			}
			else
			{
				resList[index_res++] = nums2[index_1];
				++index_1;
			}

		} while ((index_0 < m) && (index_1 < n));

		if (index_0 < m)
		{
			for (size_t i = index_0; i < m; ++i)
			{
				resList[index_res++] = nums1[i];
			}
		}
		if (index_1 < n)
		{
			for (size_t i = index_1; i < n; ++i)
			{
				resList[index_res++] = nums2[i];
			}
		}

		nums1 = resList;

		return;
	}
};