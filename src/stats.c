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
 * @file stats.c
 * @brief This program sorts a given array and finds its minimum, maximum
 * and median
 *
 * The program sorts the array from largest to the smallest first. Then it
 * finds the minimum, maximum and median value using the sorted array.
 *
 * @author Jordan (Zitian) Zhang
 * @date Nov. 5, 2023
 *
 */



#include <stdio.h>
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void print_statistics(unsigned char min, unsigned char max, unsigned char median){
  printf("Minium: %d\n", min);
  printf("Maximum: %d\n", max);
  printf("Median: %d\n", median);
}

void print_array(unsigned char * data, int length){
  #ifdef VERBOSE
    PRINTF("[ ");
  #endif
  for (int i = 0; i < length; i++){
    #ifdef VERBOSE
      PRINTF("%d ", data[i]);
    #endif
  }
  #ifdef VERBOSE
    PRINTF("] \n");
  #endif
}

unsigned char find_median(unsigned char * data, int length){
  if (length % 2 == 0) {
    /*
   Array length is even -> median is the average of the two middle data points
   in a sorted array
    */
    // Integer division automatically rounds down when calculating median
    return ((data[length/2] + data[length/2 - 1])/2);
  }
  else {
    /* Array is even -> median is the middle data in a sorted array */
    return data[length/2];
  }
}

unsigned char find_maximum(unsigned char * data, int length){
  /* Maixmum is the first element of a sorted decending array */
  return data[0];
}

unsigned char find_minimum(unsigned char * data, int length){
  /* Minimum is the last element of a sorted decending array */
  return data[length - 1];
}

unsigned char find_mean(unsigned char * data, int length){
    int sum = 0;
    for (int i = 0; i < (length - 1); i++){
        sum += (int) data[i];
    }
    return sum / length;
}

void sort_array(unsigned char * data, int length){
  int i, j = 0;
  for(i = 0; i < (length - 1); i++) {
    /* from first element of the arry to the last, find the largest element
    in the rest of the array*/
    for (j = i + 1; j < length; j++ ) {
      if ((int)data[j] > (int)data[i]) {
        unsigned char tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}
