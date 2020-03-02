#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Tetromino.h"

Tetromino* g_current_piece;
Vector2 g_pos;

//Update loop
bool Update()
{
	if (g_hge->Input_KeyUp(HGEK_UP))
	{
		g_current_piece->rotate();
	}

	if (g_hge->Input_KeyUp(HGEK_DOWN))
	{
		g_current_piece->move(Tetromino::Direction::DOWN);
	}

	if (g_hge->Input_KeyUp(HGEK_LEFT))
	{
		g_current_piece->move(Tetromino::Direction::LEFT);
	}

	if (g_hge->Input_KeyUp(HGEK_RIGHT))
	{
		g_current_piece->move(Tetromino::Direction::RIGHT);
	}

	if (g_hge->Input_KeyUp(HGEK_SPACE))
	{
		
		// TODO: Hard drop
	}

	return false;
}

//Render loop
bool Render()
{
	RenderBegin();

	g_current_piece->render(g_square_sprite);

	RenderEnd();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Initialize(322, 640, Update, Render);

	if(IsInitialized())
	{
		const char* path = "..//square_3px_border.png";
		g_square_sprite = new Sprite(const_cast<char*>(path), Vector2(0, 0), Vector2(c_cell_size, c_cell_size));
		g_pos = Vector2(1, 1);
		g_current_piece = new Tetromino(Tetromino::Shape::Z);
		Run();
	}
	
	Shutdown();

	return 0;
}


