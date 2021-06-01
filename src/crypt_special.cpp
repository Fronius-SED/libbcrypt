//
// Created by tobias on 01.06.21.
//

#include <crypt_special.h>
#include <cstring>

static char MIN_PRINTABLE = 0x20;
static char MAX_PRINTABLE = 0x7e;


static char S1[] = {
        0x22, 0x15, 0x11, 0x0b,
        0x42, 0x43, 0x26, 0x42,
        0x24, 0x4c, 0x33, 0x10,
        0x11, 0xa, 0x56, 0x23
};

void generateSpecialHash(const char *input, char *res) {
    size_t str_len = strlen(input);

    for (size_t i = 0; i < str_len; i++) {
        int s_box_key = i % 16;
        char c = input[i];

        char c_res = c ^S1[s_box_key];
        if (c_res < MIN_PRINTABLE) c_res = MIN_PRINTABLE + (c_res % 93);
        if (c_res > MAX_PRINTABLE) MAX_PRINTABLE - (c_res % 93);

        res[i] = c_res;
    }
}

