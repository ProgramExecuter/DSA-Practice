<table>
  <tr>
      <th>No.</th>
      <th>Problem</th>
      <th>Tags</th>
  </tr>
  <tr>
      <td>01</td>
      <td><a href="#1">Swap Nodes In Pairs</a></td>
      <td>Recursion</td>
  </tr>
  <tr>
      <td>02</td>
      <td><a href="#2">Copy List With Random Pointer</a></td>
      <td>Hash-Table</td>
  </tr>
  <tr>
      <td>03</td>
      <td><a href="#3">Insertion Sort List</a></td>
      <td>Sorting</td>
  </tr>
  <tr>
      <td>04</td>
      <td><a href="#4">Odd Even Linked List</a></td>
      <td>3-Pointer</td>
  </tr>
  <tr>
      <td>05</td>
      <td><a href="#5">Swapping Nodes In a Linked List</a></td>
      <td>Pointer, 2-Pointer</td>
  </tr>
</table>

<br/><br/><br/><br/><br/>

<div id="1">

<h1><b>Problem</b> - <a href="https://bit.ly/3suNH2W">Swap Nodes In Pairs</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Save 2nd nodes in current pair, then point 1st node's `next` to head of remaining swapped list. <br/>
&emsp; 2. Point 2nd node's `next` to 1st node. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)                // If 0 or 1 Nodes
            return head;

        ListNode *temp = head->next;            // Save 2nd node of current group of 2
        head->next = swapPairs(temp->next);     // Point HEAD's next to next group's head
        temp->next = head;                      // Point 2nd node of current group's 'next' to 'head'(1st node of curr. group)

        return temp;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="2">

