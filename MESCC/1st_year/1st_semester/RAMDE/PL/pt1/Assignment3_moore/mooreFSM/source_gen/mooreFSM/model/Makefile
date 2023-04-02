KERNEL = $(shell uname -s)
MACHINE = $(shell uname -m)

ifndef HOST
ifeq ($(OS),Windows_NT)
HOST = Win32
else
ifeq ($(KERNEL),Linux)
HOST = Linux
endif
ifeq ($(KERNEL),Darwin)
HOST = MacOSX
endif
endif
endif

SPACE = $() $()

CI ?= 
CI_RUNNER_TAGS ?= 

HOST_TAGS ?= $(subst $(SPACE),,$(CI_RUNNER_TAGS))

ifneq ($(CI),)
FLAVOR ?= release
endif

TARGET ?= $(HOST)
FLAVOR ?= debug

TARGET_INFIX = $(call toLowerCase,$(TARGET))
FLAVOR_INFIX = $(call toLowerCase,$(FLAVOR))

VERBOSE ?= 
ifdef VERBOSE
Q = 
else
Q = @
endif

vecho = @echo
replaceDir = $(addprefix $1/,$(notdir $2))
parentDirs = $(sort $(patsubst %/,%,$(dir $1)))
toUpperCase = $(shell echo $1 | tr a-z A-Z)
toLowerCase = $(shell echo $1 | tr A-Z a-z)

ifeq ($(HOST),$(TARGET))
export CC = gcc
export LD = $(CC)
TARGET_TOOLCHAIN_AVAILABLE = true
endif

BUILDROOT ?= 
OROOT ?= $(if $(BUILDROOT),$(BUILDROOT)/mooreFSM/model/$(TARGET_INFIX)/$(FLAVOR_INFIX),build/$(TARGET_INFIX)/$(FLAVOR_INFIX))
OBJODIR ?= $(OROOT)/obj
BINODIR ?= $(OROOT)/bin

CFLAGS = -std=c99
INCDIRS = 
LDFLAGS = 
LIBDIRS = 

ifeq ($(FLAVOR),debug)
CFLAGS += -g
endif

#  
# Begin HelloWorld Executable
#  

SUPPORTED_TARGETS_HelloWorld = any

# => 'true' if SUPPORTED_TARGETS contains 'any', undefined otherwise
FULLY_PORTABLE_HelloWorld = $(if $(filter any,$(SUPPORTED_TARGETS_HelloWorld)),true,)
# => 'true' if FULLY_PORTABLE is 'true' or SUPPORTED_TARGETS contains more than one value including 'Win32', undefined otherwise
PORTABLE_HelloWorld = $(if $(or $(FULLY_PORTABLE_HelloWorld),$(and $(filter-out 0 1,$(words $(SUPPORTED_TARGETS_HelloWorld))),$(filter Win32,$(SUPPORTED_TARGETS_HelloWorld)))),true,)
# => 'true' if SUPPORTED_TARGETS contains a single value different from 'any', undefined otherwise
TARGET_SPECIFIC_HelloWorld = $(if $(and $(filter-out any,$(SUPPORTED_TARGETS_HelloWorld)),$(filter 1,$(words $(SUPPORTED_TARGETS_HelloWorld)))),true,)
# => 'true' if SUPPORTED_TARGETS contains 'any' or TARGET, undefined otherwise
MATCHES_TARGET_HelloWorld = $(if $(or $(FULLY_PORTABLE_HelloWorld),$(filter $(TARGET),$(SUPPORTED_TARGETS_HelloWorld))),true,)
# => 'true' if MATCHES_TARGET and TARGET_TOOLCHAIN_AVAILABLE are 'true', undefined otherwise
BUILDABLE_HelloWorld = $(if $(and $(MATCHES_TARGET_HelloWorld),$(TARGET_TOOLCHAIN_AVAILABLE)),true,)

EXPFX_HelloWorld = ./
EXAFKT_HelloWorld = HelloWorld
EXEXT_HelloWorld = $(if $(filter Win32,$(TARGET)),.exe,)

ALL_CFLAGS_HelloWorld = $(CFLAGS) $(if $(filter Win32,$(TARGET)),-DWINVER=0x0601 -D_WIN32_WINNT=0x0601,-D_DEFAULT_SOURCE)

LIBS_HelloWorld = 
LIBDIRS_HelloWorld = 
EXT_LIBS_HelloWorld = 
EXT_LIBDIRS_HelloWorld = 
ALL_LIBS_HelloWorld = 
ALL_LIB_FLAGS_HelloWorld = $(addprefix -l,$(LIBS_HelloWorld)) $(addprefix -l,$(EXT_LIBS_HelloWorld))
ALL_LIBDIR_FLAGS_HelloWorld = $(addprefix -L,$(LIBDIRS_HelloWorld)) $(addprefix -L,$(LIBDIRS)) $(addprefix -L,$(EXT_LIBDIRS_HelloWorld))

