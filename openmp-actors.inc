#if defined _inc_omp_actors
    #endinput
#endif
#define _inc_omp_actors
#define _actor_included

_OPENMP_TAG(Actor);

const TAG__<Actor>:MAX_ACTORS = 1000;

const TAG__<Actor>:INVALID_ACTOR_ID = 0xFFFF;

#define SAMP_CONST_CORRECT

#pragma tabsize 4

/// <summary>Create a static 'actor' in the world. These 'actors' are like NPCs, however they have limited functionality. They do not take up server player slots.</summary>
/// <param name="modelid">The model ID (skin ID) the actor should have</param>
/// <param name="X">The X coordinate to create the actor at</param>
/// <param name="Y">The Y coordinate to create the actor at</param>
/// <param name="Z">The Z coordinate to create the actor at</param>
/// <param name="Rotation">The facing angle (rotation) for the actor to have</param>
/// <seealso name="DestroyActor"/>
/// <seealso name="SetActorPos"/>
/// <seealso name="GetActorPos"/>
/// <seealso name="SetActorFacingAngle"/>
/// <seealso name="GetActorFacingAngle"/>
/// <seealso name="SetActorVirtualWorld"/>
/// <seealso name="GetActorVirtualWorld"/>
/// <seealso name="ApplyActorAnimation"/>
/// <seealso name="ClearActorAnimations"/>
/// <seealso name="GetPlayerCameraTargetActor"/>
/// <seealso name="IsActorStreamedIn"/>
/// <seealso name="SetActorHealth"/>
/// <seealso name="GetActorHealth"/>
/// <seealso name="SetActorInvulnerable"/>
/// <seealso name="IsActorInvulnerable"/>
/// <seealso name="IsValidActor"/>
/// <seealso name="GetActorPoolSize"/>
/// <seealso name="GetPlayerTargetActor"/>
/// <seealso name="OnActorStreamIn"/>
/// <seealso name="OnActorStreamOut"/>
/// <seealso name="OnPlayerGiveDamageActor"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   Actors are completely separate from NPCs. They do NOT use player IDs/slots on the server and CANNOT be handled like NPCs.<p/>
///   Actors are limited to <b><c>1000</c></b> (<b><c>MAX_ACTORS</c></b>).<p/>
///   Actors can be pushed by vehicles, use a timer to put them back at their positions.<p/>
///   As of <b>0.3.7 R2</b> actors default to being <a href="http://wiki.sa-mp.com/wiki/SetActorInvulnerable">invulnerable</a>.
/// </remarks>
/// <returns>
///   The created Actor ID (start at <b><c>0</c></b>).<p/>
///   <b><c>INVALID_ACTOR_ID</c></b> (<b><c>65535</c></b>) If the actor limit (<b><c>1000</c></b>) is reached.
/// </returns>
NEW_NATIVE__ Actor:Actor@Create(modelid, Float:posX, Float:posY, Float:posZ, Float:angle) = Actor__Create
	return Actor:CreateActor__(modelid, posX, posY, posZ, angle);

#pragma deprecated Use `Actor@Create` instead.
OLD_NATIVE__ CreateActor(modelid, Float:posX, Float:posY, Float:posZ, Float:angle)
	return _:Actor@Create(modelid, posX, posY, posZ, angle);

/// <summary>Destroy an actor which was created with <a href="#CreateActor">CreateActor</a>.</summary>
/// <param name="actorid">The ID of the actor to destroy. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <seealso name="CreateActor"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor with the ID specified does not exist.
/// </returns>
NEW_NATIVE__ bool:Actor@Destroy(Actor:actorid) = Actor__Destroy
	return !!DestroyActor__(_:actorid);

#pragma deprecated Use `Actor@Destroy` instead.
OLD_NATIVE__ DestroyActor(actorid)
	return Actor@Destroy(Actor:actorid);

/// <summary>Checks if an actor is streamed in for a player.</summary>
/// <param name="actorid">The ID of the actor</param>
/// <param name="forplayerid">The ID of the player</param>
/// <seealso name="CreateActor"/>
/// <seealso name="IsPlayerStreamedIn"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is streamed in for the player, or <b><c>0</c></b> if it is not.</returns>
#pragma deprecated Use `Actor_IsStreamedInForPlayer` instead.
NATIVE__ IsActorStreamedIn(actorid, forplayerid) \
    = bool:Actor_IsStreamedInForPlayer(Actor:actorid, Player:playerid);

