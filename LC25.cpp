class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy, *end = dummy;
        while(true) {
            for(int i = 0; i < k && end; i++) {
                end = end->next;
            }
            if(!end) break;

            ListNode *startNext = start->next;
            ListNode *endNext = end->next;

            end->next = nullptr;
            start->next = reverse(start->next);
            startNext->next = endNext;
            start = end = startNext;
        }
        return dummy->next;
    }
}
