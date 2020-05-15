
NIMLIB := $(shell nim dump file.json 2>&1 | grep lib | sort | head -n1 )
NIMCACHE := _nimcache

all: clean
	nim c --no_main example_server.nim
	@echo NIMLIB: $(NIMLIB)
	cp -v $(NIMLIB)/nimbase.h  $(NIMCACHE)/nimbase.h

clean:
	rm -Rf $(NIMCACHE)
