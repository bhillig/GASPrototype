// Copyright Brandon Hillig


#include "Actor/GEffectActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/GAttributeSet.h"

AGEffectActor::AGEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	// Attach components
	RootComponent = Mesh;
	Sphere->SetupAttachment(Mesh);
}

void AGEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind events
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AGEffectActor::OnBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AGEffectActor::OnEndOverlap);
}

void AGEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change implementation to use gameplay effects! (This is just a hack!)
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		UAbilitySystemComponent* ASC = ASCInterface->GetAbilitySystemComponent();
		if (!ASC) return;

		const UGAttributeSet* AttributeSet = Cast<UGAttributeSet>(ASC->GetAttributeSet(UGAttributeSet::StaticClass()));

		UGAttributeSet* MutableAttributeSet = const_cast<UGAttributeSet*>(AttributeSet);
		MutableAttributeSet->SetHealth(MutableAttributeSet->GetHealth() + 50.0f);
		Destroy();
	}
}

void AGEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
