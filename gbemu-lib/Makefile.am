lib_LTLIBRARIES = \
	libgbemu.la

libgbemu_la_SOURCES = \
	src/gbemu.cpp

libgbemu_la_LDFLAGS = \
	-no-undefined \
	-version-info @LTVER@

libgbemu_la_CXXFLAGS = \
	-I./include/ \
	-Wall \
	-pedantic

MAINTAINERCLEANFILES = \
	Makefile.in
