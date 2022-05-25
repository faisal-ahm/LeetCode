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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*curr = head;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(curr){
            if(curr->val == val){
                auto tempNext = curr->next;
                delete curr;
                if(prev){
                    prev->next = tempNext;
                }
                curr = tempNext;
            }else{
                if(!prev){
                    newHead = curr;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return newHead;
    }
};