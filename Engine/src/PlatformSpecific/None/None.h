#pragma once
#include "Application.h"

class None : public Application
{
public:
	None(const Application::Specification& applicationSpecification = Application::Specification());
	virtual ~None();

	void Run() override;


	void Close() override;

private:
	void Init();
	void Shutdown();
};

