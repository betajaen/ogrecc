#ifndef OGRECC_CHARACTERCONTROLLER_DESCRIPTION_H
#define OGRECC_CHARACTERCONTROLLER_DESCRIPTION_H

class CharacterControllerDescription
{
 
 public:
  
  
  CharacterControllerDescription()
  {
   mRigidBodyMass = 120;
   mVerticalOffset = 0.1;
   mCapsuleRadius = 0.2
   mCapsuleHeight = 2 - (mCapsuleRadius * 0.2) - mVerticalOffset;
   mUpDirection = Vector3(0,1,0);
   mWalkingSpeed  = 4;
   mSidesteppingSpeed = 2.5;
   mJumpSpeed = 12;
  }
  
  float mRigidBodyMass;
  
  float mCapsuleHeight;
  
  float mCapsuleRadius;
  
  float mAutoStepOffset;
  
  Vector3 mUpDirection;
  
  float mWalkingSpeed;
  
  float mSidesteppingSpeed;
  
  float mJumpSpeed;
};


#endif