#define CTCL_CHAPTER_TWO_H

#include <iostream>

class List
{
    public:
        class Node
        {
        public:
            Node() : next(nullptr), data() {};
            Node(int d) : next(nullptr), data(d) {};
            ~Node();

            Node* next;
            int data;

        };

        List() : head(nullptr) {}
        ~List() 
        {
            while(head)
            {   
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }

    void print()
    {
        Node* cur = head;
        while (cur)
        {
            std::cout << cur->data << " ";

            cur = cur->next;
        }
    }


    void append(int d)
    {
        Node* end = new Node(d);
        Node* cur = head;

        if (!head)
        {
            head = end;
            return;
        }

        while(cur->next)
            cur = cur->next;

        cur->next = end;
    }

    void remove(Node* n)
    {
        Node* cur = head;
        while (cur)
        {
            if (cur->next == n)
            {
                cur->next = n->next;
                break;
            }

            cur = cur->next;
        }
    }

    Node* find(int d)
    {
        Node* cur = head;
        while (cur)
        {
            if (cur->data == d)
                break;
            
            cur = cur->next;
        }

        return cur;
    }

    

    private:
        Node* head;
};
