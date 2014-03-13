AC_PREREQ(2.59)

AC_INIT([gbemu], [m4_esyscmd([./version.sh])], [vallee.aurelien@gmail.com])

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([foreign])
LT_INIT

m4_ifdef([AM_SILENT_RULES], [
    AM_SILENT_RULES([yes])
])

LTVER="1:0:0"
AC_SUBST(LTVER)

AC_PROG_CXX
AC_LANG([C++])
AC_PROG_LIBTOOL
AM_PROG_CC_C_O

AC_CONFIG_FILES(Makefile \
                gbemu-lib/Makefile \
                gbemu-as/Makefile \
                gbemu-play/Makefile )

AC_OUTPUT
