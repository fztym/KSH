# KSH — Data Structures & Algorithms in C++

A collection of carefully crafted data structures and algorithms implemented in modern C++.
This library grows over time as new components are added — starting from fundamental building
blocks and gradually expanding to more advanced topics.

## Requirements

- **C++20** or later
- **CMake** ≥ 3.20
- **Clang++** (default; GCC also works after adjusting `CMakeLists.txt`)

## Project Structure

```
KSH/
├── include/          # Header-only library files
│   ├── Dlist.h       # Doubly-linked list
│   └── LRU.h         # LRU (Least Recently Used) cache
├── tests/            # Unit tests & usage examples
│   └── test_LRU.cpp
├── CMakeLists.txt    # Build configuration
└── README.md
```

## Components

| File | Description |
|------|-------------|
| `Dlist.h` | A generic doubly-linked list supporting O(1) push/pop at both ends, full copy/move semantics, and in-order traversal. |
| `LRU.h` | A generic least-recently-used cache built on `std::list` and `std::unordered_map`, providing O(1) `get` and `put` with automatic eviction. |

More data structures and algorithms will be added over time — check back for updates.

## Build & Run

```bash
# Configure (from the project root)
cmake -B build -S .

# Build
cmake --build build

# Run the example / smoke test
./build/lru
```

## Design Philosophy

- **Modern C++** — uses C++20, templates, RAII, and const-correctness throughout.
- **Header-only** — no separate compilation units; drop the headers into your project and go.
- **Well-tested** — every component is backed by tests in the `tests/` directory.
- **Clean & readable** — code is structured for learning as much as for production use.

## License

MIT
