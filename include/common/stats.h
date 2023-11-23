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
 * @file stats.h
 * @brief header file containing the function declarations of the program
 *
 * This program sorts and finds the max, min and median of an array.
 * The sort is in descending order (largest to smallest)
 *
 * @author Jordan (Zitian) Zhang
 * @date Nov. 5, 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief print the statistics of an array
 *
 * Print the statitscs of an array including minimum, maximum,
 * mean, and median.
 *
 * @param unsigned char min - contains the minimum nubmer found in the array
 * @param unsigned char max - contains the maximum nubmer found in the array
 * @param unsigned char median - contains the median nubmer found in the array
 * @return None
 */
void print_statistics(unsigned char min, unsigned char max, unsigned char median);

/**
 * @brief prints an array
 *
 * Print an array to the screen, given its length
 *
 * @param char * data - A sorted character array contains the data to be printed
 * @param int length - the length of the array to be printed
 * @return None
 */
void print_array(unsigned char *data, int length);

/**
 * @brief find the median of an array of numbers
 *
 * Find the median in a sorted arrary of numbers
 *
 * @param char * data - A sorted character array contains the data to be processed
 * @param int length - the length of the array
 * @return unsinged char - the median number of the array
 */
unsigned char find_median(unsigned char * data, int length);

/**
 * @brief find the maximum of an array of numbers
 *
 * Find the maximum number in a sorted arrary of numbers
 *
 * @param char * data - A sorted character array contains the data to be processed
 * @param int length - the length of the array
 * @return unsinged char - the maximum number of the array
 */
unsigned char find_maximum(unsigned char * data, int length);

/**
 * @brief find the minimum of an array of numbers
 *
 * Find the minimum number in a sorted arrary of numbers
 *
 * @param char * data - A sorted character array contains the data to be processed
 * @param int length - the length of the array
 * @return unsinged char - the minimum number of the array
 */
unsigned char find_minimum(unsigned char * data, int length);

/**
 * @brief find the mean value of an array of numbers
 *
 * Find the mean value in a sorted arrary of numbers
 *
 * @param char * data - A sorted character array contains the data to be processed
 * @param int length - the length of the array
 * @return unsinged char - the mean average of the array
 */
unsigned char find_mean(unsigned char * data, int length);

/**
 * @brief sort the array from largest to smallest
 *
 * Sort an arrary of numbers from largest to smallest
 *
 * @param char * data - A character array contains the data to be sorted
 * @param int length - the length of the input array
 * @return None
 */
void sort_array(unsigned char * data, int length);

#endif /* __STATS_H__ */
