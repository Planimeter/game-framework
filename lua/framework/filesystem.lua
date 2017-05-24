--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local physfs = require( "physicsfs" )
local ffi    = require( "ffi" )
local os     = os
local string = string
local table  = table

module( "framework.filesystem" )

function exists( filename )
	return physfs.PHYSFS_exists( filename ) ~= 0
end

function getAppdataDirectory()
	if ( ffi.os == "Windows" ) then
		return string.gsub( os.getenv( "APPDATA" ), "\\", "/" )
	elseif ( ffi.os == "OSX" ) then
		return getUserDirectory() .. "/Library/Application Support"
	elseif ( ffi.os == "Linux" ) then
		local xdgdatahome = os.getenv( "XDG_DATA_HOME" )
		if ( not xdgdatahome ) then
			return getUserDirectory() .. "/.local/share/"
		else
			return xdgdatahome
		end
	end
	return getUserDirectory()
end

function getDirectoryItems( dir )
	local rc = physfs.PHYSFS_enumerateFiles( dir )
	local i = 0
	local v = nil
	local t = {}
	repeat
		v = rc[ i ]
		if ( v ~= nil ) then
			table.insert( t, ffi.string( v ) )
		end
		i = i + 1
	until ( v == nil )
	physfs.PHYSFS_freeList( rc )
	return t
end

function getLastModified( filename )
	return physfs.PHYSFS_getLastModTime( filename )
end

function getUserDirectory()
	return ffi.string( physfs.PHYSFS_getUserDir() )
end

function getWriteDirectory()
	return ffi.string( physfs.PHYSFS_getWriteDir() )
end

function init( argv0 )
	return physfs.PHYSFS_init( argv0 ) ~= 0
end

function isDirectory( filename )
	return physfs.PHYSFS_isDirectory( filename ) ~= 0
end

function isFile( file )
	return exists( file ) and not isDirectory( file )
end

function mount( newDir, mountPoint, appendToPath )
	appendToPath = appendToPath and 1 or 0
	return physfs.PHYSFS_mount( newDir, mountPoint, appendToPath ) ~= 0
end

function read( filename )
	local file   = physfs.PHYSFS_openRead( filename )
	local length = physfs.PHYSFS_fileLength( file )
	local buffer = ffi.new( "char[?]", length )
	physfs.PHYSFS_read( file, buffer, 1, length )
	physfs.PHYSFS_close( file )
	return ffi.string( buffer, length ), length
end
