# FdF - Wireframe Landscape Renderer 🌄

Welcome to **FdF**! This project is a graphical program that renders 3D wireframe landscapes from a 2D height map. It’s a fascinating dive into computer graphics, matrix transformations, and perspective projection.

## 📖 Project Overview
The FdF project reads a text-based map file containing height values for a grid of points. Each point on the map corresponds to a vertex in a 3D landscape, and the program projects this 3D representation onto a 2D plane to create a visually engaging wireframe.

### Key Features
- **3D to 2D Projection**: Uses mathematical transformations to project 3D points onto a 2D window.
- **Isometric and Parallel Views**: Allows switching between isometric and parallel projections for different perspectives.
- **Color Gradients**: Adjusts colors based on elevation to create a more immersive visualization.

## 🔧 How It Works
1. **Reading the Map**: The program takes a `.fdf` file as input, where each number represents the height (z-value) of a point on the grid.
2. **Transformation and Projection**: Using matrix transformations, the points are rotated and scaled in 3D space, then projected onto a 2D plane.
3. **Rendering the Wireframe**: Lines are drawn between adjacent points in the grid, creating a wireframe model of the landscape.

## 📝 Compilation & Usage
To compile the project, run:
```bash
make
```

### Usage
Once compiled, you can run the program with a map file as an argument:
```bash
./fdf maps/42.fdf
```

### Controls
- **Arrow keys**: Rotate the landscape
- **+ / -**: Zoom in and out
- **I / P**: Switch between isometric and parallel projections
- **ESC**: Exit the program

## 🌱 Learning Outcomes
Working on FdF was a rewarding experience that enhanced my understanding of 3D graphics, transformations, and projection techniques. Implementing wireframe rendering and experimenting with different projections gave me practical insights into the fundamentals of computer graphics.

## 🔗 Connect with Me
If you're interested in computer graphics or would like to discuss this project, feel free to reach out on [LinkedIn](https://www.linkedin.com/in/sonam-crumiere/).

Happy rendering!
