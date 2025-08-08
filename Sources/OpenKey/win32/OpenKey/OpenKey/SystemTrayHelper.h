/*----------------------------------------------------------
Vie-Type - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vie-type
-----------------------------------------------------------*/
#pragma once
#include "stdafx.h"

class SystemTrayHelper {
private:
	static void CALLBACK WaitToCreateFakeWindow(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime);
	static HWND createFakeWindow(const HINSTANCE& hIns);
	static void createPopupMenu();

	static void _createSystemTrayIcon(const HINSTANCE& hIns);
public:
	static void createSystemTrayIcon(const HINSTANCE& hIns);
	static void updateData();
	static void removeSystemTray();
};

