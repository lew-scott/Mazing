#include "Board.h"
#include <assert.h>
#include <vector>
#include <random>
#include "Walls.h"


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

			 ScreenPos.x = gridpos.x * dimension + offset  + borderWidth + borderPadding;
			 ScreenPos.y = gridpos.y * dimension + offset  + borderWidth + borderPadding;

			
			AtTile(gridpos).Draw(ScreenPos,gfx);
		}
	}

}


void Board::DrawBorder()
{
	const int top = offset;
	const int left = offset;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	// top
	gfx.DrawRect( left,top,right,top + borderWidth, Colors::Green );
	// left
	gfx.DrawRect( left,top + borderWidth,left + borderWidth,bottom - borderWidth, Colors::Green);
	// right
	gfx.DrawRect( right - borderWidth,top + borderWidth,right,bottom - borderWidth, Colors::Green);
	// bottom
	gfx.DrawRect( left,bottom - borderWidth,right,bottom, Colors::Green);


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
	AtTile(CurrPos).SetCurrent();
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
				AtTile(OldPos).setLeftConnection();
				AtTile(CurrPos).setRightConnection();
			}
			if (direction == 2)
			{
				CurrPos += MoveHoz;
				AtTile(OldPos).setRightConnection();
				AtTile(CurrPos).setLeftConnection();
			}
			if (direction == 3)
			{
				CurrPos -= MoveVert;
				AtTile(OldPos).setUpConnection();
				AtTile(CurrPos).setDownConnection();
			}
			if (direction == 4)
			{
				CurrPos += MoveVert;
				AtTile(OldPos).setDownConnection();
				AtTile(CurrPos).setUpConnection();
			}
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



Board::Tile & Board::AtTile(const Vei2 & gridpos)
{
	return grid[gridpos.y * width + gridpos.x];
}

const Board::Tile & Board::AtTile(const Vei2 & gridpos) const
{
	return grid[gridpos.y * width + gridpos.x];
}



void Board::Tile::Draw(const Vei2& ScreenPos, Graphics& gfx)
{

	if (LeftConnection == true && RightConnection == false && UpConnection == false && DownConnection == false)
	{
		Walls::LeftToEnd(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == true && UpConnection == false && DownConnection == false)
	{
		Walls::RightToEnd(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == false && UpConnection == true && DownConnection == false)
	{
		Walls::TopToEnd(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == false && UpConnection == false && DownConnection == true)
	{
		Walls::BottomToEnd(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == false && UpConnection == true && DownConnection == true)
	{
		Walls::VertPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == true && UpConnection == false && DownConnection == false)
	{
		Walls::HorzPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == false && UpConnection == true && DownConnection == false)
	{
		Walls::CorLUPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == false && UpConnection == false && DownConnection == true)
	{
		Walls::CorLDPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == true && UpConnection == true && DownConnection == false)
	{
		Walls::CorRUPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == true && UpConnection == false && DownConnection == true)
	{
		Walls::CorRDPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == true && UpConnection == true && DownConnection == false)
	{
		Walls::TUpPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == true && UpConnection == false && DownConnection == true)
	{
		Walls::TDownPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == true && RightConnection == false && UpConnection == true && DownConnection == true)
	{
		Walls::TLeftPipe(ScreenPos, gfx);
	}
	else if (LeftConnection == false && RightConnection == true && UpConnection == true && DownConnection == true)
	{
		Walls::TRightPipe(ScreenPos, gfx);
	}
	else if(LeftConnection == true && RightConnection == true && UpConnection == true && DownConnection == true)
	{
		Walls::FourWayPipe(ScreenPos, gfx);
	}
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

bool Board::Tile::setLeftConnection()
{
	return LeftConnection = true;
}

bool Board::Tile::setRightConnection()
{
	return RightConnection = true;
}

bool Board::Tile::setUpConnection()
{
	return UpConnection = true;
}

bool Board::Tile::setDownConnection()
{
	return DownConnection = true;
}


Board::Tile::State Board::Tile::SetCurrent()
{
	return state = State::Visited;
}



