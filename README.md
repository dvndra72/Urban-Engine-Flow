# Urban Engine Flow

Urban Engine Flow is a C++-based graph analytics engine for transportation network analysis. It models urban road networks as directed graphs and supports efficient shortest path, maximum flow, and minimum cut computations using classical graph algorithms.

---

## Features

- Shortest Path Analysis using Dijkstra's Algorithm
- Maximum Flow Computation using Dinic's Algorithm
- Minimum Cut Identification
- Directed Graph Representation
- JSON-based Input and Output using nlohmann/json

---

## Technologies

- C++
- STL (Standard Template Library)
- nlohmann/json

---

## Algorithms Implemented

| Algorithm | Purpose |
|-----------|---------|
| Dijkstra's Algorithm | Computes the shortest path between two nodes |
| Dinic's Algorithm | Computes the maximum flow in a flow network |
| Minimum Cut | Identifies the minimum cut after maximum flow computation |

---

## Repository Structure

```
Urban-Engine-Flow/
│
├── cpp/
│   ├── engine.cpp
│   ├── json.hpp
│   └── README.md
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## Future Improvements

- Interactive command-line interface
- Additional graph algorithms
- Transportation network visualization
- Performance benchmarking on large-scale road networks

---

## Author

Devendra Prajapat
