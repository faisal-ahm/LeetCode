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
    int length(ListNode *head) {

    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

        ListNode* reverseLL(ListNode* head){
    ListNode* current = head;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }
        int n = length(head);
        int halflen = n/2;
        auto tail1 = head;
        
        for(int i = 1; i < n/2; i++){
            tail1 = tail1->next;
        }
        auto head2 = tail1->next;
        tail1->next = NULL;
        head2 = reverseLL(head2);
        auto head1 = head;
        while(head1 && head2){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};