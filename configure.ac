#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libcardcheck], [0.1], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/card_check.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
#AM_SILENT_RULES(yes)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
# Checks for Boost libraries. Other macros:
# https://www.gnu.org/software/autoconf-archive/The-Macros.html#The-Macros
AX_BOOST_BASE([1.42], [], [AC_MSG_ERROR([This program needs Boost, but it was not found in your system])])
#AX_BOOST_SYSTEM
#AX_BOOST_UNIT_TEST_FRAMEWORK

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11(,mandatory)
#AX_CXX_COMPILE_STDCXX([11], [], [mandatory])

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
