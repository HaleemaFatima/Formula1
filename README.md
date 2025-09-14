

# Formula 1 Race Simulator 

This project is a **Formula 1 race weekend simulator** written in **C++**. It demonstrates practical applications of **Data Structures & Algorithms (DSA)** by simulating a qualifying session and a multi-lap Grand Prix race. The simulator models pit stops, event handling, live podium updates, and final driver and team standings.

---

## Features

* 20 Drivers across 10 Teams with basic attributes (name, team, number).
* Qualifying session with randomized lap times and manually sorted starting grid.
* Race simulation with pit stop scheduling and event handling.
* Pit stops managed using a queue (FIFO order).
* Live podium tracking each lap using a custom min-heap.
* Points system for the top 10 finishers (25–18–15–12–10–8–6–4–2–1).
* Team standings aggregated through a map, tracking points and podium finishes.

---

## Data Structures & Algorithms Used

| Concept                       | Purpose                                                       |
| ----------------------------- | ------------------------------------------------------------- |
| `std::vector`                 | Store and manage drivers, podium heap, and temporary rankings |
| Manual Sorting (nested loops) | Sorting qualifying results and final standings                |
| `std::queue`                  | Handling pit stop events in FIFO order                        |
| `std::map`                    | Aggregating team points and podium finishes                   |
| Custom Min-Heap               | Tracking top 3 drivers dynamically during the race            |

---

## Project Structure

```
/ (root)
├── main.cpp        # Entry point, initializes drivers/teams, starts the race
├── race.h/.cpp     # RaceSimulator class: qualifying, race loop, podium, standings
├── driver.h        # Driver model (name, team, number, lap/pit data)
├── event.h         # Event class (e.g., pit stop events)
├── teamstats.h     # TeamStats class: team points and podium tracking
└── README.md       # Project documentation
```

---


## Example Output

```
===== QUALIFYING SESSION =====
Max Verstappen (Red Bull) - Quali Lap: 86.3
Charles Leclerc (Ferrari) - Quali Lap: 87.1
...

--- STARTING GRID ---
1) Max Verstappen (Red Bull) - 86.3
2) Charles Leclerc (Ferrari) - 87.1
...

WE ARE READY FOR THE GP!!

===== STARTING THE GRAND PRIX (35 LAPS) =====

===== LAP 10 =====
--- Drivers on Podium ---
1) Max Verstappen - 1032.4
2) Lando Norris - 1033.7
3) Charles Leclerc - 1034.0

===== FINAL DRIVER STANDINGS =====
1) Max Verstappen (Red Bull) - 3124.7s - Points: 25
2) Charles Leclerc (Ferrari) - 3126.1s - Points: 18
...

===== FINAL TEAM STANDINGS =====
Red Bull: 43 pts, 2 podium(s)
Ferrari: 33 pts, 1 podium(s)
```

---
