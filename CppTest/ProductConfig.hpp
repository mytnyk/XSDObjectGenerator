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
	const std::string schema_CppTest_ProductConfig_namespace = "";
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
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		BuildInfo(const BuildInfo&) = delete;
		BuildInfo& operator=(BuildInfo&&) = delete;
		BuildInfo& operator=(BuildInfo&) = delete;
		BuildInfo(BuildInfo&&) noexcept;
		BuildInfo() = default;
		~BuildInfo() = default;
		std::string Prerelease;
		std::string Branch;
		std::string VcsNumber;
	};
	struct PackageId {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PackageId(const PackageId&) = delete;
		PackageId& operator=(PackageId&&) = delete;
		PackageId& operator=(PackageId&) = delete;
		PackageId(PackageId&&) noexcept;
		PackageId() = default;
		~PackageId() = default;
		std::optional<std::string> path;
	};
	struct BundlePackages {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		BundlePackages(const BundlePackages&) = delete;
		BundlePackages& operator=(BundlePackages&&) = delete;
		BundlePackages& operator=(BundlePackages&) = delete;
		BundlePackages(BundlePackages&&) noexcept;
		BundlePackages() = default;
		~BundlePackages() = default;
		std::vector<PackageId> PackageId;
	};
	struct LicenseFiles {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		LicenseFiles(const LicenseFiles&) = delete;
		LicenseFiles& operator=(LicenseFiles&&) = delete;
		LicenseFiles& operator=(LicenseFiles&) = delete;
		LicenseFiles(LicenseFiles&&) noexcept;
		LicenseFiles() = default;
		~LicenseFiles() = default;
		std::optional<std::string> Prerelease;
		std::optional<std::string> Release;
	};
	struct ExcludeFiles {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		ExcludeFiles(const ExcludeFiles&) = delete;
		ExcludeFiles& operator=(ExcludeFiles&&) = delete;
		ExcludeFiles& operator=(ExcludeFiles&) = delete;
		ExcludeFiles(ExcludeFiles&&) noexcept;
		ExcludeFiles() = default;
		~ExcludeFiles() = default;
		std::optional<std::string> except;
	};
	struct Filters {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Filters(const Filters&) = delete;
		Filters& operator=(Filters&&) = delete;
		Filters& operator=(Filters&) = delete;
		Filters(Filters&&) noexcept;
		Filters() = default;
		~Filters() = default;
		std::optional<std::unique_ptr<ExcludeFiles>> ExcludeFiles;
		std::optional<std::string> ExcludeFolders;
		std::optional<std::string> IncludeFolders;
	};
	struct Installer {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Installer(const Installer&) = delete;
		Installer& operator=(Installer&&) = delete;
		Installer& operator=(Installer&) = delete;
		Installer(Installer&&) noexcept;
		Installer() = default;
		~Installer() = default;
		std::string Binaries;
		std::string UpgradeId;
		std::string BundleUpgradeId;
		std::string Name;
		std::optional<std::unique_ptr<Filters>> Filters;
		std::optional<std::unique_ptr<LicenseFiles>> LicenseFiles;
		BundlePackages BundlePackages;
	};
	struct DriverDefinitionMetaData {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		DriverDefinitionMetaData(const DriverDefinitionMetaData&) = delete;
		DriverDefinitionMetaData& operator=(DriverDefinitionMetaData&&) = delete;
		DriverDefinitionMetaData& operator=(DriverDefinitionMetaData&) = delete;
		DriverDefinitionMetaData(DriverDefinitionMetaData&&) noexcept;
		DriverDefinitionMetaData() = default;
		~DriverDefinitionMetaData() = default;
		std::string FileNameForBuildDirectory;
		std::string FileNameWithPlaceHolders;
		std::string AbsolutePathPlaceHolder;
	};
	struct Version {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Version(const Version&) = delete;
		Version& operator=(Version&&) = delete;
		Version& operator=(Version&) = delete;
		Version(Version&&) noexcept;
		Version() = default;
		~Version() = default;
		char Major;
		char Minor;
		unsigned short int Build;
		unsigned short int Revision;
	};
	struct Product {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Product(const Product&) = delete;
		Product& operator=(Product&&) = delete;
		Product& operator=(Product&) = delete;
		Product(Product&&) noexcept;
		Product() = default;
		~Product() = default;
		std::string Title;
		std::string ShortName;
		std::string Company;
		std::string Copyright;
		Version Version;
		std::string DriverId;
		DriverDefinitionMetaData DriverDefinitionMetaData;
		Installer Installer;
		BuildInfo BuildInfo;
	};
}
Materialise::Product::Product(Materialise::Product &&___Product) noexcept
	: Title(std::move(___Product.Title))
	, ShortName(std::move(___Product.ShortName))
	, Company(std::move(___Product.Company))
	, Copyright(std::move(___Product.Copyright))
	, Version(std::move(___Product.Version))
	, DriverId(std::move(___Product.DriverId))
	, DriverDefinitionMetaData(std::move(___Product.DriverDefinitionMetaData))
	, Installer(std::move(___Product.Installer))
	, BuildInfo(std::move(___Product.BuildInfo))
{ }
void Materialise::Product::Write(IXmlSerializerWriter& s, const std::string& __name__) {
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
bool Materialise::Product::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
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
Materialise::Version::Version(Materialise::Version &&___Version) noexcept
	: Major(std::move(___Version.Major))
	, Minor(std::move(___Version.Minor))
	, Build(std::move(___Version.Build))
	, Revision(std::move(___Version.Revision))
{ }
void Materialise::Version::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Major", Major);
	s.Write("Minor", Minor);
	s.Write("Build", Build);
	s.Write("Revision", Revision);
}
bool Materialise::Version::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadChar("Major", Major);
	s.ReadChar("Minor", Minor);
	s.ReadUnsignedShortInt("Build", Build);
	s.ReadUnsignedShortInt("Revision", Revision);
	return true;
}
Materialise::DriverDefinitionMetaData::DriverDefinitionMetaData(Materialise::DriverDefinitionMetaData &&___DriverDefinitionMetaData) noexcept
	: FileNameForBuildDirectory(std::move(___DriverDefinitionMetaData.FileNameForBuildDirectory))
	, FileNameWithPlaceHolders(std::move(___DriverDefinitionMetaData.FileNameWithPlaceHolders))
	, AbsolutePathPlaceHolder(std::move(___DriverDefinitionMetaData.AbsolutePathPlaceHolder))
{ }
void Materialise::DriverDefinitionMetaData::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("FileNameForBuildDirectory", FileNameForBuildDirectory.c_str());
	s.Write("FileNameWithPlaceHolders", FileNameWithPlaceHolders.c_str());
	s.Write("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder.c_str());
}
bool Materialise::DriverDefinitionMetaData::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("FileNameForBuildDirectory", FileNameForBuildDirectory);
	s.ReadStr("FileNameWithPlaceHolders", FileNameWithPlaceHolders);
	s.ReadStr("AbsolutePathPlaceHolder", AbsolutePathPlaceHolder);
	return true;
}
Materialise::Installer::Installer(Materialise::Installer &&___Installer) noexcept
	: Binaries(std::move(___Installer.Binaries))
	, UpgradeId(std::move(___Installer.UpgradeId))
	, BundleUpgradeId(std::move(___Installer.BundleUpgradeId))
	, Name(std::move(___Installer.Name))
	, Filters(std::move(___Installer.Filters))
	, LicenseFiles(std::move(___Installer.LicenseFiles))
	, BundlePackages(std::move(___Installer.BundlePackages))
{ }
void Materialise::Installer::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Binaries", Binaries.c_str());
	s.Write("UpgradeId", UpgradeId.c_str());
	s.Write("BundleUpgradeId", BundleUpgradeId.c_str());
	s.Write("Name", Name.c_str());
	if (Filters.has_value())
		Filters.value().get()->Write(s, "Filters");
	if (LicenseFiles.has_value())
		LicenseFiles.value().get()->Write(s, "LicenseFiles");
	BundlePackages.Write(s, "BundlePackages");
}
bool Materialise::Installer::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Binaries", Binaries);
	s.ReadStr("UpgradeId", UpgradeId);
	s.ReadStr("BundleUpgradeId", BundleUpgradeId);
	s.ReadStr("Name", Name);
	Materialise::Filters* __Filters = new Materialise::Filters();
	if (__Filters->Read(s, "Filters"))
		Filters = std::optional<std::unique_ptr<Materialise::Filters>> { __Filters };
	Materialise::LicenseFiles* __LicenseFiles = new Materialise::LicenseFiles();
	if (__LicenseFiles->Read(s, "LicenseFiles"))
		LicenseFiles = std::optional<std::unique_ptr<Materialise::LicenseFiles>> { __LicenseFiles };
	BundlePackages.Read(s, "BundlePackages");
	return true;
}
Materialise::Filters::Filters(Materialise::Filters &&___Filters) noexcept
	: ExcludeFiles(std::move(___Filters.ExcludeFiles))
	, ExcludeFolders(std::move(___Filters.ExcludeFolders))
	, IncludeFolders(std::move(___Filters.IncludeFolders))
{ }
void Materialise::Filters::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (ExcludeFiles.has_value())
		ExcludeFiles.value().get()->Write(s, "ExcludeFiles");
	if (ExcludeFolders.has_value())
		s.Write("ExcludeFolders", ExcludeFolders.value().c_str());
	if (IncludeFolders.has_value())
		s.Write("IncludeFolders", IncludeFolders.value().c_str());
}
bool Materialise::Filters::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	Materialise::ExcludeFiles* __ExcludeFiles = new Materialise::ExcludeFiles();
	if (__ExcludeFiles->Read(s, "ExcludeFiles"))
		ExcludeFiles = std::optional<std::unique_ptr<Materialise::ExcludeFiles>> { __ExcludeFiles };
	s.ReadStr("ExcludeFolders", ExcludeFolders.value());
	s.ReadStr("IncludeFolders", IncludeFolders.value());
	return true;
}
Materialise::ExcludeFiles::ExcludeFiles(Materialise::ExcludeFiles &&___ExcludeFiles) noexcept
	: except(std::move(___ExcludeFiles.except))
{ }
void Materialise::ExcludeFiles::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (except.has_value())
		s.WriteAttr("except", except.value().c_str());
}
bool Materialise::ExcludeFiles::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __except;
	if (s.ReadAttrStr("except", __except))
		except = std::optional<std::string> { __except };
	return true;
}
Materialise::LicenseFiles::LicenseFiles(Materialise::LicenseFiles &&___LicenseFiles) noexcept
	: Prerelease(std::move(___LicenseFiles.Prerelease))
	, Release(std::move(___LicenseFiles.Release))
{ }
void Materialise::LicenseFiles::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Prerelease.has_value())
		s.Write("Prerelease", Prerelease.value().c_str());
	if (Release.has_value())
		s.Write("Release", Release.value().c_str());
}
bool Materialise::LicenseFiles::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Prerelease", Prerelease.value());
	s.ReadStr("Release", Release.value());
	return true;
}
Materialise::BundlePackages::BundlePackages(Materialise::BundlePackages &&___BundlePackages) noexcept
	: PackageId(std::move(___BundlePackages.PackageId))
{ }
void Materialise::BundlePackages::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : PackageId)
	{
		element.Write(s, "PackageId"); 
	}
}
bool Materialise::BundlePackages::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::PackageId __t;
		if (!__t.Read(s, "PackageId"))
			break;
		PackageId.push_back(std::move(__t));
	}
	return true;
}
Materialise::PackageId::PackageId(Materialise::PackageId &&___PackageId) noexcept
	: path(std::move(___PackageId.path))
{ }
void Materialise::PackageId::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (path.has_value())
		s.WriteAttr("path", path.value().c_str());
}
bool Materialise::PackageId::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	std::string __path;
	if (s.ReadAttrStr("path", __path))
		path = std::optional<std::string> { __path };
	return true;
}
Materialise::BuildInfo::BuildInfo(Materialise::BuildInfo &&___BuildInfo) noexcept
	: Prerelease(std::move(___BuildInfo.Prerelease))
	, Branch(std::move(___BuildInfo.Branch))
	, VcsNumber(std::move(___BuildInfo.VcsNumber))
{ }
void Materialise::BuildInfo::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.Write("Prerelease", Prerelease.c_str());
	s.Write("Branch", Branch.c_str());
	s.Write("VcsNumber", VcsNumber.c_str());
}
bool Materialise::BuildInfo::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadStr("Prerelease", Prerelease);
	s.ReadStr("Branch", Branch);
	s.ReadStr("VcsNumber", VcsNumber);
	return true;
}
