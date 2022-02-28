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
        ListNode *pResultNode = Solution_876_FindLinkListMiddle::FindListNodeMiddle(pNode);
        ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode);
    }

    ListNode* FindListNodeMiddle(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
            return head;

        ListNode *pQuickNode = head;
        //ListNode *pSlowNode = head;
        do 
        {
            pQuickNode = pQuickNode->next;
            if (nullptr != pQuickNode)
                pQuickNode = pQuickNode->next;
            else
                break;

            head = head->next;
            
        } while (nullptr != pQuickNode);

        return head;
    }
};