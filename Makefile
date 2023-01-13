CXXFLAGS := clang++ -Wall -std=c++17
SRC := ./src
RELEASEFLAGS := -DRELEASE
DEBUGFLAGS := -DDEBUG
COPYFILE := ./libs/lib/sdl2.dll
SRCDIRS := -I $(SRC)/Game -I $(SRC)/GameObject -I $(SRC)/Input -I $(SRC)/Window -I $(SRC)/Time -I $(SRC)/Graphics/Shader
SRCFILES := $(shell find $(SRC) -name '*.cpp')
HEADERFILES := $(shell find $(SRC) -name '*.hpp')
RELEASEDIR := ./release
DEBUGDIR := ./debug
WINRELEASE := ./winrelease
WINDEBUG := ./windebug
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
INCLUDEDIR := ./libs/include
LIBDIR := ./libs/lib
DYLIBS := $(LIB)/*.dylib
OUTPUT := run

# Create debug directory and compile exec
$(DEBUGDIR): $(OBJS)
	if ! [ -d "$(DEBUGDIR)" ]; then mkdir -p $(DEBUGDIR); fi
	$(CXXFLAGS) $(DEBUGFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lGLEW -lSDL2 -o $(DEBUGDIR)/$(OUTPUT) -framework OpenGL


# Create Build directory and compile exec
$(RELEASEDIR): $(OBJS)
	if ! [ -d "$(RELEASEDIR)" ]; then mkdir -p ./$(RELEASEDIR); fi
	$(CXXFLAGS) $(RELEASEFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lGLEW -lSDL2 -o $(RELEASEDIR)/$(OUTPUT) -framework OpenGL

# Create debug directory and compile exec
$(WINDEBUG): $(OBJS)
	if ! [ -d "$(DEBUGDIR)" ]; then mkdir -p $(DEBUGDIR); fi
	cp $(COPYFILE) $(DEBUGDIR)
	$(CXXFLAGS) $(DEBUGFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lopengl32 -lglu32 -lGLEW32s -lSDL2 -o $(DEBUGDIR)/$(OUTPUT).exe


#Create Build directory and compile exec
$(WINRELEASE): $(OBJS)
	if ! [ -d "$(RELEASEDIR)" ]; then mkdir -p ./$(RELEASEDIR); fi
	cp $(COPYFILE) $(RELEASEDIR)
	$(CXXFLAGS) $(RELEASEFLAGS) $(SRCFILES) -I $(INCLUDEDIR) $(SRCDIRS) -L $(LIBDIR) -lopengl32 -lglu32 -lGLEW32s -lSDL2 -o $(RELEASEDIR)/$(OUTPUT).exe

# Mark all headerfiles as dependencies for .cpp files
$(OBJS): $(HEADERFILES)

# uninstall xcode CLT
xcode remove:
	sudo rm -rf /Library/Developer/CommandLineTools

# Remove Build directory
clean:
	if [ -d "./$(RELEASEDIR)" ]; then rm -r $(RELEASEDIR); fi
	if [ -d "./$(DEBUGDIR)" ]; then rm -r $(DEBUGDIR); fi