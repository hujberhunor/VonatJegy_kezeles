# GNU make verzió

# Program neve (ezt állítjuk elő)
PROG = wMakeMain

# Program forrásfájljai
SRCS = main.cpp allomas.cpp ido.cpp mav.cpp

# Header fileok
HDRS = allomas.h vonat.h jegy.h mav.h kiosk.h seged.h

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
