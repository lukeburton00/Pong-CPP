CXXFLAGS := clang++ -Wall -std=c++17
SRC := ./src
SRCDIRS := -I $(SRC)/Game -I $(SRC)/Component -I $(SRC)/Input -I $(SRC)/Window
SRCFILES := $(shell find $(SRC) -name '*.cpp')
HEADERFILES := $(shell find $(SRC) -name '*.hpp')
BUILDDIR := ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
INCLUDEDIR := ./libs/include
LIBDIR := ./libs/lib
DYLIBS := $(LIB)/*.dylib
OUTPUT := run

# Create Build directory and compile exec
$(BUILDDIR)/$(OUTPUT): $(OBJS)
	if ! [ -d "./build" ]; then mkdir -p ./build; fi
	$(CXXFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lGLEW -lSDL2 -o $@ $^-framework OpenGL

# Mark all headerfiles as dependencies for .cpp files
$(OBJS): $(HEADERFILES)

# Check for xcode CLT and install
xcode:
	chmod +x install-xcode-clt.sh
	./install-xcode-clt.sh

# Remove Build directory
clean:
	if [ -d "./build" ]; then rm -r $(BUILDDIR); fi