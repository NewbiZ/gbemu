lib_LTLIBRARIES = \
	libgbemu.la

libgbemu_la_SOURCES = \
	@srcdir@/src/gbemu.cpp

libgbemu_la_LDFLAGS = \
	-no-undefined \
	-version-info @LTVER@

libgbemu_la_CPPFLAGS = \
	-I@srcdir@/include/

libgbemu_la_CXXFLAGS = \
	-Wall

MAINTAINERCLEANFILES = \
	Makefile.in
