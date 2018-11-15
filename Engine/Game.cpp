/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <chrono>
#include <thread>
#include <random>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx, { 4,4 })
{
	//std::random_device rd;
	//std::mt19937 rng(rd());
	//std::uniform_int_distribution<int> maze(0, 20);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	while(brd.TilesUnvisited() == true)
	{
		brd.DesignMaze();
	}

	if (SetStartEnd == false)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> lowx(0, 4);
		std::uniform_int_distribution<int> y(40, 49);
		std::uniform_int_distribution<int> highx(31, 34);
		brd.SetNewCurrent({ lowx(rng),y(rng) });
		brd.SetEndPos({ highx(rng), y(rng) });
		SetStartEnd = true;
	}

	if (MoveCounter > MoveSpeed)
	{
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			brd.MoveBy({ -1,0 });
			MoveCounter = 0;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			brd.MoveBy({ 1,0 });
			MoveCounter = 0;
		}
		else if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			brd.MoveBy({ 0,-1 });
			MoveCounter = 0;
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			brd.MoveBy({ 0,1 });
			MoveCounter = 0;
		}
		else
		{
			brd.MoveBy({ 0,0 });
		}
	}

	MoveCounter++;
	if(count == FlashSpeedMax)
	{
		count = 0;
	}

	brd.MoveMazeInView();
	count++;
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Game::ComposeFrame()
{
	
	brd.DrawCells(gfx);
	brd.DrawEndPos();
	if (count < FlashSpeed)
	{
		brd.DrawPosInMaze();
	}
	
	brd.DrawBorder();

}
