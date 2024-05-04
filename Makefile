# GNU make verzió

# Program neve (ezt állítjuk elő)
PROG = wMakeMain

# Program forrásfájljai
SRCS = beolvas.cpp  

# Header fileok
HDRS = ./header/allomas.h ./header/vonat.h

# Fordítási kapcsolók: legyen pedáns és legyenek figyelmeztetések
CXXFLAGS = -pedantic -Wall

# Debug információval fordítás
CXXFLAGS += -ggdb

# Linkelésnél debug információval
LDFLAGS = -ggdb

# Alapértelmezett cél: a program
.PHONY: all
all: $(PROG)

$(PROG): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

# Takarítás
.PHONY: clean
clean:
	rm -f $(PROG)
