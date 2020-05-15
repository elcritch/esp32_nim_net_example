
NIM_CPU := arm
NIMBLE := _nimble
NIMLIB := $(shell nim dump file.json 2>&1 | grep lib | sort | head -n1 )
NIMCACHE := _nimcache

all: clean
	nim c \
		--gc:arc \
		-d:debug \
		--os:any \
		-d:posix \
		--debugger:native \
		--exceptions:goto \
		-d:use_malloc \
		--cpu:$(NIM_CPU) \
		--no_main \
		--dead_code_elim:on \
		--threads:on \
		--tls_emulation:off \
		--verbosity:3 \
		--multimethods:on \
		-d:no_signal_handler \
		--nim_cache:"$(NIMCACHE)" \
		--nimble_path:"$(NIMBLE)/pkgs" \
		--compile_only \
		--gen_script \
		example_server.nim

	@echo NIMLIB: $(NIMLIB)
	cp -v $(NIMLIB)/nimbase.h  $(NIMCACHE)/nimbase.h

clean:
	rm -Rf $(NIMCACHE)
