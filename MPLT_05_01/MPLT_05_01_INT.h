#pragma once
#include <string>

namespace MPLT_05_01 {
	class GameObject abstract {
	public:
		GameObject(int _ID);
		GameObject(const GameObject &object);
		virtual ~GameObject();

		int GetID();
		virtual std::string print();
	private:
		int ID;
	};

	class PhysicalObject abstract : public virtual GameObject{
	public:
		PhysicalObject(int _ID, double _Weight);
		PhysicalObject(const PhysicalObject& object);
		virtual ~PhysicalObject();

		virtual std::string print();
	private:
		double Weight;
	};

	class GraphicalObject abstract : public virtual GameObject {
	public:
		GraphicalObject(int _ID, std::string _Texture);
		GraphicalObject(const GraphicalObject& object);
		virtual ~GraphicalObject();

		virtual std::string print();
	private:
		std::string Texture;
	};

	class Projectile : public PhysicalObject {
	public:
		Projectile(int _ID, double _Weight, int _Caliber);
		Projectile(const Projectile& object);
		virtual ~Projectile();

		virtual std::string print();
	private:
		int Caliber;
	};

	class TransportVehicle : public PhysicalObject {
	public:
		TransportVehicle(int _ID, double _Weight, double _EnginePower);
		TransportVehicle(const TransportVehicle& object);
		virtual ~TransportVehicle();

		virtual std::string print();
	private:
		double EnginePower;
	};

	class Tank : public TransportVehicle, public GraphicalObject {
	public:
		Tank(int _ID, double _Weight, std::string _Texture, double _EnginePower, int _ArmorThickness);
		Tank(const Tank& object);
		virtual ~Tank();

		virtual std::string print();
	private:
		int ArmorThickness;
	};

	class Plane : public TransportVehicle, public GraphicalObject {
	public:
		Plane(int _ID, double _Weight, std::string _Texture, double _EnginePower, double _Capacity);
		Plane(const Plane& object);
		virtual ~Plane();

		virtual std::string print();
	private:
		double Capacity;
	};
}