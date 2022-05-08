<h1><b>Problem</b> - <a href="https://leetcode.com/problems/remove-duplicates-from-sorted-list/">Remove Duplicates From Sorted List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Make `prev = head` and `curr = head->next`, then traverse the linked list. <br/>
&emsp; 2. Skip the duplicates wherever they are, and point first occurence of duplicate and point it to next value(which is not `curr`'s duplicate). <br/>
&emsp; 3. Free memory of the duplicates, and return new `head`. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return head;

        ListNode *prev = head, *curr = head->next, *del = NULL;

        while(curr) {
            bool dup = false;

            while(curr  &&  curr->val == prev->val) {       // Skip Duplicates
                curr = curr->next;
                dup = true;
            }

            del = prev->next;

            prev->next = curr;                              // Point prev's next to 'curr'

            if(!curr)   break;                              // If list ends, break from loop

            prev = curr;                                    // Make 'curr', prev for next nodes
            curr = curr->next;                              // Move to next node

            if(dup)     delete del;                         // Free memory of duplicate nodes
        }

        return head;
    }
};
```
