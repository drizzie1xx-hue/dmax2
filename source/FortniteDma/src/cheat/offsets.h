#pragma once
#include <cstdint>

namespace offsets {
	uintptr_t temp1 = 0x0;
	uintptr_t temp2 = 0x0;

	uintptr_t Uworld = 0x169D6108; // NOT in dump - GWorld RVA, must be updated per build
	// GWorld is encrypted: decrypted = UworldDecryptMul * enc - UworldDecryptSub (mod 2^64)
	uintptr_t UworldDecryptMul = 0xA323219E066D436DuLL;
	uintptr_t UworldDecryptSub = 0x6FA832BFC5B44018uLL;
	uintptr_t CameraLocationPointer = 0x128; // NOT in dump - verify for current build
	uintptr_t CameraRotationPointer = 0x138; // NOT in dump - verify for current build
	uintptr_t GameInstance = 0x248;
	uintptr_t GameState = 0x1D0;
	uintptr_t PersistentLevel = 0x40;
	uintptr_t LocalPlayers = 0x38;
	uintptr_t FieldOfView = 0x4AC; // NOT in dump - point::LocalPlayer + 0x4AC, verify
	uintptr_t PlayerController = 0x30;
	uintptr_t LocalPawn = 0x318; // acknowledged_pawn
	uintptr_t Cameramanager = 0x348; // NOT in dump - verify for current build
	uintptr_t PlayerState = 0x290;
	uintptr_t PawnPrivate = 0x2E8; // pawn_private
	uintptr_t PlayerArray = 0x288; // player_array
	uintptr_t Mesh = 0x2F0; // skeletal_mesh
	uintptr_t ComponentToWorld = 0x1E0;
	uintptr_t Seconds = 0x148; // NOT in dump - UWorld + 0x148, verify
	uintptr_t LastRenderTime = 0x330; // last_render_time
	uintptr_t BoneArray = 0x650; // bone_array (bone_array_cached = 0x660)
	uintptr_t Velocity = 0x188; // component_velocity
	uintptr_t IsDBNO = 0x849; // is_dbno
	uintptr_t isDying = 0x720; // is_dying
	uintptr_t bIsABot = 0x27A; // is_bot
	uintptr_t TeamId = 0xF11; // team_index
	uintptr_t RootComponent = 0x1B0;
	uintptr_t LocationUnderReticle = 0x2748; // NOT in dump - verify for current build
	uintptr_t WeaponData = 0x5E8;
	uintptr_t CurrentWeapon = 0x998;
	uintptr_t WeaponProjectileSpeed = 0x1F64; // ProjectileSpeed
	uintptr_t WeaponProjectileGravity = 0x1F64 + 0x4; // ProjectileGravityScale = ProjectileSpeed + 0x4

	uintptr_t FNamePool = 0x12BA9140; // NOT in dump - GNames RVA, must be updated per build
	uintptr_t FNameKey = 0x18; // NOT in dump
	uintptr_t ItemDefinition = 0x368; // NOT in dump
	uintptr_t OwningWorld = 0xC8; // NOT in dump - ULevel::OwningWorld, verify
	uintptr_t ULevelArray = 0x190; // NOT in dump - UWorld::Levels, verify
	uintptr_t ULevelCount = ULevelArray + 8;
	uintptr_t AActorArray = 0x1F8; // AActors
	uintptr_t AActorCount = AActorArray + 8;
	uintptr_t Kills = 0x1274; // NOT in dump
	uintptr_t TextPtr = 0x38; // NOT in dump
	uintptr_t NameOffset = 0xAF0; // NOT in dump

	// Additional offsets provided in the dump (not currently referenced in code)
	uintptr_t GEngine = 0x1A46DE88;
	uintptr_t GameViewport = 0xB70;
	uintptr_t World = 0x78; // GameViewport->World
	uintptr_t RelativeLocation = 0x140;
	uintptr_t BoneArrayCached = 0x660; // bone_array_cached
	uintptr_t WeaponOffsetCorrection = 0x2230; // weapon_offset_correction
	uintptr_t MemoryAim = 0x2230; // memory_aim
	uintptr_t CameraRotation = 0x190; // camera_rotation
	uintptr_t CachedViewInfoRenderedLastFrame = 0x190;
	uintptr_t ServerTime = 0x2A8;
	uintptr_t DefaultFlyTime = 0x554;
	uintptr_t ReviveFromDBNOTime = 0x4920;
	uintptr_t TargetedFortPawn = 0x1630;
	uintptr_t MaxLevel = 0x2AC; // max_level
	uintptr_t WeakspotFlags = 0x2A0; // weakspot_flags
}
