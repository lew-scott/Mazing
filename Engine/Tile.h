#pragma once
#include "Graphics.h"
#include "Vei2.h"

class Tile
{
public:
	static void VertPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void HorzPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void CorRDPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void CorLDPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void CorRUPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void CorLUPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void TRightPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void TLeftPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void TUpPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void TDownPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void FourWayPipe(const Vei2& ScreenPos, Graphics& gfx);
	static void DrawSquare(const Vei2& ScreenPos, Graphics& gfx);
	static void LeftToEnd(const Vei2& ScreenPos, Graphics& gfx);
	static void RightToEnd(const Vei2& ScreenPos, Graphics& gfx);
	static void UpToEnd(const Vei2& ScreenPos, Graphics& gfx);
	static void DownToEnd(const Vei2& ScreenPos, Graphics& gfx);


};