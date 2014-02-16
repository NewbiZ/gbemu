AM_CXXFLAGS = \
	-std=c++11 \
	-Wall \
	-I$(top_srcdir)/gbemu-lib/include

bin_PROGRAMS = \
	gbemu-as

gbemu_as_SOURCES = \
	$(top_srcdir)/gbemu-as/src/gbemu-as.cpp

gbemu_as_LDADD = \
	$(top_builddir)/gbemu-lib/libgbemu.la

MAINTAINERCLEANFILES = \
	Makefile.in
