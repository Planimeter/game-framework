# lgameframework
Game development framework for Lua

[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/Planimeter/lgameframework?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Discord](https://img.shields.io/badge/chat-on%20discord-brightgreen.svg)](https://discord.gg/aR3X8Vz?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Install
### Windows
**Microsoft Visual C++ Redistributable for Visual Studio 2017**  
https://go.microsoft.com/fwlink/?LinkId=746572

**02/13/2018 - CEF 3.3282.1733.g9091548 / Chromium 64.0.3282.119**  
http://opensource.spotify.com/cefbuilds/index.html

### macOS
```bash
brew install luajit physfs sdl2 devil freetype sdl_sound chipmunk assimp enet opus
```

## Run
```bash
./lgf
```

## Features
* SDL2 for window creation, OpenGL function loading, and event handling
* Modern OpenGL (OpenGL 3.3/4.0+ Core Profile)
* PhysicsFS for abstracting access to various archives
* DevIL for loading a wide variety of image formats
* FreeType for rendering text
* SDL_sound for decoding several popular sound file formats
* OpenAL for rendering 3D sound
* Chipmunk for 2-dimensional real-time rigid body physics
* Assimp for loading various 3D file formats
* glTF 2.0 physically-based rendering reference shaders
* Chromium Embedded Framework for UI
* ENet for online multi-player support
* Opus for in-game chat
* Lua Lanes for multithreading
* LuaSocket for network support
* LuaSec for secure connections
* [Drop-in LÖVE 0.10.2 support](https://github.com/Planimeter/lgf/blob/master/lua/framework/love.lua)

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
* [lcef](https://github.com/Planimeter/lcef)  
LuaJIT FFI bindings for Chromium Embedded Framework
* [lenet](https://github.com/Planimeter/lenet)  
LuaJIT FFI bindings for ENet
* [lopus](https://github.com/Planimeter/lopus)  
LuaJIT FFI bindings for Opus

## License
MIT License

Copyright (c) 2018 Planimeter

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
