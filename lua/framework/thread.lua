--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

local ffi = require( "ffi" )

module( "framework.thread" )

CriticalSection = CriticalSection or ffi.new( "CRITICAL_SECTION[1]" )
ffi.C.InitializeCriticalSection( CriticalSection[0] )

function lock()
	ffi.C.EnterCriticalSection( CriticalSection[0] )
end

function unlock()
	ffi.C.LeaveCriticalSection( CriticalSection[0] )
end
