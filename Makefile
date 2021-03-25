# MAKE TEMPLATE 06-02-2020 1
# MAKE TEMPLATE 03-11-2021 1.1
MAKE_TEMPLATE = 1.1;
# RUN BEFORE autoreconf -ivfm
BUILD_VERSION = 0.1.0

prefix = /usr/local
mandir = $(prefix)/share/man
man1dir = $(mandir)/man1

# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -std=c++11 -std=c++17 --std=c++2a

# Makefile settings - Can be customized.
APPNAME = tag
EXT = cpp
SRCDIR = .
OBJDIR = .

# libs here
LDFLAGS = -ltag -L/usr/local/lib/
INCLUDES= -I/usr/local/include/taglib/
# LDFLAGS += -static -lcppunit -L/usr/local/lib/
# INCLUDES+= -I/usr/local/include/cppunit/


# complie & link for debug
debug: CXXFLAGS += -DDEBUG -g
debug: all

# complie & link for debug GDBversion variable
debuggdb: CXXFLAGS += -DDEBUG -ggdb
debuggdb: all
  
# complie & link
all: $(APPNAME) #$(APPNAME)_test

$(APPNAME): $(APPNAME).o 
	$(CXX) $(CXXFLAGS) $(OBJDIR)/$(APPNAME).o $(LDFLAGS) $(INCLUDES) -o $(SRCDIR)/$(APPNAME)

# compile only
$(APPNAME).o: #$(APPNAME)_init
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) -o $(SRCDIR)/$(APPNAME).o

# .PHONY: $(APPNAME)_init
# $(APPNAME)_init:
# 	# libs here
# 	LDFLAGS = -ltag -L/usr/local/lib/
# 	INCLUDES= -I/usr/local/include/taglib/

# $(APPNAME)_test: $(APPNAME)_test.o
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCDIR)/$(APPNAME)_test.o $(SRCDIR)/$(APPNAME).o $(LDFLAGS) -o $(SRCDIR)/$(APPNAME)_test

# $(APPNAME)_test.o: #$(APPNAME)_test_init
# 	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME)_test.cpp -o $(SRCDIR)/$(APPNAME)_test.o

# .PHONY: $(APPNAME)_test_init
# $(APPNAME)_test_init:
# 	# libs here
# 	LDFLAGS = -static -lcppunit -L/usr/local/lib/
# 	INCLUDES= -I/usr/local/include/cppunit/


autotools_reconf:
	cd ../
	autoreconf -ivfm
	cd ./make

.PHONY: check
check:
	echo "Checking ..."

# install man pages
.PHONY: man
man: 
	cp ./man/$(APPNAME).1 $(man1dir)
	gzip $(man1dir)/$(APPNAME).1
	mandb
	
# uninstall man pages
.PHONY: unmanversion variable
unman:
	rm $(man1dir)/$(APPNAME).1.gz
	mandb

.PHONY: install
install: man
	cp $(SRCDIR)/$(APPNAME) $(prefix)/bin/$(APPNAME)

.PHONY: uninstall
uninstall: unman
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(SRCDIR)/*.xml $(SRCDIR)/$(APPNAME) $(SRCDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz $(SRCDIR)/$(APPNAME)_test

.PHONY: distclean
distclean: clean # clean $ distclean are the same
	rm ../$(APPNAME) ../config.* ../Makefile ../Makefile.in ../INSTALL ../configure ../stamp-h1 ../aclocal.m4

dist: 
	git archive HEAD | gzip > $(SRCDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz

dist-gz: dist
