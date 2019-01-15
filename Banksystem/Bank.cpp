#include <iostream>

#include "Bank.h"

cBank g_Bank;

void cAutomat::GeldkarteInput() {
	std::cout << "\nBenutzername der Karte eingeben: ";
	std::cin >> szBenutzername;
};

bool cAutomat::PinEingeben() {
	std::cout << "\nGeben Sie ihre Geheimzahl ein: ";
	std::cin >> szPIN;
	return g_Bank.Zugriffsberechtigung(szBenutzername,szPIN);
};

bool cAutomat::BetragEingabe() {
	int iBetrag, iSelection;
	std::cout << "\nMoechten Sie Geld abheben oder einzahlen?\n\nAbheben = 0\nEinzahlen = 1\n\n";
	std::cin >> iSelection;

	const auto bWithdraw = iSelection == 0;

	std::cout << "\nGeben Sie ihren gewuenschten Betrag ein: ";
	std::cin >> iBetrag;
	return g_Bank.MoneyDraw(iBetrag, bWithdraw);
};



void cBank::Init(std::string p_szBenutzername, std::string p_szPIN, int p_iKontostand) {
	szBenutzername = p_szBenutzername;
	szPIN = p_szPIN;
	iKontostand = p_iKontostand;
};

bool cBank::Zugriffsberechtigung(std::string p_szBenutzername, std::string p_szPIN) {
	if (p_szBenutzername == szBenutzername && p_szPIN == szPIN) {
		return true;
	}
	return false;
};

bool cBank::MoneyDraw(int p_iBetrag, bool p_bWithdraw) {
	if (iKontostand >= p_iBetrag && p_bWithdraw) {
		iKontostand -= p_iBetrag;
		return true;
	}
	else if(!p_bWithdraw){
		iKontostand += p_iBetrag;
		return true;
	}
	else {
		std::cout << "\nIhr Kontostand ist niedriger als ihre gewuenschte Summe\nKontostand: " << iKontostand;
		return false;
	}
};

void cBank::GetKontostand() {
	std::cout <<iKontostand;
};
