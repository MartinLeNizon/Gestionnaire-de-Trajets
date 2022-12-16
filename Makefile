CXX = g++
DEBUG = no
ifeq ($(DEBUG),yes)
	CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -g
	LDFLAGS = -DMAP
else
	CXXFLAGS = -ansi -pedantic -Wall -std=c++11
	LDFLAGS =
endif
EXEC  = trajet
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Mode debug"
else
	@echo "Mode release"
endif

$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)

TrajetSimple.o: Trajet.h

Maillon.o: Trajet.h

ListeChainee.o: Trajet.h Maillon.h

TrajetCompose.o: Trajet.h TrajetSimple.h ListeChainee.h

Catalogue.o: ListeChainee.h

main.o: Trajet.h TrajetSimple.h Maillon.h ListeChainee.h TrajetCompose.h Catalogue.h

%.o: %.cpp
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY:clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
