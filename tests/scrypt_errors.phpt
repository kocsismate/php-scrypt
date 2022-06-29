--TEST--
Test scrypt() error conditions
--SKIPIF--
<?php if (!extension_loaded("scrypt")) print "skip"; ?>
--FILE--
<?php

try {
	scrypt("", "", 1, 1, 1, 64);
} catch (ValueError $e) {
	echo $e->getMessage() . "\n";
}

try {
	scrypt("", "", 16, 0, 1, 64);
} catch (ValueError $e) {
	echo $e->getMessage() . "\n";
}
?>
--EXPECT--
scrypt(): Argument #3 ($N) must be greater than 1
scrypt(): Argument #4 ($r) must be greater than 0
