#include <vector>
#include <iostream>
using namespace std;

// var: val, next
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class LinkedList
{

private:
    ListNode *head;
    ListNode *tail;

public:
    // initial the head and tail
    LinkedList()
    {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index)
    {
        // list start with head->next
        ListNode *cur = head->next;
        for (int i = 0; i <= index; i++)
        {
            if (cur == nullptr)
                return -1;

            if (i == index)
            {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }

    void insertHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;

        // if list is empty
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    void insertTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index)
    {
        if (index < 0 || head == nullptr)
            return false;

        ListNode *cur = head;

        // search pre cur
        int i = 0;
        while (i < index && cur != nullptr)
        {
            i++;
            cur = cur->next;
        }

        // todelet is cur->next
        if (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next == tail)
            {
                tail = cur;
            }
            ListNode *ToDelete = cur->next;
            cur->next = cur->next->next;
            delete ToDelete;
            return true;
        }
        else
        {
            return false;
        }

        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;
        ListNode *cur = head->next;
        while (cur != nullptr)
        {
            values.push_back(cur->val);
            cur = cur->next;
        }
        return values;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->remove(1);
    list->insertHead(1);
    list->insertHead(2);
    list->insertTail(3);
    list->insertHead(4);
    for (int i = 0; i < list->getValues().size(); i++)
    {
        if (i == list->getValues().size() - 1)
        {

            cout << list->getValues()[i] << endl;
        }
        else
        {
            cout << list->getValues()[i] << "->";
        }
    }
    return 0;
}