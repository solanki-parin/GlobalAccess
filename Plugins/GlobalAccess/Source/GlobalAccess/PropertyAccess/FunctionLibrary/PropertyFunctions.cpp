
#include "PropertyFunctions.h"
#include "UObject/UnrealTypePrivate.h"

///Getters and setters

//Setters

bool UPropertyFunctions::SetFloatByName(UObject * Target, FName VarName, float NewValue, float & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FFloatProperty* typedProperty = CastField<FFloatProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetIntByName(UObject * Target, FName VarName, int NewValue, int & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FIntProperty* typedProperty = CastField<FIntProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetInt64ByName(UObject * Target, FName VarName, int64 NewValue, int64 & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FInt64Property* typedProperty = CastField<FInt64Property>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetBoolByName(UObject * Target, FName VarName, bool NewValue, bool & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FBoolProperty* typedProperty = CastField<FBoolProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetNameByName(UObject * Target, FName VarName, FName NewValue, FName & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FNameProperty* typedProperty = CastField<FNameProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetObjectByName(UObject * Target, FName VarName, UObject* NewValue, UObject* & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FObjectProperty* typedProperty = CastField<FObjectProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetByteByName(UObject * Target, FName VarName, uint8 NewValue, uint8 & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FByteProperty* typedProperty = CastField<FByteProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetStringByName(UObject * Target, FName VarName, FString NewValue, FString & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FStrProperty* typedProperty = CastField<FStrProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::SetTextByName(UObject * Target, FName VarName, FText NewValue, FText & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FTextProperty* typedProperty = CastField<FTextProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

//bool UPropertyFunctions::SetStructByName(UObject * Target, FName VarName, UScriptStruct* NewValue, UScriptStruct* & OutValue)
//{
//	//This will need to iterate and shit
//	/*
//	if (Target)
//	{
//		UScriptStruct* FoundValue;
//		UStructProperty* ValueProp = FindField<UStructProperty>(Target->GetClass(), VarName);
//		if (ValueProp)
//		{
//			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
//			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
//			OutValue = FoundValue;
//			return true;
//		}
//	}
//	*/
//	return false;
//}

bool UPropertyFunctions::SetEnumByName(UObject * Target, FName VarName, uint8 NewValue, uint8 & OutValue)
{
	//Some kind of magic here i guess
	/*
	if (Target)
	{
		uint8 FoundValue;
		UEnumProperty* ValueProp = FindField<UEnumProperty>(Target->GetClass(), VarName);
		if (ValueProp)
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	*/

	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FInt8Property* typedProperty = CastField<FInt8Property>(property);
		if (!typedProperty)
		{
			return false;
		}
		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);
		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}


bool UPropertyFunctions::SetClassByName(UObject* Target, FName VarName, class UClass* NewValue, class UClass*& OutValue)
{	
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FClassProperty* typedProperty = CastField<FClassProperty>(property);
		if (!typedProperty)
		{
			return false;
		}
		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);
		typedProperty->SetPropertyValue(propertyAddress, NewValue);
		auto valuetype = typedProperty->GetPropertyValue(propertyAddress);

		if (UClass* ReturnClass = Cast<UClass>(valuetype))
		{
			OutValue = ReturnClass;
			return true;
		}
		else
		{
			return false;
		}
		return true;
	}
	return false;

}


//Getters

bool UPropertyFunctions::GetFloatByName(UObject * Target, FName VarName, float & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FFloatProperty* typedProperty = CastField<FFloatProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetIntByName(UObject * Target, FName VarName, int & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FIntProperty* typedProperty = CastField<FIntProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetInt64ByName(UObject * Target, FName VarName, int64 & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FInt64Property* typedProperty = CastField<FInt64Property>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetBoolByName(UObject * Target, FName VarName, bool &OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FBoolProperty* typedProperty = CastField<FBoolProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetNameByName(UObject * Target, FName VarName, FName & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FNameProperty* typedProperty = CastField<FNameProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetObjectByName(UObject * Target, FName VarName, UObject *& OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FObjectProperty* typedProperty = CastField<FObjectProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetByteByName(UObject * Target, FName VarName, uint8 & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FByteProperty* typedProperty = CastField<FByteProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetStringByName(UObject * Target, FName VarName, FString & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FStrProperty* typedProperty = CastField<FStrProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

bool UPropertyFunctions::GetTextByName(UObject * Target, FName VarName, FText & OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FTextProperty* typedProperty = CastField<FTextProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		OutValue = typedProperty->GetPropertyValue(propertyAddress);
		return true;
	}
	return false;
}

//bool UPropertyFunctions::GetStructByName(UObject * Target, FName VarName, UScriptStruct *& OutValue)
//{
//	if (Target)
//	{
//		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
//		if (!property)
//		{
//			return false;
//		}
//		FStructProperty* typedProperty = CastField<FStructProperty>(property);
//		if (!typedProperty)
//		{
//			return false;
//		}
//
//		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);
//
//		OutValue = typedProperty->GetPropertyValue(propertyAddress);
//		return true;
//	}
//	return false;
//}
//
//bool UPropertyFunctions::GetEnumByName(UObject * Target, FName VarName, uint8 & OutValue)
//{
//	if (Target)
//	{
//		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
//		if (!property)
//		{
//			return false;
//		}
//		FEnumProperty* typedProperty = CastField<FEnumProperty>(property);
//		if (!typedProperty)
//		{
//			return false;
//		}
//
//		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);
//
//		OutValue = typedProperty->GetPropertyValue(propertyAddress);
//		return true;
//	}
//	return false;
//}
//

bool UPropertyFunctions::GetClassByName(UObject* Target, FName VarName, UClass*& OutValue)
{
	if (Target)
	{
		FProperty* property = Target->GetClass()->FindPropertyByName(VarName);
		if (!property)
		{
			return false;
		}
		FClassProperty* typedProperty = CastField<FClassProperty>(property);
		if (!typedProperty)
		{
			return false;
		}

		void* propertyAddress = property->ContainerPtrToValuePtr<void>(Target);

		auto valuetype= typedProperty->GetPropertyValue(propertyAddress);
		
		if (UClass* ReturnClass = Cast<UClass>(valuetype))
		{
			OutValue = ReturnClass;
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}