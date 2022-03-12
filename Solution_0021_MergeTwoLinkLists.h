#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>

class Solution_0021_MergeTwoLinkLists : public SolutionBase
{
public:

    virtual void RunTest()
    {
        ListNode *pNode1 = ListNode::CreateLinkList(4);
        ListNode *pNode2 = ListNode::CreateLinkList(6);
        ListNode::PrintLinkList(pNode1, "pNode1");
        ListNode::PrintLinkList(pNode2, "pNode2");
        ListNode *pResultNode = mergeTwoLists(pNode1, pNode2);
        ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode1);
        ListNode::FreeLinkList(&pNode2);
    }

    /// 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (nullptr == list1 || nullptr == list2)
            return nullptr;

		if (nullptr == list1)
			return list2;
		if (nullptr == list2)
			return list1;

		ListNode *resHead = nullptr;
		bool bHeadOK = false;

		if (list1->val <= list2->val)
		{
			resHead = list1;
			list1 = list1->next;
		}
		else
		{
			resHead = list2;
			list2 = list2->next;
		}
		ListNode *resTemp = resHead;

		while (true)
		{
			if (nullptr != list1 && nullptr != list2)
			{
				if (list1->val <= list2->val)
				{
					resTemp->next = list1;
					resTemp = list1;
					list1 = list1->next;
				}
				else
				{
					resTemp->next = list2;
					resTemp = list2;
					list2 = list2->next;
				}
			}
			else if (nullptr != list1)
			{
				resTemp->next = list1;
				resTemp = list1;
				list1 = list1->next;
			}
			else if (nullptr != list2)
			{
				resTemp->next = list2;
				resTemp = list2;
				list2 = list2->next;
			}
			else
				break;
		}
		
        return resHead;
    }
};