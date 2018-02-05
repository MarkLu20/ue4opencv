// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include  "opencv2/core.hpp"
#include  "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
//#include "opencv2/utility.hpp"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "GameFramework/Actor.h"

#include "WebcamReader.generated.h"

UCLASS()
class UE4OPENCV_API AWebcamReader : public AActor
{
	GENERATED_BODY()
	
public:	
	cv::Mat frame;
	cv::VideoCapture stream;
	cv::Size size;
	void UpdateFrame();
	void DoProcessing();
	void UpdateTexture();
	// Sets default values for this actor's properties
	AWebcamReader();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		int32 CameraID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		int32 OperationMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		bool ShouldResize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		FVector2D ResizeDeminsions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		float RefreshRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wbcame")
		float RefreshTimer;
	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void OnNextVideoFrame();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Change Operations", Keywords = "Change Operation"), Category ="wbcame")
		void ChangeOperation();
		


	UPROPERTY(BlueprintReadOnly, Category = "wbcame")
		bool isStreamOpen;
	UPROPERTY(BlueprintReadWrite, Category = "wbcame")
		FVector2D VideoSize;
	UPROPERTY(BlueprintReadOnly, Category = "wbcame")
		UTexture2D *VideoTexture;
	UPROPERTY(BlueprintReadOnly, Category = "wbcame")
		TArray<FColor>  Data;

protected:

	// Use this function to update the texture rects you want to change:
	// NOTE: There is a method called UpdateTextureRegions in UTexture2D but it is compiled WITH_EDITOR and is not marked as ENGINE_API so it cannot be linked
	// from plugins.
	// FROM: https://wiki.unrealengine.com/Dynamic_Textures
	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);

	FUpdateTextureRegion2D* VideoUpdateTextureRegion;
	
	
};
