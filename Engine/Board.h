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
			Unvisited
		};


	public:
		void Draw(const Vei2& ScreenPos, const Vei2& GridPos, const Vei2& CurrPos, Graphics& gfx);
		bool IsUnvisited();

	private:
		State state = State::Unvisited;
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
	void DrawPaths(Graphics& gfx);
	Vei2 Getoffset(const Vei2& newpos, const Vei2& oldpos);

private:
	Tile& AtTile(const Vei2& gridpos);
	const Tile& AtTile(const Vei2& gridpos) const;

private:
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	Vei2 offset = { 70,50 };
	Vei2 CurrPos = { 0,0 };
	Vei2 OldPos;
	Tile grid[width * height];
	std::vector<Vei2> moves = { CurrPos };
	std::vector<Vei2> Paths = { CurrPos };
	Graphics& gfx;
	
};