-include MakeDefns

INSTALLDIRS = $(bindir) $(includedir) $(pkgincludedir) $(includedir)/lemur $(libdir) $(pkgdatadir) $(pkgdatadir)/doc

LDFLAGS = -lz

.PHONY: all dist clean install $(INSTALLDIRS) site-search

all: 
	$(MAKE) -C contrib $(LDFLAGS)
	$(MAKE) -C obj -f ../src/Makefile $(LDFLAGS)
ifeq ($(WITH_SWIG), 1)
	$(MAKE) -C swig/src $(LDFLAGS)
endif
	$(MAKE) -C buildindex $(LDFLAGS)
	$(MAKE) -C runquery $(LDFLAGS)
	$(MAKE) -C indrid $(LDFLAGS)
	$(MAKE) -C dumpindex $(LDFLAGS)
	$(MAKE) -C harvestlinks $(LDFLAGS)
	$(MAKE) -C pagerank $(LDFLAGS)
	$(MAKE) -C rmodel $(LDFLAGS)
	$(MAKE) -C makeprior $(LDFLAGS)
	$(MAKE) -C site-search $(LDFLAGS)
	$(MAKE) -C modifyfields $(LDFLAGS)
	$(MAKE) -C clarity $(LDFLAGS)
	$(MAKE) -C reformulate $(LDFLAGS)

$(INSTALLDIRS):
	$(INSTALL_DIR) $@

clean:
	$(MAKE) clean -C contrib $(LDFLAGS)
	$(MAKE) clean -C obj -f ../src/Makefile $(LDFLAGS)
ifeq ($(WITH_SWIG), 1)
	$(MAKE) clean -C swig/src $(LDFLAGS)
endif
	$(MAKE) clean -C buildindex $(LDFLAGS)
	$(MAKE) clean -C runquery $(LDFLAGS)
	$(MAKE) clean -C indrid $(LDFLAGS)
	$(MAKE) clean -C dumpindex $(LDFLAGS)
	$(MAKE) clean -C harvestlinks $(LDFLAGS)
	$(MAKE) clean -C pagerank $(LDFLAGS)
	$(MAKE) clean -C rmodel $(LDFLAGS) 
	$(MAKE) clean -C makeprior $(LDFLAGS)
	$(MAKE) -C site-search clean $(LDFLAGS)
	$(MAKE) -C modifyfields clean $(LDFLAGS)
	$(MAKE) -C clarity clean $(LDFLAGS)
	$(MAKE) -C reformulate clean $(LDFLAGS)
	rm -f depend/*

distclean: clean
	rm -rf autom4te.cache MakeDefns Makefile.app config.log config.status indri.ncb indri.suo
dist: distclean
	$(MAKE) stamp -C obj -f ../src/Makefile
	cd ..; tar zcvf indri-`date +%Y%m%d-%H%M`.tar.gz indri $(LDFLAGS)

install: $(INSTALLDIRS)
	rm -f $(libdir)/$(INDRILIB)
	$(MAKE) install -C contrib 
	$(MAKE) install -C obj -f ../src/Makefile
ifeq ($(WITH_SWIG), 1)
	$(MAKE) install -C swig/src
endif
	$(MAKE) install -C buildindex
	$(MAKE) install -C runquery
	$(MAKE) install -C indrid
	$(MAKE) install -C dumpindex
	$(MAKE) install -C harvestlinks
	$(MAKE) install -C pagerank
	$(MAKE) install -C rmodel
	$(MAKE) install -C makeprior
	$(MAKE) install -C modifyfields
	$(MAKE) install -C clarity
	$(MAKE) install -C reformulate
	$(MAKE) install -C doc
	$(MAKE) -C site-search install
	$(INSTALL_DATA) Makefile.app $(pkgdatadir)

test:
