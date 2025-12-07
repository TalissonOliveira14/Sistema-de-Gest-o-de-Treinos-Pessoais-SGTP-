CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
TARGET = sgtp
SRCDIR = src
BUILDDIR = build

SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Exercicio.cpp $(SRCDIR)/Cardio.cpp \
          $(SRCDIR)/Forca.cpp $(SRCDIR)/Ficha.cpp $(SRCDIR)/Historico.cpp \
          $(SRCDIR)/Sistema.cpp $(SRCDIR)/Utils.cpp
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET) data/*.txt

run: all
	./$(TARGET)

.PHONY: all clean run
