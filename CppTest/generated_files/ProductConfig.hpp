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
	struct Product;
	struct Version;
	struct DriverDefinitionMetaData;
	struct Installer;
	struct Filters;
	struct ExcludeFiles;
	struct LicenseFiles;
	struct BundlePackages;
	struct PackageId;
	struct BuildInfo;
	struct BuildInfo {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Prerelease;
		std::string Branch;
		std::string VcsNumber;
		BuildInfo() {}
		~BuildInfo() {}
	};
	struct PackageId {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> path {""};
		PackageId() {}
		~PackageId() {}
	};
	struct BundlePackages {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::vector<Materialise::PackageId> PackageId;
		BundlePackages() {}
		~BundlePackages() {}
	};
	struct LicenseFiles {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> Prerelease {""};
		std::optional<std::string> Release {""};
		LicenseFiles() {}
		~LicenseFiles() {}
	};
	struct ExcludeFiles {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::string> except {""};
		ExcludeFiles() {}
		~ExcludeFiles() {}
	};
	struct Filters {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<std::reference_wrapper<Materialise::ExcludeFiles>> ExcludeFiles;
		std::optional<std::string> ExcludeFolders {""};
		std::optional<std::string> IncludeFolders {""};
		Filters() {}
		~Filters() {}
	};
	struct Installer {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Binaries;
		std::string UpgradeId;
		std::string BundleUpgradeId;
		std::string Name;
		std::optional<std::reference_wrapper<Materialise::Filters>> Filters;
		std::optional<std::reference_wrapper<Materialise::LicenseFiles>> LicenseFiles;
		Materialise::BundlePackages BundlePackages;
		Installer() {}
		~Installer() {}
	};
	struct DriverDefinitionMetaData {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string FileNameForBuildDirectory;
		std::string FileNameWithPlaceHolders;
		std::string AbsolutePathPlaceHolder;
		DriverDefinitionMetaData() {}
		~DriverDefinitionMetaData() {}
	};
	struct Version {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		char Major;
		char Minor;
		unsigned short int Build;
		unsigned short int Revision;
		Version() {}
		~Version() {}
	};
	struct Product {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::string Title;
		std::string ShortName;
		std::string Company;
		std::string Copyright;
		Materialise::Version Version;
		std::string DriverId;
		Materialise::DriverDefinitionMetaData DriverDefinitionMetaData;
		Materialise::Installer Installer;
		Materialise::BuildInfo BuildInfo;
		Product() {}
		~Product() {}
	};
}
void Materialise::Product::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Product");
	s.Write("Title", Title.c_str());
	s.Write("ShortName", ShortName.c_str());
	s.Write("Company", Company.c_str());
	s.Write("Copyright", Copyright.c_str());
	Version.Write(s);
	s.Write("DriverId", DriverId.c_str());
	DriverDefinitionMetaData.Write(s);
	Installer.Write(s);
	BuildInfo.Write(s);
}
bool Materialise::Product::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Product");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Title", Title);
	s.ReadStr("ShortName", ShortName);
	s.ReadStr("Company", Company);
	s.ReadStr("Copyright", Copyright);
	Version.Read(s);
	s.ReadStr("DriverId", DriverId);
	DriverDefinitionMetaData.Read(s);
	Installer.Read(s);
	BuildInfo.Read(s);
	return true;
}
void Materialise::Version::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Version");
	s.Write("Major", Major);
	s.Write("Minor", Minor);
	s.Write("Build", Build);
	s.Write("Revision", Revision);
}
bool Materialise::Version::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Version");
	if (scope.exist() == false)
		return false;
	s.ReadChar("Major", Major);
	s.ReadChar("Minor", Minor);
	s.ReadUnsignedShortInt("Build", Build);
	s.ReadUnsignedShortInt("Revision", Revision);
	return true;
}
void Materialise::DriverDefinitionMetaData::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "DriverDefinitionMetaData");
	s.Write("FileNameForBuildDirectory", FileNameForBuildDirectory.c_str());
	s.Write("FileNameWithPlaceHolders", FileNameWithPlaceHolders.c_str());
	s.Write("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder.c_str());
}
bool Materialise::DriverDefinitionMetaData::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "DriverDefinitionMetaData");
	if (scope.exist() == false)
		return false;
	s.ReadStr("FileNameForBuildDirectory", FileNameForBuildDirectory);
	s.ReadStr("FileNameWithPlaceHolders", FileNameWithPlaceHolders);
	s.ReadStr("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder);
	return true;
}
void Materialise::Installer::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Installer");
	s.Write("Binaries", Binaries.c_str());
	s.Write("UpgradeId", UpgradeId.c_str());
	s.Write("BundleUpgradeId", BundleUpgradeId.c_str());
	s.Write("Name", Name.c_str());
	Filters.value().get().Write(s);
	LicenseFiles.value().get().Write(s);
	BundlePackages.Write(s);
}
bool Materialise::Installer::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Installer");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Binaries", Binaries);
	s.ReadStr("UpgradeId", UpgradeId);
	s.ReadStr("BundleUpgradeId", BundleUpgradeId);
	s.ReadStr("Name", Name);
	Materialise::Filters* __Filters = new Materialise::Filters();
	__Filters->Read(s);
	Filters = std::optional<std::reference_wrapper<Materialise::Filters>> { *__Filters };
	Materialise::LicenseFiles* __LicenseFiles = new Materialise::LicenseFiles();
	__LicenseFiles->Read(s);
	LicenseFiles = std::optional<std::reference_wrapper<Materialise::LicenseFiles>> { *__LicenseFiles };
	BundlePackages.Read(s);
	return true;
}
void Materialise::Filters::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "Filters");
	ExcludeFiles.value().get().Write(s);
	s.Write("ExcludeFolders", ExcludeFolders.value().c_str());
	s.Write("IncludeFolders", IncludeFolders.value().c_str());
}
bool Materialise::Filters::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "Filters");
	if (scope.exist() == false)
		return false;
	Materialise::ExcludeFiles* __ExcludeFiles = new Materialise::ExcludeFiles();
	__ExcludeFiles->Read(s);
	ExcludeFiles = std::optional<std::reference_wrapper<Materialise::ExcludeFiles>> { *__ExcludeFiles };
	s.ReadStr("ExcludeFolders", ExcludeFolders.value());
	s.ReadStr("IncludeFolders", IncludeFolders.value());
	return true;
}
void Materialise::ExcludeFiles::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "ExcludeFiles");
	s.WriteAttr("except", except.value().c_str());
}
bool Materialise::ExcludeFiles::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "ExcludeFiles");
	if (scope.exist() == false)
		return false;
	except = s.ReadAttrStr("except");
	return true;
}
void Materialise::LicenseFiles::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "LicenseFiles");
	s.Write("Prerelease", Prerelease.value().c_str());
	s.Write("Release", Release.value().c_str());
}
bool Materialise::LicenseFiles::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "LicenseFiles");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Prerelease", Prerelease.value());
	s.ReadStr("Release", Release.value());
	return true;
}
void Materialise::BundlePackages::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "BundlePackages");
	for(int i = 0;i < PackageId.size();i++)
	{
		PackageId[i].Write(s); 
	}
}
bool Materialise::BundlePackages::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "BundlePackages");
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::PackageId __t;
		if (__t.Read(s) == false)
			break;
		PackageId.push_back(__t);
	}
	return true;
}
void Materialise::PackageId::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PackageId");
	s.WriteAttr("path", path.value().c_str());
}
bool Materialise::PackageId::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PackageId");
	if (scope.exist() == false)
		return false;
	path = s.ReadAttrStr("path");
	return true;
}
void Materialise::BuildInfo::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "BuildInfo");
	s.Write("Prerelease", Prerelease.c_str());
	s.Write("Branch", Branch.c_str());
	s.Write("VcsNumber", VcsNumber.c_str());
}
bool Materialise::BuildInfo::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "BuildInfo");
	if (scope.exist() == false)
		return false;
	s.ReadStr("Prerelease", Prerelease);
	s.ReadStr("Branch", Branch);
	s.ReadStr("VcsNumber", VcsNumber);
	return true;
}
