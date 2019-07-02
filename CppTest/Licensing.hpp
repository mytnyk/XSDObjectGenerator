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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::string DisplayName;
		std::optional<bool> IsMain;
		std::optional<bool> IsDemo;
		std::optional<Materialise::LicenseVisibility> Visibility;
		License() {}
		~License() {}
	};
	struct Licenses {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::License> License;
		Licenses() {}
		~Licenses() {}
	};
	struct Licensing {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		Materialise::Licenses Licenses;
		std::optional<std::reference_wrapper<Materialise::PluginsLicenseNameMapping>> PluginsLicenseNameMapping;
		Licensing() {}
		~Licensing() {}
	};
	struct LicenseName {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string From;
		std::string To;
		LicenseName() {}
		~LicenseName() {}
	};
	struct Plugin {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		std::vector<Materialise::LicenseName> LicenseName;
		Plugin() {}
		~Plugin() {}
	};
	struct PluginsLicenseNameMapping {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Plugin> Plugin;
		PluginsLicenseNameMapping() {}
		~PluginsLicenseNameMapping() {}
	};
}
void Materialise::License::Write(IXmlSerializerWriter& s, std::string __name__) {
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
bool Materialise::License::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadAttrStr("Name", Name);
	s.ReadAttrStr("DisplayName", DisplayName);
	bool* __IsMain = new bool();
	if (s.ReadAttrBool("IsMain", *__IsMain))
		IsMain = std::optional<std::reference_wrapper<bool>> { *__IsMain };
	bool* __IsDemo = new bool();
	if (s.ReadAttrBool("IsDemo", *__IsDemo))
		IsDemo = std::optional<std::reference_wrapper<bool>> { *__IsDemo };
	if (s.ReadAttrStr("Visibility", __tmp_var)) 
		Visibility = Materialise::ConvertStringToLicenseVisibility(__tmp_var);
	return true;
}
void Materialise::Licenses::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < License.size();i++)
	{
		License[i].Write(s, "License"); 
	}
}
bool Materialise::Licenses::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::License __t;
		if (__t.Read(s, "License") == false)
			break;
		License.push_back(__t);
	}
	return true;
}
void Materialise::Plugin::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
	for(int i = 0;i < LicenseName.size();i++)
	{
		LicenseName[i].Write(s, "LicenseName"); 
	}
}
bool Materialise::Plugin::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Name", Name);
	while (true) { 
		Materialise::LicenseName __t;
		if (__t.Read(s, "LicenseName") == false)
			break;
		LicenseName.push_back(__t);
	}
	return true;
}
void Materialise::LicenseName::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("From", From.c_str());
	s.WriteAttr("To", To.c_str());
}
bool Materialise::LicenseName::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("From", From);
	s.ReadAttrStr("To", To);
	return true;
}
void Materialise::PluginsLicenseNameMapping::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Plugin.size();i++)
	{
		Plugin[i].Write(s, "Plugin"); 
	}
}
bool Materialise::PluginsLicenseNameMapping::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Plugin __t;
		if (__t.Read(s, "Plugin") == false)
			break;
		Plugin.push_back(__t);
	}
	return true;
}
void Materialise::Licensing::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	Licenses.Write(s, "Licenses");
	if (PluginsLicenseNameMapping.has_value())
		PluginsLicenseNameMapping.value().get().Write(s, "PluginsLicenseNameMapping");
}
bool Materialise::Licensing::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Licenses.Read(s, "Licenses");
	Materialise::PluginsLicenseNameMapping* __PluginsLicenseNameMapping = new Materialise::PluginsLicenseNameMapping();
	__PluginsLicenseNameMapping->Read(s, "PluginsLicenseNameMapping");
	PluginsLicenseNameMapping = std::optional<std::reference_wrapper<Materialise::PluginsLicenseNameMapping>> { *__PluginsLicenseNameMapping };
	return true;
}
