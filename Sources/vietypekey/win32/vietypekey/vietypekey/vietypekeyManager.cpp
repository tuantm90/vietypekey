/*----------------------------------------------------------
vietypekey - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vietypekey
-----------------------------------------------------------*/
#include "vietypekeyManager.h"
#include <shlobj.h>

static vector<LPCTSTR> _inputType = {
	_T("Telex"),
	_T("VNI"),
	_T("Simple Telex"),
};

static vector<LPCTSTR> _tableCode = {
	_T("Unicode"),
	_T("TCVN3 (ABC)"),
	_T("VNI Windows"),
	_T("Unicode Tổ hợp"),
	_T("Vietnamese Locale CP 1258")
};

/*-----------------------------------------------------------------------*/

extern void vietypekeyInit();
extern void vietypekeyFree();

unsigned short  vietypekeyManager::_lastKeyCode = 0;

vector<LPCTSTR>& vietypekeyManager::getInputType() {
	return _inputType;
}

vector<LPCTSTR>& vietypekeyManager::getTableCode() {
	return _tableCode;
}

void vietypekeyManager::initEngine() {
	vietypekeyInit();
}

void vietypekeyManager::freeEngine() {
	vietypekeyFree();
}

bool vietypekeyManager::checkUpdate(string& newVersion) {
	wstring dataW = vietypekeyHelper::getContentOfUrl(L"https://raw.githubusercontent.com/tuyenvm/vietypekey/master/version.json");
	string data = wideStringToUtf8(dataW);

	//simple parse
	constexpr char versionNameStr[] = "\"versionName\":";
	constexpr char versionCodeStr[] = "\"versionCode\":";
	constexpr char numbers[] = "0123456789";
	size_t posBegin = string::npos;
	size_t posEnd = string::npos;

	posBegin = data.find("latestWinVersion");
	posBegin = data.find(versionNameStr, posBegin);
	posBegin += (sizeof(versionNameStr) - 1);
	posBegin = data.find('\"', posBegin);
	posBegin = data.find_first_of(numbers, posBegin);

	posEnd = data.find('\"', posBegin);

	if (posBegin == string::npos || posEnd == string::npos) {
		return false;
	}

	newVersion = data.substr(posBegin, posEnd - posBegin);

	posBegin = posEnd;
	posBegin = data.find(versionCodeStr, posBegin);
	posBegin += (sizeof(versionCodeStr) - 1);

	posEnd = data.find("}", posBegin);

	if (posBegin == string::npos || posEnd == string::npos) {
		return false;
	}

	auto shiftVersion = [](DWORD version) {
		return (version << 16) | (version & 0x00FF00) | (version >> 16 & 0xFF);
		};

	string newVersionCodeStr = data.substr(posBegin, posEnd - posBegin);
	DWORD newVersionCode = (DWORD)atoi(newVersionCodeStr.data());
	newVersionCode = shiftVersion(newVersionCode);

	DWORD currentVersionCode = vietypekeyHelper::getVersionNumber();
	currentVersionCode = shiftVersion(currentVersionCode);

	return newVersionCode > currentVersionCode;
}

void vietypekeyManager::createDesktopShortcut() {
	CoInitialize(NULL);
	IShellLink* pShellLink = NULL;
	HRESULT hres;
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_ALL,
							IID_IShellLink, (void**)&pShellLink);
	if (SUCCEEDED(hres)) {
		wstring path = vietypekeyHelper::getFullPath();
		pShellLink->SetPath(path.c_str());
		pShellLink->SetDescription(_T("vietypekey - Bộ gõ Tiếng Việt"));
		pShellLink->SetIconLocation(path.c_str(), 0);

		IPersistFile* pPersistFile;
		hres = pShellLink->QueryInterface(IID_IPersistFile, (void**)&pPersistFile);

		if (SUCCEEDED(hres)) {
			wchar_t desktopPath[MAX_PATH + 1];
			wchar_t savePath[MAX_PATH + 10];
			SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath);
			wsprintf(savePath, _T("%s\\vietypekey.lnk"), desktopPath);
			hres = pPersistFile->Save(savePath, TRUE);
			pPersistFile->Release();
			pShellLink->Release();
		}
	}
}
