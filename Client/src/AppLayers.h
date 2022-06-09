

class AppLayer : public Layer
{
public:
	AppLayer() {
	}

	virtual void OnUIRender() override
	{
		//ImGui::ShowDemoWindow();

		ImGui::Begin("Treeview");
		
		if (ImGui::TreeNode("SmartFlo Devices"))
		{
			for (int i = 0; i < 4; i++)
			{
				static ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;

				ImGui::TreeNodeEx((void*)(intptr_t)i, node_flags, "Smartflo %d", i);

			}
			ImGui::TreePop();
		}

		ImGui::End();

		ImGui::Begin("Sideview");

		ImGui::End();

		ImGui::Begin("Console");

		ImGui::End();
	}
};
