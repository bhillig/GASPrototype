// Copyright Brandon Hillig

using UnrealBuildTool;
using System.Collections.Generic;

public class GASPrototypeEditorTarget : TargetRules
{
	public GASPrototypeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GASPrototype" } );
	}
}
