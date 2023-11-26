/****************************************************************************** *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software.
 *****************************************************************************/
/**
 * @file data.h
 * @brief header file containing the function declarations of the program
 *
 * This program sorts and finds the max, min and median of an array.
 * The sort is in descending order (largest to smallest)
 *
 * @author Jordan (Zitian) Zhang
 * @date Nov. 23, 2023
 *
 */
// #ifndef __DATA_H__
// #define __DATA_H__
#include <stdint.h>

/**
 * @brief Convert data from a standard integer type into an ASCII string
 *
 * Given an integer data and a base range from 2-16, convert it into an ASCII
 * string
 *
 *
 * @param data A signed 32-bit integer, to be converted according to base
 * @param ptr Pointer storing the result of the conversion
 * @param base range from 2-16 (for example Base 16 is hexadecimal written in
 * ASCII form )
 * @return unint8_t the length of the converted data (including the negative
 * sign and the null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert data from an ASCII string into an integer type.
 *
 * Given an ASCII data and a base range from 2-16, convert it into an integer
 *
 * @param ptr Character string to be converted
 * @param digits The number of digits in the string
 * @param base base of the input string, ranges from 2-16
 * (for example Base 16 is hexadecimal written inASCII form )
 *
 * @return int32_t The 32-bit integer after conversion
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
