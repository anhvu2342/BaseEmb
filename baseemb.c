#include "baseemb.h"
#include <stdbool.h>

uint8_t uint8_to_str(uint8_t num, uint8_t *str) {
    uint8_t temp[4];  // max 3 chars + '\0'
    uint8_t i = 0;

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return 1;
    }

    // take char 
    while (num > 0) {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }

    // reverse
    for (uint8_t j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[i] = '\0';

    return i;
}
#if HEX_HEXSTR_CVT_ON
const char hex_table[] = "0123456789ABCDEF";
/**
 * 
 * @param hex: input
 * @param hexstr: output
 * @return success/fail
 * @brief using dict table to find char, using flash memory
 */
bool hex_to_hexstr(uint8_t hex, uint8_t *hexstr){
    if(hex<16){
        *hexstr = hex_table[hex];
        return true;
    }
    return false;
}
#endif
uint8_t generate_crc8(const uint8_t* data, uint16_t data_len, uint8_t crc_init, uint8_t crc_polynomial) { 
    uint16_t current_byte;
    uint8_t crc = crc_init;
    uint8_t crc_bit;
    /* calculates 8-Bit checksum with given polynomial */ 
    for (current_byte = 0; current_byte < data_len; ++current_byte) { 
        crc ^= (data[current_byte]); 
        for (crc_bit = 8; crc_bit > 0; --crc_bit) {
            if (crc & 0x80) 
                crc = (crc << 1) ^ crc_polynomial; 
            else
                crc = (crc << 1); 
        }
    } 
    return crc; 
}