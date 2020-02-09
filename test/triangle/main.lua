--=========== Copyright © 2020, Planimeter, All rights reserved. ===========--
--
-- Purpose:
--
--==========================================================================--

function framework.draw()
	local width, height = framework.graphics.getSize()
	framework.graphics.polygon( "fill", {
		0.25 * width, 0.75 * height,
		0.75 * width, 0.75 * height,
		0.50 * width, 0.25 * height
	} )
end
