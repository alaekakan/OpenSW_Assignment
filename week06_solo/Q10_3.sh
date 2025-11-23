#!/bin/bash
print_param_3() {
    echo $0
    echo $1
    echo $1
    echo $*
    echo $#
}
print_param_3 "hello" "world" "!"