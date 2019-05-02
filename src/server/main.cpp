/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Server main entry point
*/

#include <iostream>
#include "Binge/Binge.hpp"
#include "BingeNetwork/Network.hpp"


struct PlayerData {
    int test;
};

int main(int ac, char **av) {

    Binge::Binge *binge = new Binge::Binge();
    std::cout << "...server..." << std::endl;

    Binge::Network *network = new Binge::Network();

    Binge::ServerHandler<PlayerData> handler
        = [&] (Binge::IServerClient<PlayerData> *client) {
            Binge::TCPServerClient<PlayerData> *c =
                static_cast<Binge::TCPServerClient<PlayerData> *>(client);
            std::cout << "New user message from ip " << c->getIp() << ": '" << c->_buffer << "'" << std::endl;
    };

    Binge::TCPServer<PlayerData> *server = network->createTCPServer<PlayerData>(8765, handler);
    server->start();
    return 0;
}