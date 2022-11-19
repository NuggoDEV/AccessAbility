#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "UI/AccessAbilityUI.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

DEFINE_CONFIG(ModConfig);

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getModConfig().Init(modInfo);
    QuestUI::Init();
    QuestUI::Register::RegisterGameplaySetupMenu<AccessAbility::UI::AccessAbilityUI *>(modInfo, "AccessAbility");

    getLogger().info("Installing hooks...");
    
    auto& logger = getLogger();
    Hooks::InstallHooks(logger);

    getLogger().info("Installed all hooks!");
}