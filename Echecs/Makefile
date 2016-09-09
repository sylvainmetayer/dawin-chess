SRC_CXX=\
	Piece.cpp

OBJ=${SRC_CXX:.cpp=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	g++ -c $<

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

