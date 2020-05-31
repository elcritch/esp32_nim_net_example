c-nodes-example
===============

Updated simple Elixir/Erlang C Nodes example. The server `cnode_ei_s2.c` has been updated to utilize the `ei_***` api. 

0. Test Elixir C Node server 

```shell
shell1$ ./cserver_ei3 3456

Connected to e1@127.0.0.1
message: 1
erl_reg_send: msgtype: 6 buff: 0x7fd4ec500010 idx: 42 bufsz: 128 
term: ``
bar: 4
tick: 0
```

```shell
shell2$ erl -name e1 -setcookie secretcookie
Erlang/OTP 22 [erts-10.6.1] [source] [64-bit] [smp:8:8] [ds:8:8:10] [async-threads:1] [hipe]

Interactive Elixir (1.9.4) - press Ctrl+C to exit (type h() ENTER for help)
iex(e1@127.0.0.1)1> Node.connect :'cnode@127.0.0.1'  
true
iex(e1@127.0.0.1)2> Complex4.bar(4)                  
4
iex(e1@127.0.0.1)3> 
```

1. Test C node server example with short node names

```shell
$ ./cserver 3456

$ erl -sname e1 -setcookie secretcookie
Erlang/OTP 17 [erts-6.1] [source] [smp:2:2] [async-threads:10] [hipe] [kernel-poll:false]

Eshell V6.1  (abort with ^G)
(e1@alpha)1> c(complex3).
{ok,complex3}
(e1@alpha)2> complex3:foo(3).
4
(e1@alpha)3> complex3:bar(5).
10
```

2. Test C node server example with long node names

```shell
$ ./cserver2 3456

$ erl -name e1 -setcookie secretcookie
Erlang/OTP 17 [erts-6.1] [source] [smp:2:2] [async-threads:10] [hipe] [kernel-poll:false]

Eshell V6.1  (abort with ^G)
(e1@alpha.example.com)1> c(complex4).
{ok,complex4}
(e1@alpha.example.com)2> complex4:foo(3).
4
(e1@alpha.example.com)3> complex4:bar(5).
10
```

3. Test C node client example

```shell
$ erl -sname e1 -setcookie secretcookie
Erlang/OTP 17 [erts-6.1] [source] [smp:2:2] [async-threads:10] [hipe] [kernel-poll:false]

Eshell V6.1  (abort with ^G)
(e1@alpha)1> c(complex3).
{ok,complex3}
```

run the C node client

```shell
$ ./cclient
```

back to the erlang shell

```shell
(e1@alpha)2> complex3:foo(3).
4
(e1@alpha)3> complex3:bar(5).
10
```
