# MiniRT
<p align="center">
  <img src="https://github.com/LaOuede/42-project-badges/blob/main/badges/minirte.png" />
</p>

<h1 align=center>MiniRT</h1>

<div align=center>

**Real-time ray tracing engine written in C — built at École 42 Québec**

</div>

<div align="center">
<img src="rendu/ezgif.com-gif-maker.gif"><br />
<img src="rendu/ezgif.com-video-to-gif.gif">
<img src="rendu/Capture d'écran, le 2023-11-21 à 14.18.58.png">
<img src="https://user-images.githubusercontent.com/114024436/270670806-1e550985-798d-455c-ae50-b0acab46989e.png">
<img src="https://user-images.githubusercontent.com/114024436/270671001-d57fab27-61dd-4bb7-9290-bb4b79379787.png">

</div>

---

## About

MiniRT is a fully functional real-time ray tracing engine built from scratch in C, with no garbage collector and no high-level abstractions — every byte managed manually.

The project renders 3D scenes by casting rays from a camera into the scene, computing intersections with geometric objects, and simulating physically-based lighting. The result runs in real time, with no memory leaks.

## Technical highlights

- **Real-time rendering** — interactive frame output with no pre-computation shortcuts
- **Multithreaded architecture** — parallel ray computation across threads for performance
- **Manual memory management** — written in C with zero memory leaks (valgrind-verified)
- **UV mapping** — texture coordinates computed per-surface for realistic material rendering
- **Reflections** — recursive ray bouncing for mirror-like surfaces
- **Ray-object intersection** — geometric solvers for spheres, planes, cylinders, and cones
- **Phong shading model** — ambient, diffuse, and specular lighting components
