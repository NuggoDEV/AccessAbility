#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "UI/AccessAbilityUI.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

static ModInfo modInfo;

ModInfo& ModInf() {
    return modInfo;
}

Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    getModConfig().Init(modInfo);
    QuestUI::Init();
    QuestUI::Register::RegisterGameplaySetupMenu<AccessAbility::UI::AccessAbilityUI *>(modInfo, "AccessAbility");

    getLogger().info("Installing hooks");
    Hooks::InstallHooks(getLogger());
    getLogger().info("Installed all hooks!");
}