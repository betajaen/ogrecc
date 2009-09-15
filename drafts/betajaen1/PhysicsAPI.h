#ifndef OGRECC_PHYSICSAPI_H
#define OGRECC_PHYSICSAPI_H

#include "CharacterControllerEnums.h"

class PhysicsRigidBody;
class PhysicsCapsule;
class SweepVolume;

struct RayResult
{
 Vector3 position;
 Vector3 normal;
 float   distance;
};

class PhysicsAPI
{
 
 public:
  
  
  virtual ~PhysicsAPI() {}
  
  virtual PhysicsRigidBody* createRigidBody(float mass, PhysicsCapsule*, Vector3 position, Quaternion orientation) = 0;
  
  virtual void              destroyRigidBody(PhysicsRigidBody*) = 0;
  
  virtual PhysicsCapsule*   createCapsule(float width, float height) = 0;
  
  //
  virtual PhysicsCapsule*   destroyCapsule() = 0;
  
  // Raycast for the nearest rigidbody/shape.
  virtual RayResult         rayCastNearest(const Vector3&, const Vector3& direction) = 0;

  // Sweep test for auto-stepping and possible side/above collisions. 
  virtual CollisionFlags    sweep(const Vector3& direction, bool experiment, bool& nonWalkable) = 0
  
  // Sweep test for auto-stepping and possible side/above collisions.
  virtual bool              sweepTest(PhysicsCapsule*, const Vector3&, const Vector3& direction, unsigned int &nbCollisions, bool walkExperiment, bool normaliseResponse = true) = 0;
  
  // Sweep test for auto-stepping and possible side/above collisions.
  virtual                   sweepCollisionResponse(Vector3& target, const Vector3& current, const Vector3& direction, const Vector3& normal, bool normalise = false) = 0;

};

class PhysicsRigidBody
{
 public:
  
  virtual void setPosition(const Vector3&) = 0;
  
  virtual Vector3 getPosition() = 0;
  
  virtual void setMomentum(const Vector3&) = 0;
  
  virtual Vector3 getMomentum() = 0;
  
  virtual void setOrientation(const Quaternion&) = 0;
  
  virtual Quaternion getOrientation() = 0;
  
  virtual void setMass(float) = 0;
  
  virtual float getMass() = 0;
  
  virtual void setCapsule(PhysicsCapsule*) = 0;
  
  virtual void freeCapsule(PhysicsCapsule*) = 0;
};

class PhysicsCapsule
{
 public:
  
  virtual float getRadius() = 0;
  
  virtual void setRadius(float) = 0;
  
  virtual float getHeight() = 0;
  
  virtual void setHeight() = 0;

  SweepVolume* getVolume() { return mVolume; }

 protected:

  SweepVolume* mVolume;
};

struct SweepVolume
{
 Vector3 position;
 Vector3 extents;
};

#endif