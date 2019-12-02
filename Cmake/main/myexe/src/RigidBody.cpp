#include "RigidBody.h"
#include <math.h>

//Methode pour calculer les donnees derivees du corps rigide
RigidBody::RigidBody(float InverseMass, float LinearDamping, float AngularDamping,
                     Vector3D Position, Quaternion Orientation)
{
    m_InverseMass = InverseMass;
    m_LinearDamping = LinearDamping;
    m_AngularDamping = AngularDamping;
    m_Position = Position; // position du centre de masse du rigidbody
    m_Orientation = Orientation;

    float tab[12] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    m_TransformMatrix = Matrix4(tab);
    m_Velocity = Vector3D(0, 0, 0);
	m_Acceleration = Vector3D(0, 0, 0);
	m_Rotation = Vector3D(0, 0, 0);
	m_AngularAcceleration =Vector3D(0, 0, 0);
	m_AngularVelocity = Vector3D(0, 0, 0);

	forceAccum = Vector3D(0, 0, 0);
	torqueAccum = Vector3D(0, 0, 0);
	
}
RigidBody::RigidBody(const RigidBody& p_RigidBody) {
	m_InverseMass = p_RigidBody.m_InverseMass;
    m_LinearDamping = p_RigidBody.m_LinearDamping;
	m_AngularDamping =p_RigidBody.m_AngularDamping;
    m_Position = p_RigidBody.m_Position; // position du centre de masse du rigidbody
    m_Velocity = p_RigidBody.m_Velocity;
	m_Acceleration = p_RigidBody.m_Acceleration;
    m_AngularAcceleration = p_RigidBody.m_AngularAcceleration;
	m_AngularVelocity = p_RigidBody.m_AngularVelocity;
    m_Orientation = p_RigidBody.m_Orientation;
    m_Rotation = p_RigidBody.m_Rotation;
    m_TransformMatrix = p_RigidBody.m_TransformMatrix;
    m_InverseInertieTensor = p_RigidBody.m_InverseInertieTensor;
	

	forceAccum = p_RigidBody.forceAccum;
	torqueAccum = p_RigidBody.torqueAccum;
}


//Methode pour ajouter un force a un point 
//Param : p_Force : le vecteur correspondant a la force a appliquer
//Param : p_Point : le point sur le quel on doit ajouter la force
void RigidBody::AddForceAtPoint(Vector3D p_Force, Vector3D p_Point)
{
    // convertir p_Point en coord relatives au centre de masse
	Vector3D pointRelatif =
		m_Position - m_TransformMatrix.transformationVecteurPos(p_Point);
	
    pointRelatif.normalisation();

    // update forceAccum
    this->forceAccum += p_Force;
    // update torqueAccum
	
    this->torqueAccum += p_Force.prodVectorielle(pointRelatif);
	
}

//Methode pour ajouter une force a un point du corps rigide
//Param : p_Force : le vecteur correspondant a la force a appliquer
//Param : p_Point : le point sur le quel on doit ajouter la force
void RigidBody::AddForceAtBodyPoint(Vector3D p_Force, Vector3D p_Point)
{
	
    // Ne convertit plus le pint dans le monde et n'appel plus AddForceAtPoint car c'est une perte de performance

    this->forceAccum += p_Force;
    // update torqueAccum
	
    this->torqueAccum += p_Force.prodVectorielle(p_Point);
}

// Fonction pour nettoyer la resultante courante
void RigidBody::clearAccum()
{
    this->forceAccum = Vector3D(0, 0, 0);
    this->torqueAccum = Vector3D(0, 0, 0);
}

//Surcharge de l'operateur de comparaison pour la classe particule
//param : &particule : l'adresse de la particule a comparer
bool RigidBody::operator==(RigidBody& p_RigidBody)
{
	return this->m_InverseMass == p_RigidBody.m_InverseMass
    && this->m_LinearDamping == p_RigidBody.m_LinearDamping
	&& this->m_AngularDamping ==p_RigidBody.m_AngularDamping
    && this->m_Position == p_RigidBody.m_Position
    && this->m_Velocity == p_RigidBody.m_Velocity
	&& this->m_Acceleration == p_RigidBody.m_Acceleration
    && this->m_AngularAcceleration == p_RigidBody.m_AngularAcceleration
	&& this->m_AngularVelocity == p_RigidBody.m_AngularVelocity
    && this->m_Orientation == p_RigidBody.m_Orientation
    && this->m_Rotation == p_RigidBody.m_Rotation
    && this->m_TransformMatrix == p_RigidBody.m_TransformMatrix
    && this->m_InverseInertieTensor == p_RigidBody.m_InverseInertieTensor
	&& this->forceAccum == p_RigidBody.forceAccum
	&& this->torqueAccum == p_RigidBody.torqueAccum;
}

void RigidBody::integrate(float frameTime)
{
	
    // add drag linear velocity
    /*float coeffDrag1 = 1;
    float coeffDrag2 = 1;
    Vector3D velocitypart = this->m_Velocity;
    Vector3D force = Vector3D(velocitypart.getx(), velocitypart.gety(), velocitypart.getz());
    force.normalisation();
    force.mulScalaire((coeffDrag1 * velocitypart.norme() + coeffDrag2 * velocitypart.normecarre()) *
                     -1);
    this->forceAccum += force;*/

    // add drag angulare velocity
    /*float coeffDrag1 = 1;
    float coeffDrag2 = 1;
    Vector3D velocitypart = this->m_AngularVelocity;
    Vector3D force = Vector3D(velocitypart.getx(), velocitypart.gety(), velocitypart.getz());
    force.normalisation();
    force.mulScalaire((coeffDrag1 * velocitypart.norme() + coeffDrag2 * velocitypart.normecarre()) *
                      -1);
    this->torqueAccum += force;*/
    
    // calcul acceleration lineaire
    Vector3D AccumForcesTemp = this->forceAccum;
    AccumForcesTemp.mulScalaire(this->m_InverseMass);
    this->m_Acceleration = AccumForcesTemp;

    // calcul acceleration angulaire
    Vector3D torqueAccumTemp = this->torqueAccum;
    Matrix3 inverseInertieTensorTemp = this->m_InverseInertieTensor;
    this->m_AngularAcceleration =
    this->m_InverseInertieTensor.MultiplicationVectorielle(this->torqueAccum);

    // update velocite
    Vector3D AccelerationTemp = this->m_Acceleration;
    AccelerationTemp.mulScalaire(frameTime);
    Vector3D velocityTemp =
    this->m_Velocity.mulScalaireResult(pow(this->m_LinearDamping, frameTime));
    this->m_Velocity = velocityTemp + AccelerationTemp;

    // velocity angular
    Vector3D AccelerationAngTemp = this->m_AngularAcceleration;
    AccelerationAngTemp.mulScalaire(frameTime);
    Vector3D velocityAngTemp =
    this->m_AngularVelocity.mulScalaireResult(pow(this->m_AngularDamping, frameTime));
    this->m_AngularVelocity = velocityAngTemp + AccelerationAngTemp;

    // update position
    Vector3D Temp = this->m_Velocity;
    Temp.mulScalaire(frameTime);
    this->m_Position = this->m_Position + Temp;

	                           
    // update orientation
    this->m_Orientation.UpdateAngularVelocity(this->m_AngularVelocity, frameTime);

	
	
    //update derived Data se fait dans l'objet car c'est lui qui possède les différents sommets pour mettre à jour la matrice tensor
    

    // clear accums
    clearAccum();
}