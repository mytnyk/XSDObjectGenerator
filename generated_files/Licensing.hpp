#pragma once
// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk
// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)
//--------------------------------------------------------------
#include <iostream>
#include <string>
#include <ctime>
#include "Serializers.hpp"
#include <optional>
namespace Materialise {
	const std::string schema_generated_files_Licensing_namespace = "";
	enum class LicenseVisibility {
		Visible,
		Hidden,
		HiddenIfAbsent,
	};

	LicenseVisibility ConvertStringToLicenseVisibility(std::string str) {
		if (str == "Visible") return LicenseVisibility::Visible;
		if (str == "Hidden") return LicenseVisibility::Hidden;
		if (str == "HiddenIfAbsent") return LicenseVisibility::HiddenIfAbsent;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertLicenseVisibilityToString(LicenseVisibility e) {
		if (e == LicenseVisibility::Visible) return "Visible";
		if (e == LicenseVisibility::Hidden) return "Hidden";
		if (e == LicenseVisibility::HiddenIfAbsent) return "HiddenIfAbsent";
		throw std::exception("Can't convert enum value to string");
	}

	struct License;
	struct Licenses;
	struct Plugin;
	struct LicenseName;
	struct PluginsLicenseNameMapping;
	struct Licensing;
	struct License {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		License(const License&) = delete;
		License& operator=(License&&) = delete;
		License& operator=(License&) = delete;
		License(License&&) noexcept;
		License() = default;
		~License() = default;
		std::string Name;
		std::string DisplayName;
		std::optional<bool> IsMain;
		std::optional<bool> IsDemo;
		std::optional<LicenseVisibility> Visibility;
	};
	struct Licenses {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Licenses(const Licenses&) = delete;
		Licenses& operator=(Licenses&&) = delete;
		Licenses& operator=(Licenses&) = delete;
		Licenses(Licenses&&) noexcept;
		Licenses() = default;
		~Licenses() = default;
		std::vector<License> License;
	};
	struct Licensing {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Licensing(const Licensing&) = delete;
		Licensing& operator=(Licensing&&) = delete;
		Licensing& operator=(Licensing&) = delete;
		Licensing(Licensing&&) noexcept;
		Licensing() = default;
		~Licensing() = default;
		Licenses Licenses;
		std::optional<std::unique_ptr<PluginsLicenseNameMapping>> PluginsLicenseNameMapping;
	};
	struct LicenseName {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		LicenseName(const LicenseName&) = delete;
		LicenseName& operator=(LicenseName&&) = delete;
		LicenseName& operator=(LicenseName&) = delete;
		LicenseName(LicenseName&&) noexcept;
		LicenseName() = default;
		~LicenseName() = default;
		std::string From;
		std::string To;
	};
	struct Plugin {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Plugin(const Plugin&) = delete;
		Plugin& operator=(Plugin&&) = delete;
		Plugin& operator=(Plugin&) = delete;
		Plugin(Plugin&&) noexcept;
		Plugin() = default;
		~Plugin() = default;
		std::string Name;
		std::vector<LicenseName> LicenseName;
	};
	struct PluginsLicenseNameMapping {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PluginsLicenseNameMapping(const PluginsLicenseNameMapping&) = delete;
		PluginsLicenseNameMapping& operator=(PluginsLicenseNameMapping&&) = delete;
		PluginsLicenseNameMapping& operator=(PluginsLicenseNameMapping&) = delete;
		PluginsLicenseNameMapping(PluginsLicenseNameMapping&&) noexcept;
		PluginsLicenseNameMapping() = default;
		~PluginsLicenseNameMapping() = default;
		std::vector<Plugin> Plugin;
	};
}
Materialise::License::License(Materialise::License &&___License) noexcept
	: Name(___License.Name)
	, DisplayName(___License.DisplayName)
	, IsMain(___License.IsMain)
	, IsDemo(___License.IsDemo)
	, Visibility(___License.Visibility)
{ }
void Materialise::License::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("DisplayName", DisplayName.c_str());
	if (IsMain.has_value())
		s.WriteAttr("IsMain", IsMain.value());
	if (IsDemo.has_value())
		s.WriteAttr("IsDemo", IsDemo.value());
	if (Visibility.has_value())
		s.WriteAttr("Visibility", Materialise::ConvertLicenseVisibilityToString(Visibility.value()).c_str());
}
bool Materialise::License::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	s.ReadAttrStr("DisplayName", DisplayName);
	bool __IsMain;
	if (s.ReadAttrBool("IsMain", __IsMain))
		IsMain = std::optional<bool> { __IsMain };
	bool __IsDemo;
	if (s.ReadAttrBool("IsDemo", __IsDemo))
		IsDemo = std::optional<bool> { __IsDemo };
	if (s.ReadAttrStr("Visibility", __tmp_var)) 
		Visibility = Materialise::ConvertStringToLicenseVisibility(__tmp_var);
	return true;
}
Materialise::Licenses::Licenses(Materialise::Licenses &&___Licenses) noexcept
	: License(std::move(___Licenses.License))
{ }
void Materialise::Licenses::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : License)
	{
		element.Write(s, "License"); 
	}
}
bool Materialise::Licenses::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::License __t;
		if (!__t.Read(s, "License"))
			break;
		License.push_back(std::move(__t));
	}
	return true;
}
Materialise::Plugin::Plugin(Materialise::Plugin &&___Plugin) noexcept
	: Name(___Plugin.Name)
	, LicenseName(std::move(___Plugin.LicenseName))
{ }
void Materialise::Plugin::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	for(auto&& element : LicenseName)
	{
		element.Write(s, "LicenseName"); 
	}
}
bool Materialise::Plugin::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Name", Name);
	while (true) { 
		Materialise::LicenseName __t;
		if (!__t.Read(s, "LicenseName"))
			break;
		LicenseName.push_back(std::move(__t));
	}
	return true;
}
Materialise::LicenseName::LicenseName(Materialise::LicenseName &&___LicenseName) noexcept
	: From(___LicenseName.From)
	, To(___LicenseName.To)
{ }
void Materialise::LicenseName::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("From", From.c_str());
	s.WriteAttr("To", To.c_str());
}
bool Materialise::LicenseName::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("From", From);
	s.ReadAttrStr("To", To);
	return true;
}
Materialise::PluginsLicenseNameMapping::PluginsLicenseNameMapping(Materialise::PluginsLicenseNameMapping &&___PluginsLicenseNameMapping) noexcept
	: Plugin(std::move(___PluginsLicenseNameMapping.Plugin))
{ }
void Materialise::PluginsLicenseNameMapping::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Plugin)
	{
		element.Write(s, "Plugin"); 
	}
}
bool Materialise::PluginsLicenseNameMapping::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Plugin __t;
		if (!__t.Read(s, "Plugin"))
			break;
		Plugin.push_back(std::move(__t));
	}
	return true;
}
Materialise::Licensing::Licensing(Materialise::Licensing &&___Licensing) noexcept
	: Licenses(std::move(___Licensing.Licenses))
	, PluginsLicenseNameMapping(std::move(___Licensing.PluginsLicenseNameMapping))
{ }
void Materialise::Licensing::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Licenses.Write(s, "Licenses");
	if (PluginsLicenseNameMapping.has_value())
		PluginsLicenseNameMapping.value().get()->Write(s, "PluginsLicenseNameMapping");
}
bool Materialise::Licensing::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	Licenses.Read(s, "Licenses");
	std::unique_ptr<Materialise::PluginsLicenseNameMapping> __PluginsLicenseNameMapping = std::make_unique<Materialise::PluginsLicenseNameMapping>();
	if (__PluginsLicenseNameMapping->Read(s, "PluginsLicenseNameMapping"))
		PluginsLicenseNameMapping = std::make_optional(std::move(__PluginsLicenseNameMapping));
	return true;
}
