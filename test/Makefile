# Automatically Generated Makefile by EDE.
# For use with: make
#
# DO NOT MODIFY THIS FILE OR YOUR CHANGES MAY BE LOST.
# EDE is the Emacs Development Environment.
# http://cedet.sourceforge.net/ede.shtml
#

top="$(CURDIR)"/
ede_FILES=Project.ede Makefile

test_SOURCES=main.cpp
test_OBJ= main.o
CXX= g++
CXX_COMPILE=$(CXX) $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS)
CXX_DEPENDENCIES=-Wp,-MD,.deps/$(*F).P
CXX_LINK=$(CXX) $(CFLAGS) $(LDFLAGS) -L.
VERSION=1.0
DISTDIR=$(top)-$(VERSION)
top_builddir = 

DEP_FILES=.deps/main.P

all: test

DEPS_MAGIC := $(shell mkdir .deps > /dev/null 2>&1 || :)
-include $(DEP_FILES)

%.o: %.cpp
	@echo '$(CXX_COMPILE) -c $<'; \
	$(CXX_COMPILE) $(CXX_DEPENDENCIES) -o $@ -c $<

test: $(test_OBJ)
	$(CXX_LINK) -o $@ $^ $(LDDEPS)

tags: 


clean:
	rm -f *.mod *.o *.obj .deps/*.P .lo

.PHONY: dist

dist:
	rm -rf $(DISTDIR)
	mkdir $(DISTDIR)
	cp $(test_SOURCES) $(ede_FILES) $(DISTDIR)
	tar -cvzf $(DISTDIR).tar.gz $(DISTDIR)
	rm -rf $(DISTDIR)

Makefile: Project.ede
	@echo Makefile is out of date!  It needs to be regenerated by EDE.
	@echo If you have not modified Project.ede, you can use 'touch' to update the Makefile time stamp.
	@false



# End of Makefile