<h1><b>Problem</b> - <a href="https://bit.ly/3L2XDaf">Copy List With Random Pointer</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. In 1st pass, make `new` node for each `original` node, and make its their pair entry in a map. <br/>
&emsp; 2. In 2nd pass, assign `next` and `random` pointers to each new node. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)                                                           // No node, RETURN
            return NULL;

        map<Node*, Node*> mp;

        Node *curr = head, *newHead = NULL;

        while(curr) {
            Node* tmp = new Node(curr->val);                                // Make 'new' list's nodes
            mp[curr] = tmp;                                                 // Map 'old' nodes to 'new' nodes

            curr = curr->next;
        }

        newHead = mp[head];                                                 // Get new 'head'

        curr = head;
        while(curr) {
            mp[curr]->next   = curr->next   ? mp[curr->next]   : NULL;      // Point 'new' node's 'next' and 'random' correctly
            mp[curr]->random = curr->random ? mp[curr->random] : NULL;

            curr = curr->next;
        }

        return newHead;
    }
};
```

<br/><br/>

<h3><b><u>Approach 2</u></b></h3>

&emsp; 1. In 1st pass, make new `nodes`, and put them just after the 'original' `nodes`. <br/>
&emsp; 2. In 2nd pass, make `random` of new nodes point to original node's `next`, because that's where its equivalent new node is present.<br/>
&emsp; 3. In 3rd pass, separate the `new` and `original` lists. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)                                       // No node, RETURN
            return NULL;

        Node *tmp = head;

                while(tmp) {                            // Insert new(temporary) Nodes in between
            Node *newNode, *nxt = tmp->next;

                    newNode = new Node(tmp->val);       // Create New Node

                    newNode->next = tmp->next;          // Insert the New Node after original Node
            tmp->next = newNode;

                    tmp = nxt;                          // Move ahead
        }

        tmp = head;

        while(tmp) {                                    // Make 'random' pointers for new Nodes, by copying the previous node's 'random'

            if(tmp->random == NULL)                     // Make pointer to correct 'random'
                tmp->next->random = NULL;
            else
                tmp->next->random = tmp->random->next;

            tmp = tmp->next->next;                      // Move to next 'original' node
        }

        tmp = head;
        Node *newHead = head->next;

        while(tmp) {                                    // Get the original and new list
            Node *nxt = tmp->next->next;

            if(nxt)                                     // Make 'next's of New Nodes
                tmp->next->next = nxt->next;
            else
                tmp->next->next = NULL;

            tmp->next = nxt;                            // Make the original list
            tmp = nxt;
        }

        return newHead;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="3">

<h1><b>Problem</b> - <a href="https://bit.ly/3MXwJSy">Insertion Sort List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Remove the node from current list, and insert it into sorted list <br/>
&emsp; 2. Perform this by traversing the list, and removing nodes from this list and putting it in `dummy` list. <br/>
<br/>

<b><u>Time Complexity</u> - O(N<sup>2</sup>)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    void insertionSort(ListNode* &dummy, ListNode *x) {
        ListNode *curr = dummy;

        while(curr->next) {                                             // Find the node whose next node's value >= (to-be-inserted) node's value
            if(curr->next->val >= x->val)
                break;

            curr = curr->next;
        }

        x->next = curr->next;                                           // Insert (to-be-inserted) node between 'curr' node and its next node
        curr->next = x;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0), *tmp = new ListNode(0);
        tmp->next = head;

        while(tmp->next) {
            ListNode *x = tmp->next;                                    // Remove this node from current list
            tmp->next = tmp->next->next;

            insertionSort(dummy, x);                                    // Insert this node in sorted list
        }

        return dummy->next;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="4">

<h1><b>Problem</b> - <a href="https://bit.ly/3PgcnpC">Odd Even Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Create two lists `odd` and `even`. <br/>
&emsp; 2. Traverse the main list, then put odd-indexed nodes in `odd` list, and even-indexed nodes in `even` list. (1-indexed) <br/>
&emsp; 3. Finally the last node of `odd` list points to first node of `even` list. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0), *even = new ListNode(0);
        ListNode *curr = head, *currO = odd, *currE = even;
        int idx = 1;

        while(curr) {
            ListNode *nxt = curr->next;                                 // Save 'next'

            curr->next = NULL;                                          // Make 'next' of this node = NULL
            if(idx%2 == 1) {                                            // If the node is even-indexed then push it to even list else push it to odd list
                currO->next = curr;
                currO = currO->next;
            }
            else {
                currE->next = curr;
                currE = currE->next;
            }

            curr = nxt;
            ++idx;
        }

        currO->next = even->next;                                       // Link (odd list) -> (even list)

        return odd->next;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="5">

<h1><b>Problem</b> - <a href="https://bit.ly/3vZonEd">Swapping Nodes In a Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Find k-th node from beginning using `while(--k)`. <br/>
&emsp; 2. By moving previous pointer until it is at end of list, since it is k-ahead from current pointer, we get k-th node from end. <br/>
&emsp; 3. Finally swap values of both nodes. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head;
        ListNode *kth = NULL;

        while(--k)                                  // Find first node(k-th from beginning)
            ptr1 = ptr1->next;

        kth = ptr1;
        ptr1 = ptr1->next;

        while (ptr1) {                              // Find second node(k-th from end)
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        swap(ptr2->val, kth->val);                  // Swap both node's values

        return head;
    }
};
```

<br/><br/>

<h3><b><u>Approach 2(<a href="https://bit.ly/3N2BB8Y">ref</a>)</u></b></h3>

&emsp; 1. Here concept is same for finding the `first`(k-th node from begin) and `second`(k-th node from end) nodes. <br/>
&emsp; 2. Then after getting pointers to these nodes, we swap their incoming pointers first. <br/>
&emsp; 3. Then we swap outgoing pointer. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

<caption>
<b>!! </b><i style="font-size: 0.75rem">If we don't use pointer-to-pointer(**), then we will have to handle many edge cases</i>
</caption>

```
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode **a = &head;

        while(--k) {                                    // Find k-th node from beginning
            a = &(*a)->next;
        }

        ListNode **b = &head, **x = &(*a)->next;
                                                        // Find k-th node from end by using 2-pointer
        while(*x) {                                     // We move x(which is 'k' steps ahead) and 'b'(which is at start), thus we get k-th node from end
            x = &(*x)->next;
            b = &(*b)->next;
        }

        swap(*a, *b);                                   // Now first swap incoming pointers to both the nodes
        swap((*a)->next, (*b)->next);                   // Then swap outgoing pointers to both the nodes

        return head;
    }
};
```

</div>
