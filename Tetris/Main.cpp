#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"

constexpr unsigned short int c_cell_height = 32;

Vector2 g_pos;
const Vector2 g_vec_y = Vector2(0, c_cell_height);
const Vector2 g_vec_x = Vector2(c_cell_height, 0);

//Update loop
bool Update()
{
	if (g_hge->Input_KeyUp(HGEK_UP))
	{
		g_pos -= g_vec_y;
	}

	if (g_hge->Input_KeyUp(HGEK_DOWN))
	{
		g_pos += g_vec_y;
	}

	if (g_hge->Input_KeyUp(HGEK_LEFT))
	{
		g_pos -= g_vec_x;
	}

	if (g_hge->Input_KeyUp(HGEK_RIGHT))
	{
		g_pos += g_vec_x;
	}
	return false;
}

//Render loop
bool Render()
{
	RenderBegin();
	g_square_sprite->Render(g_pos);
	RenderEnd();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Initialize(320, 640, Update, Render);

	if(IsInitialized())
	{
		const char* path = "..//square_3px_border.png";
		g_square_sprite = new Sprite(const_cast<char*>(path), Vector2(0, 0), Vector2(c_cell_height, c_cell_height));
		g_pos = Vector2(5, 5);
		Run();
	}
	
	Shutdown();

	return 0;
}


