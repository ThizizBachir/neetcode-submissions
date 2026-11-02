/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> m;

        Node * cur = head;

        while(cur)
        {
            m[cur] = new Node(cur->val);
            cur=cur->next;
        }

        cur = head;
        while(cur)
        {
            Node * next = cur->next;
            Node * random = cur->random;
            m[cur]->next = m[next];
            m[cur]->random =  m[random];
            cur= cur->next;
        }



        return m[head];        
    }
};
