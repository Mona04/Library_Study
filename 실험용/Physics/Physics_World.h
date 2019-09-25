#pragma once

class Physics_World
{
private:
	Physics_World();
	~Physics_World();

public:
	static Physics_World* Get() { static Physics_World instance; return &instance; }

	void Update();

	btVector3 GetGravity();
	class btDiscreteDynamicsWorld* GetWorld() { return world; }


private:
	class btCollisionDispatcher* dispatcher;
	class btBroadphaseInterface* broadphase;
	class btConstraintSolver* constraintSolver;
	class btDefaultCollisionConfiguration* collisionConfiguration;
	class btDiscreteDynamicsWorld* world;
};