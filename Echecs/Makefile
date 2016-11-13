SRC_CXX=Piece.cpp Echiquier.cpp Cavalier.cpp Fou.cpp JoueurBlanc.cpp	JoueurNoir.cpp Joueur.cpp Pion.cpp Reine.cpp Roi.cpp Tour.cpp

OBJ=${SRC_CXX:.cpp=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) chess.o -o chess

%.o: %.cxx
	g++ -c $<

clean:
	@rm -f $(OBJ) chess.o chess *~

