#include "stdio.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    /**
    * create link list
    */
    static ListNode* CreateLinkList(int nodeNum = 5)
    {
        ListNode *pListHead = nullptr;
        ListNode *pLastNode = nullptr;
        for (int i = 1; i <= nodeNum; ++i)
        {
            auto pNode= new ListNode(i);
            if (1 == i)
            {
                pListHead = pNode;
            }
            if (nullptr != pLastNode)
            {
                pLastNode->next = pNode;
            }
            pLastNode = pNode;
        }
        return pListHead;
    }
    /**
     * Destroy link list
     */
    static void FreeLinkList(ListNode **pHeadNode)
    {
        if (nullptr == pHeadNode || nullptr == *pHeadNode)
            return;

        ListNode *pNode = *pHeadNode;
        ListNode *pNextNode = nullptr;
        do
        {
            pNextNode = pNode->next;
            if (nullptr != pNode)
            {
                delete pNode;
                pNode = nullptr;
            }
            pNode = pNextNode;
        } while (nullptr != pNode);
    }
    /**
     * print link list
     */
    static void PrintLinkList(ListNode *pNode, std::string info)
    {
        if (nullptr == pNode)
            return;
        
        std::cout << info.c_str() << " PrintLinkList " << std::endl;
        auto *p = pNode;
        do {
            std::cout << "PrintLinkList " << p->val << std::endl;
            p = p->next;
        } while(nullptr != p);
    }
};