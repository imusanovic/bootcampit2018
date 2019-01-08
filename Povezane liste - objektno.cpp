// Povezana lista - klase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// definiranje klasa

class Node {
private:
	int podatak;
	Node *next;
	static int broj_nodeova;

public:
	Node();
	~Node();
	void set_podatak(int vrijednost);
	int get_podatak();
	void set_next(Node *nnn);
	Node *get_next();
	static int get_broj_nodeova();
};

class PovezanaLista {
private:
	Node *head;
public:
	PovezanaLista();
	void unos_pocetak(int vrijednost);
	void brisanje_pocetak();
	void unos_kraj(int vrijednost);
	void brisanje_kraj();
	void ispis();
};

// Definicije klase Node

int Node::broj_nodeova = 0; // inicijaliziranje statickog clana broj_nodeova na 0

Node::Node() {
	broj_nodeova++;
}

Node::~Node() {
	broj_nodeova--;
}

void Node::set_podatak(int vrijednost) {
	podatak = vrijednost;
}

int Node::get_podatak() {
	return podatak;
}

void Node::set_next(Node *nnn) {
	next = nnn;
}

Node* Node::get_next() {
	return next;
}

int Node::get_broj_nodeova() {
	return broj_nodeova;
}

// Definicije klase PovezanaLista

PovezanaLista::PovezanaLista() {
	head = nullptr;
}

void PovezanaLista::unos_pocetak(int vrijednost) {
	Node *temp = new Node;
	temp->set_podatak(vrijednost);
	temp->set_next(head);
	head = temp;
}

void PovezanaLista::brisanje_pocetak() {
	Node *temp = head;
	head = temp->get_next();
	delete temp;
}

void PovezanaLista::unos_kraj(int vrijednost) {
	Node *n = new Node;
	n->set_podatak(vrijednost);
	n->set_next(nullptr);
	if (head == nullptr) {
		head = n;
	}
	else {
		Node *temp = head;
		while (temp->get_next() != nullptr) {
			temp = temp->get_next();
		}
		temp->set_next(n);
	}
}

void PovezanaLista::brisanje_kraj() {
	Node *temp = head;
	Node *prev = temp;
	while (temp->get_next() != nullptr) {
		prev = temp;
		temp = temp->get_next();
	}
	prev->set_next(nullptr);
	delete temp;
}

void PovezanaLista::ispis() {
	Node *temp = head;
	while (temp != nullptr) {
		cout << temp->get_podatak() << "\t";
		temp = temp->get_next();
	}
	cout << endl;
}

int main()
{
	PovezanaLista lista;
	int x;
	do {
		cout << "Povezana lista - koristeci klase\n\n";
		cout << "1 - Unos na pocetak\n2 - Brisanje s pocetka\n3 - Unos na kraj\n";
		cout << "4 - Brisanje s kraja\n5 - Ispis\n6 - Broj nodeova\n0 - Izlaz\n";
		cout << "Vas izbor: ";
		cin >> x;
		switch (x) {

			int broj;
		case 1:
			cout << "Unesite broj: ";
			cin >> broj;
			lista.unos_pocetak(broj);
			cout << endl;
			break;
		case 2:
			lista.brisanje_pocetak();
			break;
		case 3:
			cout << "Unesite broj: ";
			cin >> broj;
			lista.unos_kraj(broj);
			cout << endl;
			break;
		case 4:
			lista.brisanje_kraj();
			break;
		case 5:
			cout << endl;
			lista.ispis();
			cout << endl;
			break;
		case 6:
			cout << endl << Node::get_broj_nodeova() << endl;
		case 0:
			break;
		default:
			cout << "Molim ispravan unos!\n";
			break;
		}
	} while (x != 0);

	return 0;
}