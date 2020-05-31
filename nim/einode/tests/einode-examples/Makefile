# build under OTP 17.1 on Linux
# -lsocket should be added and -lrt should be removed while build on FreeBSD

ERTS=$(shell elixir ../erl_base.exs)
INCLUDE_DIR=$(ERTS)/include
LIB_DIR=$(ERTS)/lib

all: cserver cserver2 cserver_ei3 cclient nim

## Should move these to use rules, but ain't nobody got time 
server1:
	nim c --d:debug \
		--passC=-I"$(INCLUDE_DIR)" \
		--passL=-L"$(LIB_DIR) -lerl_interface -lei -lpthread " \
		--debugger:native \
		enode_server1.nim 

		# -d:traceArc \

server2:
	nim c --d:debug \
		--gc:arc \
		--passC=-I"$(INCLUDE_DIR)" \
		--passL=-L"$(LIB_DIR) -lerl_interface -lei -lpthread " \
		--debugger:native \
		enode_server2.nim 

client2:
	nim c --d:debug \
		--gc:arc \
		--passC=-I"$(INCLUDE_DIR)" \
		--passL=-L"$(LIB_DIR) -lerl_interface -lei -lpthread " \
		--debugger:native \
		enode_client2.nim 

client3:
	nim c --d:debug \
		--gc:arc \
		--passC=-I"$(INCLUDE_DIR)" \
		--passL=-L"$(LIB_DIR) -lerl_interface -lei -lpthread " \
		--debugger:native \
		enode_client3.nim 


clean:
	rm -Rf enode_server1 enode_server2 enode_client2
	rm -Rf *.dSYM # macos
