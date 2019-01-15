#include <string>


class cBank {
public:
	bool MoneyDraw(int p_iBetrag, bool p_iWithdraw);
	bool Zugriffsberechtigung(std::string p_szBenutzername, std::string p_szPIN);
	void Init(std::string p_szBenutzername, std::string p_szPIN, int p_iKontostand);
	void GetKontostand();

private:
	std::string szBenutzername;
	std::string szPIN;
	int iKontostand;
};


class cAutomat {
public:
	bool PinEingeben();
	bool BetragEingabe();
	void GeldkarteInput();

private:
	std::string szPIN;
	std::string szBenutzername;
};
