#pragma once
#include "IInteractable.generated.h"

UINTERFACE(Blueprintable)
class BADASS_API UInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class  BADASS_API IInteractable
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Item")
	void OnInteraction();
};