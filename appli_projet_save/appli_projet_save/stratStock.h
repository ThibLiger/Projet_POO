#pragma once
#include "pch.h"

ref class stratStock : public stratCRUD
{
public:
	void create() override {};
	void create(int, int, String^, String^, String^, String^, String^, int) override;
	//personnel
	void create(String^, String^, String^, String^, String^, String^) override {};
	//client
	void create(String^, String^, String^, String^, String^, String^, String^, String^, String^) override {};


	void update() override {};
	void update(String^, String^, String^, String^, String^, int, String^) override;
	//client
	void update(String^, String^, String^, int id) override {};


	void suppr() override {};
	//personnel
	void suppr(int) override {};
};

