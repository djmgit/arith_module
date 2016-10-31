# Arith Module

## About the module

  Arith module contains 6 arithmetic methods that can be applied on simple keys with integer values 
  and 1 arithmetic method which can be applied on lists integer values and two utility method for lists 
  with type of value.
  
## Arith methods

### ARITH.SUM
```
ARITH.SUM key1 key2 key3
```
Applicable on keys with integer values

Add the values of key1 and key2 and stores the result in key3 and displays the result.
> Time Complexity O(1)

### ARITH.SUB
```
ARITH.SUB key1 key2 key3
```
Applicable on keys with integer values

Subtracts the value of key2 from key1 and stores the result in key3 and displays the result.
> Time Complexity O(1)

### ARITH.PROD
```
ARITH.PROD key1 key2 key3
```
Applicable on keys with integer values

Multiply the values of key1 and key2 and stores the result in key3 and displays the result.
> Time Complexity O(1)

### ARITH.DIV
```
ARITH.DIV key1 key2 key3
```
Applicable on keys with integer values

Divides the value of key1 by key2 and stores the quotient in key3 and displays the quotient.
The value of key3 should be non-zero.
> Time Complexity O(1)

### ARITH.MOD
```
ARITH.MOD key1 key2 key3
```
Applicable on keys with integer values

Divides the value of key1 by key2 and stores the remainder in key3 and displays the remainder.
> Time Complexity O(1)

### ARITH.POW
```
ARITH.POW key1 key2 key3
```
Applicable on keys with integer values

Raises the value of key1 to the power of key2 and stores the result in key3 and displays the result.
> Time Complexity O(1)

### ARITH.LINCRBY
```
ARITH.LINCRBY listkey increment_value start_index end_index
```
Applicable on lists with integer values

Increases the values present in the range from start_index to end_index (start_index and end_index inclusive) by increment_value
and returns the length of the range on success
> Time Complexity O(N)

### ARITH.LRSUM
```
ARITH.LRSUM listkey start_index end_index sum_key
```
Applicable on lists with integer values

Adds all the values prsent in the range from start_index to end_index (start_index and end_index inclusive) and
returns the sum. The sum_key argument is optional. If present then the sum is stored in sum_key.
> Time Complexity O(N)

### ARITH.LRMAX
```
ARITH.LRSUM listkey start_index end_index result_key
```
Applicable on lists with integer values

Finds the largest value present in the range from start_index to end_index (start_index and end_index inclusive) and
returns the max value. The result_key argument is optional. If present then the max value is stored in result_key. 
> Time Complexity O(N)

### ARITH.LRMIN
```
ARITH.LRMIN listkey start_index end_index result_key
```
Applicable on lists with integer values

Finds the lowest value present in the range from start_index to end_index (start_index and end_index inclusive) and
returns the min value. The result_key argument is optional. If present then the min value is stored in result_key. 
> Time Complexity O(N)

### ARITH.LLSUM
```
ARITH.LLSUM listkey1 listkey2 listkey3
```
Applicable on lists with integer values

Adds the corresponding values of lists speified by listkey1 and listkey2 and stores the values in listkey3 and
returns the list length on success. The length of lists specified by listkey1 and listkey2 must be equal
> Time Complexity O(N)

### ARITH.LLKPUSH
```
ARITH.LLKPUSH listkey key1 key2 key3 ...
```
This method inserts the values of keys specified by key1, key2 and so on to list specified by listkey from left
and returns the number of values added on success.
> Time Complexity O(N)

### ARITH.LRKPUSH
```
ARITH.LRKPUSH listkey key1 key2 key3 ...
```
This method inserts the values of keys specified by key1, key2 and so on to list specified by listkey from right
and returns the number of values added on success.
> Time Complexity O(N)

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
127.0.0.1:6379> RPUSH list 2 4 1 7 9
(integer) 5
127.0.0.1:6379> LRANGE list 0 -1
1) "2"
2) "4"
3) "1"
4) "7"
5) "9"
127.0.0.1:6379> ARITH.LRSUM list 1 3 sum
(integer) 12
127.0.0.1:6379> GET sum
"12"
127.0.0.1:6379> ARITH.LRMAX list 1 3 max
(integer) 7
127.0.0.1:6379> GET max
"7"
127.0.0.1:6379> ARITH.LRMIN list 1 3 min
(integer) 1
127.0.0.1:6379> GET min
"1"
127.0.0.1:6379> RPUSH list2 1 6 3 8 4
(integer) 5
127.0.0.1:6379> LRANGE list 0 -1
1) "2"
2) "4"
3) "1"
4) "7"
5) "9"
127.0.0.1:6379> LRANGE list2 0 -1
1) "1"
2) "6"
3) "3"
4) "8"
5) "4"
127.0.0.1:6379> ARITH.LLSUM list list2 list3
(integer) 5
127.0.0.1:6379> LRANGE list3 0 -1
1) "3"
2) "10"
3) "4"
4) "15"
5) "13"
127.0.0.1:6379> SET key1 2
OK
127.0.0.1:6379> SET key2 4
OK
127.0.0.1:6379> SET key3 10
OK
127.0.0.1:6379> ARITH.LLKPUSH list4 key1 key2 key3
(integer) 3
127.0.0.1:6379> LRANGE list4 0 -1
1) "10"
2) "4"
3) "2"
127.0.0.1:6379> ARITH.LRKPUSH list5 key1 key2 key3
(integer) 3
127.0.0.1:6379> LRANGE list5 0 -1
1) "2"
2) "4"
3) "10"

```
