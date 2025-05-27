// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VersatileUObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class UOBJECTTEST_API UVersatileUObject : public UObject
{
	GENERATED_BODY()
	
public:

	virtual UWorld* GetWorld() const override
	{
        if (GetOuter())
        {
            return GetOuter()->GetWorld();
        }
        return nullptr;
	}
};
