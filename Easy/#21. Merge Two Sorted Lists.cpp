#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp;
        ListNode *head;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val)
        {
            head = l1;
            l1 = l1->next;
            head->next = NULL;
        }
        else
        {
            head = l2;
            l2 = l2->next;
            head->next = NULL;
        }
        temp = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
                temp->next = NULL;
                continue;
            }
            if (l1->val > l2->val)
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
                temp->next = NULL;
                continue;
            }
        }
        temp->next = l1 == NULL ? l2 : l1;
        return head;
    }
};

int main(int argc, const char *argv[])
{
    ListNode *p;
    ListNode test(5);
    p = &test;
    std::cout << p->val << ' ' << p->next << std::endl;
    return 0;
}
