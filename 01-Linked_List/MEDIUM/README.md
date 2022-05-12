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
  <tr>
      <td>06</td>
      <td><a href="#6">Split Linked List In Parts</a></td>
      <td></td>
  </tr>
  <tr>
      <td>07</td>
      <td><a href="#7">Design Linked List</a></td>
      <td>Design</td>
  </tr>
  <tr>
      <td>08</td>
      <td><a href="#8">Remove Zero Sum Consecutive Nodes From Linked List</a></td>
      <td>Hash-Table</td>
  </tr>
  <tr>
      <td>09</td>
      <td><a href="#9">Add Two Numbers</a></td>
      <td>Two-Pointers, Math</td>
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

<br/><br/><br/><br/><br/>

<div id="6">

<h1><b>Problem</b> - <a href="https://bit.ly/3LbyBpC">Split Linked List In Parts</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Calculate size of linked list. <br/>
&emsp; 2. We get minimum required length of each list by `reqLen = len / k`, and extra length by `extra = len % k`. <br/>
&emsp; 3. We have to add 1 extra node at starting lists, until `extra` reaches 0. <br/>
&emsp; 4. Finally we add empty lists, if we used up all the nodes in the list, so that we can have `k` lists.
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

```
class Solution {
public:
    int getLen(ListNode* head) {
        ListNode *tmp = head;
        int len = 0;

        while(tmp) {
            ++len;
            tmp = tmp->next;
        }

        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLen(head);                             // Get size of list

        int reqLen = len / k;                               // Each list must have atleast these no. of nodes
        int extra  = len % k;                               // We add 1 extra node to starting lists, until 'extra' becomes 0

        vector<ListNode*> res;

        ListNode *curr = head;

        while(curr) {
            int currLen = reqLen + (extra ? 1 : 0);

            if(extra)   --extra;                            // Decrease 'extra', as we used 1

            ListNode *tmp = curr, *nxt = NULL;
            while(--currLen)                                // Reach last node of this list
                tmp = tmp->next;

            nxt = tmp->next;                                // Break link from this list's end to forward
            tmp->next = NULL;

            res.push_back(curr);                            // Push this list to 'res'

            curr = nxt;                                     // Move ahead, for next list
        }

        while(res.size() < k)                               // Push NULL list for remaining lists
            res.push_back(NULL);

        return res;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="7">

<h1><b>Problem</b> - <a href="https://bit.ly/3l5jAe6">Design Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. <b>get</b>
&emsp; &emsp; a. Reach `index` node, by `while(index--)`, if we reach `index` then `curr` will not be `NULL`, else it will be `NULL`.
&emsp; 2. <b>addAtHead</b>
&emsp; &emsp; a. Simply push new Node at head by `newNode->next = head`, `head = newNode`.
&emsp; 3. <b>addAtTail</b>
&emsp; &emsp; a. Reach last node by `while(curr->next)`, and then append the new Node, to last node's next
&emsp; 4. <b>addAtIndex</b>
&emsp; &emsp; a. Reach required index's previous node, then add the new Node after that 'previous node'.
&emsp; &emsp; b. Use `dummy` node for ease.
&emsp; 5. <b>deleteAtIndex</b>
&emsp; &emsp; a. Reach required index's previous node, then delete node after that 'previous node'.
&emsp; &emsp; b. Use `dummy` node for ease.
<br/>

<b><u>Time Complexity</u></b> - [get - O(N)], [addAtHead - O(1)], [addAtTail - O(N)], [addAtIndex - O(N)], [deleteAtIndex - O(N)] <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Node {
public:
    int val;
    Node* next = NULL;

    Node(int val) {
        this->val = val;
    }
};
class MyLinkedList {
    Node* head;
public:
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        if(index < 0)   return -1;                  // Invalid -ve index

        Node* curr = head;
        while(index--  &&  curr)                    // Search for 'index' node
            curr = curr->next;

        if(curr == NULL)                            // Index is greater than nodes available
            return -1;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;                       // Put 'newNode' before previous head node
        head = newNode;                             // And make 'newNode' as 'head'
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(!head) {                                 // This is first node to be inserted, thus becomes 'head'
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr->next)                           // Reach last node
            curr = curr->next;

        curr->next = newNode;                       // Append 'newNode' to last of list
    }

    void addAtIndex(int index, int val) {
        if(index < 0)                               // Invalid -ve index
            return;

        Node *newNode = new Node(val);

        Node *dummy   = new Node(0);                // Add 'dummy' at start for ease
        dummy->next = head;

        Node *curr = dummy;

        while(curr  &&  index--)                    // Reach 1-node before 'index' node
            curr = curr->next;

        if(curr == NULL)                            // List size is less than required index
            return;

        newNode->next = curr->next;                 // Insert node after 'curr'
        curr->next = newNode;

        head = dummy->next;                         // Re-assign 'head' if needed

        delete dummy;
    }

    void deleteAtIndex(int index) {
        if(index < 0)                               // Invalid -ve index
            return;

        Node *dummy   = new Node(0);                // Add 'dummy' at start for ease
        dummy->next = head;

        Node *curr = dummy;

        while(curr  &&  index--)                    // Reach 1-node before 'index' node
            curr = curr->next;

        if(!curr  ||  !curr->next)                  // List size is less than required index
            return;                                 // or the node at given index is 'NULL'

        Node* del = curr->next;

        curr->next = curr->next->next;              // Remove pointer, pointing to 'index' node, and
        delete del;                                 // then remove it from list and memory

        head = dummy->next;                         // Re-assign 'head' if needed

        delete dummy;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="8">

<h1><b>Problem</b> - <a href="https://bit.ly/3w5I0KT">Remove Zero Sum Consecutive Nodes from Linked List</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. Use prefix sum technique, take sum until each node while traversing the linked list, and put it in `map`. <br/>
&emsp; 2. If we encounter a sum again, then it means starting from `previous sum's encounter node`(means node where we encountered this sum previosly)'s next node until `curr` node, this whole sub-list produced `0` sum. <br/>
&emsp; 3. We remove this sub-list from list, and their related sub-part's entries in map <br/>
&emsp; 4. While removing such sub-lists, we get our result. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(N)</b> <br/>

