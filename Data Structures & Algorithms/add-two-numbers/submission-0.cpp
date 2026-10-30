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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy ;
        ListNode *tail = &dummy;

        ListNode *cur1 = l1;
        ListNode *cur2 = l2;

        int carry =0;

        while (cur1 || cur2)
        {

            ListNode * next = new ListNode(0);
            tail->next= next;
            tail = next;

            if(cur1 && cur2)
            {
                int sum = cur1->val + cur2-> val + carry;
                next->val =sum%10 ;
                carry  = sum /10;

                cur1 = cur1->next;
                cur2= cur2->next;
                continue;

            }
            if(cur1)
            {
                int sum = cur1->val  + carry;
                next->val =sum%10 ;
                carry  = sum /10;

                cur1 = cur1->next;
                continue;

            }
            if(cur2)
            {
                int sum = cur2-> val + carry;
                next->val =sum%10 ;
                carry  = sum /10;

                cur2= cur2->next;
                continue;
            }

        }
        if(carry) 
        {
            ListNode * next = new ListNode(0);
            tail->next= next;
            tail = next;
            next->val = 1;

        }






        return dummy.next;
        
    }
};
