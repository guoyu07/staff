include ../../Makefile.env

COMPONENT = staff.das/providers/staff.das.Shell
TARGET = shell
LIBTARGETVER = $(LIBPREFIX)staffdasprov-$(TARGET)$(LIBVEREXT)
LIBTARGET = $(LIBPREFIX)staffdasprov-$(TARGET)$(LIBEXT)

CXXFLAGS += -I$(DEPLOYDIR)include
LDFLAGS += -lpthread -lrise -lstaffcommon -lstaffdascommon
LDFLAGS += $(LDLIB)$(LIBTARGETVER)

SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJDIR)%.o,$(notdir $(SOURCES)))

# == make ===========================================
make: check "$(OBJDIR)" "$(OUTDIR)" $(OUTDIR)$(LIBTARGETVER) deploy

# link
$(OUTDIR)$(LIBTARGETVER): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(OUTDIR)$(LIBTARGETVER) $(LDFLAGS)

# compile
$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# == deploy  ========================================
deploy: "$(DEPLOYDIR)$(COMDIR)$(COMPONENT)/" $(OUTDIR)$(LIBTARGETVER)
	cp -f $(OUTDIR)$(LIBTARGETVER) "$(DEPLOYDIR)$(COMDIR)$(COMPONENT)/"
	$(LN) $(LIBTARGETVER) $(DEPLOYDIR)$(COMDIR)$(COMPONENT)/$(LIBTARGET)

# == distrib =========================================
distrib:;

# == install ========================================
install: check "$(INSTALLDIR)$(COMDIR)$(COMPONENT)/"
	cp -f $(OUTDIR)$(LIBTARGETVER) $(INSTALLDIR)$(COMDIR)$(COMPONENT)/
	$(LN) $(LIBTARGETVER) $(INSTALLDIR)$(COMDIR)$(COMPONENT)/$(LIBTARGET)

# == uninstall ======================================
uninstall: check
	rm -f $(INSTALLDIR)$(COMDIR)$(COMPONENT)/$(LIBTARGETVER) $(INSTALLDIR)$(COMDIR)$(COMPONENT)/$(LIBTARGET)
	-rmdir $(INSTALLDIR)$(COMDIR)$(COMPONENT)

# == clean ==========================================
clean:
	rm -Rf $(OBJDIR) $(OUTDIR)

# == mkdir ==========================================
"%/":
	@[ -z "$@" -o -d "$@" ] || mkdir -p $@ && chmod g+w $@