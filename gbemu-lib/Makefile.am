AM_CXXFLAGS = \
	-std=c++11 \
	-Wall \
	-I$(top_srcdir)/gbemu-lib/include

lib_LTLIBRARIES = \
	libgbemu.la

libgbemu_la_SOURCES = \
	$(top_srcdir)/gbemu-lib/src/gbemu.cpp \
	$(top_srcdir)/gbemu-lib/src/gameboy.cpp \
	$(top_srcdir)/gbemu-lib/src/mmu.cpp \
	$(top_srcdir)/gbemu-lib/src/cpu.cpp \
	$(top_srcdir)/gbemu-lib/src/cartridge.cpp \
	$(top_srcdir)/gbemu-lib/src/gpu.cpp

pkginclude_HEADERS = \
	$(top_srcdir)/gbemu-lib/include/gbemu/gbemu.h \
	$(top_srcdir)/gbemu-lib/include/gbemu/gameboy.h \
	$(top_srcdir)/gbemu-lib/include/gbemu/mmu.h \
	$(top_srcdir)/gbemu-lib/include/gbemu/cpu.h \
	$(top_srcdir)/gbemu-lib/include/gbemu/cartridge.h \
	$(top_srcdir)/gbemu-lib/include/gbemu/gpu.h

libgbemu_la_LDFLAGS = \
	-no-undefined \
	-version-info $(LTVER)

MAINTAINERCLEANFILES = \
	Makefile.in
