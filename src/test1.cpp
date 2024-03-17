#include <cpprest/http_client.h>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::client;

int main() {
    //创建一个 http_client 对象
    http_client client(U("https://api.gateio.ws/api/v4/spot/currencies/GT"));
    
    //构建请求并设置头部信息
    http_request request(methods::GET);
    request.headers().add(U("Content-Type"), U("application/json"));
    request.headers().add(U("Accept"), U("application/json"));

    // 发送请求并接收响应
    http_response response = client.request(request).get();

    //输出相应的状态码和内容
    if (response.status_code() == status_codes::OK) {
        utility::string_t body = response.extract_string().get();
        std::cout << "Response body: " << body << std::endl;
    } else {
        std::cout << "Error: " << response.status_code() << std::endl;
    }
    
    return 0; 
}