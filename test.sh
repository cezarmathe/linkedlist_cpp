#!/bin/bash

function compile_run() {
  g++ "$1.cpp" -o "$1"
  ./"$1"
  rm "$1"
}

cp linkedlist.cpp test/linkedlist.cpp
cp linkedlist.h test/linkedlist.h

cd test

# Tests go here

compile_run test_int
compile_run test_bool

# -----
rm linkedlist.cpp
rm linkedlist.h