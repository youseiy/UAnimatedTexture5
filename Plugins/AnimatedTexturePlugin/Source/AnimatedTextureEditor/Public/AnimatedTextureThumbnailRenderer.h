// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "AnimatedTextureThumbnailRenderer.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATEDTEXTUREEDITOR_API UAnimatedTextureThumbnailRenderer : public UThumbnailRenderer
{
	GENERATED_BODY()
	
public:
	// Begin UThumbnailRenderer Object
	virtual void GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const override;
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	// End UThumbnailRenderer Object
};
