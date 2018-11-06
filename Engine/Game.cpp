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
#include "Tile.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx)
{
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
	while (brd.TilesUnvisited() == true)
	{
		brd.MoveTo();
	}

	if (DrawnBeginEnd == false)
	{
				std::random_device rd;
				std::mt19937 rng(rd());
				std::uniform_int_distribution<int> lowx(0, 4);
				std::uniform_int_distribution<int> lowy(0, 24);
				std::uniform_int_distribution<int> highx(31, 34);
				std::uniform_int_distribution<int> highy(0, 24);

				brd.StopDrawing();
				brd.GetStart({ lowx(rng), lowy(rng) });
				brd.GetEnd({ highx(rng),highy(rng) });
				DrawnBeginEnd = true;
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Game::ComposeFrame()
{
	brd.DrawBorder();
	//brd.DrawCells(gfx);
	//brd.DrawPaths(gfx);

}
