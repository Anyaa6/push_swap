# push_swap
A sorting algorithm project
1) Go to srcs/
2) make
3) ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker_Mac $ARG; ./push_swap $ARG | ./checker $ARG

Create a 500 number variable and check with the homemade checker program and the one given if push_swap is giving the right instructions to sort the stack

4) ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | wc -l

Gives number of instructions for sorting the entire stack
