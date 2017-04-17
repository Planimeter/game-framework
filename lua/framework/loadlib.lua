--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

-- Add `./?/init.lua'
package.path = string.gsub( package.path, "^./?.lua;", "./?.lua;./?/init.lua;" )

if ( jit.os == "Windows" ) then
	-- Add `framework.path' and `framework.cpath'
	framework.path  = string.gsub( arg[ 0 ], "\\framework\\init.lua$", "\\" )
	framework.cpath = string.gsub( framework.path, "\\lua$", "\\" )

	-- Add `lib'
	package.path    = package.path  .. framework.path .. "lib\\?.lua;"
	package.cpath   = package.cpath .. ";".. framework.path .. "lib\\?.dll;"
	package.cpath   = package.cpath .. framework.path .. "loadall.dll"
else
	-- Add `framework.path' and `framework.cpath'
	framework.path  = string.gsub( arg[ 0 ], "/framework/init.lua$", "/" )
	framework.cpath = string.gsub( framework.path, "/lua$", "/" )

	-- Add working directory
	package.path    = package.path  .. ";" .. framework.path .. "?.lua;"
	package.path    = package.path  .. framework.path .. "?/init.lua;"

	-- Add `lib'
	package.path    = package.path  .. framework.path .. "lib/?.lua"
	package.cpath   = package.cpath .. ";" .. framework.path .. "lib/?.so;"
	package.cpath   = package.cpath .. framework.path .. "loadall.so"
end
