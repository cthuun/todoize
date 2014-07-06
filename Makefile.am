SUBDIRS=src

ACLOCAL_AMFLAGS=-Im4


DISTCLEANFILES=doxygen.conf Makefile.in

.PHONY: doc

doc:
	doxygen doxygen.conf

clean-local:
	-rm -rf latex
	-rm -rf html
