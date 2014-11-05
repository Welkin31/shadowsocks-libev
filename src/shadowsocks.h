/*
 * shadowsocks.h - Header files of library interfaces
 *
 * Copyright (C) 2013 - 2014, Max Lv <max.c.lv@gmail.com>
 *
 * This file is part of the shadowsocks-libev.
 * shadowsocks-libev is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * shadowsocks-libev is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with pdnsd; see the file COPYING. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef _SHADOWSOCKS_H
#define _SHADOWSOCKS_H

typedef struct {
    /*  Required  */
    char *remote_host;    // hostname or ip of remote server
    char *local_addr;     // local ip to bind 
    char *method;         // encryption method
    char *password;       // password of remote server
    int remote_port;      // port number of remote server
    int local_port;       // port number of local server
    int timeout;          // connection timeout

    /*  Optional, set NULL if not valid   */
    char *acl;            // file path to acl
    char *log;            // file path to log
    int fast_open;        // enable tcp fast open
    int udp_relay;        // enable udp relay
    int verbose;          // verbose mode
} profile_t;

/* An example profile

const profile_t EXAMPLE_PROFILE = {
    .remote_host = "example.com",
    .local_addr = "127.0.0.1",
    .method = "bf-cfb",
    .password = "barfoo!",
    .remote_port = 8338,
    .local_port = 1080,

    .acl = NULL,
    .log = NULL,
    .fast_open = 0,
    .udp_relay = 0,
    .verbose = 0
};
*/

/*
 * Create and start a shadowsocks service.
 *
 * If background is set to true, the service will run in a child process and
 * return the pid if success. Otherwise, calling this function will block the
 * current thread forever.
 *
 * On Win32, background mode is invalid. This function will always block the
 * caller and never return.
 *
 * If failed, -1 is returned.
*/
int start_ss_service(profile_t profile, int background);

// To stop the service on posix system, just kill the daemon process
// kill(pid, SIGKILL);

#endif // _SHADOWSOCKS_H
