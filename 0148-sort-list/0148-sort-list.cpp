class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left != NULL)
            temp->next = left;

        if (right != NULL)
            temp->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge
        return merge(left, right);
    }
};