#include "Walls.h"


void Walls::VertPipe(const Vei2& ScreenPos, Graphics & gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::HorzPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::CorRDPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::CorLDPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::CorRUPipe(const Vei2& ScreenPos, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::CorLUPipe(const Vei2& ScreenPos, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::TRightPipe(const Vei2& ScreenPos, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 17; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::TLeftPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::TUpPipe(const Vei2& ScreenPos, Graphics& gfx)
{

	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::TDownPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::FourWayPipe(const Vei2& ScreenPos, Graphics& gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::DrawSquare(const Vei2& ScreenPos, Graphics & gfx)
{ 
	for (int y = 4; y < 16; y++)
	{
		for (int x = 4; x < 16; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::White);
		}
	}
}

void Walls::LeftToEnd(const Vei2 & ScreenPos, Graphics & gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::RightToEnd(const Vei2 & ScreenPos, Graphics & gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::TopToEnd(const Vei2 & ScreenPos, Graphics & gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}

void Walls::BottomToEnd(const Vei2 & ScreenPos, Graphics & gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::Blue);
		}
	}
}
