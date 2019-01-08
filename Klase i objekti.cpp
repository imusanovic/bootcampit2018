// Klase i objekti.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Televizija {
protected:
	bool ukljucena;
public:
	Televizija() {
		ukljucena = false;
		cout << "Stvorena je novi TV." << endl;
	}
	void power() {
		if (ukljucena == true) {
			ukljucena = false;
			cout << "TV je iskljucen!" << endl;
		}
		else {
			ukljucena = true;
			cout << "TV je ukljucen!" << endl;
		}
	}
};

class LED : public Televizija {
private:
	string tip;
public:
	LED() {
		tip = "OLED";
		cout << "Stvorena je novi " <<
			tip << " televizor" << endl;
	}
	void power() {
		if (ukljucena == true) {
			ukljucena = false;
			cout << "LED TV je iskljucen!" << endl;
		}
		else {
			ukljucena = true;
			cout << "LED TV je ukljucen!" << endl;
		}
	}
};

class Spaceship {
private:
	int shield_strength;
public:
	string name;

	Spaceship() {
		name = "Bezimeni brod";
		shield_strength = 100;
	}

	Spaceship(string naziv) {
		name = naziv;
		shield_strength = 100;
	}

	string fire() {
		return "Boom!";
	}
	void reduce_shields(int amount);
};

void Spaceship::reduce_shields(int amount) {
	shield_strength -= amount;
}

class Xyz {
private:
	int x;
public:
	Xyz() {};
	void set_x(int xx);
	void metoda();
};

void Xyz::set_x(int xx) {
	x = xx;
}

void Xyz::metoda() {
	cout << "Na adresi sam: " << this << ", a moj broj je " << x << endl;
}

class Singleton {
private:
	static bool instance_flag;
	static Singleton *instance;
	Singleton() {
	}
public:
	static Singleton *get_instance();
	void my_method();
	~Singleton() {
		instance_flag = false;
	}
};

bool Singleton::instance_flag = false;
Singleton *Singleton::instance = nullptr;

Singleton *Singleton::get_instance() {
	if (!instance_flag) {
		instance = new Singleton();
		instance_flag = true;
	}
	
	return instance;
}

void Singleton::my_method() {
	cout << "Samo sam jedan na svijetu i to na adresi: " << this << endl;
}

class Aaaa {
public:
	void set_x(int iks) {
		x = iks;
	}
	int get_x() {
		return x;
	}
private:
	int x;
	int y;
};

int main()
{
	
	/*
	Televizija tv1;
	LED tv2;
	
	tv1.power();
	tv2.power();

	// objekti obiène klase Xyz
	Xyz *jedan = new Xyz();
	Xyz *dva = new Xyz();
	jedan->set_x(5);
	dva->set_x(7);

	jedan->metoda();
	dva->metoda();
	*/
	// objekti klase Singleton (zapravo samo pokazivaèi na isti objekt)
	Singleton *sam_sam_na_svijetu = Singleton::get_instance();
	Singleton *drugi_sam_na_svijetu = Singleton::get_instance();
	Singleton *treci_sam_na_svijetu = Singleton::get_instance();
	
	sam_sam_na_svijetu->my_method();
	drugi_sam_na_svijetu->my_method();
	treci_sam_na_svijetu->my_method();
	
	cout << endl;

	system("pause");
    return 0;
}