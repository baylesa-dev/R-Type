/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Physics class implementation
*/

#include "Physics.hpp"

Binge::Physics::Physics()
{
}

Binge::Physics::~Physics()
{
}

/*
** Update functions
*/

void Binge::Physics::updatePhysics() {
    this->_updateAcceleration();
    this->_updateSpeed();
    this->_updatePosition();
}

void Binge::Physics::_updatePosition() {
    this->_position = _setVector(
        this->_position.x + this->_speed.x,
        this->_position.y + this->_speed.y,
        this->_position.z + this->_speed.z
    );
}

void Binge::Physics::_updateSpeed() {
    this->_speed = _setVector(
        this->_speed.x + this->_acceleration.x,
        this->_speed.y + this->_acceleration.y,
        this->_speed.z + this->_acceleration.z
    );
}

void Binge::Physics::_updateAcceleration() {
    if (this->_timeAcceleration == 0)
        this->_acceleration = _setVector(0, 0, 0);
}

bool Binge::Physics::_checkNullVector(Binge::Vector vec) {
    if (vec.x == 0 && vec.y == 0 && vec.z == 0)
        return true;
    return false;
}


Binge::Vector Binge::Physics::_setVector(double x, double y, double z) {
    Binge::Vector vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

/*
** Getter and Setters
*/


void Binge::Physics::setPosition(Vector newPosition) {
    this->_position = newPosition;
}

Binge::Vector &Binge::Physics::getPosition() {
    return this->_position;
}

void Binge::Physics::setGravityStatus(bool activation) {
    this->_gravityStatus = activation;
}

bool Binge::Physics::getGravityStatus() {
    return this->_gravityStatus;
}

Binge::Vector &Binge::Physics::getGravity() {
    return this->_gravity;
}

void Binge::Physics::setAcceleration(Binge::Vector newAcceleration, int newTimeAcceleration) {
    this->_acceleration = newAcceleration;
    this->_timeAcceleration = newTimeAcceleration;
}

Binge::Vector &Binge::Physics::getAcceleration() {
    return this->_acceleration;
}

int &Binge::Physics::getTimeAcceleration() {
    return this->_timeAcceleration;
}

void Binge::Physics::setSpeed(Binge::Vector newSpeed) {
    this->_speed = newSpeed;
}

Binge::Vector &Binge::Physics::getSpeed() {
    return this->_speed;
}

void Binge::Physics::setRotation(Binge::Vector newRotation) {
    this->_rotation = newRotation;
}

Binge::Vector &Binge::Physics::getRotation() {
    return this->_rotation;
}

void Binge::Physics::setRotationSpeed(double newRotationSpeed) {
    this->_rotationSpeed = newRotationSpeed;
}

double &Binge::Physics::getRotationSpeed() {
    return this->_rotationSpeed;
}