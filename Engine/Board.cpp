#include "Board.h"
#include <assert.h>




Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCells(Graphics& gfx)
{
	Vei2 ScreenPos;


	for (Vei2 gridpos = { 0,0 }; gridpos.y < height; gridpos.y++)
	{
		for (gridpos.x = 0; gridpos.x < width; gridpos.x++)
		{

			 ScreenPos.x = gridpos.x * dimension + offset.x + cellPadding + borderWidth + borderPadding;
			 ScreenPos.y = gridpos.y * dimension + offset.y + cellPadding + borderWidth + borderPadding;

			AtTile(gridpos).Draw(ScreenPos, gridpos, CurrPos, gfx);
		}
	}

}


void Board::DrawBorder()
{
	const int top = offset.y;
	const int left = offset.x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	// top
	gfx.DrawRect( left,top,right,top + borderWidth, Colors::Blue );
	// left
	gfx.DrawRect( left,top + borderWidth,left + borderWidth,bottom - borderWidth, Colors::Blue);
	// right
	gfx.DrawRect( right - borderWidth,top + borderWidth,right,bottom - borderWidth, Colors::Blue);
	// bottom
	gfx.DrawRect( left,bottom - borderWidth,right,bottom, Colors::Blue);


}

Board::Tile & Board::AtTile(const Vei2 & gridpos)
{
	return grid[gridpos.y * width + gridpos.x];
}

const Board::Tile & Board::AtTile(const Vei2 & gridpos) const
{
	return grid[gridpos.y * width + gridpos.x];
}

void Board::Tile::Draw(const Vei2 & ScreenPos, const Vei2& GridPos, const Vei2& CurrPos, Graphics & gfx)
{
	Color TileColor;

	if (CurrPos.x == GridPos.x && CurrPos.y == GridPos.y)
	{
		state = State::Current;
	}

	switch (state)
	{
	case State::Current:
		state = State::Visited;
		TileColor = Colors::Green;
		break;

	case State::Visited:
		TileColor = Colors::White;
		break;

	case State::Unvisited:
		TileColor = Colors::Gray;
		break;
	}
	

	const int dim = dimension - cellPadding * 2;
	gfx.DrawRectDim(ScreenPos.x, ScreenPos.y, dim , dim, TileColor);
}
