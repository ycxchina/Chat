# -项目概述
    C++,gRPC,asio 网络库，多线程，Redis，Mysgl，设计模式 个人项目
    本项目后端采用分布式微服务架构，支持用户注册登录、好友管理、消息传递、聊天记录展示等功能
    · GateServer对外采用http服务，负责用户登录，注册，并通过VarifyServer发送验证码邮件
    · StatusServer管理用户在线状态和聊天服务节点，解决聊天服务直接查询数据库导致的访问瓶颈以
     及数据一致性问题
    · ChatServer聊天服务器基于Asio实现TCP可靠长连接的异步/通信和消息转发,采用多线程IOcontext池提高并发性能
    · 各服务采用 RPC通信，支持断线重连和负载均衡，提高系统吞吐量，提供聊天服务的高扩展性以及跨语言支持
    · 使用池化技术，基于mysglconnector库封装连接池，同时封装Redis连接池处理缓存数据，以及grpc连接池保证多服务并发访问
    · 使用了单例和生产者消费者的设计模式，奇异递归模板，RAI等编程技巧和思想
