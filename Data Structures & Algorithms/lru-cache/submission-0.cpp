class LRUCache {
public:
    int capacity = 0;
    struct Node
    {
        int key;
        int value;
        Node * next;
        Node * prev;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int ,Node*> m;

    Node * head = new Node(0,0);
    Node * tail = new Node(0,0);



    LRUCache(int _capacity) {
        capacity = _capacity;
        head->prev = tail;
        tail->next = head;
    }

    void remove(Node *n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    void putLast(Node * n)
    {   

        n->prev = tail;
        n->next=tail->next;
        tail->next->prev =n;
        tail->next = n; 
    }

    void deleteFirst()
    {
        Node * n = head->prev;
        n->prev->next = head;
        head->prev = n->prev ;
    }


    
    int get(int key) {

        if(!m.contains(key)) return -1;

        Node * n = m[key];
        remove(n);
        putLast(n);

        return n ->value;
        
    }
    
    void put(int key, int value) {

        if(m.contains(key))
        {   
            Node * n = m[key];
            n->value = value;
            remove(n);
            putLast(n);
            return;
            
        }

        if(m.size()==capacity)
        {
            
            m.erase(head->prev->key);

            Node * n = head->prev;
            remove(head->prev);
            if(n!= tail) delete(n);

        }

        Node * n = new Node(key,value);
        putLast(n);
        m[key] = n;
    
    }
};
