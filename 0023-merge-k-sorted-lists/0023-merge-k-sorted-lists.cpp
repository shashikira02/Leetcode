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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; 
        if (lists.size() == 1) return lists[0];

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;

        for(int i =0;i<lists.size();i++){
           if(lists[i] != nullptr)pq.push({lists[i]->val,lists[i]});
        }

        auto dNode = new ListNode(-1);
        auto temp = dNode;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            temp->next = p.second;
            temp = temp->next;
            if(p.second->next != nullptr){
                pq.push({p.second->next->val,p.second->next});
            }
        }
        return dNode->next;
    }
};