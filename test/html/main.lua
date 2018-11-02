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

function framework.keypressed( key, scancode, isrepeat )
	browser:keypressed( key, scancode, isrepeat )
end

function framework.keyreleased( key, scancode )
	browser:keyreleased( key, scancode )
end

function framework.mousemoved( x, y, dx, dy, istouch )
	browser:mousemoved( x, y, dx, dy, istouch )
end

function framework.mousepressed( x, y, button, istouch )
	browser:mousepressed( x, y, button, istouch )
end

function framework.mousereleased( x, y, button, istouch )
	browser:mousereleased( x, y, button, istouch )
end

function framework.wheelmoved( x, y )
	browser:wheelmoved( x, y )
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
