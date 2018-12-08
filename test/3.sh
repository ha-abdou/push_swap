#!/bin/bash
echo "test 3 params:";
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;
ARG="3 1 2"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;
ARG="2 3 1"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;
ARG="1 2 3"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;
ARG="1 3 2"; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;