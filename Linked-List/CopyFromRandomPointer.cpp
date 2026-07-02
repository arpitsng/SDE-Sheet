//--------------Brute FOrce------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        unordered_map<Node*, Node*> copy;

        Node* temp = head;
        while(temp){
            copy[temp] = new Node(temp -> val);
            temp = temp -> next;
        }

        temp = head;
        while(temp){
            if(temp -> random) {
                copy[temp] -> random = copy[temp -> random];
                
            }
            else copy[temp] -> random = NULL;
            copy[temp] -> next = copy[temp -> next];

            temp = temp -> next;
        }

        return copy[head];
    }
};


//--------------Optimal Approach-----------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        //step 1: place copied nodes in between the org node and its next node
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp -> val);
            copy -> next = temp -> next;
            temp -> next = copy;

            temp = temp -> next -> next;
        }

        //step 2: connect Random pointers
        temp = head;
        while(temp){
            if(temp -> random) temp -> next -> random = temp -> random -> next;
            
            temp = temp -> next -> next;
        }

        //step 3: connect next pointers and separate copy and org list
        temp = head;
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while(temp){
            curr -> next = temp -> next;
            temp -> next = temp -> next -> next;

            temp = temp -> next;
            curr = curr -> next;
        }

        return dummy -> next;
    }
};