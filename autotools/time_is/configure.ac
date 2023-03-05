# Force Autoconf to be this version number or higher
AC_PREREQ([2.71])

# Macro: AC_INIT (package, version, [bug-report], [tarname], [url])
AC_INIT([time_is], [1.0], [christophercylai@outlook.com], [time-is], [https://github.com/christophercylai/cplusplus])

# src directory
AC_CONFIG_SRCDIR([main.cpp])

# Put autotool's auxiliary files in a subdir, so they don't clutter up top dir
AC_CONFIG_AUX_DIR([auxiliary])

# Put configuration results here, so they can be easily included
AC_CONFIG_HEADERS([config.h])

# Automake options
# -Wall: enable all warnings
# -Werror: treat warnings as errors
# foreign: a low strictness level that does not require the package to follow GNU standard
# subdir-objects: 
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Look for C and C++ comiler
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET

# predefine $MAKE
AC_CONFIG_FILES([Makefile])

# Autoconf output
AC_OUTPUT