/// <summary>Apply an animation to an actor.</summary>
/// <param name="actorid">The ID of the actor to apply the animation to</param>
/// <param name="animlib">The animation library from which to apply an animation</param>
/// <param name="animname">The name of the animation to apply, within the specified library</param>
/// <param name="fDelta">The speed to play the animation (use <b><c>4.1</c></b>)</param>
/// <param name="loop">If set to <b><c>1</c></b>, the animation will loop. If set to <b><c>0</c></b>, the animation will play once</param>
/// <param name="lockx">If set to <b><c>0</c></b>, the actor is returned to their old X coordinate once the animation is complete (for animations that move the actor such as walking). <b><c>1</c></b> will not return them to their old position</param>
/// <param name="locky">Same as above but for the Y axis. Should be kept the same as the previous parameter</param>
/// <param name="freeze">Setting this to <b><c>1</c></b> will freeze an actor at the end of the animation. <b><c>0</c></b> will not</param>
/// <param name="time">Timer in milliseconds. For a never-ending loop it should be <b><c>0</c></b></param>
/// <seealso name="ClearActorAnimations"/>
/// <remarks>You must preload the animation library for the player the actor will be applying the animation for, and not for the actor. Otherwise, the animation won't be applied to the actor until the function is executed again.</remarks>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
/// <b><c>1</c></b>: The function executed successfully.<p/>
/// <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
#pragma deprecated Use `Actor_ApplyAnimation` instead.
NATIVE__ ApplyActorAnimation(actorid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time) \
    = Actor_ApplyAnimation(Actor:actorid, const animLib[], const animName[], Float:speed, bool:loop, bool:moveX, bool:moveY, bool:freeze, duration);

/// <summary>Clear any animations applied to an actor.</summary>
/// <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to clear the animations for</param>
/// <seealso name="ApplyActorAnimation"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
#pragma deprecated Use `Actor_ClearAnimations` instead.
NATIVE__ ClearActorAnimations(actorid) \
    = Actor_ClearAnimations(Actor:actorid);

/// <summary>Set the position of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the position of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="X">The X coordinate to position the actor at</param>
/// <param name="Y">The Y coordinate to position the actor at</param>
/// <param name="Z">The Z coordinate to position the actor at</param>
/// <seealso name="GetActorPos"/>
/// <seealso name="CreateActor"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's position. You do not need to use this function unless you want to change its position later.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
#pragma deprecated Use `Actor_SetPosition` instead.
NATIVE__ SetActorPos(actorid, Float:X, Float:Y, Float:Z) \
    = Actor_SetPosition(Actor:actorid, Float:posX, Float:posY, Float:posZ);

/// <summary>Get the position of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the position of. Returned by <a href="# CreateActor">CreateActor</a></param>
/// <param name="X">A float variable, passed by reference, in which to store the X coordinate of the actor</param>
/// <param name="Y">A float variable, passed by reference, in which to store the Y coordinate of the actor</param>
/// <param name="Z">A float variable, passed by reference, in which to store the Z coordinate of the actor</param>
/// <seealso name="SetActorPos"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.<p/>
/// </returns>
#pragma deprecated Use `Actor_GetPosition` instead.
NATIVE__ GetActorPos(actorid, &Float:X, &Float:Y, &Float:Z) \
    = Actor_GetPosition(Actor:actorid, &Float:posX, &Float:posY, &Float:posZ);

/// <summary>Set the facing angle of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the facing angle of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="ang">The facing angle to set for the actor</param>
/// <seealso name="GetActorFacingAngle"/>
/// <seealso name="SetActorPos"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Players will see actor's facing angle changed only when it is restreamed to them.</remarks>
/// <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's facing angle. You do not need to use this function unless you want to change its facing angle later.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native bool:Actor_SetRotation_E(Actor:actorid, Float:x, Float:y, Float:z);
forward bool:Actor_SetRotation_Q(Actor:actorid, Float:w, Float:x, Float:y, Float:z);
stock bool:Actor_SetRotation_Z(Actor:actorid, Float:z)
	return Actor_SetRotation_E(actorid, 0.0, 0.0, z);

#define Actor_SetRotation(%0) Actor_SetRotation_Z(%0)
#define Actor_SetRotation_Z(%0,%1,%2) Actor_SetRotation_E(%0,%1,%2)
#define Actor_SetRotation_E(%0,%1,%2,%3,%4) Actor_SetRotation_Q(%0,%1,%2,%3,%4)
#define _ALS_Actor_SetRotation

#pragma deprecated Use `Actor_SetRotation` instead.
OLD_NATIVE__ SetActorFacingAngle(actorid, Float:angle)
    return Actor_SetRotation_E(Actor:actorid, 0.0, 0.0, angle);

/// <summary>Get the facing angle of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the facing angle of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="ang">A float variable, passed by reference, in to which the actor's facing angle will be stored</param>
/// <seealso name="SetActorFacingAngle"/>
/// <seealso name="GetActorPos"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
NEW_NATIVE__ bool:Actor_GetRotation_E(Actor:actorid, &Float:x, &Float:y, &Float:z);
forward bool:Actor_GetRotation_Q(Actor:actorid, &Float:w, &Float:x, &Float:y, &Float:z);
stock Float:Actor_GetRotation_Z(Actor:actorid)
	return Actor_GetRotation_E(actorid, __FLOAT, __FLOAT, __FLOAT) ? (__FLOAT): (FLOAT_NAN);

#define Actor_GetRotation(%0) Actor_GetRotation_Z(%0)
#define Actor_GetRotation_Z(%0,%1) Actor_GetRotation_E(%0,%1)
#define Actor_GetRotation_E(%0,%1,%2,%3,%4) Actor_GetRotation_Q(%0,%1,%2,%3,%4)
#define _ALS_Actor_GetRotation

