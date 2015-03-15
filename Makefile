SOURCES=$(wildcard src/*.cpp)
TARGET=coding_test

CPPFLAGS += -MD -MP
CXXFLAGS += -Wall -Wpedantic -std=c++11
OBJECTS=$(SOURCES:.cpp=.o)
DEPENDENCIES=$(SOURCES:.cpp=.d)

all: $(SOURCES) $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(OBJECTS) $(DEPENDENCIES) $(TARGET)

-include $(DEPENDENCIES)
