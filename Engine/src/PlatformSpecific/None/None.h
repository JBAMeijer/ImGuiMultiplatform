#pragma once
#include "Application.h"

namespace CF {

	class None : public Application
	{
	public:
		None(const Application::Specification& applicationSpecification = Application::Specification());
		virtual ~None();

		void Run() override;


		void Close() override;

	private:
		void Init() override;
		void Shutdown() override;
	};

}