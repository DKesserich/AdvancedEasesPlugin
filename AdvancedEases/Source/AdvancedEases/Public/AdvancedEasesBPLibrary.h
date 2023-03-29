/* Copyright (c) 2023 David Lejeune
Licensed under Creative Commons Attribution Sharealike 4.0*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdvancedEasesBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)
enum class EAdvancedEases : uint8
{
	AE_INBACK		UMETA(DisplayName = "Ease In Back"),
	AE_OUTBACK		UMETA(DisplayName = "Ease Out Back"),
	AE_INOUTBACK	UMETA(DisplayName = "Ease InOut Back"),
	AE_INELASTIC	UMETA(DisplayName = "Ease In Elastic"),
	AE_OUTELASTIC	UMETA(DisplayName = "Ease Out Elastic"),
	AE_INOUTELASTIC	UMETA(DisplayName = "Ease InOut Elastic"),
	AE_INBOUNCE		UMETA(DisplayName = "Ease In Bounce"),
	AE_OUTBOUNCE	UMETA(DisplayName = "Ease Out Bounce"),
	AE_INOUTBOUNCE	UMETA(DisplayName = "Ease In Out Bounce"),
	AE_LERP			UMETA(DisplayName = "Linear")
};


UCLASS()
class UAdvancedEasesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Advanced Ease (Float)"), Category = "Interpolation")
		static float AdvancedEase_Float(EAdvancedEases EaseType, float Delta, float Start = 0.0f, float End = 1.0f);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Advanced Ease (Vector)"), Category = "Interpolation")
		static FVector AdvancedEase_Vector(EAdvancedEases EaseType, FVector Start, FVector End, float Delta);

private:

	static float EaseInBack(float Delta);

	static float EaseOutBack(float Delta);

	static float EaseInOutBack(float Delta);

	static float EaseInBounce(float Delta);

	static float EaseOutBounce(float Delta);

	static float EaseInOutBounce(float Delta);

	static float EaseInElastic(float Delta);

	static float EaseOutElastic(float Delta);

	static float EaseInOutElastic(float Delta);

};
