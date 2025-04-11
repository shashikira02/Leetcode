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
    void insertInbetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextEle = temp->next;
            Node* copy = new Node(temp->val);

            copy->next = nextEle;
            temp->next = copy;
            temp = nextEle;
        }
    }
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }
            else copy->random = NULL;

            temp = temp->next->next;
        }
    }
    Node* getdeepCopyList(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL){
            res->next =temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
       insertInbetween(head);
       connectRandomPointers(head);
       return getdeepCopyList(head);
    }
};