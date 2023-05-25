# Push_swap
Coding a program that can sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The possible moves used to sort the stack are:
<p>
- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
<p>
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
<p>
- ss : sa and sb at the same time.
<p>
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
<p>
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
<p>
- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
<p>
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
<p>
- rr : ra and rb at the same time.
<p>
- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
<p>
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
<p>
- rrr : rra and rrb at the same time.

The algorithm, before executing each move between stack a and stack b, calculates which number of stack a takes the least possible number of moves to be pushed in order to stack b. This way, when stack b fills up completely, it rotates so that the maximum is in the first position. Finally, a series of repushes follow on stack a until stack b is completely empty.
<p>
🎆BOOM!🎆 Now you have stack a sorted in ascending order (the minimum is in first place).
<p>
🏁 For a stack of 100 numbers this algorithm performs 550 moves on average
<p>
🏁 For a stack of 500 numbers this algorithm performs 5100 moves on average
