//-----------------optimal1 ------------------------
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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* temp1 = a;
        ListNode* temp2 = b;

        while(temp1 != temp2){
            temp1 = (temp1 == NULL) ? b : temp1 -> next;
            temp2 = (temp2 == NULL) ? a : temp2 -> next;
        }

        return temp1;


    }
};


//-----------------optimal2 ------------------------
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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int len1 = len(a);
        int len2 = len(b);

        int diff = abs(len1 - len2);

        ListNode* temp1 = a;
        ListNode* temp2 = b;

        if(len1 > len2){
            for(int i=0; i<diff; i++){
                temp1 = temp1 -> next;
            }
        }
        else{
            for(int i=0; i<diff; i++){
                temp2 = temp2 -> next;
            }
        }

        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        return NULL;


    }

    int len(ListNode *temp){
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp -> next;
        }

        return cnt;
    }
};