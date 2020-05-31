#!/bin/sh

set -e
set -x

./enode_client3 cnode1 > /dev/null 2>&1 &

iex --name e1@127.0.0.1 --cookie secretcookie  complex_test_call.exs  


