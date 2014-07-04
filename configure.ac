#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ToDoize], [0.0], [cthuun@cthuun.fr])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([doxygen.conf \
    Makefile \
src/Makefile \
src/tests/Makefile \
src/includes/Makefile])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([assert.h])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])
AC_CHECK_LIB([ncurses],[initscr])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
