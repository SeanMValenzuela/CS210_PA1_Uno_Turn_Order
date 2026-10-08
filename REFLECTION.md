# Reflection Questions
### 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?
concat only needs to work between two lists of the same representation because concat is written differently
for the ArrayList implementation and the LinkedList implementation. This is mainly due to the fact that concat for ArrayList
copies each item of the new list and adds them one by one to the old list. However, on the other hand, concat for LinkedList simply
connects the two lists by making the last item of the old list's next pointer point to the head of the new list. As the program stands,
it is impossible to concatenate an ArrayList with a LinkedList as their methods of connection differ due to their respective features, 
but if one wanted to make it work, one way would be creating a method that converts one into the other.

### 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.
In reverse() for a LinkedList, the three pointers you need alive at once are: current, previous, and follow. current keeps track of the
node that is due to be reversed, previous keeps track of the node that should come before current after the reversal, and follow is essentially
a temp node that keeps track of the node that was originally after current prior to the reversal. Losing track of any one of these pointers corrupts the list 
as they are all necessary in keeping every node of the LinkedList accessible, as LinkedLists are only able to be traversed through the head and its successive pointers.

### 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?
For addAnywhere, position has to be less than or equal to size_ but also greater than or equal zero, with the ArrayList implementation explicitly checking both of these
conditions, while the LinkedList implementation does not explicitly check if position is less than or equal to size_, and rather handles that indirectly through the while-loop. 
A position passed outside the range would print out a statement saying it is an invalid index/position and return, leaving the list unaffected. For deleteAnywhere in both implementations, position has to be
greater than or equal to zero as well but this time, strictly less than size_. A position passed outside the range would print out an invalid index/position statement and return here as well, and similarly to addAnywhere, 
the LinkedList implementation does not explicitly check if position is strictly less than size_ and handles that separately.

### 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
In LinkedList::concat, we needed to walk to the end of the list first as LinkedList does not track a tail pointer, requiring us to traverse through the entire list starting from the head to reach the end, where we would change the last node’s pointer point to the head of the other list, linking the two together. 
addFront and deleteFront never needed to walk to the end of the list first as they simply only required to change what the head was pointing to, which is the first node we look at when traversing through a LinkedList. 
If LinkedList still tracked a tail pointer, concat would be much more efficient (going from O(n) to O(1)) as we could go directly to the end of the list and perform the pointer swap right away. 
If one was added back, the old list’s tail would need to be updated to the other list’s tail.

### 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.
For addAnywhere in ArrayList, the current item at the position the new item is to be placed in and the items that follow it shift to the right.
One important thing to note is that this does not outright create the space empty, as we are simply copying elements over by one index, so the original item is still in that position.
However, it does allow us to overwrite it as it has already been copied over to the next, making it safe to do so. 
Shifting in the wrong direction would overwrite data you still need as an item would take the place of another item, but that other item would not be saved in some way, making it completely inaccessible and therefore, impossible to shift it as well.

### 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.
The reverse sequence of my main.cpp takes place in lines 43-49, with reverse being called specifically in line 46. 
If that call were missing, a reverse card is hypothetically played but does not actually reverse the direction of play, 
messing up the turn order by causing turns to continue in the same direction rather than the opposite.