SUBDIRS=src

ACLOCAL_AMFLAGS=-Im4

DISTCHECK_CONFIGURE_FLAGS="--enable-sqlite3"

AM_CFLAGS=-W -Wall -Werror -Wextra

if DEBUG
AM_CFLAGS+=-DDEBUG
endif

if SQLITE3
AM_CFLAGS+=-DSQLITE3
endif
AM_CPPFLAGS=$(AM_CFLAGS)

export AM_CFLAGS AM_CPPFLAGS

DISTCLEANFILES=doxygen.conf
MAINTAINERCLEANFILES=Makefile.in

.PHONY: doc

doc:
	doxygen doxygen.conf

clean-local:
	-rm -rf latex
	-rm -rf html
