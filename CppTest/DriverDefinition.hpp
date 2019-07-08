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
	const std::string schema_generated_files3_DriverDefinition_namespace = "";
	enum class PrintMode {
		None,
		Normal,
		Monitor,
	};

	PrintMode ConvertStringToPrintMode(std::string str) {
		if (str == "None") return PrintMode::None;
		if (str == "Normal") return PrintMode::Normal;
		if (str == "Monitor") return PrintMode::Monitor;
		throw std::exception("Can't convert string to enum value");
	}

	std::string ConvertPrintModeToString(PrintMode e) {
		if (e == PrintMode::None) return "None";
		if (e == PrintMode::Normal) return "Normal";
		if (e == PrintMode::Monitor) return "Monitor";
		throw std::exception("Can't convert enum value to string");
	}

	struct Printer;
	struct DriverCapabilities;
	struct Properties;
	struct Property;
	struct Driver;
	struct SupportedPrinters;
	struct Printer {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string ModelId;
		std::string Name;
		std::string Manufacturer;
		std::optional<std::string> IconFile;
		std::optional<std::reference_wrapper<Materialise::DriverCapabilities>> DriverCapabilities;
		std::optional<std::reference_wrapper<Materialise::Properties>> Properties;
		Printer() {}
		~Printer() {}
	};
	struct SupportedPrinters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Printer> Printer;
		SupportedPrinters() {}
		~SupportedPrinters() {}
	};
	struct Driver {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Id;
		std::string Name;
		std::string Provider;
		std::string Version;
		std::string DriverDll;
		std::optional<std::string> MonitorDll;
		std::optional<std::string> UserDriverDll;
		std::string SupportedApi;
		std::optional<std::reference_wrapper<Materialise::Properties>> Properties;
		Materialise::SupportedPrinters SupportedPrinters;
		Driver() {}
		~Driver() {}
	};
	struct Property {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Name;
		Property() {}
		~Property() {}
	};
	struct Properties {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::Property> Property;
		Properties() {}
		~Properties() {}
	};
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<bool> CanUploadOnly;
		std::optional<PrintMode> PrintMode;
		std::optional<bool> NoUpload;
		std::optional<bool> CanGetPrintDetails;
		DriverCapabilities() {}
		~DriverCapabilities() {}
	};
}
void Materialise::Printer::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ModelId", ModelId.c_str());
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	if (IconFile.has_value())
		s.Write("IconFile", IconFile.value().c_str());
	if (DriverCapabilities.has_value())
		DriverCapabilities.value().get().Write(s, "DriverCapabilities");
	if (Properties.has_value())
		Properties.value().get().Write(s, "Properties");
}
bool Materialise::Printer::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("ModelId", ModelId);
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	s.ReadStr("IconFile", IconFile.value());
	Materialise::DriverCapabilities* __DriverCapabilities = new Materialise::DriverCapabilities();
	__DriverCapabilities->Read(s, "DriverCapabilities");
	DriverCapabilities = std::optional<std::reference_wrapper<Materialise::DriverCapabilities>> { *__DriverCapabilities };
	Materialise::Properties* __Properties = new Materialise::Properties();
	__Properties->Read(s, "Properties");
	Properties = std::optional<std::reference_wrapper<Materialise::Properties>> { *__Properties };
	return true;
}
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (CanUploadOnly.has_value())
		s.Write("CanUploadOnly", CanUploadOnly.value());
	if (PrintMode.has_value())
		s.WriteAttr("PrintMode", Materialise::ConvertPrintModeToString(PrintMode.value()).c_str());
	if (NoUpload.has_value())
		s.Write("NoUpload", NoUpload.value());
	if (CanGetPrintDetails.has_value())
		s.Write("CanGetPrintDetails", CanGetPrintDetails.value());
}
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	std::string __tmp_var;
	s.ReadBool("CanUploadOnly", CanUploadOnly.value());
	if (s.ReadAttrStr("PrintMode", __tmp_var)) 
		PrintMode = Materialise::ConvertStringToPrintMode(__tmp_var);
	s.ReadBool("NoUpload", NoUpload.value());
	s.ReadBool("CanGetPrintDetails", CanGetPrintDetails.value());
	return true;
}
void Materialise::Properties::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s, "Property"); 
	}
}
bool Materialise::Properties::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Property __t;
		if (__t.Read(s, "Property") == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::Property::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
}
bool Materialise::Property::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Name", Name);
	return true;
}
void Materialise::Driver::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Id", Id.c_str());
	s.Write("Name", Name.c_str());
	s.Write("Provider", Provider.c_str());
	s.Write("Version", Version.c_str());
	s.Write("DriverDll", DriverDll.c_str());
	if (MonitorDll.has_value())
		s.Write("MonitorDll", MonitorDll.value().c_str());
	if (UserDriverDll.has_value())
		s.Write("UserDriverDll", UserDriverDll.value().c_str());
	s.Write("SupportedApi", SupportedApi.c_str());
	if (Properties.has_value())
		Properties.value().get().Write(s, "Properties");
	SupportedPrinters.Write(s, "SupportedPrinters");
}
bool Materialise::Driver::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("Id", Id);
	s.ReadStr("Name", Name);
	s.ReadStr("Provider", Provider);
	s.ReadStr("Version", Version);
	s.ReadStr("DriverDll", DriverDll);
	s.ReadStr("MonitorDll", MonitorDll.value());
	s.ReadStr("UserDriverDll", UserDriverDll.value());
	s.ReadStr("SupportedApi", SupportedApi);
	Materialise::Properties* __Properties = new Materialise::Properties();
	__Properties->Read(s, "Properties");
	Properties = std::optional<std::reference_wrapper<Materialise::Properties>> { *__Properties };
	SupportedPrinters.Read(s, "SupportedPrinters");
	return true;
}
void Materialise::SupportedPrinters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < Printer.size();i++)
	{
		Printer[i].Write(s, "Printer"); 
	}
}
bool Materialise::SupportedPrinters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Printer __t;
		if (__t.Read(s, "Printer") == false)
			break;
		Printer.push_back(__t);
	}
	return true;
}
