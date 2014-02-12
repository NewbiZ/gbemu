VERSION=$(shell $(CURDIR)/../version.sh)

include Makefile.source
include Makefile.debian
include Makefile.redhat

all: source
.PHONY: all

clean:
	rm -rf $(CURDIR)/dist
