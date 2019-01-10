#include <array>
#include <iostream>
#include <thread>

#include "Bank.h"


extern cBank g_Bank;


int main() {
	g_Bank.Init("TyronS","5631", 5000);

	for (;;) {
		cAutomat m_Kunde;
		m_Kunde.GeldkarteInput();

		if (m_Kunde.PinEingeben()) {
			std::cout << "\nAktueller Kontostand: ";
			g_Bank.GetKontostand();
			if (m_Kunde.BetragEingabe()) {
				std::cout << "\nDer gewuenschte Betrag wurde erfolgreich bearbeitet\nAktueller Kontostand: ";
				g_Bank.GetKontostand();
			}
		}
		else {
			std::cout << "\nDie Pin ist falsch!";
		}
		std::cout << "\n";
	}
	
};