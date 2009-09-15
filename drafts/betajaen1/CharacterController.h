#ifndef OGRECC_CHARACTERCONTROLLER_H
#define OGRECC_CHARACTERCONTROLLER_H

#include "CharacterEnums.h"
#include "CharacterControllerDescription.h"
#include "PhysicsAPI.h"

class CharacterController
{
 
 public:
  
  
  CharacterController(const Vector3& position, const Radian& direction, const CharacterControllerDescription&, PhysicsAPI*);
  
 ~CharacterController();
  
  // "Impolite" set functions
  // ------------------------

  // Set the position for warping/ai/networking,etc.
  void setPosition(const Vector3& position);
  
  // Set the facing direction.
  void setDirection(const Radian& direction);
  
  // Set the up direction
  void setUp(const Vector3& up);
  
  // Set the momentum
  void setMomentum(const Vector3& momentum);
  
  // For the character to be in a state.
  void setState(CharacterState);
  
  // Set the size now.
  void setSize(const Vector3& size);
  
  // Set the mass now.
  void setMass(float);

  // Set the auto-stepping offset.
  void setOffset(float);

  // Polite set functions
  // --------------------------
  
  // Set the walking speed.
  void setWalkingSpeed(float speed);
  
  // Walking speed.
  float getWalkingSpeed();
  
  // Set the sidestepping speed.
  void setSidesteppingSpeed(float speed);
  
  // Sidestepping speed.
  float getSideSteppingSpeed(float speed);
  
  // Set Initial jump speed.
  void setJumpSpeed(float speed);
  
  // Initial jumping speed.
  float getJumpSpeed();
  
  // Query Functions
  // ---------------
  
  // Actual position.
  Vector3 getPosition() const;
  
  // Yaw/Facing direction.
  Radian  getDirection() const;
  
  // Up direction.
  Vector3 getUp() const { return mUp; }
  
  // Momentum
  Vector3 getMomentum() const { return mMomentum; }
  
  // Size(Height/Radius)
  Vector2 getSize() const { return mCapsule->getSize(); }
  
  // Mass.
  float   getMass() const { return mRigidBody->getMass(); }
  
  // Auto-stepping offset.
  float   getOffset() const { return mOffset; }

  // What state is in the character now?
  inline int CharacterState() const { return mState; }
  
  // What was the last frames collision.
  inline int getCollisionStatus() const { return mCollisionStatus; }

  // Is the CC on ground (i.e. level geometry)
  inline bool isOnStatic() const { return getColllisionStatus() & CS_ON_GROUND };
  
  // Is the CC on a RigidBody. (i.e. a wooden box)
  inline bool isOnRigidBody() const { return getCollisionStatus() & CS_ON_RIGIDBODY; }
  
  // Is the CC on ground or RigidBody.
  inline bool isOnGround() const { return (isOnStatic() || isOnRigidBody());}
  
  // Is the CC touching anything on the side.
  inline bool hasCollisionSides() const { return mCollisionStatus & CS_SIDES; }
  
  // Is the CC touching anything above.
  inline bool hasCollisionAbove() const { return mCollisionStatus & CS_ABOVE; }
  
  // Is the CC not touching anything at all.
  inline bool isInAir() const { return mCollisionStatus & CS_AIR; }
  
  // How long the CC has been in the air for.
  float getAirTime() const { return mAirTime; }
  
  // How far the CC has been whilst in the Air.
  Vector3 getAirDistance() const;
  
  // Should the CC jump?
  inline bool canJump() const { return isOnGround(); }
  
  // Movement functions
  // ------------------------
  
  // Walk or Sidestep in direction. If X only then is walking, if X&&Z or Z then sidestepping.
  void walk(const Vector2& direction);
  
  // Jump.
  void jump();
  
  // Face the character in a direction
  void face(const Radian& direction);
  
};


#endif