#!/bin/bash
print_param() {
    echo $0
    echo $1
    echo $2
    echo $*
    echo $#
}
print_param "Hello" "Word" "!"