#pragma once

#include "Graphics.h"
#include "Location.h"
#include "RectI.h"
#include <random>
#include <vector>
#include <memory>


class Board
{
	class Tile
	{
		enum class State
		{
			Visited,
			Unvisited,
			Start,
			End
		};


	public:
		void Draw(const Vei2& GridPos, Graphics& gfx);
		bool IsUnvisited();
		bool setLeftConnection();
		bool setRightConnection();
		bool setUpConnection();
		bool setDownConnection();

		bool checkLeftConnnection();
		bool checkRightConnection();
		bool checkUpConnection();
		bool checkDownConnection();

		State SetToVisited();

	private:
		State state = State::Unvisited;
		bool LeftConnection = false;
		bool RightConnection = false;
		bool UpConnection = false;
		bool DownConnection = false;
	};



public:
	Board(Graphics& gfx, const Vei2& CurrPos);
	void DrawCells(Graphics& gfx);
	void DrawBorder();
	void DrawPosInMaze();
	void DrawEndPos();
	bool IsUnvisitedTile(const Vei2& gridpos);
	void DesignMaze();
	bool TilesUnvisited();
	void SetNewCurrent(const Vei2& gridpos);
	void SetEndPos(const Vei2& gridpos);
	void MoveBy(const Vei2& delta_loc);
	void MoveMazeInView();
	RectI GetScrRect();
	RectI GetMazeRect();

private:
	Tile& AtTile(const Vei2& gridpos);
	const Tile& AtTile(const Vei2& gridpos) const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 65;
	static constexpr int height = 50;
	static constexpr int borderWidth = 4;
	static constexpr int offset = 40;
	static constexpr int MazeWinx = 35;
	static constexpr int MazeWiny = 25;
	RectI MazeRect;
	RectI ScrRect;
	Vei2 CurrPos;
	Vei2 EndPos;
	Tile grid[width * height];
	std::vector<Vei2> moves = { CurrPos };
	Graphics& gfx;
	
};