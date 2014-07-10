AM_CFLAGS=
SUBDIRS=tests \
	includes

bin_PROGRAMS=todoize

if DEBUG
AM_CFLAGS+=-DDEBUG
endif
todoize_SOURCES=todoize_main.c \
todoize_options.c \
  todoize_display.c
todoize_CPPFLAGS=-I$(top_srcdir)/src/includes

DISTCLEANFILES=Makefile.in
