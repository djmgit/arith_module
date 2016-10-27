# Arith Module

## About the module

  Arith module contains 6 arithmetic methods that can be applied on simple keys and 1 arithmetic method 
  which can be applied on lists.
  
## Arith methods

### ARITH.SUM

ARITH.SUM key1 key2 key3

Add the values of key1 and key2 and stores the result in key3 and displays the result.

### ARITH.SUB

ARITH.SUB key1 key2 key3

Subtracts the value of key2 from key1 and stores the result in key3 and displays the result.

### ARITH.PROD

ARITH.PROD key1 key2 key3

Multiply the values of key1 and key2 and stores the result in key3 and displays the result.

### ARITH.DIV

ARITH.DIV key1 key2 key3

Divides the value of key1 by key2 and stores the quotient in key3 and displays the quotient.
The value of key3 should be non-zero.

### ARITH.MOD

ARITH.MOD key1 key2 key3

Divides the value of key1 by key2 and stores the remainder in key3 and displays the remainder.

### ARITH.POW

ARITH.POW key1 key2 key3

Raises the value of key1 to the power of key2 and stores the result in key3 and displays the result.

### ARITH.LINCRBY

ARITH.LINCRBY listkey increment_value start_index end_index

Increases the values present in the range from start_index to end_index (start_index and end_index inclusive) by increment_value

# Quick Start Guide

Here's what you need to do build arith_module:

0. Build Redis in a build supporting modules.
1. Clone this repository or download zip
2. cd arith_module
3. Build librmutil: `cd rmutil && make`
4. Build the arith module: `cd arith && make`
5. Run redis loading the module: `/path/to/redis-server --loadmodule ./arith/module.so`

Now run `redis-cli` and try the commands:

```
127.0.0.1:6379> SET key1 400
OK
127.0.0.1:9979> SET key2 150
OK
127.0.0.1:9979> ARITH.SUM key1 key2 key3
(integer) 550
127.0.0.1:9979> GET key3
"550"
127.0.0.1:9979> ARITH.SUB key1 key2 key3
(integer) 250
127.0.0.1:9979> GET key3
"250"
127.0.0.1:9979> ARITH.PROD key1 key2 key3
(integer) 60000
127.0.0.1:9979> GET key3
"60000"
127.0.0.1:9979> ARITH.DIV key1 key2 key3
(integer) 2
127.0.0.1:9979> GET key3
"2"
127.0.0.1:9979> ARITH.MOD key1 key2 key3
(integer) 100
127.0.0.1:9979> GET key3
"100"
127.0.0.1:6379> SET key1 2
OK
127.0.0.1:9979> SET key2 4
OK
127.0.0.1:9979> ARITH.POW key1 key2 key3
(integer) 16
127.0.0.1:9979> GET key3
"16"
127.0.0.1:6379> RPUSH listkey 1 2 3 4 5
(integer) 5
127.0.0.1:6379> ARITH.LINCRBY listkey 100 1 3
(integer) 3
127.0.0.1:6379> LRANGE listkey 0 -1
1) "1"
2) "102"
3) "103"
4) "104"
5) "5"

```
