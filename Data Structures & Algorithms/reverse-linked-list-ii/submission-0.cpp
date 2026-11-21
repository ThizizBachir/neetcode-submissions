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
    // void reverse(ListNode * head,ListNode * tail)
    // {
    //     ListNode * prev=nullptr;
    //     ListNode* cur = head;
    //     ListNode* next = head->next;
    //     while(cur)
    //     {
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;
    //         next = cur->next;
    //         if(cur == tail)
    //         {
    //             cur->next = prev;
    //             break;
    //         }
    //     }
    //}
    void reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (true)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;

            if (cur == tail) break;

            cur = next;
        }
    }

    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        int i=1;
        ListNode* cur =  head;
        ListNode* l;
        ListNode* r;
        ListNode* preL = nullptr;
        ListNode* postR = nullptr;
        while(cur)
        {
            if(i==left-1) preL =cur;
            if(i==left)    l =cur;
            if(i==right+1) postR = cur;
            if(i==right)   r = cur;
            cur = cur->next;
            i++;
        }
        reverse(l,r);
        swap(l,r);
        if(preL) preL->next = l;
        if(postR) r->next = postR;
        return preL? head :l;





        
    }
};