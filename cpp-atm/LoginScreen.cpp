#pragma once
#include "Screen.cpp"

class LoginScreen : Screen
{
	*var instance;

	public static init()
	{
		if (instance == nullptr)
			this->instance = new();
	}

	private constructor()
	{
		
	}

	LoginScreen(int width, int height) : Screen(width, height)
	{
		

	}
};