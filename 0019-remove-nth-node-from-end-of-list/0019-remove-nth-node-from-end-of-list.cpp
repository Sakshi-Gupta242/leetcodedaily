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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy= new ListNode(-1);
        dummy->next = head;

        ListNode*slow = dummy;
        ListNode* fast = dummy;
    //fast ko n step aage le jaao
        for(int i= 0;i< n;i++){
            fast= fast->next;
        }
       //dono fast and slow ko move karu
       while(fast->next != nullptr){
        slow = slow->next;
        fast= fast->next;
       }
       // nth node delete kar do

       ListNode*temp = slow->next;
       slow->next=slow->next->next;
       delete temp;

       return dummy->next;      
    }
};