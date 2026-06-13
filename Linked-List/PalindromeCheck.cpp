//----------------optimal----------------------
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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        mid = slow;
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLL(mid);

        while(temp2){
            if(temp1 -> val != temp2 -> val) return false;

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = head;

        while(forward){
            forward = forward -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

};