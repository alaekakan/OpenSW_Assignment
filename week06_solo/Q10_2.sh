#!/bin/bash
print_param_2() {
    echo $0
    echo $1
    echo $2
    echo $*
    echo $#
}
print_param_2 "hello" "world" "!"