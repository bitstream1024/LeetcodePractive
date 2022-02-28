#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>

class Solution_21_MergeTwoLists : public SolutionBase
{
public:

    virtual void RunTest()
    {
        ListNode *pNode1 = ListNode::CreateLinkList(4);
        ListNode *pNode2 = ListNode::CreateLinkList(6);
        ListNode::PrintLinkList(pNode1, "pNode1");
        ListNode::PrintLinkList(pNode2, "pNode2");
        ListNode *pResultNode = Solution_21_MergeTwoLists::MergeTwoLists(pNode1, pNode2);
        ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode1);
        ListNode::FreeLinkList(&pNode2);
    }

    /// 
    ListNode* MergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (nullptr == list1 || nullptr == list2)
            return nullptr;

        // todo:

        return nullptr;
    }
};