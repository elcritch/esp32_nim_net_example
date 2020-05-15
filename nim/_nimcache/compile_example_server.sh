gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_locks.nim.c.o stdlib_locks.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_sharedlist.nim.c.o stdlib_sharedlist.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_system.nim.c.o stdlib_system.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_posix.nim.c.o stdlib_posix.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_times.nim.c.o stdlib_times.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_os.nim.c.o stdlib_os.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_heapqueue.nim.c.o stdlib_heapqueue.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_deques.nim.c.o stdlib_deques.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_asyncfutures.nim.c.o stdlib_asyncfutures.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_monotimes.nim.c.o stdlib_monotimes.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_nativesockets.nim.c.o stdlib_nativesockets.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_selectors.nim.c.o stdlib_selectors.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_asyncdispatch.nim.c.o stdlib_asyncdispatch.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o stdlib_base64.nim.c.o stdlib_base64.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/hello_world/nim -o @mexample_server.nim.c.o @mexample_server.nim.c
gcc   -o example_server  stdlib_locks.nim.c.o stdlib_sharedlist.nim.c.o stdlib_system.nim.c.o stdlib_posix.nim.c.o stdlib_times.nim.c.o stdlib_os.nim.c.o stdlib_heapqueue.nim.c.o stdlib_deques.nim.c.o stdlib_asyncfutures.nim.c.o stdlib_monotimes.nim.c.o stdlib_nativesockets.nim.c.o stdlib_selectors.nim.c.o stdlib_asyncdispatch.nim.c.o stdlib_base64.nim.c.o @mexample_server.nim.c.o  -lm -pthread -lm   -ldl
