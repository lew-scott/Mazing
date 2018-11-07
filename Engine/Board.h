#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>
#include <vector>
#include <memory>


class Board
{
	class Tile
	{
		enum class State
		{
			Current,
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

		State SetCurrent();

	private:
		State state = State::Unvisited;
		bool LeftConnection = false;
		bool RightConnection = false;
		bool UpConnection = false;
		bool DownConnection = false;
	};



public:
	Board(Graphics& gfx);
	void DrawCells(Graphics& gfx);
	void DrawBorder();
	bool IsUnvisitedTile(const Vei2& gridpos);
	void MoveTo();
	int GetGridWidth();
	int GetGridHeight();
	bool TilesUnvisited();

private:
	Tile& AtTile(const Vei2& gridpos);
	const Tile& AtTile(const Vei2& gridpos) const;

private:
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 4;
	bool drawing = true;
	static constexpr int offset = 40;
	Vei2 CurrPos = { 0,0 };
	Vei2 OldPos;
	Tile grid[width * height];
	std::vector<Vei2> moves = { CurrPos };
	Graphics& gfx;
	
};