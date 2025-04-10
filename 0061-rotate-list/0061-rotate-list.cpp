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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)return head;

        // Calculate the length of the list
        int length=1;
        ListNode* tail =head;
        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }

        // Update k to avoid unnecessary rotations
        k = k % length;
        if( k % length == 0)return head;

        //connecting the tail to head making a loop
        tail->next = head;  
        
        // Find the new tail: (length - k) steps from the head
        ListNode* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }
        // The new head is the next node after the new tail
        head = newTail->next;
         // The new head is the next node after the new tail
        newTail->next = NULL;

        return head;
    }
};