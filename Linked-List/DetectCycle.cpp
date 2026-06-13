//-------------optimal-----------------
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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* intersect = head;

        while(fast){
            slow = slow -> next;
            fast = fast -> next;
            if(fast) fast = fast -> next;
         //   if(!fast || !slow ) return false;
            if(slow == fast) break;
        }
        if(!fast) return NULL;

        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;

    }
};