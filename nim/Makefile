
NIM_CPU := arm
NIMBLE := _nimble
NIMLIB := $(shell nim dump file.json 2>&1 | grep lib | sort | head -n1 )
NIMCACHE := _nimcache

all: nim

		# -d:traceArc \
		# -d:use_malloc



nim: clean
	nim c \
		-d:debug \
		-d:use_malloc \
		--os:freertos \
		-d:StandaloneHeapSize:100000 \
		--no_main \
		--cpu:$(NIM_CPU) \
		--nim_cache:"$(NIMCACHE)" \
		--nimble_path:"$(NIMBLE)/pkgs" \
		--compile_only \
		--gen_script \
		example_server.nim

	cp -v $(NIMLIB)/nimbase.h  $(NIMCACHE)/nimbase.h

		# -d:debug \

test-local: clean
	nim c \
		--nim_cache:"$(NIMCACHE)" \
		--nimble_path:"$(NIMBLE)/pkgs" \
		example_server.nim

	cp -v $(NIMLIB)/nimbase.h  $(NIMCACHE)/nimbase.h

clean:
	rm -Rf $(NIMCACHE)
