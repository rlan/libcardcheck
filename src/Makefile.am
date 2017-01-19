## List executables to build
noinst_PROGRAMS = main test
TESTS = test

## Boost
AM_CPPFLAGS = \
  $(BOOST_CPPFLAGS)

AM_LDFLAGS = \
  $(BOOST_LDFLAGS)

## .h files for all templates
HFILES_TEMPLATES =

## .cc files for all templates
CCFILES_TEMPLATES =

## .h files for all non-templates
HFILES = \
  card_check.hpp

## .cc files for all non-templates
CCFILES = \
	card_check.cpp

## all the source files that are compiled into the
main_SOURCES = \
	$(HFILES) \
	$(CCFILES) \
  card_check_main.cpp

test_SOURCES = \
	$(HFILES) \
	$(CCFILES) \
  card_check_test.cpp

## These are the files that will get installed into the includes directory
## Should include all .h files and the .cc for all templates.
include_HEADERS = \
	$(HFILES) \
	$(HFILES_TEMPLATES) \
	$(CCFILES_TEMPLATES)
