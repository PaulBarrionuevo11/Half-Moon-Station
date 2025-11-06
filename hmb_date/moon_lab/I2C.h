#ifndef I2C_H_
#define I2C_H_
#include <stdint.h>

// I2C_MS_MODE select Master or slave mode
// REG_I2C_BASE+0x100. Each byte of I2C data is stored in a 32-bit word of memory
// (so, the first byte is at +0x100, the second byte at +0x104, the third byte at +0x108, etc.) 

class I2C
{

};