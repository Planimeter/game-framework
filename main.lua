--=========== Copyright © 2016, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

function framework.load()
end

function framework.update( dt )
end

function framework.draw()
	local width, height = framework.graphics.getSize()
	framework.graphics.polygon( "line", {
	    width / 2,         height / 4,          -- Vertex 1 (X, Y)
	    width - width / 4, height - height / 4, -- Vertex 2 (X, Y)
	    width / 4,         height - height / 4  -- Vertex 3 (X, Y)
	} )
end

function framework.keypressed( key, scancode, isrepeat )
	print( key, scancode, isrepeat )
end

function framework.keyreleased( key, scancode )
	print( key, scancode )
end
