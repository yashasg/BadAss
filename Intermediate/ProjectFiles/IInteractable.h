#pragma once
#include "IInteractable.generated.h"

/** Class needed to support InterfaceCast<IToStringInterface>(Object) */
UINTERFACE(MinimalAPI)
class UInternactable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IToStringInterface
{
	GENERATED_IINTERFACE_BODY()

		virtual void OnInteraction();
};