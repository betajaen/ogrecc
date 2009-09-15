#ifndef OGRECC_CHARACTERCONTROLLER_ENUMS_H
#define OGRECC_CHARACTERCONTROLLER_ENUMS_H

enum CharacterState
{
 CS_INVALID      = 0, // Constructor/Destructor
 CS_STILL        = 1, // Standing still
 CS_WALKING      = 2, // Walking
 CS_SIDESTEPPING = 3, // Sidestepping
 CS_FALLING      = 4, // Falling.
 CS_JUMPING      = 5, // Jumping
 CS_JUMPING_APEX = 6, // Near or at the apex of a jump.
};

enum CollisionStatus
{
 CS_AIR = 0
 CS_ON_GROUND = 1,  
 CS_ON_RIGIDBODY = 2,
 CS_SIDES = 3,
 CS_ABOVE = 4,
};

#endif