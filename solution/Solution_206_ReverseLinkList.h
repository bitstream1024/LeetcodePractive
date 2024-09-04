#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>

class Solution_206_ReverseLinkList : public SolutionBase
{
public:

    virtual void RunTest()
    {
        ListNode *pNode = ListNode::CreateLinkList();
        ListNode::PrintLinkList(pNode, "pNode");
        ListNode *pResultNode = Solution_206_ReverseLinkList::reverseLinkListWithStack(pNode);
        ListNode::PrintLinkList(pResultNode, "pResultNode");
        ListNode::FreeLinkList(&pNode);
    }

    /// use vector to store ListNode
    static ListNode* reverseLinkListWithVector(ListNode* head)
    {
        if (nullptr == head)
            return nullptr;

        if (nullptr == head->next)
            return head;

        std::vector<int> list;
        ListNode* p = head;
        do {
            list.push_back(p->val);
            p = p->next;
        } while(nullptr != p);

        size_t len = list.size();
        int index = 1;
        p = head;
        do {
            p->val = list[len - index];
            p = p->next;
            ++index;
        } while(nullptr != p);
        
        return head;
    }

    /// use stack to store ListNode
    static ListNode* reverseLinkListWithStack(ListNode* head)
    {
        if (nullptr == head)
            return nullptr;

        if (nullptr == head->next)
            return head;

        std::stack<ListNode*> listStack;

        auto p = head;
        do 
        {
            listStack.push(p);
            p  = p->next;
        } while(nullptr != p);

        auto pRHead = listStack.top(); 
        do
        {
            auto p = listStack.top();
            listStack.pop();
            if (listStack.empty())
            {
                p->next = nullptr;
                break;
            } 
            else 
            {
                p->next = listStack.top();
            }
        } while (true);
        
        return pRHead;
    }

    /// use next node and pre node to store ListNode
    static ListNode* reverseLinkListWithNode(ListNode *head)
    {
        if (nullptr == head)
            return nullptr;

        if (nullptr == head->next)
            return head;

        ListNode *pCurrent = head;
        ListNode *pPre = nullptr;
        ListNode *pNext = nullptr;
        do 
        {
            pNext = pCurrent->next;
            if (head == pCurrent)
                pCurrent->next = nullptr;
            else
                pCurrent->next = pPre;

            pPre = pCurrent;
            pCurrent = pNext;
        } while(nullptr != pCurrent);

        return pPre;
    }
};