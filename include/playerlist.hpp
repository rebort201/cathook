/*
 * playerlist.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: nullifiedcat
 */

#ifndef PLAYERLIST_HPP_
#define PLAYERLIST_HPP_

#include "common.hpp"

namespace playerlist
{

constexpr int SERIALIZE_VERSION = 3;

enum class k_EState
{
    DEFAULT,
    FRIEND,
    RAGE,
    IPC,
    DEVELOPER,
    STATE_LAST = DEVELOPER
};

extern rgba_t k_Colors[];
const std::string k_Names[] = { "DEFAULT", "FRIEND", "RAGE", "IPC",
                                "DEVELOPER" };
const char *const k_pszNames[] = { "DEFAULT", "FRIEND", "RAGE", "IPC",
                                   "DEVELOPER" };

struct userdata
{
    k_EState state{ k_EState::DEFAULT };
    rgba_t color{ 0, 0, 0, 0 };
    float inventory_value{ 0 };
    unsigned deaths_to{ 0 };
    unsigned kills{ 0 };
};

extern std::unordered_map<unsigned, userdata> data;

void Save();
void Load();

constexpr bool IsFriendly(k_EState state)
{
    return state == k_EState::DEVELOPER || state == k_EState::FRIEND ||
           state == k_EState::IPC;
}

rgba_t Color(unsigned steamid);
rgba_t Color(CachedEntity *player);
userdata &AccessData(unsigned steamid);
userdata &AccessData(CachedEntity *player);
bool IsDefault(unsigned steamid);
bool IsDefault(CachedEntity *player);
}

#endif /* PLAYERLIST_HPP_ */
