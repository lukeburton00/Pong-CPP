CXX := clang++
CXXFLAGS := -Wall -std=c++17
SRC := ./src
SRCDIRS := -I $(SRC)/Game
SRCFILES := $(shell find $(SRC) -name '*.cpp')
HEADERFILES := $(shell find $(SRC) -name '*.hpp')
BUILDDIR := ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
INCLUDEDIR := ./libs/include
LIBDIR := ./libs/lib
DYLIBS := $(LIB)/*.dylib
OUTPUT := run

$(BUILDDIR)/$(OUTPUT): $(OBJS)
	mkdir -p ./build
	$(CXX) $(CXXFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lGLEW -lSDL2 -o $@ $^-framework OpenGL

$(OBJS): $(HEADERFILES)

xcode:
	chmod +x install-xcode-clt.sh
	./install-xcode-clt.sh


clean:
	rm -r $(BUILDDIR)