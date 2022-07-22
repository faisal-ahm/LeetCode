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
    pair<ListNode*, ListNode*>reverse(ListNode* head){
        ListNode* newTail = head;
        ListNode* prev = NULL;
        ListNode* curr = head; 
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {prev, head};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int j = 1;
        ListNode* end = head;
        while(j != right){
            end = end->next;
            j++;
        }
        ListNode*tempNext = end->next;
        end->next = NULL;
        
        if(left == 1){
            auto ans = reverse(head);
            ans.second->next = tempNext;
            return ans.first;
        }
        
        
        
        ListNode* start = head;
        j = 1;
        while(j+1 != left){
            start = start->next;
            j++;
        }
        auto ans = reverse(start->next);
        ans.second->next = tempNext;
        start->next = ans.first;
        return head;
    }
};