```
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> mp;
        int sum = 0;

        ListNode *dummy = new ListNode(0);                              // Use 'dummy' node for ease
        dummy->next = head;

        ListNode* curr = dummy;
        while(curr) {
            sum += curr->val;

            if(mp.find(sum) == mp.end()) {                              // This is first time this sum occuring
                mp[sum] = curr;
            }
            else {
                curr = mp[sum]->next;

                int tmp = sum + curr->val;                              // Remove the sub-list which produced 0 sum
                while(tmp != sum) {
                    mp.erase(tmp);
                    curr = curr->next;
                    tmp += curr->val;
                }

                mp[sum]->next = curr->next;                             // Deleting list starts from start point's next node
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};
```

</div>

<br/><br/><br/><br/><br/>

<div id="8">

<h1><b>Problem</b> - <a href="https://bit.ly/3sqhmu3">Add Two Numbers</a></h1>

<h3><b><u>Approach 1</u></b></h3>

&emsp; 1. We take `dummy` node, and we will get summed list's `head` in `dummy->next`. <br/>
&emsp; 2. We traverse the lists until any of them hasn't reached end, then we add both lists's current node and `carry`. We then assign this value to `l1`'s current if it's `!NULL`, else assign it to `l2`'s current node. <br/>
&emsp; 3. We do this until both of the lists reach end, after it if `carry != 0`, then we add a new node(last node) to the resultant sum-list, which contains `carry`'s value. <br/>
<br/>

<b><u>Time Complexity</u> - O(N)</b> <br/>
<b><u>Space Complexity</u> - O(1)</b> <br/>

<caption>
<b>!! </b><i style="font-size: 0.75rem">Here we are given reversed lists, and we also have to return reversed list, so no need for reversing list.</i>
</caption>
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);

        ListNode* curr = dummy;
        int carry = 0;

        while(l1  ||  l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;      // Add numbers in nodes which aren't NULL

            carry = sum / 10;                                               // Get new carry & sum
            sum = sum % 10;

            l1 ? l1->val = sum : l2->val = sum ;                            // sum is assigned to "l1" if it's !NULL, else assigned to "l2"

            curr->next = l1 ? l1 : l2;                                      // Point next to "l1" it it's !NULL, else point to "l2"

            l1 ? l1 = l1->next : NULL ;
            l2 ? l2 = l2->next : NULL ;

            curr = curr->next;                                              // Move ahead
        }

        if(carry > 0) {                                                     // 'carry` is not 0, we add last node
            ListNode* lastNode = new ListNode(carry);
            curr->next = lastNode;
        }

        l1 = dummy->next;                                                   // l1 is 'head' of summed-list
        delete dummy;

        return l1;
    }

};

</div>
