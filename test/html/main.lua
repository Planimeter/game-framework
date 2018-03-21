--=========== Copyright © 2018, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

require( "framework.html" )

function framework.load( arg )
	browser = framework.html.newBrowser( "https://www.google.com/ncr" )
end

function framework.resize( width, height )
	browser:resize( width, height )
end

function framework.update( dt )
	framework.html.update( dt )
end

function framework.draw()
	framework.graphics.draw( browser )
end

function framework.quit()
	framework.html.quit()
	return true
end
