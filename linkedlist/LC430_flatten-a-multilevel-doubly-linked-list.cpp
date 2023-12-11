// O(n)
// O(n)
class Solution {
public:
    Node* flatten(Node* head) {
        auto dfs = [&](Node* node) {
            Node* cur = node;
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;
                if (cur->child) {
                    Node* child_last = dfs(cur->child);

                    next = cur->next;

                    // connect node and child
                    cur->next = child;
                    cur->child->prev = cur;

                    // next not null, connect last and next
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    cur->child = nullptr;
                    last = child_last;
                } else {
                    last = cur;
                }
                cur = next;
            }
            return last;
        };

        dfs(head);
        return head;
    }
};
