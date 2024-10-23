# Pune Metro Travel Planner
stations updated until October 2024
## Overview
The Pune Metro Travel Planner is a console-based application that helps users plan their metro journeys by calculating the shortest route between stations using Dijkstra's algorithm (modified to suit the use case). The program displays the stations involved in the journey along with the total distance traveled.

## Features
- **Graph (Adjacency List)**: The primary data structure used is a graph represented as an adjacency list. Each station is indexed in the list, and its value is a vector of pairs that represent connected stations and their distances.
- **Vectors**: 
  - Used for storing the list of stations.
  - Used to represent the adjacency list.
  - Utilized for tracking distances and paths during the pathfinding process.
- **Queue**: A queue is employed for Dijkstra’s algorithm, modified for the metro system, allowing efficient processing of stations in the order they are discovered.

## Future Scope
This algorithm is designed to handle the addition of more stations and multiple travel options between stations. As the metro expands, new stations can be easily integrated into the graph structure with minimal changes to the program(without changing the algorithm).

## Output Example
The program provides:
- The total distance of the journey in kilometers.
- The path taken between the source and destination stations.
- Metro line information (Aqua or Purple Line).
  ![{8119B432-7667-4D45-B342-57F787827C6F}](https://github.com/user-attachments/assets/7ea39c1a-ca6a-4fac-bc98-7b3e193f8f92)
![{65DF4246-AF24-4167-8B58-8F7CEA503840}](https://github.com/user-attachments/assets/d1beca30-3fa0-4ab4-8d2c-b8c138215f93)
