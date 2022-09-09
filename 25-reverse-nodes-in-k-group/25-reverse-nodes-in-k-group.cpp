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
    int getn(ListNode* head){
        int ans = 0;
        while(head){
            head = head->next;
            ans++;
        }
        return ans;
    }
    ListNode* help(ListNode* head, int k, int n){
        if(n < k) return head;
        ListNode* tail = head;
        int K = k-1;
        while(K--){
            tail = tail->next;
        }
        auto nextHead = tail->next;
        tail->next = NULL;
        auto curr = head;
        ListNode* prev = NULL; ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = help(nextHead, k, n-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getn(head);
        return help(head, k, n);
    }
};