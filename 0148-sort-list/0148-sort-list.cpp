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
    ListNode* sortList(ListNode* head) {

        // 0 or 1 node
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two halves
        ListNode* right = slow->next;
        slow->next = NULL;

        ListNode* left = head;

        // Sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Attach remaining nodes
        if (left != NULL)
            temp->next = left;
        else
            temp->next = right;

        return dummy.next;
    }
};