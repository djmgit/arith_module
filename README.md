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
```
