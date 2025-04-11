/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* merge(Node* list1, Node* list2) {
        Node *head1 = list1, *head2 = list2;
        Node* dummy = new Node(-1);  
        Node* temp = dummy;
        
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1->prev = temp;  
                temp = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2->prev = temp;  
                temp = head2;
                head2 = head2->next;
            }
        }
        if (head1) {
            temp->next = head1;
            head1->prev = temp;
        } else {
            temp->next = head2;
            head2->prev = temp;
        }
        
        Node* result = dummy->next; 
        if (result) result->prev = NULL;  
        delete dummy;  
        return result;
    }

    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* childList = flatten(curr->child);
                curr->child = NULL;  
                
                Node* nextNode = curr->next;
                curr->next = childList;  
                childList->prev = curr;
                
                while (curr->next) curr = curr->next;
                curr->next = nextNode;  
                if (nextNode) nextNode->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
