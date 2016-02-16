AC_PREREQ([2.69])
AC_INIT([bs-cem], [0.1])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([subdir-objects])

AC_CONFIG_SRCDIR([src/cem.c])
AC_CONFIG_MACRO_DIR([m4])


AC_PROG_CC


AC_CHECK_HEADERS([stdio.h])


PKG_CHECK_MODULES(GTK3, [gtk+-3.0])
PKG_CHECK_MODULES(GL, [gl])
PKG_CHECK_MODULES(X11, [x11])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  src/gui/Makefile
])

AC_OUTPUT
