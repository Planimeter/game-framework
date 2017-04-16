--=========== Copyright © 2017, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local physfs = require( "physicsfs" )
local ffi    = require( "ffi" )

module( "framework.filesystem" )

function exists( filename )
	return physfs.PHYSFS_exists( filename ) ~= 0
end

function getLastModified( filename )
	return physfs.PHYSFS_getLastModTime( filename )
end

function init( arg )
	return physfs.PHYSFS_init( arg ) ~= 0
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
