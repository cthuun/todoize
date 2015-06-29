#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ToDoize], [0.0], [cthuun@cthuun.fr])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([ doxygen.conf          \
                  Makefile              \
                  src/Makefile          \
                  src/sqlite3/Makefile  \
                  src/tests/Makefile    \
                  src/include/Makefile ])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])

AC_ARG_ENABLE(debug,
    AC_HELP_STRING([--enable-debug], "Enable the support of debug"),
    [case "${enableval}" in
    yes) debug=true ;;
    no) debug=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
    esac],[debug=false]
    )

AC_ARG_ENABLE(sqlite3,
    AC_HELP_STRING([--enable-sqlite3], "Enable the support of sqlite3"),
    [case "${enableval}" in
    yes) sqlite3=true ;;
    no) sqlite3=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-sqlite3]) ;;
    esac],[sqlite3=false]
    )

AM_CONDITIONAL([SQLITE3], [test x$sqlite3 = xtrue])
AM_CONDITIONAL([DEBUG], [test x$debug = xtrue])

# Checks for libraries.
AC_CHECK_LIB([ncurses],[initscr])
AS_IF([test x$sqlite3 = xtrue], [AC_CHECK_LIB([sqlite3],[sqlite3_open])])

# Checks for header files.
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([assert.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
echo "------------"
echo ""
echo "sqlite3 support:    ${sqlite3}"
echo "debug support:      ${debug}"
echo ""
echo "------------"
