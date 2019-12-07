#include "Board.h"
#include <assert.h>
#include <vector>
#include <random>
#include "Walls.h"


Board::Board(Graphics & gfx, const Vei2& CurrPos)
	:
	gfx(gfx),
	CurrPos(CurrPos),
	MazeRect({ offset + borderWidth,offset + borderWidth }, dimension * width, dimension * height),
	ScrRect({ offset + borderWidth,offset + borderWidth }, dimension * MazeWinx, dimension * MazeWiny)
{
}

void Board::DrawCells(Graphics& gfx)
{
	Vei2 ScreenPos;


	for (Vei2 gridpos = { 0,0 }; gridpos.y < height; gridpos.y++)
	{
		for (gridpos.x = 0; gridpos.x < width; gridpos.x++)
		{

			 ScreenPos.x = gridpos.x * dimension + MazeRect.left;
			 ScreenPos.y = gridpos.y * dimension + MazeRect.top;

			 if (ScreenPos.x >= ScrRect.left && ScreenPos.x < ScrRect.right
			 && ScreenPos.y >= ScrRect.top && ScreenPos.y < ScrRect.bottom )
			 {
				 AtTile(gridpos).Draw(ScreenPos, gfx);
			 }
		}
	}

}


void Board::DrawBorder() // issue with border found
{
	//Outer boarder
	const int top = offset;
	const int left = offset;
	const int bottom = top + borderWidth + 25 * dimension - 2;
	const int right = left + borderWidth + 35 * dimension - 2;

	// top
	gfx.DrawRect( left,top,right + borderWidth,top + borderWidth + 2, Colors::Blue);
	// left
	gfx.DrawRect( left, top + borderWidth, left + borderWidth + 2, bottom, Colors::Blue);
	// right
	gfx.DrawRect( right - 2, top + borderWidth, right + borderWidth, bottom, Colors::Blue);
	// bottom
	gfx.DrawRect( left,bottom - 2,right + borderWidth,bottom + borderWidth+1, Colors::Blue);
}

void Board::DrawPosInMaze()
{
	Vei2 ScreenPos;
	ScreenPos.x = CurrPos.x * dimension + MazeRect.left + 3;
	ScreenPos.y = CurrPos.y * dimension + MazeRect.top + 3;

	if (ScreenPos.x >= ScrRect.left && ScreenPos.x < ScrRect.right
		&& ScreenPos.y >= ScrRect.top && ScreenPos.y < ScrRect.bottom)
	{
		gfx.DrawRectDim(ScreenPos.x, ScreenPos.y, 14, 14, Colors::White);
	}
}

void Board::DrawEndPos()
{
	Vei2 ScreenPos;
	ScreenPos.x = EndPos.x * dimension + MazeRect.left + 3 ;
	ScreenPos.y = EndPos.y * dimension + MazeRect.top + 3;

	if (ScreenPos.x >= ScrRect.left && ScreenPos.x < ScrRect.right
		&& ScreenPos.y >= ScrRect.top && ScreenPos.y < ScrRect.bottom)
	{
		gfx.DrawRectDim(ScreenPos.x, ScreenPos.y, 14, 14, Colors::Red);
	}
}


bool Board::IsUnvisitedTile(const Vei2 & gridpos)
{
	assert(gridpos.x>= 0);
	assert(gridpos.x <= width);
	assert(gridpos.y >= 0);
	assert(gridpos.y <= height);

	return AtTile(gridpos).IsUnvisited();
}

