<h1><b>Problem</b> - <a href="https://leetcode.com/problems/merge-two-sorted-lists/">Merge Two Sorted Lists</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Traverse both lists at same time, and add `lower-value` nodes to `result`, until no list is empty <br/>
&emsp; 2. When one or both lists are empty, traverse the remaining list and add its nodes to `result`<br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);                  // Make a dummy node for ease
        ListNode *l1 = list1, *l2 = list2, *tmp = dummy;


        while(l1  &&  l2) {                                 // While both lists have remaining nodes
            if(l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        l1 = l1 != NULL ? l1 : l2;                           // Remaining list is assigned to 'l1'

        while(l1) {
            tmp->next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }

        tmp = dummy->next;
        delete dummy;                                        // Free extra memory, so memory leaks don't happen

        return tmp;
    }
};
```
