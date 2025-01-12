// INI Reader / Writer by ItsClonkAndre

#pragma once

namespace IVSDKDotNet {

	private ref class SectionValues
	{
	public:
		SectionValues(String^ firstkey, String^ firstValue);

		Dictionary<String^, String^>^ Values;
	};

	public ref class SettingsFile
	{
	public:
		/// <summary>
		/// Creates a new instance of the SettingsFile class.
		/// </summary>
		/// <param name="filePath">The path to the ini file.</param>
		SettingsFile(String^ filePath);

		~SettingsFile()
		{
			m_sFilePath = String::Empty;
			if (m_dSections) {
				m_dSections->Clear();
				m_dSections = nullptr;
			}
		}

		/// <summary>
		/// Overrides the current ini file with the new content.
		/// </summary>
		/// <returns>True if the file got saved. False when the file does not exists or if there is nothing to save.</returns>
		bool Save();

		/// <summary>
		/// Loads the content of the specified ini file.
		/// If you made changes to the ini via SetValue and reload the file those changes are getting lost if you haven't saved the file first with Save.
		/// </summary>
		/// <returns>True if the file got loaded. False when the file does not exists.</returns>
		bool Load();

		/// <summary>
		/// Adds a new section to the ini file.
		/// </summary>
		/// <param name="sectionName">The name of the new section.</param>
		/// <returns>True if the section got created. Otherwise false if the section already exists in the ini or if the name is null.</returns>
		bool AddSection(String^ sectionName);

		/// <summary>
		/// Adds a new key to the specified section.
		/// </summary>
		/// <param name="section">The section to add the new key.</param>
		/// <param name="keyName">The name of the new key.</param>
		/// <returns>True if the key got created in the section. Otherwise false if the section does not exists, the key already exists in the ini or if the name is null.</returns>
		bool AddKeyToSection(String^ section, String^ keyName);

		/// <summary>
		/// Gets the value from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The value from the given section and key strings. Otherwise it returns defaultValue.</returns>
		String^ GetValue(String^ section, String^ key, String^ defaultValue);

		/// <summary>
		/// Sets the value from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool	SetValue(String^ section, String^ key, String^ value);

#pragma region Boolean
		/// <summary>
		/// Gets the boolean from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The boolean from the given section and key strings. Otherwise it returns defaultValue.</returns>
		bool GetBoolean(String^ section, String^ key, bool defaultValue);

		/// <summary>
		/// Sets the boolean from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool SetBoolean(String^ section, String^ key, bool value);
#pragma endregion

#pragma region Integer
		/// <summary>
		/// Gets the integer from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The integer from the given section and key strings. Otherwise it returns defaultValue.</returns>
		int GetInteger(String^ section, String^ key, int defaultValue);

		/// <summary>
		/// Sets the integer from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool SetInteger(String^ section, String^ key, int value);
#pragma endregion

#pragma region Float
		/// <summary>
		/// Gets the float from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The float from the given section and key strings. Otherwise it returns defaultValue.</returns>
		float GetFloat(String^ section, String^ key, float defaultValue);

		/// <summary>
		/// Sets the float from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool SetFloat(String^ section, String^ key, float value);
#pragma endregion

#pragma region Color
		/// <summary>
		/// Gets the color from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The color from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Color GetColor(String^ section, String^ key, Color defaultValue);

		/// <summary>
		/// Sets the color from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool SetColor(String^ section, String^ key, Color value);
#pragma endregion

#pragma region Key
		/// <summary>
		/// Gets the WinForms Key from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The WinForms Key from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Keys GetKey(String^ section, String^ key, Keys defaultValue);

		/// <summary>
		/// Sets the WinForms Key from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool SetKey(String^ section, String^ key, Keys value);
#pragma endregion

#pragma region Quaternion
		/// <summary>
		/// Gets an Quaternion from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The Quaternion from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Quaternion	GetQuaternion(String^ section, String^ key, Quaternion defaultValue);

		/// <summary>
		/// Sets the Quaternion from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool		SetQuaternion(String^ section, String^ key, Quaternion value);
#pragma endregion

#pragma region Vector2
		/// <summary>
		/// Gets an Vector2 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The Vector2 from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Vector2 GetVector2(String^ section, String^ key, Vector2 defaultValue);

		/// <summary>
		/// Sets the Vector2 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool	SetVector2(String^ section, String^ key, Vector2 value);
#pragma endregion

#pragma region Vector3
		/// <summary>
		/// Gets an Vector3 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The Vector3 from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Vector3 GetVector3(String^ section, String^ key, Vector3 defaultValue);

		/// <summary>
		/// Sets the Vector3 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool	SetVector3(String^ section, String^ key, Vector3 value);
#pragma endregion

#pragma region Vector4
		/// <summary>
		/// Gets an Vector4 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to get the value from.</param>
		/// <param name="defaultValue">The default value if get value fails.</param>
		/// <returns>The Vector4 from the given section and key strings. Otherwise it returns defaultValue.</returns>
		Vector4 GetVector4(String^ section, String^ key, Vector4 defaultValue);

		/// <summary>
		/// Sets the Vector4 from the given section and key strings from the loaded ini file.
		/// </summary>
		/// <param name="section">The section the key is located.</param>
		/// <param name="key">The key you want to set the value to.</param>
		/// <param name="value">The new value.</param>
		/// <returns>True if the value from the given section and key got changed. Otherwise false if the section or key does not exists.</returns>
		bool	SetVector4(String^ section, String^ key, Vector4 value);
#pragma endregion

		/// <summary>
		/// The path to the ini file.
		/// </summary>
		property String^ FilePath {
			public:		String^ get()			{ return m_sFilePath; }
			internal:	void set(String^ value) { m_sFilePath = value; }
		}

	private:
		static array<String^>^ s_aSeparator =		gcnew array<String^>(1)	{ "=" };
		static array<String^>^ s_aVectorSeparator = gcnew array<String^>(1)	{ ":" };

		String^ m_sFilePath;
		Dictionary<String^, SectionValues^>^ m_dSections;
	};

}