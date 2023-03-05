# Macro: AC_INIT (package, version, [bug-report], [tarname], [url])
AC_INIT([atomic-time], [1.0], [christophercylai@outlook.com], [atomic-time], [https://github.com/christophercylai/cplusplus])

# Force Autoconf to be this version number or higher
AC_PREREQ([2.71])

# Put autotool's auxiliary files in a subdir, so they don't clutter up top dir
AC_CONFIG_AUX_DIR([aux])

# Put configuration results here, so they can be easily included
AC_CONFIG_HEADERS([config.h])

# Automake options
# -Wall: enable all warnings
# -Werror: treat warnings as errors
# foreign: a low strictness level that does not require the package to follow GNU standard
# subdir-objects: 
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_FILES([Makefile])

# Look for a C++ comiler
AC_PROG_CXX

# Autoconf output
AC_OUTPUT
