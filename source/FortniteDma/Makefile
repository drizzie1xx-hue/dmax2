##############################################################################
# MinGW-w64 cross-compilation Makefile for FortniteDma
# Target: Windows x64 executable
# Build: make
# Output: FortniteDma.exe  (plus required DLLs in dll/)
##############################################################################

CXX      := x86_64-w64-mingw32-g++
WINDRES  := x86_64-w64-mingw32-windres
STRIP    := x86_64-w64-mingw32-strip

PROJECT  := FortniteDma
SRCDIR   := src
EXTDIR   := external
DLLDIR   := dll
OUTDIR   := build

##############################################################################
# Source files (matches FortniteDma.vcxproj ClCompile list)
##############################################################################
SRCS := \
    $(EXTDIR)/imgui/imgui.cpp \
    $(EXTDIR)/imgui/imgui_demo.cpp \
    $(EXTDIR)/imgui/imgui_draw.cpp \
    $(EXTDIR)/imgui/imgui_impl_dx11.cpp \
    $(EXTDIR)/imgui/imgui_impl_win32.cpp \
    $(EXTDIR)/imgui/imgui_tables.cpp \
    $(EXTDIR)/imgui/imgui_widgets.cpp \
    $(SRCDIR)/dma/DMAHandler.cpp \
    $(SRCDIR)/kmbox/kmboxNet.cpp \
    $(SRCDIR)/menu/menu.cpp \
    $(SRCDIR)/main.cpp

OBJS := $(patsubst %.cpp,$(OUTDIR)/%.o,$(SRCS))

##############################################################################
# Include paths
##############################################################################
INCDIRS := \
    -I$(EXTDIR) \
    -Icompat \
    -I$(SRCDIR) \
    -I$(SRCDIR)/cheat \
    -I$(SRCDIR)/dma \
    -I$(SRCDIR)/kmbox \
    -I$(SRCDIR)/menu \
    -I$(SRCDIR)/rendering \
    -I$(SRCDIR)/console

##############################################################################
# Compiler flags
##############################################################################
CXXFLAGS := \
    $(INCDIRS) \
    -include compat/msvc_compat.h \
    -std=c++20 \
    -O2 \
    -DNDEBUG \
    -D_CRT_SECURE_NO_WARNINGS \
    -DUNICODE \
    -D_UNICODE \
    -D_WIN32 \
    -DNOMINMAX \
    -Wno-attributes \
    -Wno-deprecated-declarations \
    -Wno-unused-result \
    -fpermissive \
    -fexceptions

##############################################################################
# Library flags
##############################################################################
LIBDIRS := -L$(DLLDIR)

LIBS := \
    -lvmm \
    -lleechcore \
    -lFTD3XX \
    -ld3d11 \
    -ldwmapi \
    -lws2_32 \
    -lsetupapi \
    -ld3dcompiler \
    -ldxgi \
    -luuid \
    -lole32

LDFLAGS := \
    $(LIBDIRS) \
    $(LIBS) \
    -mwindows \
    -static-libgcc \
    -static-libstdc++

##############################################################################
# Build rules
##############################################################################
.PHONY: all clean

all: dirs $(OUTDIR)/$(PROJECT).exe

dirs:
	@mkdir -p $(OUTDIR)
	@mkdir -p $(OUTDIR)/$(EXTDIR)/imgui
	@mkdir -p $(OUTDIR)/$(SRCDIR)/dma
	@mkdir -p $(OUTDIR)/$(SRCDIR)/kmbox
	@mkdir -p $(OUTDIR)/$(SRCDIR)/menu

$(OUTDIR)/%.o: %.cpp
	@echo "[CXX] $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTDIR)/$(PROJECT).exe: $(OBJS)
	@echo "[LINK] $@"
	$(CXX) $(OBJS) $(LDFLAGS) -o $@
	@echo "[OK] Built: $@"
	@echo ""
	@echo "Required DLLs to ship alongside the EXE:"
	@echo "  vmm.dll  leechcore.dll  FTD3XX.dll  dbghelp.dll  symsrv.dll"
	@echo "  info.db  mmap.txt (generated at runtime)"

clean:
	rm -rf $(OUTDIR)
