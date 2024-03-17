#include <cpprest/http_client.h>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::client;

int main() {
    //创建一个 http_client 对象
    http_client client(U("http://www.bing.com"));
    
    // 构建请求 URI 和发送 GET 请求
    uri_builder builder(U("/search"));
    http_response response = client.request(methods::GET, builder.to_string()).get();

    // 输出响应的状态码
    if (response.status_code() == status_codes::OK) {
        utility::string_t body = response.extract_string().get();
        std::wcout << body << std::endl;
    } else {
        std::wcout << "Error: " << response.status_code() << std::endl;
    }

    return 0;
}