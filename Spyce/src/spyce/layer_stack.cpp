#include "scpch.h"
#include "layer_stack.h"

namespace Spyce
{
	LayerStack::LayerStack() { }

	LayerStack::~LayerStack()
	{
		for (Layer* layer : mLayers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		mLayers.emplace_back(layer);
		layer->OnAttach();
	}

	void LayerStack::RemoveLayer(Layer* layer)
	{
		mLayers.erase(std::find(mLayers.begin(), mLayers.end(), layer));
		layer->OnDetach();
	}

	void LayerStack::PopLayer()
	{
		Layer* l = mLayers.back();
		l->OnDetach();
		delete l;
		mLayers.pop_back();
	}

}