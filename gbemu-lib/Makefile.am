lib_LTLIBRARIES = \
	libgbemu.la

libgbemu_la_SOURCES = \
	$(top_srcdir)/gbemu-lib/src/gbemu.cpp

include_HEADERS = \
	$(top_srcdir)/gbemu-lib/include/gbemu/gbemu.h

libgbemu_la_LDFLAGS = \
	-no-undefined \
	-version-info $(LTVER)

libgbemu_la_CPPFLAGS = \
	-I$(top_srcdir)/gbemu-lib/include

libgbemu_la_CXXFLAGS = \
	-Wall

MAINTAINERCLEANFILES = \
	Makefile.in
