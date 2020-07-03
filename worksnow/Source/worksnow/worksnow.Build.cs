// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class worksnow : ModuleRules
{
	public worksnow(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
