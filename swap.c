//
// Created by raulett on 04.07.2023.
//
#include "swap.h"



void swap(void * a, void * b, size_t const size_bytes)
{
    for(size_t byte_i = 0; byte_i < size_bytes; byte_i++)
    {
        uint8_t * const p_left_byte = ((uint8_t *) a) + byte_i;
        uint8_t * const p_right_byte = ((uint8_t *) b) + byte_i;
        uint8_t const tmp = *p_left_byte;
        *p_left_byte = *p_right_byte;
        *p_right_byte = tmp;
    }
}