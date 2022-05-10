<table>
<tr>
    <th>Problem</th>
    <th>Tags</th>
</tr>
<tr>
    <td><a href="#1">Reverse A Linked List</a></td>
    <td>Stack</td>
</tr>
<tr>
    <td><a href="#2">Middle Of Linked List</a></td>
    <td>Two Pointer</td>
</tr>
<tr>
    <td><a href="#3">Linked List Cycle</a></td>
    <td>Two Pointer, Hash-Table</td>
</tr>
<tr>
    <td><a href="#4">Merge Two Sorted List</a></td>
    <td>Two Pointer</td>
</tr>
<tr>
    <td><a href="#5">Intersection Of Two Linked List</a></td>
    <td>Two Pointer</td>
</tr>
<tr>
    <td><a href="#6">Remove Duplicates From Sorted List</a></td>
    <td>Two Pointer</td>
</tr>
<tr>
    <td><a href="#7">Palindrome</a></td>
    <td>Stack, Two Pointer</td>
</tr>
</table>

<div id="1">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/reverse-linked-list/">
Reverse A Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Traverse the linked list <br/>
&emsp; 2. Then put each node into the stack <br/>
&emsp; 3. Then pop the nodes from stack and make them point to next popping node <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* tmp = head;

        while(tmp) {                        // Put all nodes into the stack
            st.push(tmp);
            tmp = tmp->next;
        }

        ListNode* dummy = new ListNode(0);  // Dummy node for making easier

        tmp = dummy;
        while(!st.empty()) {
            tmp->next = st.top();           // Point to popped node, and pop it from stack
            st.pop();
            tmp = tmp->next;                // Move to next node
        }
        tmp->next = NULL;                   // Make last node's next = NULL

        return dummy->next;                 // Dummy's next always contains the HEAD
    }

};
```

<br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. `prev = NULL`, previous node is <u>NULL</u> at start<br/>
&emsp; 2. Traverse the linked list <br/>
&emsp; 3. Reverse the links, i.e. make previous node as current node's <i>next</i><br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

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

</div>

<br/><br/><br/><br/><br/>

<div id="2">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/middle-of-the-linked-list/">Middle Of Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Take two pointer `fast` and `slow` <br/>
&emsp; 2. `fast` moves 2X as fast as `slow`<br/>
&emsp; 3. So when `fast` reaches end, `slow` reaches middle<br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="3">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/linked-list-cycle/">Linked List Cycle</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Traverse each node, and put it into a `set`<br/>
&emsp; 2. If we find a node that is already present in the set, then this linked list has a cycle <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;

        ListNode* tmp = head;

        while(tmp) {
            if(st.find(tmp) != st.end())        // This node is already been visited so there's a cycle
                return true;

            st.insert(tmp);                     // Insert this node to 'set', then move ahead
            tmp = tmp->next;
        }

        return false;
    }
};
```

<br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. Take two pointer `fast` and `slow`.<br/>
&emsp; 2. `fast` moves 2X faster than `slow`<br/>
&emsp; 3. So, if these two meet, then linked list has cycle<br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL  ||  head->next == NULL)        // If the list has 0 or 1 node only
            return false;

        ListNode *slow = head, *fast = head;

        while(fast  &&  fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)                            // If these pointers meet then there's a cycle
                return true;
        }

        return false;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="4">

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

</div>

<br/><br/><br/><br/><br/>

<div id="5">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/">Intersection Of Two Linked List</a></h1>

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

</div>

<br/><br/><br/><br/><br/>

<div id="6">

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

</div>

<br/><br/><br/><br/><br/>

<div id="7">

<h1><b>Problem</b> - <a href="https://leetcode.com/problems/palindrome-linked-list/">Palindrome Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Find middle of linked list using <b>turtoise-hare</b> method, and push first half of list's values in the stack. <br/>
&emsp; 2. If fast becomes `NULL` after loop, then list is of even-length, else odd-length `bool flag = fast ? true : false` <br/>
&emsp; 3. If `flag == true` then move the `slow` by 1 position(skip real middle of odd-length list). <br/>
&emsp; 3. Now compare stack's values with `slow`'s values, to check for palindrome condition. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;

        ListNode *slow = head, *fast = head;

        while(fast  &&  fast->next) {
            st.push(slow->val);                     // Push the first half list's values
            slow = slow->next;
            fast = fast->next->next;
        }

        bool flag = fast ? true : false;            // If fast != NULL, then list is odd length, else if is of even length

        if(flag)    slow = slow->next;              // If the list is of odd length, then move 'slow' ahead by 1 for starting comparisons

        while(!st.empty()) {
            if(slow->val != st.top())               // Not a palindrome
                return false;

            st.pop();
            slow = slow->next;
        }

        return true;
    }
};
```

<br/><br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. Find middle of the linked list starting from 2nd node(1-indexed), so that we can implement for both(odd & even) lengths `list`. <br/>
&emsp; 2. Reverse the second half of the linked list. <br/>
&emsp; 3. Compare both the halves until one of them reaches `NULL`. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *nxt = NULL;

        while(curr) {
            nxt = curr->next;                               // Save 'next'
            curr->next = prev;                              // Reverse link
            prev = curr;                                    // Save 'prev' for next Node
            curr = nxt;                                     // Move ahead
        }

        return prev;                                        // New head
    }
    bool isPalindrome(ListNode* head) {
        if(!head  ||  !head->next)                          // If noOfNodes <= 1, return TRUE
            return true;

        ListNode *slow = head->next, *fast = head->next;
        ListNode *prev = head;

        while(fast && fast->next) {                         // Get middle of list, for both(odd & even length)
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = reverseList(slow);                     // Reverse 2nd half of list
                                                            // and point prev's next to reversed list's head

        slow = head, fast = prev->next;                     // Now both of the halves of list are at their heads

        while(slow  &&  fast) {
            if(slow->val  !=  fast->val)                    // Not a palindrome
                return false;

            slow = slow->next;
            fast = fast->next;
        }

        prev->next = reverseList(prev->next);               // Reverse back the list, to get original list

        return true;
    }
};
```

</div>
