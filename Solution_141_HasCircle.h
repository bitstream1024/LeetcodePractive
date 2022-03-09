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

    // ����ָ�룬��ָ��ÿ������������ָ��ÿ����һ��������л���һ��������
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