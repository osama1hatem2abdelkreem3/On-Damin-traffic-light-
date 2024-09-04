/*
 * BitMath.h
 *
 * Created: 22/02/2023
 *  Author: osama
 */

#ifndef BITMATH_H_
#define BITMATH_H_
#include "Registers.h"
#define Set_Bit(REG, BIT) REG |= (1 << BIT)
#define Clear_Bit(REG, BIT) REG &= ~(1 << BIT)
#define Toggle_Bit(REG, BIT) REG ^= (1 << BIT)
#define Get_Bit(REG, BIT) ((REG >> BIT) & 0x01)

#endif /* BITMATH_H_ */