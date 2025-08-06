#include <stdio.h>
#include "defs.h"

void print_board_mappings() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%2d ", board_120_to_64[i]);
    }
    printf("\n");

    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0) {
            printf("\n");
        }
        printf("%2d ", board_64_to_120[i]);
    }
    printf("\n");
}

void bitboard_example() {
    uint64 bitboard = 0ULL;
    print_bit_board(bitboard);

    bitboard |= (1ULL << board_120_to_64[H8]);
    bitboard |= (1ULL << board_120_to_64[E4]);
    bitboard |= (1ULL << board_120_to_64[E5]);
    print_bit_board(bitboard);
    printf("Count of bits set: %d\n", count_bits(bitboard));

    int square = pop_bit(&bitboard);
    printf("Popped square: %d\n", square);
    print_bit_board(bitboard);
    printf("Count of bits set after pop: %d\n", count_bits(bitboard));
}

int main() {
    printf("Welcome to the %s\n", NAME);

    init_all();
    printf("Initialization complete\n\n");
    // print_board_mappings();
    bitboard_example();

    return 0;
}