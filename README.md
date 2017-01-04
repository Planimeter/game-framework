# lgameframework
Game development framework for Lua

## Create a Project

[Getting Started](https://github.com/Planimeter/lgameframework/wiki/Getting%20Started)  
[API Documentation](https://github.com/Planimeter/lgameframework/wiki)

## Install

### Windows

**Microsoft Visual C++ 2010 SP1 Redistributable Package (x64)**  
https://www.microsoft.com/en-us/download/details.aspx?id=13523

### macOS

```bash
brew install luajit physfs sdl2
```

## Run

```bash
luajit framework/init.lua
```

## Libraries

* [lphysicsfs](https://github.com/Planimeter/lphysicsfs)  
LuaJIT FFI bindings for PhysicsFS
* [lsdl](https://github.com/Planimeter/lsdl)  
LuaJIT FFI bindings for SDL 2.0
* [lopengl](https://github.com/Planimeter/lopengl)  
LuaJIT FFI bindings for OpenGL
* [lkazmath](https://github.com/Planimeter/lkazmath)  
LuaJIT FFI bindings for kazmath
* [lstb_image](https://github.com/Planimeter/lstb_image)  
LuaJIT FFI bindings for stb_image
* [lclass](https://github.com/andrewmcwatters/lclass)  
Lua with Classes

## License

The MIT License

Copyright (c) 2016 Planimeter. http://planimeter.org

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
