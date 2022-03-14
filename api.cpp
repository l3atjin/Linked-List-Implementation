#include <list>
#include <iostream>
#include <string>
#include "json.hpp"
#include <algorithm>

using nlohmann::json;
using namespace std;

class Request
{
private:
    string type;
    string path;
    int content_length;
public:
    Request(string type_in, string path_in, int length_in)
    : type(type_in), path(path_in), content_length(length_in) { }

    string get_type()
    {
        return type;
    }

    string get_path()
    {
        return path;
    }

    int get_length()
    {
        return content_length;
    }
};

class Response
{
private:
    int code;
    int content_length;
    json body;
public:
    Response();

    Response(int code_in, int length_in, json body_in)
    : code(code_in), content_length(length_in), body(body_in) { }

    Response(int code_in, int length_in)
    : code(code_in), content_length(length_in){ 
        body = {
            {"queue_head_url", "http://localhost/queue/head/"},
            {"queue_list_url", "http://localhost/queue/"},
            {"queue_tail_url", "http://localhost/queue/tail/"}
        };
    }

    void print(string type)
    {
        string str = " OK";
        if(type == "POST")
        {
            str = " Created";
        }
        cout << "HTTP/1.1 " << code << str << endl
        << "Content-Type: application/json; charset=utf-8" << endl
        << "Content-Length: " << content_length << endl
        << endl;
        cout << body.dump(4) << endl;
    }
};

class Data {
private:
    string uniqname;
    string location;
    int position;

public:
    Data(string name_in, string location_in, int pos_in)
    : uniqname(name_in), location(location_in), position(pos_in) {}

    int get_position()
    {
        return position;
    }

    void set_position(int num)
    {
        position = num;
    }
};

int main()
{
    string request_type, request_path, 
    http, host, localhost, content_type,
    app_json, charset, content_length;
    int length;
    //List<Data> queue;

    list<Data> queue;
    json body;
    json all, list;

    while(cin >> request_type >> request_path >> http >> 
    host >> localhost >> content_type >> app_json >> charset
    >> content_length >> length)
    {
        Request request(request_type, request_path, length);
        

        //Access json members and push them into the list
        if(request_type == "GET" && length == 0) {
            if(request_path == "/api/")
            {
                Response response(200, 159);
                response.print("GET");
            }

            if(request_path == "/api/queue/")
            {
                all["count"] = queue.size();
                all["results"] = list;
                string str = all.dump(4);
                Response response(200, str.length(), all);
                response.print("GET");
            }

            if(request_path == "/api/queue/head/")
            {
                string str = list[0].dump(4);
                Response response(200, str.length(), list[0]);
                response.print("GET");
            }
        }

        else if(request_type == "POST") {
            cin >> body;
            Data data(body["uniqname"], body["location"], queue.size());
            queue.push_back(data);
            json temp = {
                {"location", body["location"]},
                {"position", queue.size()},
                {"uniqname", body["uniqname"]}
            };
            list.push_back(temp);
            string str = temp.dump(4);
            Response response(201, str.length(), temp);
            response.print("POST");
        }
        else if(request_type == "DELETE" && request_path == "/api/queue/head/") {
            queue.pop_front();
            list.erase(list.begin());
            cout << "HTTP/1.1 204 No Content" << endl
            << "Content-Type: application/json; charset=utf-8" << endl
            << "Content-Length: 0" << endl;
            cout << endl;
        }
        else
        {
            cout << "HTTP/1.1 400 Bad Request" << endl
            << "Content-Type: application/json; charset=utf-8" << endl
            << "Content-Length: 0" << endl;
            cout << endl;
        }
        
    }
}

/*
- Read a request with cin
    To read data, create a temporary json object 
    and use cin (Reading JSON from a stream)
- Read or write the list data structure
- Write a response with cout
    To write data, create a temporary json object 
    and use cout (Writing JSON to a stream)
*/


/*
What data do you need to read in through a request?
- 

What data do you need to store/maintain for the OH queue? 
- uniqname
- position
- location


What do you need to return as a response?
- 
*/

