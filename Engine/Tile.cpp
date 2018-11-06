#include "Tile.h"


void Tile::VertPipe(const Vei2& ScreenPos, Graphics & gfx)
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

void Tile::HorzPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::CorRDPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::CorLDPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::CorRUPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::CorLUPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::TRightPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::TLeftPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::TUpPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::TDownPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::FourWayPipe(const Vei2& ScreenPos, Graphics& gfx)
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

void Tile::DrawSquare(const Vei2& ScreenPos, Graphics & gfx)
{ 
	for (int y = 4; y < 16; y++)
	{
		for (int x = 4; x < 16; x++)
		{
			gfx.PutPixel(ScreenPos.x + x, ScreenPos.y + y, Colors::White);
		}
	}
}
