//  Copyright (c) 2017-2018 The WeChat Authors. All rights reserved.
//  Created on: 2017年1月12日 Author: kerry

#include "user/user_logic.h"
#include "config/config.h"
#include "core/common.h"
#include <string>
#include <sstream>

#define DEFAULT_CONFIG_PATH "./plugins/user/user_config.xml"

namespace user_logic {

Userlogic *Userlogic::instance_ = NULL;

Userlogic::Userlogic() {
    if (!Init())
        assert(0);
}

Userlogic::~Userlogic() {
}

bool Userlogic::Init() {
    bool r = false;
    std::string path = DEFAULT_CONFIG_PATH;
    config::FileConfig *config = config::FileConfig::GetFileConfig();
    if (config == NULL)
        return false;
    r = config->LoadConfig(path);
    return true;
}

Userlogic *Userlogic::GetInstance() {
    if (instance_ == NULL)
        instance_ = new Userlogic();
    return instance_;
}

void Userlogic::FreeInstance() {
    delete instance_;
    instance_ = NULL;
}

bool Userlogic::OnUserConnect(struct server *srv, const int socket) {
    return true;
}

bool Userlogic::OnUserMessage(struct server *srv, const int socket,
                                  const void *msg, const int len) {
    return true;
}


bool Userlogic::OnUserClose(struct server *srv, const int socket) {
    return true;
}

bool Userlogic::OnBroadcastConnect(struct server *srv, const int socket,
                                     const void *msg, const int len) {
    return true;
}

bool Userlogic::OnBroadcastMessage(struct server *srv, const int socket,
                                     const void *msg, const int len) {
    printf("OnBroadcastMessage \n");
    return true;
}

bool Userlogic::OnBroadcastClose(struct server *srv, const int socket) {
    return true;
}

bool Userlogic::OnIniTimer(struct server *srv) {
    if (srv->add_time_task != NULL) {
    }
    return true;
}

bool Userlogic::OnTimeout(struct server *srv, char *id, int opcode, int time) {
    switch (opcode) {
    default:
        break;
    }
    return true;
}


}  // namespace user_logic
