AM_CXXFLAGS = \
	-std=c++11 \
	-Wall \
	-I$(top_srcdir)/gbemu-lib/include

bin_PROGRAMS = \
	gbemu-play

gbemu_play_SOURCES = \
	$(top_srcdir)/gbemu-play/src/gbemu-play.cpp

gbemu_play_LDADD = \
	$(top_builddir)/gbemu-lib/libgbemu.la

MAINTAINERCLEANFILES = \
	Makefile.in
