// Copyright (C) 2021 MoonStudio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SettingsProvider.h"
#include "SettingsExample.generated.h"

UCLASS(Config = SettingsExample, DefaultConfig, Meta = (DisplayName = "SettingsExample"))
class USettingsExample : public USettingsProvider
{
	GENERATED_UCLASS_BODY()
	
public:
	static USettingsExample &Get();

public:
	UPROPERTY(Transient, EditAnywhere, Category = SettingsExample, Meta = (DisplayPriority = 0))
	bool bGlobalSettings;

public:
	UPROPERTY(GlobalConfig, EditAnywhere, Category = SettingsExample)
	FString ConfigTest;

private:
	UPROPERTY(Transient)
	FString EngineConfigFile;

	UPROPERTY(Transient)
	FString ProjectConfigFile;

public:
	virtual FString GetConfigName() const override;
	virtual void PreSaveSection() override;
	virtual void PreLoadSection() override;
};
