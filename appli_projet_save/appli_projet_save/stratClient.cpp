#pragma once
#include "pch.h"

using namespace appliprojet;



void stratClient::create(String^ nom, String^ prenom, String^ birthdate, String^ adresse_fact, String^ ville_fact, String^ CP_fact, String^ adresse_livr, String^ ville_livr, String^ CP_livr) {
	CLclient obj;
	obj.setnom(nom);
	obj.setprenom(prenom);
	obj.setadresseFact(adresse_fact);
	obj.setadresseLivr(adresse_livr);
	obj.setbirthdate(birthdate);
	conDataBase->Open();
	cmdclient = "insert into projetpoo.CLIENT(NOM,PRENOM,BIRTHDATE) values ('"+nom+"','"+prenom+"','"+birthdate+"');";
	command = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdclient, conDataBase);
	myReader = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(command);
	myReader->Fill(DS);

	cmdid = "select NUMCLIENT from projetpoo.CLIENT where NOM = '" + nom + "' and PRENOM = '" + prenom + "' and BIRTHDATE = '" + birthdate + "';";
	commandid = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdid, conDataBase);
	MySqlDataReader^ myreader = commandid->ExecuteReader();
	myreader->Read();
	int^ idclient = myreader->GetInt32(0);
	myreader->Close();

	cmdclient = "INSERT INTO projetpoo.ADRESSES (NUM_ET_RUE, VILLE, CP) VALUES('"+ adresse_fact +"','" + ville_fact + "','" + CP_fact + "');";
	command = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdclient, conDataBase);
	myReader = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(command);
	myReader->Fill(DS);

	cmdid = "select IDADR from projetpoo.ADRESSES where NUM_ET_RUE= '" + adresse_fact + "' and VILLE = '" + ville_fact + "' and CP='" + CP_fact + "';";
	commandid = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdid, conDataBase);
	myreader = commandid->ExecuteReader();
	myreader->Read();
	int^ idadresse = myreader->GetInt32(0);
	myreader->Close();

	cmdclient = "insert into projetpoo.A_PAYE_A(NUMCLIENT,IDADR) values (" + idclient + "," + idadresse + ");";
	command = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdclient, conDataBase);
	myReader = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(command);
	myReader->Fill(DS);
	cmdclient = "INSERT INTO projetpoo.ADRESSES (NUM_ET_RUE, VILLE, CP) VALUES('" + adresse_livr + "','" + ville_livr + "','" + CP_livr + "');";
	command = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdclient, conDataBase);
	myReader = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(command);
	myReader->Fill(DS);

	cmdid = "select IDADR from projetpoo.ADRESSES where NUM_ET_RUE= '" + adresse_livr + "' and VILLE = '" + ville_livr + "' and CP='" + CP_livr + "';";
	commandid = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdid, conDataBase);
	myreader = commandid->ExecuteReader();
	myreader->Read();
	idadresse = myreader->GetInt32(0);
	myreader->Close();

	cmdclient = "insert into projetpoo.EST_LIVRE_A(NUMCLIENT,IDADR) values (" + idclient + "," + idadresse + ");";
	command = gcnew MySql::Data::MySqlClient::MySqlCommand(cmdclient, conDataBase);
	myReader = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(command);
	myReader->Fill(DS);
	conDataBase->Close();
};
void stratClient::read(String^ nom, String^ prenom, String^ birthdate) {
	conDataBase->Open();
	cmdclient = "select * from projetpoo.CLIENT where NOM = '" + nom + "' and PRENOM = '" + prenom + "' and BIRTHDATE = '" + birthdate + "';";
	myReader->Fill(DS);
};
void stratClient::update() {
	cmdclient = "";
};
void stratClient::suppr(String^ nom, String^ prenom, String^ birthdate) {
	CLclient suppr;
	cmdid = "select id from projetpoo.CLIENT where NOM = '" + nom + "' and PRENOM = '" + prenom + "' and BIRTHDATE = '" + birthdate + "';";
	MySqlDataReader^ myreader = command->ExecuteReader();
	myreader->Read();
	int^ idclient = myreader->GetInt32(0);
	array<int^>^ adrs;
	cmdclient = "delete from projetpoo.CLIENT where NOM = '" + nom + "' and PRENOM = '" + prenom + "' and BIRTHDATE = '" + birthdate + "';";

};