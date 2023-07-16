# BINARY TREE

```
        a
    b       c
  d   e   f   g 
```
a b c d e f g  <br>
0 1 2 3 4 5 6

---
```
        a
    b       c
  d   e   
```
a b c d e      <br>
0 1 2 3 4 

--------------------------------
```
        a
    b       c
          d   e 
```
a b c # # d e   <br>
0 1 2 3 4 5 6


--------------------------------

* **node position - i**
* **left child - 2*i+1**
* **right child - 2*i+2**
* **parent - (i-1)/2**

---

# HEAP

- heap is a complete binary tree
- every node is having a value greater/smaller/equal than all its decendants
- if greater/equal than all decendants - *max heap*
- if lesser/equal than all decendants - *mean heap*
- duplicates allowed in heap

---
## Insert operation in max heap

- insert element *x* at the last position
- adjust the heap by
    - swap with parent
    - until parent>x
- time complexity - height of the tree - O(log(n));
- direction of adjustment is upwards
---
## Delete max element in a max heap

- remove the last node and insert it in the root(position of tha max element in the heap)
- now from the root
- compare its two childs and select the greater one
- swap it with the greater of the two
- do it until both childs are smaller 
- heap size reduced by one
- adjustment done from root to leaf
- max time - O()
---
## Intuition of heap sort
- we delete the max element in the heap
- this reduced the heap size by 1, but the arr size is still same
- so the last position in the array is now empty
- we can use this empty space and store the popped out max element in that position
- so, the max element is the prev heap is now in the last position
- similarly if we repeat this for n elements
- we will get a sorted array in non-decreasing order

---
## Heap Sort

- given an array a[] = [15, 20, 15, 30, 50]
- insert one by one and create a max heap
- for inserting n elements that heap creation time will be n(log(n))
- we use the above intuition to sort the array using heap sort

## Heapify (creating a ma)