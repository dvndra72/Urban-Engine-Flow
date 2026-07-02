# Urban Engine Flow

Urban Engine Flow is a C++-based graph analytics engine for transportation network analysis. It models urban road networks as directed graphs and supports shortest path, maximum flow, and minimum cut computations using efficient graph algorithms.

---

## Features

- Shortest Path Analysis using Dijkstra's Algorithm
- Maximum Flow Computation using Dinic's Algorithm
- Minimum Cut Identification
- Directed Graph Representation
- JSON-based Input and Output using nlohmann/json

---

## Technologies Used

- C++
- Standard Template Library (STL)
- nlohmann/json

---

## Algorithms Implemented

| Algorithm | Description |
|-----------|-------------|
| Dijkstra's Algorithm | Computes the shortest path between two vertices |
| Dinic's Algorithm | Computes the maximum flow in a directed graph |
| Minimum Cut | Identifies the minimum cut in a flow network after maximum flow computation |

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

## How to Compile

```bash
g++ -std=c++17 cpp/engine.cpp -o engine
```

---

## Example Execution

```bash
./engine < input.json
```

The program accepts graph data in JSON format and outputs the requested graph analysis result in JSON.

---

## Future Enhancements

- Interactive command-line interface
- Additional graph algorithms
- Transportation network visualization
- Performance benchmarking on large-scale graphs

---

## Author

**Devendra Prajapat**
