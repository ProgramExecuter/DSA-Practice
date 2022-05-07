<b>Problem Link</b> - <a href="https://leetcode.com/problems/reverse-linked-list/" target="_blank">Link</a>

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev = NULL, *curr = head;
        while(curr) {
            ListNode* nxt = curr->next;     // Save next NODE
            curr->next = prev;              // Reverse Links
            prev = curr;                    // Save PREV for next node
            curr = nxt;                     // Move ahead
        }
        head = prev;

        return head;
    }
};
```
