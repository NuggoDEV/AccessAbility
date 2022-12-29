#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "UI/UIManager.hpp"
using namespace AccessAbility::UI;
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSMLDataCache.hpp"

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
    //QuestUI::Init();
    //QuestUI::Register::RegisterGameplaySetupMenu<AccessAbility::UI::AccessAbilityUI *>(modInfo, "AccessAbility");
    BSML::Register::RegisterGameplaySetupTab("AccessAbility", MOD_ID "_settings", UIManager::get_instance(), BSML::MenuType::All);

    getLogger().info("Installing hooks");
    Hooks::InstallHooks(getLogger());
    getLogger().info("Installed all hooks!");
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::settings_bsml;
}