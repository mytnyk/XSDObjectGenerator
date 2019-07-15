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
	const std::string schema_generated_files_DriverDefinition_namespace = "";
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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Printer(const Printer&) = delete;
		Printer& operator=(Printer&&) = delete;
		Printer& operator=(Printer&) = delete;
		Printer(Printer&&) noexcept;
		Printer() = default;
		~Printer() = default;
		std::string ModelId;
		std::string Name;
		std::string Manufacturer;
		std::optional<std::string> IconFile;
		std::optional<std::unique_ptr<DriverCapabilities>> DriverCapabilities;
		std::optional<std::unique_ptr<Properties>> Properties;
	};
	struct SupportedPrinters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		SupportedPrinters(const SupportedPrinters&) = delete;
		SupportedPrinters& operator=(SupportedPrinters&&) = delete;
		SupportedPrinters& operator=(SupportedPrinters&) = delete;
		SupportedPrinters(SupportedPrinters&&) noexcept;
		SupportedPrinters() = default;
		~SupportedPrinters() = default;
		std::vector<Printer> Printer;
	};
	struct Driver {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Driver(const Driver&) = delete;
		Driver& operator=(Driver&&) = delete;
		Driver& operator=(Driver&) = delete;
		Driver(Driver&&) noexcept;
		Driver() = default;
		~Driver() = default;
		std::string Id;
		std::string Name;
		std::string Provider;
		std::string Version;
		std::string DriverDll;
		std::optional<std::string> MonitorDll;
		std::optional<std::string> UserDriverDll;
		std::string SupportedApi;
		std::optional<std::unique_ptr<Properties>> Properties;
		SupportedPrinters SupportedPrinters;
	};
	struct Property {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Property(const Property&) = delete;
		Property& operator=(Property&&) = delete;
		Property& operator=(Property&) = delete;
		Property(Property&&) noexcept;
		Property() = default;
		~Property() = default;
		std::string Name;
	};
	struct Properties {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Properties(const Properties&) = delete;
		Properties& operator=(Properties&&) = delete;
		Properties& operator=(Properties&) = delete;
		Properties(Properties&&) noexcept;
		Properties() = default;
		~Properties() = default;
		std::vector<Property> Property;
	};
	struct DriverCapabilities {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverCapabilities(const DriverCapabilities&) = delete;
		DriverCapabilities& operator=(DriverCapabilities&&) = delete;
		DriverCapabilities& operator=(DriverCapabilities&) = delete;
		DriverCapabilities(DriverCapabilities&&) noexcept;
		DriverCapabilities() = default;
		~DriverCapabilities() = default;
		std::optional<bool> CanUploadOnly;
		std::optional<PrintMode> PrintMode;
		std::optional<bool> NoUpload;
		std::optional<bool> CanGetPrintDetails;
	};
}
Materialise::Printer::Printer(Materialise::Printer &&___Printer) noexcept
	: ModelId(___Printer.ModelId)
	, Name(std::move(___Printer.Name))
	, Manufacturer(std::move(___Printer.Manufacturer))
	, IconFile(std::move(___Printer.IconFile))
	, DriverCapabilities(std::move(___Printer.DriverCapabilities))
	, Properties(std::move(___Printer.Properties))
{ }
void Materialise::Printer::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("ModelId", ModelId.c_str());
	s.Write("Name", Name.c_str());
	s.Write("Manufacturer", Manufacturer.c_str());
	if (IconFile.has_value())
		s.Write("IconFile", IconFile.value().c_str());
	if (DriverCapabilities.has_value())
		DriverCapabilities.value().get()->Write(s, "DriverCapabilities");
	if (Properties.has_value())
		Properties.value().get()->Write(s, "Properties");
}
bool Materialise::Printer::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("ModelId", ModelId);
	s.ReadStr("Name", Name);
	s.ReadStr("Manufacturer", Manufacturer);
	std::string __IconFile;
	if (s.ReadStr("IconFile", __IconFile))
		IconFile = std::make_optional(std::move(__IconFile));
	std::unique_ptr<Materialise::DriverCapabilities> __DriverCapabilities = std::make_unique<Materialise::DriverCapabilities>();
	if (__DriverCapabilities->Read(s, "DriverCapabilities"))
		DriverCapabilities = std::make_optional(std::move(__DriverCapabilities));
	std::unique_ptr<Materialise::Properties> __Properties = std::make_unique<Materialise::Properties>();
	if (__Properties->Read(s, "Properties"))
		Properties = std::make_optional(std::move(__Properties));
	return true;
}
Materialise::DriverCapabilities::DriverCapabilities(Materialise::DriverCapabilities &&___DriverCapabilities) noexcept
	: CanUploadOnly(___DriverCapabilities.CanUploadOnly)
	, PrintMode(std::move(___DriverCapabilities.PrintMode))
	, NoUpload(___DriverCapabilities.NoUpload)
	, CanGetPrintDetails(___DriverCapabilities.CanGetPrintDetails)
{ }
void Materialise::DriverCapabilities::Write(IXmlSerializerWriter& s, const std::string& __name__) {
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
bool Materialise::DriverCapabilities::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __tmp_var;
	bool __CanUploadOnly;
	if (s.ReadBool("CanUploadOnly", __CanUploadOnly))
		CanUploadOnly = std::make_optional(__CanUploadOnly);
	if (s.ReadAttrStr("PrintMode", __tmp_var)) 
		PrintMode = Materialise::ConvertStringToPrintMode(__tmp_var);
	bool __NoUpload;
	if (s.ReadBool("NoUpload", __NoUpload))
		NoUpload = std::make_optional(__NoUpload);
	bool __CanGetPrintDetails;
	if (s.ReadBool("CanGetPrintDetails", __CanGetPrintDetails))
		CanGetPrintDetails = std::make_optional(__CanGetPrintDetails);
	return true;
}
Materialise::Properties::Properties(Materialise::Properties &&___Properties) noexcept
	: Property(std::move(___Properties.Property))
{ }
void Materialise::Properties::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Property)
	{
		element.Write(s, "Property"); 
	}
}
bool Materialise::Properties::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Property __t;
		if (!__t.Read(s, "Property"))
			break;
		Property.push_back(std::move(__t));
	}
	return true;
}
Materialise::Property::Property(Materialise::Property &&___Property) noexcept
	: Name(___Property.Name)
{ }
void Materialise::Property::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("Name", Name.c_str());
}
bool Materialise::Property::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Name", Name);
	return true;
}
Materialise::Driver::Driver(Materialise::Driver &&___Driver) noexcept
	: Id(___Driver.Id)
	, Name(std::move(___Driver.Name))
	, Provider(std::move(___Driver.Provider))
	, Version(std::move(___Driver.Version))
	, DriverDll(std::move(___Driver.DriverDll))
	, MonitorDll(std::move(___Driver.MonitorDll))
	, UserDriverDll(std::move(___Driver.UserDriverDll))
	, SupportedApi(std::move(___Driver.SupportedApi))
	, Properties(std::move(___Driver.Properties))
	, SupportedPrinters(std::move(___Driver.SupportedPrinters))
{ }
void Materialise::Driver::Write(IXmlSerializerWriter& s, const std::string& __name__) {
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
		Properties.value().get()->Write(s, "Properties");
	SupportedPrinters.Write(s, "SupportedPrinters");
}
bool Materialise::Driver::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("Id", Id);
	s.ReadStr("Name", Name);
	s.ReadStr("Provider", Provider);
	s.ReadStr("Version", Version);
	s.ReadStr("DriverDll", DriverDll);
	std::string __MonitorDll;
	if (s.ReadStr("MonitorDll", __MonitorDll))
		MonitorDll = std::make_optional(std::move(__MonitorDll));
	std::string __UserDriverDll;
	if (s.ReadStr("UserDriverDll", __UserDriverDll))
		UserDriverDll = std::make_optional(std::move(__UserDriverDll));
	s.ReadStr("SupportedApi", SupportedApi);
	std::unique_ptr<Materialise::Properties> __Properties = std::make_unique<Materialise::Properties>();
	if (__Properties->Read(s, "Properties"))
		Properties = std::make_optional(std::move(__Properties));
	SupportedPrinters.Read(s, "SupportedPrinters");
	return true;
}
Materialise::SupportedPrinters::SupportedPrinters(Materialise::SupportedPrinters &&___SupportedPrinters) noexcept
	: Printer(std::move(___SupportedPrinters.Printer))
{ }
void Materialise::SupportedPrinters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Printer)
	{
		element.Write(s, "Printer"); 
	}
}
bool Materialise::SupportedPrinters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Printer __t;
		if (!__t.Read(s, "Printer"))
			break;
		Printer.push_back(std::move(__t));
	}
	return true;
}
