# Partially lifted from https://www.eyrie.org/~eagle/notes/style/build.html
MAINTAINERCLEANFILES = Makefile.in aclocal.m4 build-aux/compile \
	build-aux/config.guess build-aux/config.sub build-aux/depcomp \
	build-aux/install-sh build-aux/ltmain.sh build-aux/missing \
	config.h.in config.h.in~ configure m4/libtool.m4 m4/ltoptions.m4 \
	m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4 configure~ ltmain.sh \
	build-aux/ar-lib build-aux/test-driver $(srcdir)/include/config.h.in \
	$(srcdir)/include/config.h.in~

ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = stagehand

stagehand_SOURCES  = $(srcdir)/src/main.cpp \
	$(srcdir)/src/commands/shutdown.cpp $(srcdir)/include/bot_config.hpp \
	$(srcdir)/include/commands/command_list.hpp \
	$(srcdir)/include/commands/base.hpp

stagehand_LDADD    = @DPP_LIBS@
stagehand_CXXFLAGS = @DPP_CFLAGS@ @TOMLPLUSPLUS_CFLAGS@ -std=c++20 -I$(srcdir)/include
