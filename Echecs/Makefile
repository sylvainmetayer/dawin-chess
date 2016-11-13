SRC_CXX= Piece.cpp Cavalier.cpp Echiquier.cpp Fou.cpp JoueurBlanc.cpp JoueurNoir.cpp Joueur.cpp Pion.cpp Reine.cpp Roi.cpp Tour.cpp
	

OBJ=${SRC_CXX:.cpp=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	g++ -c $<

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

