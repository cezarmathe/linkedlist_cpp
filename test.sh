#!/bin/bash

function check_exit_status() {

  if !"$1"; then
    exit
  fi

}

function compile_run() {

  COMPILE=g++ "$1.cpp" -o "$1"
  check_exit_status $COMPILE

  COMPILE=./"$1"
  check_exit_status $COMPILE

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