void Board::DesignMaze()
{
	assert(CurrPos.x >= 0);
	assert(CurrPos.x <= width);
	assert(CurrPos.y >= 0);
	assert(CurrPos.y <= height);

	std::random_device rd;
	std::mt19937 rand{ rd() };
	std::vector<int> v1 = { 0,0,0,0 }; // left, right, up, down
	Vei2 NewPos;
	Vei2 MoveHoz = { 1,0 };
	Vei2 MoveVert = { 0,1 };
	AtTile(CurrPos).SetToVisited();
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
			CurrPos = moves.rbegin()[1];
			moves.pop_back();
		}
		else
		{
		
			std::uniform_int_distribution<int> dist(0, int(v1.size()) - 1);
			int direction = 0;
			int i = 0;
			while (i == 0) // get a random direction, based on tiles available around itself
			{
				i = v1[dist(rand)];
				direction = i;
			}
			if (direction == 1)
			{
				AtTile(CurrPos).setLeftConnection();  // set connection at old tile with new tile
				CurrPos -= MoveHoz;				      // move
				AtTile(CurrPos).setRightConnection(); // set connection at new tile with previous
			}
			if (direction == 2)
			{
				AtTile(CurrPos).setRightConnection();
				CurrPos += MoveHoz;
				AtTile(CurrPos).setLeftConnection();
			}
			if (direction == 3)
			{
				AtTile(CurrPos).setUpConnection();
				CurrPos -= MoveVert;
				AtTile(CurrPos).setDownConnection();
			}
			if (direction == 4)
			{
				AtTile(CurrPos).setDownConnection();
				CurrPos += MoveVert;
				AtTile(CurrPos).setUpConnection();
			}
			moves.push_back(CurrPos);
		}
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

void Board::SetNewCurrent(const Vei2& gridpos)
{
	CurrPos = gridpos;
}

void Board::SetEndPos(const Vei2 & gridpos)
{
	EndPos = gridpos;
}

void Board::MoveBy(const Vei2& delta_loc)
{
	Vei2 left = { -1,0 };
	Vei2 right = { 1,0 };
	Vei2 top = { 0,-1 };
	Vei2 bottom = { 0,1 };

	if (delta_loc == left && AtTile(CurrPos).checkLeftConnnection() == true)
	{
		CurrPos += delta_loc;
	}

	if(delta_loc == right && AtTile(CurrPos).checkRightConnection() == true)
	{
		CurrPos += delta_loc;
	}

	if (delta_loc == top && AtTile(CurrPos).checkUpConnection() == true)
	{
		CurrPos += delta_loc;
	}

	if (delta_loc == bottom && AtTile(CurrPos).checkDownConnection() == true)
	{
		CurrPos += delta_loc;
	}
	
}

void Board::MoveMazeInView()
{
	Vei2 ScreenPos;
	ScreenPos.x = CurrPos.x * dimension + MazeRect.left;
	ScreenPos.y = CurrPos.y * dimension + MazeRect.top;

	if (MazeRect.left < ScrRect.left && ScreenPos.x < ScrRect.left + int((ScrRect.right - ScrRect.left) * 0.2))
	{
		MazeRect.moveRect({ 100,0 });
	}
	else if (MazeRect.right > ScrRect.right && ScreenPos.x > ScrRect.left + int((ScrRect.right - ScrRect.left) * 0.8))
	{
		MazeRect.moveRect({ -100,0 });
	}
	else if (MazeRect.top < ScrRect.top && ScreenPos.y < ScrRect.top + int((ScrRect.bottom - ScrRect.top) * 0.2))
	{
		MazeRect.moveRect({ 0,100 });
	}
	else if (MazeRect.bottom > ScrRect.bottom && ScreenPos.y > ScrRect.top + int((ScrRect.bottom - ScrRect.top) * 0.8))
	{
		MazeRect.moveRect({ 0, -100 });
	}
}

RectI Board::GetMazeRect()
{
	return MazeRect;
}

RectI Board::GetScrRect()
{
	return ScrRect;
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

bool Board::Tile::checkLeftConnnection()
{
	return LeftConnection;
}

bool Board::Tile::checkRightConnection()
{
	return RightConnection;
}

bool Board::Tile::checkUpConnection()
{
	return UpConnection;
}

bool Board::Tile::checkDownConnection()
{
	return DownConnection;
}


Board::Tile::State Board::Tile::SetToVisited()
{
	return state = State::Visited;
}



