gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_io.nim.c.o stdlib_io.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_system.nim.c.o stdlib_system.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_posix.nim.c.o stdlib_posix.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_times.nim.c.o stdlib_times.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_os.nim.c.o stdlib_os.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_nativesockets.nim.c.o stdlib_nativesockets.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o stdlib_net.nim.c.o stdlib_net.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o @meinode@ssrc@seinode.nim.c.o @meinode@ssrc@seinode.nim.c
gcc -c  -w -pthread -g3 -Og  -I/home/elcritch/.asdf/installs/nim/devel/lib -I/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim -o @mexample_server.nim.c.o @mexample_server.nim.c
gcc   -o example_server  stdlib_io.nim.c.o stdlib_system.nim.c.o stdlib_posix.nim.c.o stdlib_times.nim.c.o stdlib_os.nim.c.o stdlib_nativesockets.nim.c.o stdlib_net.nim.c.o @meinode@ssrc@seinode.nim.c.o @mexample_server.nim.c.o  -lm -pthread -lm   -ldl
