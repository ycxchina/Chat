#ifndef _ASIOIOSERVICEPOOL_H
#define _ASIOIOSERVICEPOOL_H

#include"Singleton.h"
#include<memory>
#include<boost/asio.hpp>
#include<thread>
#include<vector>
class AsioIOServicePool:public Singleton<AsioIOServicePool>{
    friend Singleton<AsioIOServicePool>;
    public:
        using IOService = boost::asio::io_context;
        using Work = boost::asio::io_context::work;
        using WrokPtr = std::unique_ptr<Work>;
        ~AsioIOServicePool();
        AsioIOServicePool(const AsioIOServicePool& )= delete;
        AsioIOServicePool& operator=(const AsioIOServicePool& )= delete;    
        boost::asio::io_context& GetIOService();
        void Stop();
    private:
        AsioIOServicePool(std::size_t size = 2);
        std::vector<IOService> _ioServices;
        std::vector<WrokPtr> _works;
        std::vector<std::thread> _threads;
        std::size_t _nextIOService;

};

#endif