/*----------------------------------------------------------
Vie-Type - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vie-type
-----------------------------------------------------------*/
#pragma once
#include "stdafx.h"

class Vie-TypeManager {
public:
	static unsigned short _lastKeyCode;
	static vector<LPCTSTR>& getInputType();
	static vector<LPCTSTR>& getTableCode();

	static void initEngine();
	static void freeEngine();

	static bool checkUpdate(string& newVersion);

	static void createDesktopShortcut();
};
