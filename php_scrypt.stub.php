<?php

/** @generate-class-entries */

function scrypt(string $password, string $salt, int $N, int $r, int $p, int $key_length, bool $raw_output = false): string|false {}

function scrypt_pickparams(int $max_memory, float $memory_fraction, float $max_time): array|false {}