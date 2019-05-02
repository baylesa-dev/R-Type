<h1 align="center">
R-TYPE
<br/>
<br/>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1200px-ISO_C%2B%2B_Logo.svg.png" height="200">
</h1>

<h2 align="center">A game engine that roars!</h2>

<p align="center">
    <a href="#introduction">Introdution</a> •
    <a href="#build-and-launch">Build and Launch</a>
</p>

## Introduction

For this project of the Advanced C++ knowledge unit, R-Type introduce networked video game development.

We had to implement a multi-threaded server and a graphical client, using a re-usable game engine of our own design. Our game had also to be fun to play!

For the sad ignorants among you who may not know this best-selling video game, which accounts for countless lost hours of our childhood, here is a little introduction.

The purpose of this project was to create a one-to-four player game, using a client/server architecture.

## Getting Started

Checkout the [Build and Launch](https://github.com/baylesa-dev/R-Type/blob/master/docs/build-start.md) documentation to get started.

## Build and Launch

```bash
mkdir build && cd build && conan install .. --build=missing &&
cmake .. -G “Unix Makefiles” && cmake --build .
```
