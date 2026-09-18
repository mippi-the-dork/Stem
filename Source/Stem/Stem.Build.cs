// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Stem : ModuleRules
{
    public Stem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "DeveloperSettings" });
        PrivateDependencyModuleNames.AddRange(new[] { "Slate", "SlateCore", "SceneOutliner" });
    }
}
