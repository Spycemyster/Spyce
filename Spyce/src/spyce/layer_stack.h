#pragma once

#include "layer.h"

namespace Spyce
{
	typedef std::vector<Layer*>::iterator itv;
	class SC_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer();
		void RemoveLayer(Layer* layer);

		itv begin() { return mLayers.begin(); }
		itv end() { return mLayers.end(); }
		
	private:
		std::vector<Layer*> mLayers;
	};
}

