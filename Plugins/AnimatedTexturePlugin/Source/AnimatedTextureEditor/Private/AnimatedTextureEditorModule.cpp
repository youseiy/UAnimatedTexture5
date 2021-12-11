// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimatedTextureEditorModule.h"
#include "AnimatedTextureThumbnailRenderer.h"
#include "AnimatedTexture2D.h"
#include "Misc/CoreDelegates.h"	// Core
#include "ThumbnailRendering/ThumbnailManager.h"	// UnrealEd

#define LOCTEXT_NAMESPACE "FAnimatedTextureEditorModule"

void FAnimatedTextureEditorModule::StartupModule()
{
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FAnimatedTextureEditorModule::OnPostEngineInit);
}

void FAnimatedTextureEditorModule::OnPostEngineInit()
{
	UThumbnailManager::Get().RegisterCustomRenderer(UAnimatedTexture2D::StaticClass(), UAnimatedTextureThumbnailRenderer::StaticClass());
}

void FAnimatedTextureEditorModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UThumbnailManager::Get().UnregisterCustomRenderer(UAnimatedTexture2D::StaticClass());
	}
}

#undef LOCTEXT_NAMESPACE

DEFINE_LOG_CATEGORY(LogAnimTextureEditor);
IMPLEMENT_MODULE(FAnimatedTextureEditorModule, AnimatedTextureEditor)