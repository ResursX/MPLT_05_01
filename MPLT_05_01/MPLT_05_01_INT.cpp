#include "MPLT_05_01_INT.h"
#include <iostream>

namespace MPLT_05_01  {

	//Game Object
	GameObject::GameObject(int _ID)
	{
		std::cout << "GameObject" << std::endl;

		ID = _ID;
	}

	GameObject::GameObject(const GameObject& object)
	{
		std::cout << "GameObject" << std::endl;

		ID = object.ID;
	}

	int GameObject::GetID()
	{
		return ID;
	}

	std::string GameObject::print()
	{
		return "ID: " + std::to_string(ID) + '\n';
	}

	//Physical Object
	PhysicalObject::PhysicalObject(int _ID, double _Weight) : GameObject(_ID)
	{
		std::cout << "PhysicalObject" << std::endl;

		Weight = _Weight;
	}

	PhysicalObject::PhysicalObject(const PhysicalObject& object) : GameObject(object)
	{
		std::cout << "PhysicalObject" << std::endl;

		Weight = object.Weight;
	}

	std::string PhysicalObject::print()
	{
		return GameObject::print() + "Mass: " + std::to_string(Weight) + '\n';
	}

	//Graphical Object
	GraphicalObject::GraphicalObject(int _ID, std::string _Texture) : GameObject(_ID)
	{
		std::cout << "GraphicalObject" << std::endl;

		Texture = _Texture;
	}

	GraphicalObject::GraphicalObject(const GraphicalObject& object) : GameObject(object)
	{
		std::cout << "GraphicalObject" << std::endl;

		Texture = object.Texture;
	}

	std::string GraphicalObject::print()
	{
		return "Texture: " + Texture + '\n';

		//return GameObject::print() + "Texture: " + Texture + '\n';
	}

	//Projectile
	Projectile::Projectile(int _ID, double _Weight, int _Caliber) : GameObject(_ID), PhysicalObject(_ID, _Weight)
	{
		std::cout << "Projectile" << std::endl;

		Caliber = _Caliber;
	}

	Projectile::Projectile(const Projectile& object) : GameObject(object), PhysicalObject(object)
	{
		std::cout << "Projectile" << std::endl;

		Caliber = object.Caliber;
	}

	std::string Projectile::print()
	{
		return PhysicalObject::print() + "Caliber: " + std::to_string(Caliber) + '\n';
	}

	//Transport Vehicle
	TransportVehicle::TransportVehicle(int _ID, double _Weight, double _EnginePower) : GameObject(_ID), PhysicalObject(_ID, _Weight)
	{
		std::cout << "TransportVehicle" << std::endl;

		EnginePower = _EnginePower;
	}

	TransportVehicle::TransportVehicle(const TransportVehicle& object) : GameObject(object), PhysicalObject(object)
	{
		std::cout << "TransportVehicle" << std::endl;

		EnginePower = object.EnginePower;
	}

	std::string TransportVehicle::print()
	{
		return PhysicalObject::print() + "Engine Power: " + std::to_string(EnginePower) + '\n';
	}

	//Tank
	Tank::Tank(int _ID, double _Weight, std::string _Texture, double _EnginePower, int _ArmorThickness) : GameObject(_ID), TransportVehicle(_ID, _Weight, _EnginePower), GraphicalObject(_ID, _Texture)
	{
		std::cout << "Tank" << std::endl;

		ArmorThickness = _ArmorThickness;
	}

	Tank::Tank(const Tank& object) : GameObject(object), TransportVehicle(object), GraphicalObject(object)
	{
		std::cout << "Tank" << std::endl;

		ArmorThickness = object.ArmorThickness;
	}

	std::string Tank::print()
	{
		return TransportVehicle::print() + GraphicalObject::print() + "Armor Thickness: " + std::to_string(ArmorThickness) + '\n';
	}

	//Plane
	Plane::Plane(int _ID, double _Weight, std::string _Texture, double _EnginePower, double _Capacity) : GameObject(_ID), TransportVehicle(_ID, _Weight, _EnginePower), GraphicalObject(_ID, _Texture)
	{
		std::cout << "Plane" << std::endl;

		Capacity = _Capacity;
	}

	Plane::Plane(const Plane& object) : GameObject(object), TransportVehicle(object), GraphicalObject(object)
	{
		std::cout << "Plane" << std::endl;

		Capacity = object.Capacity;
	}

	std::string Plane::print()
	{
		return TransportVehicle::print() + GraphicalObject::print() + "Capacity: " + std::to_string(Capacity) + '\n';
	}
}