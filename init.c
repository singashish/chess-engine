#include "defs.h"

int board_120_to_64[BOARD_SIZE];
int board_64_to_120[64];
uint64 set_mask[64];
uint64 clear_mask[64];

void init_bit_masks() {
    for (int i = 0; i < 64; i++) {
        set_mask[i] = 0ULL;
        clear_mask[i] = 0ULL;
    }

    for (int i = 0; i < 64; i++) {
        set_mask[i] = (1ULL << i);
        clear_mask[i] = ~(1ULL << i);
    }
}

void init_board_120_to_64() {
    int idx = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int square_120 = A1;
    int square_64 = 0;

    for (idx = 0; idx < BOARD_SIZE; idx++) {
        board_120_to_64[idx] = 64; // Initialize to an invalid square
    }

    for (idx = 0; idx < 64; idx++) {
        board_64_to_120[idx] = 120; // Initialize to an invalid square
    }

    for (rank = RANK_1; rank <= RANK_8; rank++) {
        for (file = FILE_A; file <= FILE_H; file++) {
            square_120 = FILE_RANK_2_SQUARE(file, rank);
            board_64_to_120[square_64] = square_120;
            board_120_to_64[square_120] = square_64;
            square_64++;
        }
    }
}

void init_all() {
    init_board_120_to_64();
    init_bit_masks();
}