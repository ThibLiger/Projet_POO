#include "CLcommande.h"
#include "pch.h"

CLcommande::CLcommande(String^ refe, int^ num, String^ liv, String^ emi, array<CLpaiement^>^ paie, array<CLcatalog^>^ prod, float^ ht, float^ tva, float^ ttc, CLadresse^ adresseLivr, CLadresse^ aresseEmis)
{
    ref = refe;
    numClient = num;
    dateLivr = liv;
    dateEmis = emi;
    paiements = paie;
    produits = prod;
    prixHT = ht;
    TVA = tva;
    prixTTC = ttc;
    adresseDeLivraison = adresseLivr;
    adresseExpedition = aresseEmis;
}

String^ CLcommande::getref()
{
    return ref;
}

int^ CLcommande::getnumClient()
{
    return numClient;
}

String^ CLcommande::getdateLivr()
{
    return dateLivr;
}

String^ CLcommande::getdateEmis()
{
    return dateEmis;
}

array<CLpaiement^>^ CLcommande::getpaiements()
{
    return paiements;
}

array<CLcatalog^>^ CLcommande::getproduits()
{
    return produits;
}

float^ CLcommande::getprixHT()
{
    return prixHT;
}

float^ CLcommande::getTVA()
{
    return TVA;
}

float^ CLcommande::getprixTTC()
{
    return prixTTC;
}

CLadresse^ CLcommande::getadresseDeLivraison()
{
    //throw gcnew System::NotImplementedException();
    return adresseDeLivraison;
}

CLadresse^ CLcommande::getadresseExpedition()
{
    //throw gcnew System::NotImplementedException();
    return adresseExpedition;
}

void CLcommande::setref(String^ refe)
{
    ref = refe;
}

void CLcommande::setnumClient(int^ num)
{
    numClient = num;
}

void CLcommande::setdateLivr(String^ liv)
{
    dateLivr = liv;
}

void CLcommande::setdateEmis(String^ emi)
{
    dateEmis = emi;
}

void CLcommande::setpaiements(array<CLpaiement^>^ paie)
{
    paiements = paie;
}

void CLcommande::setproduits(array<CLcatalog^>^ prod)
{
    produits = prod;
}

void CLcommande::setprixHT(float^ ht)
{
    prixHT = ht;
}

void CLcommande::setTVA(float^ tva)
{
    TVA = tva;
}

void CLcommande::setprixTTC(float^ ttc)
{
    prixTTC = ttc;
}

void CLcommande::setadresseDeLivraison(CLadresse^ adresse)
{
    adresseDeLivraison = adresse;
}

void CLcommande::setadresseExpedition(CLadresse^ adresse)
{
    //throw gcnew System::NotImplementedException();
    adresseExpedition = adresse;
}
