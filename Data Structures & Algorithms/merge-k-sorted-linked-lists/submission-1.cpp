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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(!k) return nullptr;
        
        multimap<int, ListNode*> mp;
        ListNode*  head =  new ListNode();
        ListNode*  cur = head;
        for(auto l : lists)
        {
            if(!l) continue;
            mp.insert({l->val,l});
        }
        while(!mp.empty())
        {
            auto minIT = mp.begin();
            cur->next = minIT->second;
            ListNode* next = minIT->second->next;
            mp.erase(minIT);
            if(next) mp.insert({next->val,next});
            cur = cur->next;
        }

        return head->next;
        
    }
};
