#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>

class Solution_876_FindLinkListMiddle : public SolutionBase
{
public:

    virtual void RunTest()
    {
        ListNode *pNode = ListNode::CreateLinkList(4);
        ListNode::PrintLinkList(pNode, "pNode");
        bool bHasCircle = Solution_876_FindLinkListMiddle::hasCycle(pNode);
        //ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode);
    }

    // 快慢指针，快指针每次走两步，慢指针每次走一步，如果有环，一定会相遇
    bool hasCycle(ListNode* head) 
    {
        if (nullptr == head || nullptr == head->next || nullptr == head->next->next)
            return false;

        ListNode* pQuick = head->next->next;
        ListNode* pSlow = head->next;

        bool bHasCurcle = false;
        do
        {
            if (pSlow == pQuick)
            {
                bHasCurcle = true;
                break;
            }

            pSlow = pSlow->next;
            pQuick = pQuick->next;
            if (nullptr == pQuick)
                break;
            pQuick = pQuick->next;
        } while(nullptr != pSlow && nullptr != pQuick);

        return bHasCurcle;
    }
};