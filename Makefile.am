SUBDIRS=src

ACLOCAL_AMFLAGS=-Im4

DISTCHECK_CONFIGURE_FLAGS="--enable-sqlite3"

AM_CPPFLAGS=

if DEBUG
AM_CPPFLAGS+=-DDEBUG
endif

if SQLITE3
AM_CPPFLAGS+=-DSQLITE3
endif

export AM_CPPFLAGS

DISTCLEANFILES=doxygen.conf Makefile.in

.PHONY: doc

doc:
	doxygen doxygen.conf

clean-local:
	-rm -rf latex
	-rm -rf html
