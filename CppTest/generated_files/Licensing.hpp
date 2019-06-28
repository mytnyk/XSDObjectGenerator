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
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::string DisplayName;
		std::optional<bool> IsMain;
		std::optional<bool> IsDemo;
		std::optional<Materialise::LicenseVisibility> Visibility;
		License() {}
		~License() {}
	};
	struct Licenses {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::License> License;
		Licenses() {}
		~Licenses() {}
	};
	struct Licensing {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		Materialise::Licenses Licenses;
		std::optional<std::reference_wrapper<Materialise::PluginsLicenseNameMapping>> PluginsLicenseNameMapping;
		Licensing() {}
		~Licensing() {}
	};
	struct LicenseName {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string From;
		std::string To;
		LicenseName() {}
		~LicenseName() {}
	};
	struct Plugin {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		std::vector<Materialise::LicenseName> LicenseName;
		Plugin() {}
		~Plugin() {}
	};
	struct PluginsLicenseNameMapping {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Plugin> Plugin;
		PluginsLicenseNameMapping() {}
		~PluginsLicenseNameMapping() {}
	};
}
void Materialise::License::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "License");
	s.WriteAttr("Name", Name.c_str());
	s.WriteAttr("DisplayName", DisplayName.c_str());
	s.WriteAttr("IsMain", IsMain.value());
	s.WriteAttr("IsDemo", IsDemo.value());
	s.WriteAttr("Visibility", Materialise::ConvertLicenseVisibilityToString(Visibility.value()).c_str());
}
bool Materialise::License::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "License");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	DisplayName = s.ReadAttrStr("DisplayName");
	IsMain = s.ReadAttrBool("IsMain");
	IsDemo = s.ReadAttrBool("IsDemo");
	Visibility = Materialise::ConvertStringToLicenseVisibility(s.ReadAttrStr("Visibility"));
	return true;
}
void Materialise::Licenses::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Licenses");
	for(int i = 0;i < License.size();i++)
	{
		License[i].Write(s); 
	}
}
bool Materialise::Licenses::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Licenses");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::License __t;
		if (__t.Read(s) == false)
			break;
		License.push_back(__t);
	}
	return true;
}
void Materialise::Plugin::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Plugin");
	s.WriteAttr("Name", Name.c_str());
	for(int i = 0;i < LicenseName.size();i++)
	{
		LicenseName[i].Write(s); 
	}
}
bool Materialise::Plugin::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Plugin");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	while (true) { 
		Materialise::LicenseName __t;
		if (__t.Read(s) == false)
			break;
		LicenseName.push_back(__t);
	}
	return true;
}
void Materialise::LicenseName::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "LicenseName");
	s.WriteAttr("From", From.c_str());
	s.WriteAttr("To", To.c_str());
}
bool Materialise::LicenseName::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "LicenseName");
	if (scope.exist() == false)
		return false;
	From = s.ReadAttrStr("From");
	To = s.ReadAttrStr("To");
	return true;
}
void Materialise::PluginsLicenseNameMapping::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PluginsLicenseNameMapping");
	for(int i = 0;i < Plugin.size();i++)
	{
		Plugin[i].Write(s); 
	}
}
bool Materialise::PluginsLicenseNameMapping::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PluginsLicenseNameMapping");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Plugin __t;
		if (__t.Read(s) == false)
			break;
		Plugin.push_back(__t);
	}
	return true;
}
void Materialise::Licensing::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Licensing");
	Licenses.Write(s);
	PluginsLicenseNameMapping.value().get().Write(s);
}
bool Materialise::Licensing::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Licensing");
	if (scope.exist() == false)
		return false;
	Licenses.Read(s);
	Materialise::PluginsLicenseNameMapping* __PluginsLicenseNameMapping = new Materialise::PluginsLicenseNameMapping();
	__PluginsLicenseNameMapping->Read(s);
	PluginsLicenseNameMapping = std::optional<std::reference_wrapper<Materialise::PluginsLicenseNameMapping>> { *__PluginsLicenseNameMapping };
	return true;
}
