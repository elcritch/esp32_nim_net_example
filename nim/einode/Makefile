CI := $(shell elixir erl_home.exs)
NIMBLE_DIR = "./_nimble"
NIMCACHE = "./_nimcache"

all:
	nimble build --verbose -d:debug --nimbleDir:$(NIMBLE_DIR) --nim_cache:"$(NIMCACHE)"

test:
	nimble test --verbose -d:debug --nimbleDir:$(NIMBLE_DIR) --nim_cache:"$(NIMCACHE)"

clean:
	rm -Rf $(NIMCACHE)

distclean: clean
	rm -Rf $(NIMBLE_DIR) 

deps:
	nimble install -y --nimbleDir:$(NIMBLE_DIR) patty
