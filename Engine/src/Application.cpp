#include "Application.h"
#include "GenericContext.h"

Application::Application(const ContextAPI& api, const ApplicationSpecification& applicationSpecification)
{
	m_context = GenericContext::Create(api, applicationSpecification);
}

Application::~Application()
{
	delete m_context;
}

void Application::Run()
{
	m_context->Run();
}

void Application::PushLayer(const std::shared_ptr<Layer>& layer)
{
	m_context->PushLayer(layer);
}

void Application::Close()
{
	m_context->Close();
}

Application* Application::Create(const ContextAPI& api, const ApplicationSpecification& spec)
{
	return new Application(api, spec);
}

