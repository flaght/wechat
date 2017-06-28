//  Copyright (c) 2017-2018 The WeChat Authors. All rights reserved.
//  Created on: 2017年1月12日 Author: kerry

#ifndef WECHAT_SEARCH_SEARCH_LOGIC_
#define WECHAT_SEARCH_SEARCH_LOGIC_

#include "basic/basictypes.h"
#include "core/common.h"


namespace user_logic {

class Userlogic {
public:
    Userlogic();
    virtual ~Userlogic();
private:
    static Userlogic *instance_;

public:
    static Userlogic *GetInstance();
    static void FreeInstance();

    bool OnUserConnect(struct server *srv, const int socket);

    bool OnUserMessage(struct server *srv, const int socket, const void *msg,
                         const int len);

    bool OnUserClose(struct server *srv, const int socket);

    bool OnBroadcastConnect(struct server *srv, const int socket,
                            const void *data, const int len);

    bool OnBroadcastMessage(struct server *srv, const int socket, const void *msg,
                            const int len);

    bool OnBroadcastClose(struct server *srv, const int socket);

    bool OnIniTimer(struct server *srv);

    bool OnTimeout(struct server *srv, char *id, int opcode, int time);
private:
    bool Init();
};
}  // namespace user_logic

#endif
