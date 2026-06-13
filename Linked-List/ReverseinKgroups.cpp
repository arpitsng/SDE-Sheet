//---------------optimal----------------------
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = len(head);
        if(n < k) return head;

        int cnt = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr && cnt < k){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        if(forward){
            head -> next = reverseKGroup(forward, k);
        }

        return prev;
    }

    int len(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head -> next;
        }

        return cnt;
    }
};