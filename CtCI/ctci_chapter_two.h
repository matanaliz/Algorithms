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
            ~Node() = default;

            Node* next;
            int data;

        void print()
        {
            std::cout << data << " ";
        }

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
            cur->print();
            cur = cur->next;
        }

        std::cout << std::endl;
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

    void remove_all(int d)
    {
        remove_all(head, d);
    }

    void remove_all(Node* n, int d)
    {
        Node* cur = n;
        while (cur->next)
        {
            if (d == cur->next->data)
            {
                Node* tmp = cur->next->next;
                // Remove all trailing nodes
                while (tmp && tmp->data == d)
                    tmp = tmp->next;
                cur->next = tmp;
            }

            cur = cur->next;
        }
    }

    Node* find(int d)
    {
        return find_after(head, d);
    }

    Node* find_after(Node* n, int d)
    {
        Node* cur = n;
        while (cur)
        {
            if (d == cur->data)
                break;

            cur = cur->next;
        }
        
        return cur;
    }

    void remove_duplicates()
    {
        Node* cur = head;
        while (cur)
        {
            remove_all(cur, cur->data);
            cur = cur->next;
        }
    }

    Node* kth_last(int k)
    {
        Node* tmp = head;
        // Shift temp pointer for k steps
        while (k-- && tmp)
            tmp= tmp->next;

        if (k > 0)
            return nullptr;
        
        Node* cur = head;
        while (tmp)
        {
            tmp = tmp->next;
            cur = cur->next;
        }

        return cur;
    }

    void partition(int x)
    {
        Node* tail = nullptr;

        Node* cur = head;
        Node* prev = nullptr;
        while (cur)
        {
            if (cur->data >= x)
            {
                if (!tail)
                {
                    tail = cur;
                    cur = cur->next;
                }
                else
                {
                   Node* tmp = tail;
                   while (tmp->next)
                       tmp = tmp->next;

                   if (prev)
                   {
                       prev->next = cur->next;
                       prev = cur->next;
                   }

                   tmp->next = cur;
                   tmp->next->next = nullptr;
                }
            }

        }

        Node* tmp = head;
        while (tmp->next)
            tmp = tmp->next;

        tmp->next = tail;
    }

    private:
        Node* head;
};
