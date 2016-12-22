--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local physfs = require( "lib.physicsfs" )

module( "framework.filesystem" )

function exists( filename )
	return physfs.PHYSFS_exists( filename ) ~= 0
end

function isDirectory( filename )
	return physfs.PHYSFS_isDirectory( filename ) ~= 0
end

function isFile( file )
	return exists( file ) and not isDirectory( file )
end
