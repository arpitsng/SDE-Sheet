//-------------------optimal-----------------------
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
public:
    Node* flatten(Node* root) {
        if(!root) return NULL;

        Node* merged = root;
        Node* curr = root->next;

        while(curr) {
            Node* nxt = curr -> next;
            merged = merge(merged, curr);
            curr = nxt;
        }

        return merged;
    }

    Node* merge(Node* h1, Node* h2) {
        Node dummy(-1);
        Node* curr = &dummy;

        while(h1 && h2) {
            if(h1->data <= h2->data) {
                curr->bottom = h1;
                h1 = h1->bottom;
            } else {
                curr->bottom = h2;
                h2 = h2->bottom;
            }

            curr = curr->bottom;
            curr->next = NULL;
        }

        curr->bottom = (h1 ? h1 : h2);

        return dummy.bottom;
    }
};