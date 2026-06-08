# KV Engine

A lightweight Redis-inspired in-memory key-value store built from scratch in C++.

This project is focused on learning low-level systems programming concepts such as:

* TCP networking
* socket programming
* file persistence
* protocol parsing
* memory management
* data structures
* concurrency

---

## Features

Current Features:

* Basic TCP server
* In-memory key-value storage
* Command parsing
* Client-server communication

Planned Features:

* Persistence (AOF/WAL)
* Hash/List/Set support
* TTL expiration
* Multi-client handling
* Custom protocol
* LRU cache
* Replication
* Benchmarking

---

## Tech Stack

* C++
* Linux sockets API
* STL data structures

---

## Project Structure

```txt
kv-engine/
│
├── src/
│   ├── main.cpp
│   ├── server/
│   ├── storage/
│   ├── parser/
│   └── persistence/
│
├── data/
├── tests/
├── docs/
└── README.md
```

---

## Getting Started

### Clone the Repository

```bash
git clone <your-repo-url>
cd kv-engine
```

### Compile

```bash
g++ src/main.cpp -o kv-engine
```

### Run

```bash
./kv-engine
```

---

## Goals

The goal of this project is not just to build a key-value database, but to deeply understand how systems like Redis work internally.

This project is being built step-by-step while learning:

* networking
* operating systems concepts
* storage internals
* protocol design

---

## Inspiration

Inspired by:

* Redis
* LevelDB
* Build Your Own Redis with C/C++

---

## Learning Notes

Some important concepts explored in this project:

* TCP is a byte stream
* sockets use file descriptors
* Linux follows "everything is a file"
* persistence through append-only logging
* protocol framing and parsing

---

## License

MIT License
