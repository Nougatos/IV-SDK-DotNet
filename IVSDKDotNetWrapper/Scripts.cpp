#include "pch.h"
#include "Native.h"
#include "Scripts.h"

using namespace IVSDKDotNet::Manager;

namespace IVSDKDotNet {
	namespace Manager {

		// =========================================================================
		// ============================= ManagerScript =============================
		// =========================================================================
		ManagerScript::ManagerScript()
		{
			if (ManagerScript::s_Instance) delete this; // There is already a instance of the ManagerScript class. Delete this class.
		}

		void ManagerScript::Debug_ShowMessageBox(String^ str)		{ SHOW_MESSAGE(str); }
		void ManagerScript::Debug_ShowInfoMessageBox(String^ str)	{ SHOW_INFO_MESSAGE(str); }
		void ManagerScript::Debug_ShowWarnMessageBox(String^ str)	{ SHOW_WARN_MESSAGE(str); }
		void ManagerScript::Debug_ShowErrorMessageBox(String^ str)	{ SHOW_ERROR_MESSAGE(str); }

	}

	// =========================================================================
	// ================================== Script ===============================
	// =========================================================================
	Script::Script()
	{
		AssembliesLocation = eAssembliesLocation::GameRootDirectory;
		CustomAssembliesPath = String::Empty;
		ScriptDomain = AppDomain::CurrentDomain;
		ID = Guid::NewGuid();
	}

	Guid Script::StartNewTask(Func<Object^>^ funcToExecute)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->StartNewTask(this->ID, funcToExecute, nullptr);

		return Guid::Empty;
	}
	Guid Script::StartNewTask(Func<Object^>^ funcToExecute, Action<Object^>^ continueWithAction)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->StartNewTask(this->ID, funcToExecute, continueWithAction);

		return Guid::Empty;
	}

	Guid Script::StartNewTimer(int interval, Action^ actionToExecute)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->StartNewTimer(this->ID, interval, actionToExecute);

		return Guid::Empty;
	}

	void Script::WaitInTask(Guid id, int waitTimeInMilliseconds)
	{
		if (ManagerScript::s_Instance) ManagerScript::s_Instance->WaitInTask(id, waitTimeInMilliseconds);
	}

	void Script::AbortTaskOrTimer(Guid id)
	{
		if (ManagerScript::s_Instance) ManagerScript::s_Instance->AbortTaskOrTimer(id);
	}
	void Script::ChangeTimerState(Guid id, bool pause)
	{
		if (ManagerScript::s_Instance) ManagerScript::s_Instance->ChangeTimerState(id, pause);
	}
	void Script::ChangeTimerInterval(Guid id, int interval)
	{
		if (ManagerScript::s_Instance) ManagerScript::s_Instance->ChangeTimerInterval(id, interval);
	}

	void Script::ShowSubtitleMessage(String^ str, uint32_t time)
	{
		IVSDKDotNet::Native::Natives::PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", str, time, true);
	}
	void Script::ShowSubtitleMessage(String^ str, ...array<System::Object^>^ args)
	{
		IVSDKDotNet::Native::Natives::PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", String::Format(str, args), 2000, true);
	}
	void Script::ShowSubtitleMessage(String^ str)
	{
		IVSDKDotNet::Native::Natives::PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", str, 2000, true);
	}

	bool Script::IsKeyPressed(Keys key)
	{
		return Helper::IsKeyPressedAsync(key);
	}
	bool Script::Abort()
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->AbortScript(ID);
		
		return false;
	}

	bool Script::RegisterConsoleCommand(String^ name, Action<array<String^>^>^ actionToExecute)
	{
		return CGame::Console::RegisterCommand(this, name, actionToExecute);
	}

	String^ Script::GetName()
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->GetScriptName(this->ID);

		return String::Empty;
	}
	String^ Script::GetFullPath()
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->GetScriptFullPath(this->ID);

		return String::Empty;
	}

	bool Script::DoesScriptExists(Guid id)
	{
		return GetScript(id) != nullptr;
	}
	bool Script::DoesScriptExists(String^ name)
	{
		return GetScript(name) != nullptr;
	}

	bool Script::IsScriptRunning(Guid id)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->IsScriptRunning(id);

		return false;
	}
	bool Script::IsScriptRunning(String^ name)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->IsScriptRunning(name);

		return false;
	}

	Script^ Script::GetScript(Guid id)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->GetScript(id);

		return nullptr;
	}
	Script^ Script::GetScript(String^ name)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->GetScript(name);

		return nullptr;
	}

	array<Script^>^ Script::GetAllScripts()
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->GetAllScripts();

		return nullptr;
	}

	bool Script::SendScriptCommand(Script^ toScript, String^ command)
	{
		if (ManagerScript::s_Instance)
			return ManagerScript::s_Instance->SendScriptCommand(toScript, command);

		return false;
	}

}