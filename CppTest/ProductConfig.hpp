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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string Prerelease;
		std::string Branch;
		std::string VcsNumber;
		BuildInfo() {}
		~BuildInfo() {}
	};
	struct PackageId {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> path;
		PackageId() {}
		~PackageId() {}
	};
	struct BundlePackages {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::vector<Materialise::PackageId> PackageId;
		BundlePackages() {}
		~BundlePackages() {}
	};
	struct LicenseFiles {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> Prerelease;
		std::optional<std::string> Release;
		LicenseFiles() {}
		~LicenseFiles() {}
	};
	struct ExcludeFiles {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::string> except;
		ExcludeFiles() {}
		~ExcludeFiles() {}
	};
	struct Filters {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::optional<std::reference_wrapper<Materialise::ExcludeFiles>> ExcludeFiles;
		std::optional<std::string> ExcludeFolders;
		std::optional<std::string> IncludeFolders;
		Filters() {}
		~Filters() {}
	};
	struct Installer {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
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
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		std::string FileNameForBuildDirectory;
		std::string FileNameWithPlaceHolders;
		std::string AbsolutePathPlaceHolder;
		DriverDefinitionMetaData() {}
		~DriverDefinitionMetaData() {}
	};
	struct Version {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
		char Major;
		char Minor;
		unsigned short int Build;
		unsigned short int Revision;
		Version() {}
		~Version() {}
	};
	struct Product {
		void Write(IXmlSerializerWriter& s, std::string __name__);
		bool Read(IXmlSerializerReader& s, std::string __name__);
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
void Materialise::Product::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Title", Title.c_str());
	s.Write("ShortName", ShortName.c_str());
	s.Write("Company", Company.c_str());
	s.Write("Copyright", Copyright.c_str());
	Version.Write(s, "Version");
	s.Write("DriverId", DriverId.c_str());
	DriverDefinitionMetaData.Write(s, "DriverDefinitionMetaData");
	Installer.Write(s, "Installer");
	BuildInfo.Write(s, "BuildInfo");
}
bool Materialise::Product::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Title", Title);
	s.ReadStr("ShortName", ShortName);
	s.ReadStr("Company", Company);
	s.ReadStr("Copyright", Copyright);
	Version.Read(s, "Version");
	s.ReadStr("DriverId", DriverId);
	DriverDefinitionMetaData.Read(s, "DriverDefinitionMetaData");
	Installer.Read(s, "Installer");
	BuildInfo.Read(s, "BuildInfo");
	return true;
}
void Materialise::Version::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Major", Major);
	s.Write("Minor", Minor);
	s.Write("Build", Build);
	s.Write("Revision", Revision);
}
bool Materialise::Version::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadChar("Major", Major);
	s.ReadChar("Minor", Minor);
	s.ReadUnsignedShortInt("Build", Build);
	s.ReadUnsignedShortInt("Revision", Revision);
	return true;
}
void Materialise::DriverDefinitionMetaData::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("FileNameForBuildDirectory", FileNameForBuildDirectory.c_str());
	s.Write("FileNameWithPlaceHolders", FileNameWithPlaceHolders.c_str());
	s.Write("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder.c_str());
}
bool Materialise::DriverDefinitionMetaData::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("FileNameForBuildDirectory", FileNameForBuildDirectory);
	s.ReadStr("FileNameWithPlaceHolders", FileNameWithPlaceHolders);
	s.ReadStr("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder);
	return true;
}
void Materialise::Installer::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Binaries", Binaries.c_str());
	s.Write("UpgradeId", UpgradeId.c_str());
	s.Write("BundleUpgradeId", BundleUpgradeId.c_str());
	s.Write("Name", Name.c_str());
	if (Filters.has_value())
		Filters.value().get().Write(s, "Filters");
	if (LicenseFiles.has_value())
		LicenseFiles.value().get().Write(s, "LicenseFiles");
	BundlePackages.Write(s, "BundlePackages");
}
bool Materialise::Installer::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Binaries", Binaries);
	s.ReadStr("UpgradeId", UpgradeId);
	s.ReadStr("BundleUpgradeId", BundleUpgradeId);
	s.ReadStr("Name", Name);
	Materialise::Filters* __Filters = new Materialise::Filters();
	__Filters->Read(s, "Filters");
	Filters = std::optional<std::reference_wrapper<Materialise::Filters>> { *__Filters };
	Materialise::LicenseFiles* __LicenseFiles = new Materialise::LicenseFiles();
	__LicenseFiles->Read(s, "LicenseFiles");
	LicenseFiles = std::optional<std::reference_wrapper<Materialise::LicenseFiles>> { *__LicenseFiles };
	BundlePackages.Read(s, "BundlePackages");
	return true;
}
void Materialise::Filters::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (ExcludeFiles.has_value())
		ExcludeFiles.value().get().Write(s, "ExcludeFiles");
	if (ExcludeFolders.has_value())
		s.Write("ExcludeFolders", ExcludeFolders.value().c_str());
	if (IncludeFolders.has_value())
		s.Write("IncludeFolders", IncludeFolders.value().c_str());
}
bool Materialise::Filters::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	Materialise::ExcludeFiles* __ExcludeFiles = new Materialise::ExcludeFiles();
	__ExcludeFiles->Read(s, "ExcludeFiles");
	ExcludeFiles = std::optional<std::reference_wrapper<Materialise::ExcludeFiles>> { *__ExcludeFiles };
	s.ReadStr("ExcludeFolders", ExcludeFolders.value());
	s.ReadStr("IncludeFolders", IncludeFolders.value());
	return true;
}
void Materialise::ExcludeFiles::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (except.has_value())
		s.WriteAttr("except", except.value().c_str());
}
bool Materialise::ExcludeFiles::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("except", except.value());
	return true;
}
void Materialise::LicenseFiles::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Prerelease.has_value())
		s.Write("Prerelease", Prerelease.value().c_str());
	if (Release.has_value())
		s.Write("Release", Release.value().c_str());
}
bool Materialise::LicenseFiles::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Prerelease", Prerelease.value());
	s.ReadStr("Release", Release.value());
	return true;
}
void Materialise::BundlePackages::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(int i = 0;i < PackageId.size();i++)
	{
		PackageId[i].Write(s, "PackageId"); 
	}
}
bool Materialise::BundlePackages::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	while (true) { 
		Materialise::PackageId __t;
		if (__t.Read(s, "PackageId") == false)
			break;
		PackageId.push_back(__t);
	}
	return true;
}
void Materialise::PackageId::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (path.has_value())
		s.WriteAttr("path", path.value().c_str());
}
bool Materialise::PackageId::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadAttrStr("path", path.value());
	return true;
}
void Materialise::BuildInfo::Write(IXmlSerializerWriter& s, std::string __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Prerelease", Prerelease.c_str());
	s.Write("Branch", Branch.c_str());
	s.Write("VcsNumber", VcsNumber.c_str());
}
bool Materialise::BuildInfo::Read(IXmlSerializerReader& s, std::string __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (scope.exist() == false)
		return false;
	s.ReadStr("Prerelease", Prerelease);
	s.ReadStr("Branch", Branch);
	s.ReadStr("VcsNumber", VcsNumber);
	return true;
}
