#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "1.hpp"

using namespace std;

/* class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard board) {
        board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_lost_game = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game" << endl;
        };
        board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };
        board.after_piece_move = [](const auto squares) {
            string print = "";
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    auto &square = squares[i][j];
                    if(square)
                        print += square.get()->type_short();
                    else if((i + j) % 2 == 0)
                        print += "███";
                    else 
                        print += "   ";
                }
                print += "\n";
            }
            cout << print + "\n";
        };
    }
}; */

int main() {
    ChessBoard board;
    //ChessBoardPrint print(board);

    board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
        cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
        cout << piece.type() << " is being removed from " << square << endl;
    };
    board.on_lost_game = [](ChessBoard::Color color) {
        if (color == ChessBoard::Color::WHITE)
            cout << "Black";
        else
            cout << "White";
        cout << " won the game" << endl;
    };
    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
        cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };
    board.on_piece_move_missing = [](const string &square) {
        cout << "no piece at " << square << endl;
    };

  // board.squares[4][0] is the same as board.squares[4][0] but with range check
  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
