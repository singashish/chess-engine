#ifndef DEFS_H
#define DEFS_H

/*
    0    1    2    3    4    5    6    7    8    9

   10   11   12   13   14   15   16   17   18   19
      ┌────┬────┬────┬────┬────┬────┬────┬────┐
   20 │ 21 │ 22 │ 23 │ 24 │ 25 │ 26 │ 27 │ 28 │ 29
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   30 │ 31 │ 32 │ 33 │ 34 │ 35 │ 36 │ 37 │ 38 │ 39
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   40 │ 41 │ 42 │ 43 │ 44 │ 45 │ 46 │ 47 │ 48 │ 49
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   50 │ 51 │ 52 │ 53 │ 54 │ 55 │ 56 │ 57 │ 58 │ 59
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   60 │ 61 │ 62 │ 63 │ 64 │ 65 │ 66 │ 67 │ 68 │ 69
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   70 │ 71 │ 72 │ 73 │ 74 │ 75 │ 76 │ 77 │ 78 │ 79
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   80 │ 81 │ 82 │ 83 │ 84 │ 85 │ 86 │ 87 │ 88 │ 89
      ├────┼────┼────┼────┼────┼────┼────┼────┤
   90 │ 91 │ 92 │ 93 │ 94 │ 95 │ 96 │ 97 │ 98 │ 99
      └────┴────┴────┴────┴────┴────┴────┴────┘
   100  101  102  103  104  105  106  107  108  109

   110  111  112  113  114  115  116  117  118  119


        a    b    c    d    e    f    g    h
      ┌────┬────┬────┬────┬────┬────┬────┬────┐
    1 │ 00 │ 01 │ 02 │ 03 │ 04 │ 05 │ 06 │ 07 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    2 │ 08 │ 09 │ 10 │ 11 │ 12 │ 13 │ 14 │ 15 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    3 │ 16 │ 17 │ 18 │ 19 │ 20 │ 21 │ 22 │ 23 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    4 │ 24 │ 25 │ 26 │ 27 │ 28 │ 29 │ 30 │ 31 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    5 │ 32 │ 33 │ 34 │ 35 │ 36 │ 37 │ 38 │ 39 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    6 │ 40 │ 41 │ 42 │ 43 │ 44 │ 45 │ 46 │ 47 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    7 │ 48 │ 49 │ 50 │ 51 │ 52 │ 53 │ 54 │ 55 │
      ├────┼────┼────┼────┼────┼────┼────┼────┤
    8 │ 56 │ 57 │ 58 │ 59 │ 60 │ 61 │ 62 │ 63 │
      └────┴────┴────┴────┴────┴────┴────┴────┘
*/

#include <stdlib.h>

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) if (!(n)) {                                                                           \
    printf("Assertion Failed: %s on %s at %s in %s:%d\n", #n, __DATE__, __TIME__, __FILE__, __LINE__);  \
    exit(EXIT_FAILURE);                                                                                 \
}
#endif

typedef unsigned long long uint64;

#define NAME "Chess Engine"
#define BOARD_SIZE 120
#define MAX_MOVES 2048

enum { EMPTY, W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
              B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

typedef struct {
    int move;
    int castle_permits;
    int en_passant;
    int fifty_move;
    int pos_key;
} Undo;


enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQUARE = 99
};

enum { FALSE = 0, TRUE = 1 };

enum { WHITE_KING_CASTLE = 1, WHITE_QUEEN_CASTLE = 2,
       BLACK_KING_CASTLE = 4, BLACK_QUEEN_CASTLE = 8 };

typedef struct {
    int pieces[BOARD_SIZE];
    uint64 pawns[3];

    int king_square[2];

    int side;
    int en_passant;
    int fifty_move;

    int play;
    int history_play;

    int castle_permits;

    uint64 pos_key;

    int piece_num[13];
    int big_piece[3];
    int major_piece[3];
    int minor_piece[3];

    Undo history[MAX_MOVES];

    // Piece list
    int piece_list[13][10];
} Board;

// MACROS
#define FILE_RANK_2_SQUARE(file, rank) (21 + (file) + ((rank) * 10))
#define CLR_BIT(bitboard, sqr_64) ((bitboard) &= clear_mask[sqr_64])
#define SET_BIT(bitboard, sqr_64) ((bitboard) |= set_mask[sqr_64])

// GLOBALS
extern int board_120_to_64[BOARD_SIZE];
extern int board_64_to_120[64];
extern uint64 set_mask[64];
extern uint64 clear_mask[64];

// FUNCTIONS
extern void init_all();
extern int pop_bit(uint64 *bitboard);
extern int count_bits(uint64 bitboard);
extern void print_bit_board(uint64 bitboard);

#endif // DEFS_H