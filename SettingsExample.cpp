// Copyright (C) 2021 MoonStudio, Inc. All Rights Reserved.


#include "SettingsExample.h"

#define SettingsExampleCFG "SettingsExample.ini"

USettingsExample::USettingsExample(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	CategoryName = "SaoHo";
	SectionName = "SettingsExample";
	bRestartable = true;

	bGlobalSettings = true;
	
	ConfigTest = TEXT("SettingsExample");

	EngineConfigFile = FPaths::EngineConfigDir() + SettingsExampleCFG;
	ProjectConfigFile = FPaths::ProjectConfigDir() + SettingsExampleCFG;
}

USettingsExample &USettingsExample::Get()
{
	return *GetMutableDefault<USettingsExample>();
}

FString USettingsExample::GetConfigName() const
{
	//return Super::GetConfigName();
	return bGlobalSettings ? EngineConfigFile : ProjectConfigFile;
}

// ==========================================================================
//                                                        Events
// ==========================================================================

void USettingsExample::PreSaveSection()
{
	SetSection("ThemeStyle", "GlobalSettings", bGlobalSettings ? "True" : "False", EngineConfigFile);
}

void USettingsExample::PreLoadSection()
{
	bGlobalSettings = GetSection("ThemeStyle", "GlobalSettings", EngineConfigFile) == "True";
}
