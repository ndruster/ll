#pragma once

#pragma warning(disable:4311)
#pragma warning(disable:4267)
#pragma warning(disable:4312)

//-----------------------------------------------------------------------------
// 引用底层引擎
//-----------------------------------------------------------------------------

#define _WIN32_WINNT 0x0403

//------------------------------------------------------------------------------
// 包含vEngine头文件
//------------------------------------------------------------------------------
#include "..\vEngine\vEngine.h"
using namespace vEngine;

//------------------------------------------------------------------------------
// 数据库
//------------------------------------------------------------------------------
#include "..\Beton\Beton.h"
using namespace Beton;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
#pragma comment(lib,"..\\vsout\\vEngine\\debug\\vEngine.lib")
#else
#define X_STRING_RUN_TIME "Release"
#pragma comment(lib,"..\\vsout\\vEngine\\release\\vEngine.lib")
#endif

#ifdef _DEBUG
#pragma comment(lib,"..\\vsout\\Beton\\debug\\Beton.lib")
#else
#pragma comment(lib,"..\\vsout\\Beton\\release\\Beton.lib")
#endif

#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"winmm.lib")

#include "..\WorldDefine\base_define.h"
#include "..\WorldDefine\time.h"

// 引用STL
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;