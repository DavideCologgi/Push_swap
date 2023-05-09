# Push_swap
Coding a program that can sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The possible moves used to sort the stack are:
- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- rrr : rra and rrb at the same time.

The algorithm, before executing each move between stack a and stack b, calculates which number of stack a takes the least possible number of moves to be pushed in order to stack b. This way, when stack b fills up completely, it rotates so that the maximum is in the first position. Finally, a series of repushes follow on stack a until stack b is completely empty.
- For a stack of 100 numbers the algorithm performs 550 moves on average
- For a stack of 500 numbers the algorithm performs 5100 moves on average
