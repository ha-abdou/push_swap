#!/bin/bash
echo "test leaks:";
valgrind --leak-check=full ./push_swap 1 2 3
valgrind --leak-check=full ./push_swap 1
valgrind --leak-check=full ./push_swap 
valgrind --leak-check=full ./push_swap 2 1
valgrind --leak-check=full ./push_swap 1 1
ARG="1 2";valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG | ./checker $ARG;
valgrind --leak-check=full --show-leak-kinds=all printf "ra\nrb\nsadasdas\nra" | ./checker 1 2 3 9 8