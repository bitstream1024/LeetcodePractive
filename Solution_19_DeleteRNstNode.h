#include "SolutionBase.h"

#include "ListNode.h"
#include <stack>
#include <vector>

class Solution_19_DeleteRNstNode : public SolutionBase
{
public:

    virtual void RunTest()
    {
        ListNode *pNode = ListNode::CreateLinkList(4);
        ListNode::PrintLinkList(pNode, "pNode");
        ListNode *pResultNode = Solution_19_DeleteRNstNode::RemoveNthFromEndWithTwoNode(pNode, 2);
        ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode);
    }

    /// use stack
    static ListNode* RemoveNthFromEndWithStack(ListNode* head, int n)
    {
        if (nullptr == head || 0 == n)
            return head;

        std::stack<ListNode*> listStack;
        ListNode *pNode = head;
        do
        {
            listStack.push(pNode);
            pNode = pNode->next;
        } while(nullptr != pNode);

        ListNode *pLastNode = nullptr;
        ListNode *pResNode = head;
        int num = 1;
        do 
        {
            if (n == num)
            {
                listStack.pop();
                if (listStack.size() == 0)
                {
                    pResNode = pLastNode;
                }
                else
                {
                    listStack.top()->next = pLastNode;
                }
                break;
            }
            pLastNode = listStack.top();
            listStack.pop();
            ++num;
        } while(nullptr != listStack.top());

        return pResNode;
    }

    static ListNode* RemoveNthFromEndWithVector(ListNode* head, int n)
    {
        if (nullptr == head || 0 == n)
            return head;

        std::vector<ListNode*> nodeArray;
        ListNode *pNode = head;
        do
        {
            nodeArray.push_back(pNode);
            pNode = pNode->next;
        } while(nullptr != pNode);

        int deleteNum = nodeArray.size() - n;
        if(0 == deleteNum)
        {
            return head->next;
        }
        else
        {
            nodeArray[deleteNum - 1]->next = nodeArray[deleteNum]->next;
        }
        return head;
    }

    /// use fast and slow node, fast node is faster than slow node 2 steps
    static ListNode* RemoveNthFromEndWithTwoNode(ListNode* head, int n)
    {
        if (nullptr == head || 0 == n)
            return head;

        ListNode *pSlowNode = head;
        ListNode *pQuickNode = head;

        for (size_t i = 0; i < n; i++)
        {
            pQuickNode = pQuickNode->next;
            if (nullptr == pQuickNode)
            {
                return head->next;
            }
        }
        
        ListNode* pLastNode = pSlowNode;
        do
        {
            pSlowNode = pSlowNode->next;
            pQuickNode = pQuickNode->next;

            if (nullptr == pQuickNode)
            {
                pLastNode->next = pSlowNode->next;
                break;
            }
            pLastNode = pSlowNode;
        } while (true);

        return head;
    }
};