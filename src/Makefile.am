SUBDIRS=tests \
		include

bin_PROGRAMS=todoize

if SQLITE3
SUBDIRS+=sqlite3
endif

todoize_SOURCES=todoize_main.c		\
				todoize_options.c	\
				todoize_display.c

todoize_CPPFLAGS=-I$(top_srcdir)/src/include

MAINTAINERCLEANFILES=Makefile.in
