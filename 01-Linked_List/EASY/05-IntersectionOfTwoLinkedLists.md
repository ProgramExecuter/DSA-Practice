<h1><b>Problem</b> - <a href=""></a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Take list1(`l1`), list2(`l2`) and `onceA`, `onceB` for making sure we switch only once. <br/>
&emsp; 2. Start both pointers from their respective lists, and switch to other list(only once) if we reached current list's end. <br/>
&emsp; 3. Compare two pointers if they were same, if they were we found `intersection`, else there wasn't any intersection b/w two lists. <br/>
<br/>

<b><u>Time Complexity</u> - O(N + M)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;

        bool onceA = false, onceB = false;      // We don't want to switch between list1 and list2 regularly, when there's nothing to intersect
                                                // So we only switch once

        while(l1 != l2) {
            if(!l1->next && !onceA) {           // If the 'l1' reached its end and this is first switch, then continue from head of 'l2'
                onceA = true;
                l1 = headB;
            }
            else {
                l1 = l1->next;
            }

            if(!l2->next && !onceB) {            // If the 'l2' reached its end and this is first switch, then continue from head of 'l1'
                onceB = true;
                l2 = headA;
            }
            else {
                l2 = l2->next;
            }
        }

        if(l1 != l2)    return NULL;              // No Intersection

        return l1;
    }
};
```
