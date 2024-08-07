#include <iostream>

int main()
{
    int boardSize{8 * 8 * sizeof(long)};
    char *chessboard = new char[boardSize];

    int pieceCount{3};
    int firstFreePieceIndex{};
    // long **pieces = new long *[pieceCount];
    long *pieces[3]{};

    for (int pieceNo{}; pieceNo < pieceCount; pieceNo++)
    {
        std::cout << "Which square should the new objet of type \"long\" be placed?" << std::endl;
        std::cout << "Letter symbol: ";
        char letterSymbol;
        std::cin >> letterSymbol;
        int letterSymbolValue{letterSymbol - 'A'};

        if (letterSymbol == 'X')
            break;

        std::cout << "Number symbol: ";
        int numberSymbol;
        std::cin >> numberSymbol;
        int numberSymbolValue{numberSymbol - 1};

        int positionValue{8 * letterSymbolValue + numberSymbolValue};
        int byteNo{positionValue * sizeof(long)};

        std::cout << "Position in the array: " << positionValue << std::endl;
        std::cout << "Byte number: " << byteNo << std::endl;

        char *whereToPlaceThePiece = &chessboard[byteNo];
        long *pNewPiece{new (whereToPlaceThePiece) long};
        // *pNewPiece = positionValue;

        pieces[firstFreePieceIndex++] = pNewPiece;
    }

    // Print pieces
    std::cout << "Chessboard start: 0x" << std::hex << reinterpret_cast<long>(chessboard) << std::endl;

    for (int pieceNo{}; pieceNo < firstFreePieceIndex && pieceNo < pieceCount; pieceNo++)
    {
        std::cout << "Piece #" << pieceNo << " address: " << pieces[pieceNo] << std::endl;
    }
    // Delete created objects
    delete[] chessboard;

    return 0;
}
