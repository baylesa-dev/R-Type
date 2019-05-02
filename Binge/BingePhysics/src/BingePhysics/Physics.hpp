/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Physics class definition
*/

#pragma once

namespace Binge {

    struct Vector {
        double x;
        double y;
        double z;
    };

    class Physics {
	public:
		Physics();
		~Physics();

        void updatePhysics();

        void setPosition(Vector newPosition);
        Vector &getPosition();

        void setGravityStatus(bool activation);
        void setGravity(bool activation, Vector newGravity);
        bool getGravityStatus();
        Vector &getGravity();

        void setAcceleration(Vector newAcceleration, int timeAcceleration);
        Vector &getAcceleration();
        int &getTimeAcceleration();

        void setSpeed(Vector newSpeed);
        Vector &getSpeed();

        void setRotation(Vector newRotation);
        Vector &getRotation();
        void setRotationSpeed(double newRotationSpeed);
        double &getRotationSpeed();

	protected:
	private:
        Vector _position;

        bool _gravityStatus;
        Vector _gravity;

        Vector _acceleration;
        int _timeAcceleration;

        Vector _speed;

        Vector _rotation;
        double _rotationSpeed;

        void _updatePosition();
        void _updateSpeed();
        void _updateAcceleration();
        bool _checkNullVector(Binge::Vector vec);
        Vector _setVector(double x, double y, double z);
    };

} // namespace Binge
