#pragma once

//namespace rage { class fiPackfile; }

class Native_CStreaming
{
public:
	//static inline rage::fiPackfile* m_pPlayerPackfile = AddressSetter::GetRef<rage::fiPackfile*>(0xF503FC, 0xECEBCC); // player:/
	static inline uint32_t& m_nPedModelBudget = AddressSetter::GetRef<uint32_t>(0xB22B5C, 0xB49B94);
	static inline uint32_t& m_nVehicleModelBudget = AddressSetter::GetRef<uint32_t>(0xB22B60, 0xB49B98);
	static inline uint8_t& ms_disableStreaming = AddressSetter::GetRef<uint8_t>(0xE1DFAA, 0xF997D2);

	static bool IsStreamingDisabled()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x432EF0, 0x4B4E80)))();
	}

	// this is easier to use until RequestModel is fully documented
	static void ScriptRequestModel(int32_t nHash, uint32_t* pRunningThread = nullptr)
	{
		((void(__cdecl*)(int32_t, uint32_t*))(AddressSetter::Get(0x76C3D0, 0x7191D0)))(nHash, pRunningThread);
	}
	//ScriptRequestModel: CStreaming::RequestModel(v4, dword_11F73A0, dword_12C38A8 | 0xC);
	// todo: look into this
	static void RequestModel(int32_t modelIndex, int32_t unk1, int32_t nFlags)
	{
		((void(__cdecl*)(int32_t, int32_t, int32_t))(AddressSetter::Get(0x432C40, 0x4B4BD0)))(modelIndex, unk1, nFlags);
	}
	static void LoadAllRequestedModels(bool priorityOnly)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get(0x432C20, 0x4B4BB0)))(priorityOnly);
	}

	// images.txt
	static void AddImageList(char* fileName)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x4D1FB0, 0x6C6590)))(fileName);
	}

	//static rage::fiPackfile* GetPlayerPackfile()
	//{
	//	return ((rage::fiPackfile * (__cdecl*)())(AddressSetter::Get(0x4DB210, 0x56B000)))();
	//}
	static void ClosePlayerPackfile()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4DA590, 0x56A340)))();
	}
};

namespace IVSDKDotNet {

	public ref class CStreaming
	{
	public:

		static property uint32_t PedModelBudget {
			public:
				uint32_t	get()				{ return Native_CStreaming::m_nPedModelBudget; }
				void		set(uint32_t value) { Native_CStreaming::m_nPedModelBudget = value; }
		}

		static property uint32_t VehicleModelBudget {
			public:
				uint32_t	get() { return Native_CStreaming::m_nVehicleModelBudget; }
				void		set(uint32_t value) { Native_CStreaming::m_nVehicleModelBudget = value; }
		}

		static property uint8_t DisableStreaming {
			public:
				uint8_t		get()				{ return Native_CStreaming::ms_disableStreaming; }
				void		set(uint8_t value)	{ Native_CStreaming::ms_disableStreaming = value; }
		}

		static bool IsStreamingDisabled();

		/// <summary>
		/// This is easier to use until RequestModel is fully documented.
		/// </summary>
		/// <param name="nHash">The model hash of the model you want to request.</param>
		static void ScriptRequestModel(int32_t nHash);

		/// <summary>
		/// This is easier to use until RequestModel is fully documented.
		/// </summary>
		/// <param name="nHash">The model hash of the model you want to request.</param>
		/// <param name="pRunningThread">?</param>
		static void ScriptRequestModel(int32_t nHash, UIntPtr pRunningThread);

		static void RequestModel(int32_t modelIndex, int32_t unk1, int32_t nFlags);

		static void LoadAllRequestedModels(bool priorityOnly);

		/// <summary>
		/// images.txt
		/// </summary>
		/// <param name="fileName">The path to the new images.txt file to add</param>
		static void AddImageList(String^ fileName);

		static void ClosePlayerPackfile();

	};

}