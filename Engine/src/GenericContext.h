#pragma once

#include <Functional>
#include <memory>
#include "Layer.h"

enum class ContextAPI;

struct ApplicationSpecification;

class GenericContext
{
public:
	//GenericContext(const ApplicationSpecification& applicationSpecification);
	virtual ~GenericContext() = default;

	virtual void Run() = 0;
	virtual void SetMenubarCallback(const std::function<void() >& menubarCallback) = 0;
	virtual void PushLayer(const std::shared_ptr<Layer>& layer) = 0;
	virtual void Close() = 0;

	static GenericContext* Create(const ContextAPI& api, const ApplicationSpecification& Specification);
private:
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
};

