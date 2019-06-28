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
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string ModelId;
		std::string Name;
		std::string Manufacturer;
		std::optional<std::string> IconFile {""};
		std::optional<std::reference_wrapper<Materialise::DriverCapabilities>> DriverCapabilities;
		std::optional<std::reference_wrapper<Materialise::Properties>> Properties;
		Printer() {}
		~Printer() {}
	};
	struct SupportedPrinters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Printer> Printer;
		SupportedPrinters() {}
		~SupportedPrinters() {}
	};
	struct Driver {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Id;
		std::string Name;
		std::string Provider;
		std::string Version;
		std::string DriverDll;
		std::optional<std::string> MonitorDll {""};
		std::optional<std::string> UserDriverDll {""};
		std::string SupportedApi;
		std::optional<std::reference_wrapper<Materialise::Properties>> Properties;
		Materialise::SupportedPrinters SupportedPrinters;
		Driver() {}
		~Driver() {}
	};
	struct Property {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Name;
		Property() {}
		~Property() {}
	};
	struct Properties {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::Property> Property;
		Properties() {}
		~Properties() {}
	};
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> CanUploadOnly {0};
		std::optional<PrintMode> PrintMode {0};
		std::optional<bool> NoUpload {0};
		std::optional<bool> CanGetPrintDetails {0};
		DriverCapabilities() {}
		~DriverCapabilities() {}
	};
}
void Materialise::Printer::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Printer");
	s.WriteAttr("ModelId", ModelId.c_str());
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	s.Write("IconFile", IconFile.value().c_str());
	DriverCapabilities.value().get().Write(s);
	Properties.value().get().Write(s);
}
bool Materialise::Printer::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Printer");
	if (scope.exist() == false)
		return false;
	ModelId = s.ReadAttrStr("ModelId");
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	s.ReadStr("IconFile", IconFile.value());
	Materialise::DriverCapabilities* __DriverCapabilities = new Materialise::DriverCapabilities();
	__DriverCapabilities->Read(s);
	DriverCapabilities = std::optional<std::reference_wrapper<Materialise::DriverCapabilities>> { *__DriverCapabilities };
	Materialise::Properties* __Properties = new Materialise::Properties();
	__Properties->Read(s);
	Properties = std::optional<std::reference_wrapper<Materialise::Properties>> { *__Properties };
	return true;
}
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "DriverCapabilities");
	s.Write("CanUploadOnly", CanUploadOnly.value());
	s.WriteAttr("PrintMode", Materialise::ConvertPrintModeToString(PrintMode.value()).c_str());
	s.Write("NoUpload", NoUpload.value());
	s.Write("CanGetPrintDetails", CanGetPrintDetails.value());
}
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "DriverCapabilities");
	if (scope.exist() == false)
		return false;
	s.ReadBool("CanUploadOnly", CanUploadOnly.value());
	PrintMode = Materialise::ConvertStringToPrintMode(s.ReadAttrStr("PrintMode"));
	s.ReadBool("NoUpload", NoUpload.value());
	s.ReadBool("CanGetPrintDetails", CanGetPrintDetails.value());
	return true;
}
void Materialise::Properties::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Properties");
	for(int i = 0;i < Property.size();i++)
	{
		Property[i].Write(s); 
	}
}
bool Materialise::Properties::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Properties");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Property __t;
		if (__t.Read(s) == false)
			break;
		Property.push_back(__t);
	}
	return true;
}
void Materialise::Property::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Property");
	s.WriteAttr("Name", Name.c_str());
}
bool Materialise::Property::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Property");
	if (scope.exist() == false)
		return false;
	Name = s.ReadAttrStr("Name");
	return true;
}
void Materialise::Driver::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Driver");
	s.WriteAttr("Id", Id.c_str());
	s.Write("Name", Name.c_str());
	s.Write("Provider", Provider.c_str());
	s.Write("Version", Version.c_str());
	s.Write("DriverDll", DriverDll.c_str());
	s.Write("MonitorDll", MonitorDll.value().c_str());
	s.Write("UserDriverDll", UserDriverDll.value().c_str());
	s.Write("SupportedApi", SupportedApi.c_str());
	Properties.value().get().Write(s);
	SupportedPrinters.Write(s);
}
bool Materialise::Driver::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Driver");
	if (scope.exist() == false)
		return false;
	Id = s.ReadAttrStr("Id");
	s.ReadStr("Name", Name);
	s.ReadStr("Provider", Provider);
	s.ReadStr("Version", Version);
	s.ReadStr("DriverDll", DriverDll);
	s.ReadStr("MonitorDll", MonitorDll.value());
	s.ReadStr("UserDriverDll", UserDriverDll.value());
	s.ReadStr("SupportedApi", SupportedApi);
	Materialise::Properties* __Properties = new Materialise::Properties();
	__Properties->Read(s);
	Properties = std::optional<std::reference_wrapper<Materialise::Properties>> { *__Properties };
	SupportedPrinters.Read(s);
	return true;
}
void Materialise::SupportedPrinters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "SupportedPrinters");
	for(int i = 0;i < Printer.size();i++)
	{
		Printer[i].Write(s); 
	}
}
bool Materialise::SupportedPrinters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "SupportedPrinters");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::Printer __t;
		if (__t.Read(s) == false)
			break;
		Printer.push_back(__t);
	}
	return true;
}
