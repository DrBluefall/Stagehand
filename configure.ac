dnl Initialize autoconf and automake.

AC_INIT([stagehand], [0.0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects silent-rules])

dnl Decide whether we'll compile debugging code in the bot.
AC_ARG_ENABLE([debug-code],
    [AS_HELP_STRING([--enable-debug-code], [include code to assist in debugging the bot. @<:@default=no@:>@])],
    [debug_code=$withval],
    [: m4_divert_text([DEFAULTS], [debug_code=no])])

AH_TEMPLATE([STAGEHAND_DEBUG_BUILD], [Include debug code in the binary.])
AS_IF([test "x$debug_code" != xno],[AC_DEFINE([STAGEHAND_DEBUG_BUILD])])

dnl Check for a C++ compiler.
AC_PROG_CXX

dnl Check for pkg-config.
PKG_PROG_PKG_CONFIG

dnl Check for D++.
PKG_CHECK_MODULES([DPP], [dpp], [], [AC_MSG_ERROR([pkg-config could not find D++. Install the package from github, and make sure that 'dpp.pc' can be found in pkg-config's search path.])])
dnl Check for toml++.
PKG_CHECK_MODULES([TOMLPLUSPLUS], [tomlplusplus], [], [AC_MSG_ERROR([pkg-config could not find tomlplusplus. Install the package from github, and make sure that 'tomlplusplus.pc' can be found in pkg-config's search path.])])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_HEADERS([include/autoconf.h:include/config.h.in])
AC_OUTPUT
