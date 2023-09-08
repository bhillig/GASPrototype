// Copyright Brandon Hillig

using UnrealBuildTool;
using System.Collections.Generic;

public class GASPrototypeTarget : TargetRules
{
	public GASPrototypeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GASPrototype" } );
	}
}
