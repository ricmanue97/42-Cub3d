# cub3D 🕹️ - 42 School Lisbon

### Table of Contents
* [Introduction](#introduction-)
* [How to Install](#how-to-install-️)
* [How to Use?](#how-to-use-)
* [Project Objectives](#project-objectives-)
* [Game Features](#game-features-)
* [Conclusion](#conclusion-)


## Introduction 📖

cub3D is a 42 School project where students build a basic 3D raycasting engine, inspired by *Wolfenstein 3D*. It creates the illusion of a 3D environment using a 2D map, allowing the player to explore a world rendered in real time from a first-person perspective.

The challenge lies in implementing raycasting, texture mapping, player movement, and map parsing — all using only C and the lightweight MiniLibX graphics library.

## How to Install 🛠️

**Steps**

To compile and run cub3D, follow these steps:

**Dependencies:**
Ensure the following are installed on your system:

- `gcc` / `clang`
- `make`
- `MiniLibX`
- `libXext`, `libX11`, `zlib1g`, `libpng`, `mlx`

**Installing MiniLibX (Linux example):**
```bash
sudo apt-get update
sudo apt-get install libxext-dev libx11-dev zlib1g-dev
```

**Building the Project:**
```bash
make
```

## How to Use? 🎮

After building the project, run:
```bash
./cub3D maps/example.cub
```

Use the keyboard to move and rotate:
- `W`, `A`, `S`, `D`: Move forward, left, back, right
- `←`, `→`: Rotate camera left/right
- `ESC`: Exit game

**Map Format:**
Provide a `.cub` file that defines textures, colors, and the 2D layout of the map. Example:
```
NO ./sprites/North.xpm
F 128,128,128
SO ./sprites/South.xpm
WE ./sprites/West.xpm
C 250,250,250
EA ./sprites/East.xpm

111111
100001
101001
100N01
111111
```
(Here, `1` = wall, `0` = space, player starting position indicated by `N`, `S`, `E`, or `W`.)

## Project Objectives 🎯

cub3D aims to strengthen understanding of:

- Raycasting using DDA (Digital Differential Analysis)
- 2D → 3D rendering logic
- Texture mapping for walls
- Input handling (keyboard)
- Collision detection
- Game loop timing and optimization
- Parsing and validating complex file formats
- Efficient use of MiniLibX for drawing pixels and images

## Game Features 🧱

Core features of our cub3D implementation include:

- ✅ 2D Map parsing from `.cub` files
- ✅ First-person 3D view using raycasting
- ✅ Basic textures for walls
- ✅ Player movement and rotation
- ✅ Collision detection
- ✅ Dynamic window rendering with MiniLibX
- ✅ Floor and ceiling coloring
- ✅ Error handling for invalid maps
- ✅ Frame rate smoothing and optimization

### (Bonus Feature that we implemented):
- 🧭 Minimap rendering

## Conclusion ✅

cub3D was a rewarding challenge where we combined **math**, **graphics**, and **system-level programming** to build a basic 3D engine in C. It was developed by me and [@dicarval](https://github.com/dicarval).

This project not only reinforced fundamental graphics and memory management concepts, but also opened the door to more advanced game development and rendering techniques.
