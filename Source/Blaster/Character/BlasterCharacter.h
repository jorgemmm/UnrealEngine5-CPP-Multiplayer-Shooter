// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
//class UwidgetComponent;
class AWeapon;
class UCombatComponent;

UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()
		   
public:
	// Sets default values for this character's properties
	ABlasterCharacter();	
	virtual void Tick(float DeltaTime) override;	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void CrouchButtonPressed();
	void EquipButtonPressed();	
	void AimButtonPressed();
	void AimButtonReleased();
	void RollButtonPressed();
	void RollButtonReleased();
	void AimOffset(float DeltaTime);
	void RunButtonPressed();
	void RunButtonReleased();

	
	/** The player's maximum health. This is the highest that their health can be, and the value that their health starts at when spawned.*/
	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth;

	/** The player's current health. When reduced to 0, they are considered dead.*/
	//(ReplicatedUsing = OnRep_CurrentHealth)
	UPROPERTY()
	  float CurrentHealth;
	
	

private:

	UPROPERTY(VisibleAnywhere, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		UCameraComponent* FollowCamera;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UWidgetComponent* OverheadWidget;

	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	//UPROPERTY(Replicated)
		AWeapon* OverlappingWeapon;

	UPROPERTY(VisibleAnywhere)
		UCombatComponent* Combat;

	

	//petición local
	 void SetRolling(bool bIsRolling);

	//Solicitud a servidor
	UFUNCTION(Server, Reliable)
		void Server_RequestSetRolling(bool bIsRolling);

	//petición local
	void SetRunning(bool bIsRunning);

	//Solicitud a servidor
	UFUNCTION(Server, Reliable)
		void Server_RequestSetRunning(bool bIsRunning);

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float WalkSpeed=600.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float  AimSpeed = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float RunSpeed = 900.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float DefaulWalkSpeed = 600.f;

	
	


	UFUNCTION(Server, Reliable)
		void ServerEquipButtonPressed();

	UFUNCTION()
		void OnRep_OverlappingWeapon(AWeapon* LastWeapon);
	//void OnRep_OverlappingWeapon();

	//Aim Offset handle
	
		float AO_Pitch;	
		float AO_Yaw;
		FRotator StartingAimRotation;

public:	
	
	/**if true the blaster orient to movement, 
	if false the character fix the position to Forward	 lik alert mode*/
	//Whe fire from hip enable and disable this method
	void SetInAlert(bool inAlert);
	
	//void SetInAlert(bool inAlert);

	void SetOverlappingWeapon(AWeapon* Weapon);
	
	bool IsWeaponEquipped() const;
	bool IsAiming() const ;
	
	UFUNCTION(BlueprintPure)
	bool IsRolling() const;

	UFUNCTION(BlueprintPure)
	bool IsRunning() const;

	AWeapon* GetEquippedWeapon();

	/** Set by character movement to specify that this Character is currently rolling. */
	UPROPERTY(BlueprintReadOnly, replicated, Category = Character)
	 bool bRolling=false;	

	UPROPERTY(BlueprintReadOnly, replicated, Category = Character)
		bool bRunning;

	FORCEINLINE float GetAO_Yaw() const { return AO_Yaw; }
	FORCEINLINE float GetAO_Pitch() const { return AO_Pitch; }
	
	
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
