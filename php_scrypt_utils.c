/*-
 * Copyright 2012 Dominic Black
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "php_scrypt_utils.h"
#include "php_scrypt.h"

/*
 * Casts a long into a uint64_t.
 *
 * Throws a php error if the value is out of bounds and will return 0.
 */
uint64_t clampAndCast64(int32_t arg_num, zend_long value, zend_long min)
{
	if (value <= min) {
		zend_argument_value_error(arg_num, "must be greater than %d", min);
		return 0;
    }

    if (value > UINT64_MAX) {
		zend_argument_value_error(arg_num, "must be less than or equal to %d", min);
		return 0;
	}

	return (uint64_t) value;
}

/*
 * Casts a long into a uint32_t.
 *
 * Throws an exception if the value is out of bounds and will return 0.
 */
uint32_t clampAndCast32(int32_t arg_num, zend_long value, zend_long min)
{
	if (value <= min) {
		zend_argument_value_error(arg_num, "must be greater than %d", min);
		return 0;
	}

	if (value > UINT32_MAX) {
		zend_argument_value_error(arg_num, "must be less than or equal to %d", min);
		return 0;
	}

    return (uint32_t) value;
}

/*
 * Checks if the given number is a power of two
 */
uint64_t isPowerOfTwo(uint64_t N)
{
	return N & (N - 1);
}
