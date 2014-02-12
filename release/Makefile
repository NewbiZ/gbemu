VERSION=$(shell ../version.sh)
RELEASEDIR=$(shell mktemp -d -t gbemu.XXXXX)

all: source
.PHONY: all

clean:
	rm -rf $(CURDIR)/dist

dist/gbemu-$(VERSION).tar.gz:
	@mkdir -p $(CURDIR)/dist
	$(eval $@_TMP := $(shell mktemp -d -t gbemu.XXXXX))
	@cd $($@_TMP) && $(CURDIR)/../configure --quiet
	@cd $($@_TMP) && make --quiet dist
	@cd $($@_TMP) && mv gbemu-$(VERSION).tar.gz $(CURDIR)/dist
	@rm -rf $($@_TMP)

dist/gbemu-$(VERSION).deb:
	touch dist/gbemu-$(VERSION).deb

dist/gbemu-$(VERSION).rpm:
	touch dist/gbemu-$(VERSION).rpm

source: dist/gbemu-$(VERSION).tar.gz

debian: source dist/gbemu-$(VERSION).deb

redhat: source dist/gbemu-$(VERSION).rpm
