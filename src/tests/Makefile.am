check_PROGRAMS=test1 test_getopt_help_short \
			   test_getopt_help_long		\
			   test_getopt_help_with_known	\
			   test_getopt_help_with_unknown

if SQLITE3
check_PROGRAMS+=test_getopt_sqlite3_db_short_enabled
endif
test1_SOURCES=main.c
test_getopt_help_short_SOURCES=test_getopt_help_short.c $(top_srcdir)/src/todoize_options.c
test_getopt_help_long_SOURCES=test_getopt_help_long.c $(top_srcdir)/src/todoize_options.c
test_getopt_help_with_unknown_SOURCES=test_getopt_help_with_unknown.c $(top_srcdir)/src/todoize_options.c
test_getopt_help_with_known_SOURCES=test_getopt_help_with_known.c $(top_srcdir)/src/todoize_options.c
test_getopt_sqlite3_db_short_enabled_SOURCES=test_getopt_sqlite3_db_short_enabled.c $(top_srcdir)/src/todoize_options.c


AM_CFLAGS=-I$(top_srcdir)/src/includes

DISTCLEANFILES=Makefile.in

TESTS=$(check_PROGRAMS)