LIB_INCDIRS_HelloWorld = 
EXT_INCDIRS_HelloWorld = 
ALL_INCDIR_FLAGS_HelloWorld = $(addprefix -I,$(LIB_INCDIRS_HelloWorld)) $(addprefix -I,$(INCDIRS)) $(addprefix -I,$(EXT_INCDIRS_HelloWorld))
ALL_INCS_HelloWorld = HelloWorld.h stateMachine.h UnitTestCLI.h UnitTestDefinitions.h UnitTestJUnitXML.h UnitTestMessages.h UnitTestRunner.h UnitTestUtil.h $(foreach lidir,$(LIB_INCDIRS_HelloWorld),$(wildcard $(lidir)/*.h)) $(foreach idir,$(INCDIRS),$(wildcard $(idir)/*.h)) $(foreach eidir,$(EXT_INCDIRS_HelloWorld),$(wildcard $(eidir)/*.h))

ALL_SRCS_HelloWorld = HelloWorld.c stateMachine.c UnitTestCLI.c UnitTestJUnitXML.c UnitTestMessages.c UnitTestRunner.c UnitTestUtil.c

ALL_OBJS_HelloWorld = $(addsuffix .o,$(call replaceDir,$(OBJODIR),$(ALL_SRCS_HelloWorld)))

#  
# End HelloWorld Executable
#  

EXTRA_CLEAN_AFKTS ?= 

.PHONY: all allDependencies clean cleanDependencies cleanAll targets

all: allDependencies $(BINODIR)/$(EXAFKT_HelloWorld)$(EXEXT_HelloWorld)

allDependencies: 

clean: 
	$(if $(wildcard $(filter-out . ..,$(OROOT))),$(vecho) "RM $(notdir $(OROOT))",)
	$(Q) $(RM) -r $(filter-out . ..,$(OROOT))
	$(if $(wildcard HelloWorld$(EXEXT_HelloWorld)),$(vecho) "RM HelloWorld$(EXEXT_HelloWorld)",)
	$(Q) $(RM) HelloWorld$(EXEXT_HelloWorld)
	$(if $(wildcard $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))),$(vecho) "RM $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))",)
	$(Q) $(RM) -r $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))

cleanDependencies: 

cleanAll: clean cleanDependencies

targets: 
	$(vecho) $(sort $(SUPPORTED_TARGETS_HelloWorld))

$(OBJODIR): 
	$(Q) mkdir -p $@

define CompileSources
$$(OBJODIR)/%.c.o: $(1)/%.c $$(ALL_INCS_$(2)) Makefile | $$(OBJODIR)
	$$(vecho) "CC $$<"
	$$(Q) $$(CC) $$(ALL_CFLAGS_$(2)) $$(ALL_INCDIR_FLAGS_$(2)) -c -o $$@ $$<
endef
$(foreach sdir, $(call parentDirs,$(ALL_SRCS_HelloWorld)), $(eval $(call CompileSources,$(sdir),HelloWorld)))

$(BINODIR): 
	$(Q) mkdir -p $@

define LinkObjectsToExecutable
ifeq ($$(BUILDABLE_$(1)),true)
$$(BINODIR)/$$(EXAFKT_$(1))$$(EXEXT_$(1)): $$(ALL_OBJS_$(1)) $$(ALL_LIBS_$(1)) | $$(BINODIR)
	$$(vecho) "LD $$(notdir $$@)"
	$$(Q) $$(LD) $$(LDFLAGS) -o $$@ $$(filter %.o,$$^) $$(ALL_LIBDIR_FLAGS_$(1)) $$(ALL_LIB_FLAGS_$(1))
else
$$(BINODIR)/$$(EXAFKT_$(1))$$(EXEXT_$(1)): 
	$$(vecho) "Cannot build $$(if $$(TARGET_SPECIFIC_$(1)),$$(SUPPORTED_TARGETS_$(1))-specific ,)'$$(EXAFKT_$(1))' application$$(if $$(and $$(TARGET_SPECIFIC_$(1)),$$(MATCHES_TARGET_$(1))),, for $$(TARGET))$$(if $$(and $$(filter-out $$(TARGET),$$(HOST)),$$(MATCHES_TARGET_$(1))), under $$(HOST),)."
endif
endef
$(eval $(call LinkObjectsToExecutable,HelloWorld))
EXT_LIBS_HelloWorld += $(if $(filter Win32,$(TARGET)),ws2_32,)

TEST_EXEC_OPTS = --build-dir=$(OROOT)$(if $(HOST_TAGS), --host-tags=$(HOST_TAGS),)
ifneq ($(CI),)
TEST_EXEC_OPTS += --isolated
endif

test: all
ifeq ($(BUILDABLE_HelloWorld),true)
	$(vecho) "Running HelloWorld"
	$(Q) $(BINODIR)/HelloWorld$(EXEXT_HelloWorld) $(TEST_EXEC_OPTS)
endif

