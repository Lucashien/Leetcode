/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // using fast and slow to judge
        // In the end, fast will trace the slow

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast!=NULL && fast->next!=NULL){
            
            // fast goes 2 step, slow goes 1 step
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow){
                slow = head;
                while (fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL; 
    }
};
