// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#pragma comment(lib, "User32.lib")

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "defines.h"

#include <windows.h>

#include <msclr/marshal.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace System::Numerics;
using namespace System::Runtime::CompilerServices;

#include "Dummies.h"

#include "enums.h"
#include "CRGBA.h"
#include "CVectors.h"

#include "D3D9Stuff.h"

#include "AddressSetter.h"
#include "rage.h"

#include "CMenuManager.h"
#include "CTheScripts.h"

#include "NativeHashes.h"
#include "NativeInvoke.h"
#include "Native.h"

#include "SettingsFile.h"
#include "Scripts.h"
#include "CLRBridge.h"

#include "Helper.h"

#include "Direct3D9.h"

#include "CCam.h"
#include "CCamera.h"
#include "CGame.h"

#include "CPlayerInfo.h"
#include "CTimer.h"
#include "CPad.h"
#include "CEntity.h"
#include "CWorld.h"
#include "CDynamicEntity.h"
#include "CPhysical.h"
#include "CCustomShaderEffectBase.h"
#include "CBuilding.h"
#include "CInteriorInst.h"
#include "CObject.h"
#include "CHandlingDataMgr.h"
#include "CVehicle.h"
#include "CVehicleFactoryNY.h"
#include "CPed.h"
#include "CPedFactoryNY.h"
#include "CPool.h"
#include "CPools.h"

#include "CTask.h"
#include "CTasks.h"

#include "phBound.h"
#include "phInstGta.h"
#include "phConstrainedCollider.h"
#include "CFileLoader.h"
#include "CdStream.h"
#include "CHudColours.h"
#include "CVisibilityPlugins.h"
#include "CNetwork.h"
#include "CShadows.h"
#include "CClock.h"
#include "CCutsceneMgr.h"
#include "CDraw.h"
#include "CFont.h"
#include "audRadioAudioEntity.h"
#include "CShaderLib.h"
#include "CTimeCycle.h"
#include "CPickups.h"
#include "CPedType.h"

#endif //PCH_H