#pragma deprecated Use `Actor_GetRotation` instead.
FLOAT_NATIVE__ GetActorFacingAngle(actorid, &Float:angle)
	Actor_GetRotation_E(Actor:actorid, angle, angle, angle);

/// <summary>Set the health of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the health of</param>
/// <param name="health">The value to set the actors's health to</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b> on success.<p/>
///   <b><c>0</c></b> on failure (i.e. actor is not created).
/// </returns>
#pragma deprecated Use `Actor_SetHealth` instead.
NATIVE__ SetActorHealth(actorid, Float:health) \
    = Actor_SetHealth(Actor:actorid, Float:health);

/// <summary>Get the health of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the health of</param>
/// <param name="health">A float variable, passed by reference, in to which to store the actor's health</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b> - success.<p/>
///   <b><c>0</c></b> - failure (i.e. actor is not created).<p/>
/// </returns>
#pragma deprecated Use `Actor_GetHealth` instead.
FLOAT_NATIVE__ GetActorHealth(actorid, &Float:health) \
	= Float:Actor_GetHealth(Actor:actorid);

/// <summary>Toggle an actor's invulnerability.</summary>
/// <param name="actorid">The ID of the actor to set invulnerability</param>
/// <param name="invulnerable"><b><c>false</c></b> to make them vulnerable, <b><c>true</c></b> to make them invulnerable (optional=<b><c>true</c></b>)</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Once set invulnerable, the actor does not call <a href="#OnPlayerGiveDamageActor">OnPlayerGiveDamageActor</a>.</remarks>
/// <remarks>Players will have actor's invulnerability state changed only when it is restreamed to them.</remarks>
/// <returns>
///   <b><c>1</c></b> - Success.<p/>
///   <b><c>0</c></b> - Failure (i.e. Actor is not created).
/// </returns>
#pragma deprecated Use `Actor_ToggleInvulnerable` instead.
NATIVE__ SetActorInvulnerable(actorid, invulnerable = true) \
    = Actor_ToggleInvulnerable(Actor:actorid, bool:invulnerable);

/// <summary>Check if an actor is invulnerable.</summary>
/// <param name="actorid">The ID of the actor to check</param>
/// <seealso name="CreateActor"/>
/// <seealso name="SetActorInvulnerable"/>
/// <seealso name="SetActorHealth"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is invulnerable, <b><c>0</c></b> otherwise.</returns>
#pragma deprecated Use `Actor_SetInvulnerable` instead.
NATIVE__ IsActorInvulnerable(actorid) \
    = bool:Actor_IsInvulnerable(Actor:actorid);

/// <summary>Checks if an actor ID is valid.</summary>
/// <param name="actorid">The ID of the actor to check</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>

NEW_NATIVE__ bool:Actor@IsValid(Actor:actorid) = Actor__IsValid
	return !!IsValidActor__(actorid);

#pragma deprecated Use `Actor@IsValid` instead.
OLD_NATIVE__ IsValidActor(actorid) 
	return Actor@IsValid(Actor:actorid);

NEW_NATIVE__ bool:Actor_Display_A(Actor:actorid, bool:set = true);
NEW_NATIVE__ bool:Actor_Display_1(Actor:actorid, Player:playerid, bool:set);
#define Actor_Display(%0) Actor_Display_A(%0)
#define Actor_Display_A(%0,%1,%2) Actor_Display_1(%0,%1,%2)
#define _ALS_Actor_Display

NEW_NATIVE__ bool:Actor_Inhabit_A(Actor:actorid, bool:set = true);
NEW_NATIVE__ bool:Actor_Inhabit_1(Actor:actorid, vw, bool:set);
#define Actor_Inhabit(%0) Actor_Inhabit_A(%0)
#define Actor_Inhabit_A(%0,%1,%2) Actor_Inhabit_1(%0,%1,%2)
#define _ALS_Actor_Inhabit

NEW_NATIVE__ bool:Actor_Has(Actor:actorid, Player:playerid);
NEW_NATIVE__ bool:Actor_In(Actor:actorid, vw)
	return GetActorVirtualWorld__(_:actorid) == vw;

/// <summary>Set the virtual world of an actor. Only players in the same world will see the actor.</summary>
/// <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to set the virtual world of</param>
/// <param name="vworld">The virtual world to put the actor ID</param>
/// <seealso name="GetActorVirtualWorld"/>
/// <seealso name="CreateActor"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
#pragma deprecated Use `Actor_Inhabit` instead.
OLD_NATIVE__ SetActorVirtualWorld(actorid, vworld)
	return Actor_Inhabit_A(Actor:actorid, false) && Actor_Inhabit_1(Actor:actorid, vworld, true);

/// <summary>Get the virtual world of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the virtual world of</param>
/// <seealso name="SetActorVirtualWorld"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The virtual world of the actor. By default this is <b><c>0</c></b>. Also returns <b><c>0</c></b> if actor specified does not exist.</returns>
#pragma deprecated Use `Actor_In` instead.
OLD_NATIVE__ GetActorVirtualWorld(actorid);
