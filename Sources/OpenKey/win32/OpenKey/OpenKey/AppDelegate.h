/*----------------------------------------------------------
Vie-Type - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vie-type
-----------------------------------------------------------*/
#pragma once
#include "stdafx.h"
#include "MainControlDialog.h"
#include "AboutDialog.h"
#include "ConvertToolDialog.h"
#include "MacroDialog.h"

class BaseDialog;
class AppDelegate {
private:
	HINSTANCE hInstance;
	BaseDialog* mainDialog = NULL, *aboutDialog = NULL, *macroDialog = NULL, *convertDialog = NULL;
private:
	bool isDialogMsg(MSG &msg) const;
	void checkUpdate();
public:
	AppDelegate();
	static AppDelegate* getInstance();
	int run(HINSTANCE hInstance);
	void createMainDialog();
	void closeDialog(BaseDialog* dialog);
public: //event
	void onInputMethodChangedFromHotKey();
	void onDefaultConfig();

	void onToggleVietnamese();
	void onToggleCheckSpelling();
	void onToggleUseSmartSwitchKey();
	void onToggleUseMacro();

	void onMacroTable();
	void onConvertTool();
	void onQuickConvert();

	void onInputType(const int& type);
	void onTableCode(const int& code);

	void onControlPanel();
	void onvie-typeAbout();
	void onvie-typeExit();
};
