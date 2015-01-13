# FacebookREST

A REST server written in C++ for Facebook Graph API v2.2.

There is still a lot of work to do. Currently, the project is mainly a modification of [Simple-Web-Server](https://github.com/eidheim/Simple-Web-Server) and a test request to Facebook API.

### Requirements

The requirements are the same as [Simple-Web-Server](https://github.com/eidheim/Simple-Web-Server), so for now, please visit the site's repository for more information.

### What's new?

#### Setup

```
mkdir build
cd build
cmake ..
make
cd out/code/
./FacebookRest
```
Go with your browser to http://localhost:8080

#### Simple usage

The usage is inspired in cppCMS, but targeting REST servers. To add resources you first need to create a class that inherits `Server<HTTP>::Resource`, and then instantiate it in the `main()` in this way:
```
server.route("^/resource_name/?$", new ResourceClass());
```
where `resource_name is` the URL path and `ResourceClass` the name of the class mentioned previously.

#### Methods already binded with HTTP operations

Each resource inherits 4 methods: `create`, `remove`, `update` and `display`. Each method has already been binded respectively with `POST`, `DELETE`, `PUT` and `GET` operations.

### Copyright

Although some modifications have been made, the server and client are heavily based on Ole Christian Eidheim's work in [Simple-Web-Server](https://github.com/eidheim/Simple-Web-Server).

The rest of the work is done by Mariano Finochietto.

### License

GPL v3
