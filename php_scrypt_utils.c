/*-
 * Copyright 2012 Dominic Black
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
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
#include "zend_exceptions.h"

/*
 * Casts a long into a uint64_t.
 *
 * Throws a php error if the value is out of bounds and will return 0.
 */
uint64_t clampAndCast64(uint32_t argNum, const char *argName, long value, long min)
{
	TSRMLS_FETCH();
	if (value <= min)
	{
#if PHP_VERSION_ID >= 80000
		zend_argument_error(NULL, argNum, "must be greater than %ld", min);
#else
		zend_throw_error(zend_ce_error, "scrypt(): Argument #%d ($%s) must be greater than %ld", argNum, argName, min);
#endif
		return 0;
	} else if (value > UINT64_MAX) {
#if PHP_VERSION_ID >= 80000
		zend_argument_error(NULL, argNum, "is too large");
#else
		zend_throw_error(zend_ce_error, "scrypt(): Argument #%d ($%s) is too large", argNum, argName);
#endif
		return 0;
	}

	return (uint64_t)value;
}

/*
 * Casts a long into a uint32_t.
 *
 * Throws an exception if the value is out of bounds and will return -1.
 */
uint32_t clampAndCast32(uint32_t argNum, const char *argName, long value, long min)
{
	TSRMLS_FETCH();
	if (value <= min)
	{
#if PHP_VERSION_ID >= 80000
		zend_argument_error(NULL, argNum, "must be greater than %ld", min);
#else
		zend_throw_error(zend_ce_error, "scrypt(): Argument #%d ($%s) must be greater than %ld", argNum, argName, min);
#endif
		return -1;
	} else if (value > UINT32_MAX) {
#if PHP_VERSION_ID >= 80000
		zend_argument_error(NULL, argNum, "is too large");
#else
		zend_throw_error(zend_ce_error, "scrypt(): Argument #%d ($%s) is too large", argNum, argName);
#endif
		return -1;
	}

	return (uint32_t)value;
}

/*
 * Checks if the given number is a power of two
 */
uint64_t isPowerOfTwo(uint64_t N)
{
  return N & (N - 1);
}
