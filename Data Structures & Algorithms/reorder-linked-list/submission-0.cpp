/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode * cur = head;
        if(!head || !head->next) return;
        int size = 0;
        while (cur) { size++; cur = cur->next;}
        int sizeList1 = size - size/2; // size of first , index of first in list 2 ;
        int sizeList2 = size/2;
        cur = head;
        ListNode *head2;

        for(int i = 0;i<sizeList1-1;i++,cur=cur->next){}
        head2 = cur->next;
        cur->next = nullptr;

        ListNode * prev= nullptr;

        while (head2)
        {
            ListNode * next = head2->next;
            head2->next = prev;
            prev= head2;
            head2 = next;
        }

        head2 = prev;
        cur = head;

        for(int i =0; i<size;i++)
        {
            if(i%2 ==0)
            {
                ListNode * next = cur->next;
                cur->next = head2;
                cur = next;

            }

            else
            {
                ListNode * next = head2->next;
                head2->next = cur;
                head2 = next;

            }
        }

    }
};
