#include <stdio.h>
#include "defs.h"

const int bit_table[64] = {
    63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
    51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
    26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
    58, 20, 37, 17, 36, 8
};

int pop_bit(uint64 *bitboard) {
    // Isolate the least significant 1-bit in the bitboard
    uint64 bit = *bitboard ^ (*bitboard - 1);

    // Fold 64-bit value to 32 bits by XORing high and low halves (for hashing)
    unsigned int fold = (unsigned) ((bit & 0xFFFFFFFF) ^ (bit >> 32));

    // Clear the least significant 1-bit in the bitboard
    *bitboard &= (*bitboard - 1);

    // Multiply with de Bruijn constant and use top 6 bits for index lookup
    return bit_table[(fold * 0x783A9B23) >> 26];
}

int count_bits(uint64 bitboard) {
    int result;

    // Loop until all bits are cleared
    // Each iteration clears the least significant 1-bit
    for (result = 0; bitboard; result++, bitboard &= (bitboard - 1));

    // Return the number of 1-bits that were in the original bitboard
    return result;
}

void print_bit_board(uint64 bitboard) {
    uint64 shift_me = 1ULL;
    int rank = 0;
    int file = 0;
    int square = 0;
    int sqr_64 = 0;

    for (rank = RANK_8; rank >= RANK_1; rank--) {
        for (file = FILE_A; file <= FILE_H; file++) {
            square = FILE_RANK_2_SQUARE(file, rank);
            sqr_64 = board_120_to_64[square];
            if ((shift_me << sqr_64) & bitboard) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}