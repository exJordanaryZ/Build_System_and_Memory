/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief This file should do some very basic data manipulation.
 *
 * @author Jordan Zhang
 * @date Nov. 23, 2023
 *
 */
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"
#include "platform.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    if ((base < 2) || (base > 16)){
        PRINTF("The base required - %d is not supported.", base);
        return 1;
    }
    uint8_t count = 0;
    *ptr = '\0';
    count++;

    bool negative;
    if (data < 0){
        negative = true;
        data *= -1;
    } else {
        negative = false;
    }

    do{
        uint8_t remainder = data % base;
        data /= base;
        if (remainder < 10){
            *(ptr + count) = remainder + '0';
        } else {
            *(ptr + count) = remainder + 'A';
        }
        count++;

    } while (data > 0);
    if (negative){
        *(ptr + count) = '-';
        count++;
    }
    my_reverse(ptr, count);
    PRINTF("%s, %d", ptr, count);
    return count;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    bool negative = false;
    int32_t res = 0;
    uint8_t i = 0;

    if (*ptr == '-'){
        negative = true;
        i = 1;
    }

    while (i < digits - 1){
        uint8_t ascii = *(ptr + i);

        if(ascii >= 'A'){
            ascii -= 'A';
        } else {
            ascii -= '0';
        }
        res *= base;
        res += ascii;
        i++;
    }

    if(negative){
        res *= -1;
    }
    return res;
}
