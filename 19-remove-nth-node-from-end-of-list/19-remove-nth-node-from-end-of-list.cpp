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
    int getLen(ListNode*head){
        if(!head)return 0;
        return 1 + getLen(head->next);
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = getLen(head);
        int k = N - n + 1;
        if(k == 1){
            return head->next;
        }
        auto temp = head;
        int currIndex = 1;
        while(currIndex!=k-1){
            temp = temp->next;
            currIndex++;
        }
        auto dele = temp->next;
        temp->next = temp->next->next;
        delete dele;
        return head;
    }
};