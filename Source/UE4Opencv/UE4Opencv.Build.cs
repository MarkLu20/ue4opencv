// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;
public class UE4Opencv : ModuleRules
{
    private string ModulePath
    {

        get { return ModuleDirectory; }


    }
    private string ThridPartyPath
    {

        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty")); }

    }
    public UE4Opencv(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","RHI","RenderCore","ShaderCore" });
        //LoadOpenCV(Target);
        string OpenCVPath = Path.Combine(ThridPartyPath, "OpenCV");
        
       // bool isdebug = Target.Configuration == UnrealTargetConfiguration.Debug && BuildConfiguration.bDebugBuildsActuallyUseDebugCRT;
        if (Target.Platform==UnrealTargetPlatform.Win64)
        {
            string LibPath= Path.Combine(OpenCVPath, "Libraries", "Win64");
            PublicIncludePaths.AddRange(new string[] { Path.Combine(OpenCVPath, "Includes") });
            PublicIncludePaths.Add(LibPath);
            PublicAdditionalLibraries.Add(Path.Combine(LibPath, "opencv_world320.lib"));
            PublicDelayLoadDLLs.Add("opencv_world320.dll");
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(LibPath, "opencv_world320.dll")));
            PublicDelayLoadDLLs.Add("opencv_ffmpeg320_64.dll");
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(LibPath, "opencv_ffmpeg320_64.dll")));
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString()); System.Console.WriteLine(Err);
        }
      
      
        //Definitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isLibrarySupported ? 1 : 0));

        //return isLibrarySupported;

        PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
