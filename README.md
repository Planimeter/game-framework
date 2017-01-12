# lgameframework
Game development framework for Lua

[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/Planimeter/lgameframework?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Create a Project
[Getting Started](https://github.com/Planimeter/lgameframework/wiki/Getting%20Started)  
[API Documentation](https://github.com/Planimeter/lgameframework/wiki)

## Install
### Windows
**Microsoft Visual C++ 2010 SP1 Redistributable Package (x64)**  
https://www.microsoft.com/en-us/download/details.aspx?id=13523

### macOS
```bash
brew install luajit physfs sdl2 devil freetype sdl_sound chipmunk assimp
```

## Run
```bash
luajit framework/init.lua
```

## About
### Overview
lgf is a replacement for LÖVE built on LuaJIT and the FFI library. It implements a subset of LÖVE's API, while omitting LÖVE-specific features.

### Framework versus game engine
While LÖVE advertises itself as a game engine/framework, lgf is strictly a framework. It only simplifies the collective libraries below in to an easy-to-read set of modules for graphics, audio, event, filesystem, keyboard, mouse, physics, sound, timer, and window usage. It does not provider higher-level constructs such as UI, keyboard and mouse bindings, entities, or level loading.

## Features
* SDL2 for window creation, OpenGL function loading, and event handling
* Modern OpenGL (OpenGL 3.3/4.0+ Core Profile)
* DevIL for loading a wide variety of image formats
* SDL_sound for decoding several popular sound file formats
* OpenAL for rendering 3D sound
* PhysicsFS for abstracting access to various archives
* Chipmunk for 2-dimensional real-time rigid body physics
* Assimp for loading various 3D file formats

## Libraries
* [lphysicsfs](https://github.com/Planimeter/lphysicsfs)  
LuaJIT FFI bindings for PhysicsFS
* [lsdl](https://github.com/Planimeter/lsdl)  
LuaJIT FFI bindings for SDL 2.0
* [lopengl](https://github.com/Planimeter/lopengl)  
LuaJIT FFI bindings for OpenGL
* [lkazmath](https://github.com/Planimeter/lkazmath)  
LuaJIT FFI bindings for kazmath
* [lclass](https://github.com/andrewmcwatters/lclass)  
Lua with Classes
* [ldevil](https://github.com/Planimeter/ldevil)  
LuaJIT FFI bindings for DevIL
* [lfreetype](https://github.com/Planimeter/lfreetype)  
LuaJIT FFI bindings for FreeType
* [lsdl_sound](https://github.com/Planimeter/lsdl_sound)  
LuaJIT FFI bindings for SDL_sound
* [lopenal](https://github.com/Planimeter/lopenal)  
LuaJIT FFI bindings for OpenAL
* [lchipmunk](https://github.com/Planimeter/lchipmunk)  
LuaJIT FFI bindings for Chipmunk
* [lassimp](https://github.com/Planimeter/lassimp)  
LuaJIT FFI bindings for Assimp

## License
The MIT License

Copyright (c) 2017 Planimeter. http://planimeter.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
