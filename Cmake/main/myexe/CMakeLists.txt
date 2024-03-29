cmake_minimum_required(VERSION 3.12)

set(SOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Include the whole include directory for this directory
include_directories(${INCLUDE_FOLDER})

#Source files
set(SOURCES ${SOURCE_FOLDER}/main.cpp
		    ${SOURCE_FOLDER}/Particle.cpp
		    ${SOURCE_FOLDER}/Cube.cpp
		    ${SOURCE_FOLDER}/Vector3D.cpp
		    ${SOURCE_FOLDER}/DragForce.cpp
		    ${SOURCE_FOLDER}/GameWorld.cpp
		    ${SOURCE_FOLDER}/GravityForce.cpp
		    ${SOURCE_FOLDER}/ParticleAnchoredSpring.cpp
		    ${SOURCE_FOLDER}/ParticleBungeeElastic.cpp
		    ${SOURCE_FOLDER}/ParticleBuoyancy.cpp
		    ${SOURCE_FOLDER}/ParticleCable.cpp
		    ${SOURCE_FOLDER}/ParticleContact.cpp
		    ${SOURCE_FOLDER}/ParticleForceGenerator.cpp
		    ${SOURCE_FOLDER}/ParticleLink.cpp
		    ${SOURCE_FOLDER}/ParticleRod.cpp
		    ${SOURCE_FOLDER}/ParticleSpring.cpp
		    ${SOURCE_FOLDER}/ParticleStiffSpring.cpp
		    ${SOURCE_FOLDER}/RegistreForces.cpp
		    ${SOURCE_FOLDER}/ParticleContactResolver.cpp
		    ${SOURCE_FOLDER}/Quaternion.cpp
			${SOURCE_FOLDER}/Matrix3.cpp
			${SOURCE_FOLDER}/Matrix4.cpp
			${SOURCE_FOLDER}/RigidBody.cpp
			${SOURCE_FOLDER}/Cube.cpp
			${SOURCE_FOLDER}/BVH.cpp
			${SOURCE_FOLDER}/Contact.cpp
			${SOURCE_FOLDER}/Primitive.cpp
			${SOURCE_FOLDER}/Plane.cpp
			${SOURCE_FOLDER}/CollisionData.cpp
)

#Headers files (for IntelliSense)
set(HEADERS ${INCLUDE_FOLDER}/main.hpp
	        ${INCLUDE_FOLDER}/Particle.h
	        ${INCLUDE_FOLDER}/Cube.h
	        ${INCLUDE_FOLDER}/Vector3D.h
		    ${INCLUDE_FOLDER}/DragForce.h
		    ${INCLUDE_FOLDER}/GameWorld.h
		    ${INCLUDE_FOLDER}/GravityForce.h
		    ${INCLUDE_FOLDER}/ParticleAnchoredSpring.h
		    ${INCLUDE_FOLDER}/ParticleBungeeElastic.h
		    ${INCLUDE_FOLDER}/ParticleBuoyancy.h
		    ${INCLUDE_FOLDER}/ParticleCable.h
		    ${INCLUDE_FOLDER}/ParticleContact.h
		    ${INCLUDE_FOLDER}/ParticleForceGenerator.h
		    ${INCLUDE_FOLDER}/ParticleLink.h
		    ${INCLUDE_FOLDER}/ParticleRod.h
		    ${INCLUDE_FOLDER}/ParticleSpring.h
		    ${INCLUDE_FOLDER}/ParticleStiffSpring.h
		    ${INCLUDE_FOLDER}/ParticleContactResolver.h
		    ${INCLUDE_FOLDER}/RegistreForces.h
		    ${INCLUDE_FOLDER}/ParticleContactGenerator.h
		    ${INCLUDE_FOLDER}/Quaternion.h
			${INCLUDE_FOLDER}/Matrix3.h
			${INCLUDE_FOLDER}/Matrix4.h
			${INCLUDE_FOLDER}/RigidBody.h
			${INCLUDE_FOLDER}/Cube.h
			${INCLUDE_FOLDER}/BVH.h
			${INCLUDE_FOLDER}/Contact.h
			${INCLUDE_FOLDER}/Primitive.h
			${INCLUDE_FOLDER}/Plane.h
			${INCLUDE_FOLDER}/CollisionData.h
)

#Main exec
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} freeglut_static)