#include "Board.h"
#include <assert.h>
#include <vector>
#include <random>


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


bool Board::IsUnvisitedTile(const Vei2 & gridpos)
{
	assert(gridpos.x>= 0);
	assert(gridpos.x <= width);
	assert(gridpos.y >= 0);
	assert(gridpos.y <= height);

	return AtTile(gridpos).IsUnvisited();
}

void Board::MoveTo()
{
	std::vector<int> v1 = { 0,0,0,0 }; // left, right, up, down
	Vei2 NewPos;
	Vei2 MoveHoz = { 1,0 };
	Vei2 MoveVert = { 0,1 };
	//check left
	if (CurrPos.x > 0)
	{
		NewPos = CurrPos - MoveHoz;
		bool PosLoc = IsUnvisitedTile(NewPos);
		if (PosLoc == true)
		{
			v1[0] = 1;
		}
	}
	// check right
	if (CurrPos.x < width-1)
	{
		NewPos = CurrPos + MoveHoz;
		bool PosLoc = IsUnvisitedTile(NewPos);
		if (PosLoc == true)
		{
			v1[1] = 2;
		}
	}
	// check up
	if (CurrPos.y > 0)
	{
		NewPos = CurrPos - MoveVert;
		bool PosLoc = IsUnvisitedTile(NewPos);
		if (PosLoc == true)
		{
			v1[2] = 3;
		}
	}
	// check down 
	if (CurrPos.y < height-1)
	{
		NewPos = CurrPos + MoveVert;
		bool PosLoc = IsUnvisitedTile(NewPos);
		if (PosLoc == true)
		{
			v1[3] = 4;
		}
	}

	// check somewhere is free 
	bool NowhereFree;

		for (int i = 1; i < v1.size(); i++)
		{
			if (v1[i - 1] != v1[i])
			{
				NowhereFree = false;
				break;
			}
			else
			{
				NowhereFree = true; 
			}
		}

		// decise where to move or pop back
		if (NowhereFree == true)
		{
			OldPos = CurrPos;
			moves.pop_back();
			CurrPos = moves.back();
		}
		else
		{
			std::random_device rd;
			std::mt19937 rand{ rd() };
			std::uniform_int_distribution<int> dist(0, int(v1.size()) - 1);
			int direction = 0;
			int i = 0;
			while (i == 0)
			{
				i = v1[dist(rand)];
				direction = i;
			}
			OldPos = CurrPos;
			if (direction == 1)
			{
				CurrPos -= MoveHoz;
			}
			if (direction == 2)
			{
				CurrPos += MoveHoz;
			}
			if (direction == 3)
			{
				CurrPos -= MoveVert;
			}
			if (direction == 4)
			{
				CurrPos += MoveVert;
			}
			Paths.push_back(CurrPos);
			moves.push_back(CurrPos);
		}
}


int Board::GetGridWidth()
{
	return width;
}

int Board::GetGridHeight()
{
	return height;
}

bool Board::TilesUnvisited()
{
	bool test;
	for (Vei2 gridpos = { 0,0 }; gridpos.y < height; gridpos.y++)
	{
		for (gridpos.x = 0; gridpos.x < width; gridpos.x++)
		{
			test = AtTile(gridpos).IsUnvisited();
			if (test == true)
			{
				return true;
			}
		}
	}
	return false;
}

void Board::DrawPaths(Graphics & gfx)
{
	Vei2 ScreenPos;
	for (int i = 1; i < Paths.size(); i++)
	{
		Vei2 OffSet = Getoffset(Paths[i],Paths[i-1]);
		ScreenPos.x = Paths[i].x * dimension + offset.x + cellPadding + borderWidth + borderPadding + OffSet.x;
		ScreenPos.y = Paths[i].y * dimension + offset.y + cellPadding + borderWidth + borderPadding + OffSet.y;

		const int dim = dimension - cellPadding * 2;
		gfx.DrawRectFromCentre(ScreenPos.x, ScreenPos.y, dim, dim, Colors::White);
	}
}

Vei2 Board::Getoffset(const Vei2 & newpos, const Vei2 & oldpos)
{
	Vei2 path_offset;
	int HalfDim = dimension / 2;
	if (newpos.x < oldpos.x && newpos.y == oldpos.y)
	{
		path_offset = { HalfDim, 0 };
	}
	else if (newpos.x > oldpos.x && newpos.y == oldpos.y)
	{
		path_offset = { -HalfDim, 0 };
	}
	else if (newpos.y < oldpos.y && newpos.x == oldpos.x)
	{
		path_offset = { 0, HalfDim };
	}
	else if (newpos.y > oldpos.y && newpos.x == oldpos.x)
	{
		path_offset = { 0, -HalfDim };
	}
	else
	{
		path_offset = { 0,0 };
	}


	return path_offset;
	return Vei2();
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
	

	const int dim = dimension- cellPadding * 2;
	gfx.DrawRectFromCentre(ScreenPos.x, ScreenPos.y, dim , dim, TileColor);
}

bool Board::Tile::IsUnvisited()
{
	if (state == State::Unvisited)
	{
		return true;
	}
	else
	{
		return false;
	}
}



