#include <iostream>

#include "discord/discord.h"

int main()
{
	discord::Core* core;
	discord::Result result = discord::Core::Create(874718200997232710, (uint64_t)discord::CreateFlags::Default, &core);
	discord::Activity activity = discord::Activity();
	activity.SetDetails("Working");
	discord::ActivityAssets *assets = &activity.GetAssets();
	assets->SetLargeImage("rog");
	assets->SetLargeText("ROG");
	discord::ActivityTimestamps* timestamps = &activity.GetTimestamps();
	timestamps->SetStart(time(NULL));
	core->ActivityManager().UpdateActivity(activity, [](discord::Result result){});
	while (true)
	{
		core->RunCallbacks();
	}
}
