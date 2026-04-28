# Order Book Matching Engine

A from-scratch C++ limit order book matching engine with price-time priority. Single-threaded and in-memory, built to explore the data structures and algorithms behind real exchange infrastructure.

## Status

Work in progress. Currently implementing v1 (correct single-threaded matching).

See the [commit history](../../commits/main) for the project narrative.

## Building

Requires CMake 3.15+ and a C++20 compiler.

```bash
cmake -B build
cmake --build build
cd build && ctest --output-on-failure
```

## Roadmap

- v1: correct single-threaded matching engine _(in progress)_
- v2: LOBSTER replay validation, IOC/FOK orders
- v3: optimized hot path (object pool, intrusive list, flat price array)
- v4: FIX/binary protocol over TCP
- v5: multithreaded with single-writer ring buffer
