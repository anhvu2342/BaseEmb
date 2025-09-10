#ifndef BASEEMB_H
#define BASEEMB_H

#include <cstdint>
// ===================== ON/OFF SWITCH MACRO =======================
// #define HEX_HEXSTR_CVT_ON   0
// #define ESP32_DEBUG_ON      0

// ========================== BASIC MACRO ==========================
// Bit operation
#define BIT_SET(REG, BIT)     ((REG) |=  (1U << (BIT)))
#define BIT_CLEAR(REG, BIT)   ((REG) &= ~(1U << (BIT)))
#define BIT_TOGGLE(REG, BIT)  ((REG) ^=  (1U << (BIT)))
#define BIT_CHECK(REG, BIT)   (((REG) >> (BIT)) & 0x1U)
// Multi-bit operation
#define BITS_SET(REG, MASK)    ((REG) |=  (MASK))
#define BITS_CLEAR(REG, MASK)  ((REG) &= ~(MASK))
// Pointer operation
#define PTR_CHECKNULL(ptr)  ((ptr) != NULL)
// Min, Max, Clamp, Abs
#define MIN(a, b)   (((a) < (b)) ? (a) : (b))
#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
#define CLAMP(x, min_val, max_val) ( ((x) < (min_val)) ? (min_val) : (((x) > (max_val)) ? (max_val) : (x)) )
#define ABS(x)      (((x) < 0) ? -(x) : (x))
// Uint8_t process
#define U8_LOWNIBBLE(x)    ((x) & 0x0F)
#define U8_HIGHNIBBLE(x)   (((x) >> 4) & 0x0F)


// ======================= EMBEDDED FUNCTION =======================
// Convert data type function
uint8_t uint8_to_str(uint8_t num, uint8_t *str);
#if HEX_HEXSTR_CVT_ON
bool hex_to_hexstr(uint8_t hex, uint8_t *hexstr);
#endif


// Calculate function
uint8_t generate_crc8(const uint8_t* data, uint16_t data_len, uint8_t crc_init, uint8_t crc_polynomial);







// ===================== ESP32 FUNCTION =====================
// Debug function
#if ESP32_DEBUG_ON
    #define ESP_PRINTI(tag, str, ...) ESP_LOGI(tag, str, ##__VA_ARGS__)
    #define ESP_PRINTE(tag, str, ...) ESP_LOGE(tag, str, ##__VA_ARGS__)
    #define ESP_PRINTW(tag, str, ...) ESP_LOGW(tag, str, ##__VA_ARGS__)
    #define ESP_PRINTD(tag, str, ...) ESP_LOGD(tag, str, ##__VA_ARGS__)
#endif

// ========================== OTHER =========================
typedef enum {
    EMB_OK = 1,
    I2C_CRC_FAILED,
    UART_DATA_NOT_EXIST,
} general_stt_t;
#endif