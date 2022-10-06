#include "Logs.h"
#include "imgui.h"

//bool Logs::isCollapsed = false;

void Logs::PrintDebug()
{
	ImGui::Begin("Console", 0, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::RadioButton("Collapse", isCollapsed))
		{
			if (!isCollapsed)
				CollapseDebug();
			else
				UnCollapseDebug();

			isCollapsed = !isCollapsed;
		}

		if (ImGui::RadioButton("Warning", warnignDebug))
			warnignDebug = !warnignDebug;

		if (ImGui::RadioButton("System", systemDebug))
			systemDebug = !systemDebug;

		if (ImGui::RadioButton("Logs", msgDebug))
			msgDebug = !msgDebug;

		ImGui::EndMenuBar();
	}

	for (size_t i = 0; i < logs.size(); i++)
	{
		if (msgDebug && logs[i].type == LogsType::MSGLOG)
		{
			logsString = logs[i];

			ImGui::Text("%d", logsString.repts);
			ImGui::SameLine();

			ImGui::Text(logsString.st.c_str());
		}

		if (systemDebug && logs[i].type == LogsType::SYSTEM)
		{
			logsString = logs[i];

			ImGui::Text("%d", logsString.repts);
			ImGui::SameLine();

			ImGui::Text(logsString.st.c_str());
		}

		if (warnignDebug && logs[i].type == LogsType::WARNING)
		{
			logsString = logs[i];

			ImGui::Text("%d", logsString.repts);
			ImGui::SameLine();

			ImGui::Text(logsString.st.c_str());
		}
	}

	ImGui::End();

}

void Logs::DebugLog(string format, LogsType type)
{
	if (format.size() <= 0) return;

	if (isCollapsed)
		for (size_t i = 0; i < logs.size(); i++)
		{
			if (logs[i].st == format)
			{
				++logs[i].repts;
				logsCopy.push_back(DebugLogs(format, type));
				return;
			}
		}

	logs.push_back(DebugLogs(format, type));
}

void Logs::CollapseDebug()
{
	//logs copy = before collapse
	logsCopy.clear();
	logsCopy = logs;

	for (int i = 0; i < logs.size(); i++)
	{
		for (int j = i + 1; j < logs.size(); j++)
		{
			if (logs[j].repts > 0)
				if (logs[i].st == logs[j].st)
				{
					logs[i].repts++;
					logs[j].repts = 0;
				}
		}
	}

	//erase all 
	vector<DebugLogs> auxLogs;
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i].repts > 0)
			auxLogs.push_back(logs[i]);
	}
	logs = auxLogs;
	auxLogs.clear();
}

void Logs::UnCollapseDebug()
{
	logs.clear();
	logs = logsCopy;
	logsCopy.clear();
}
