#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
    private:

    class Connection {
        public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) :
            socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, 
                        *read_buffer, 
                        "\r\n",
                        [this, connection, read_buffer]
                        (const boost::system::error_code &ec, size_t) {
            // If not error:
            if (!ec) {
                // Retrieve message from client as string:
                istream read_stream(read_buffer.get());
                string message;
                getline(read_stream, message);
                message.pop_back(); // Remove "\r" at the end of message

                if (message.substr(0, 3) == "GET") {
                    string response;
                    if (message == "GET / HTTP/1.1")
                        response = "HTTP/1.1 200 OK\r\n\nDette er hovedsiden\r\n";
                    else if (message == "GET /en_side HTTP/1.1")
                        response = "HTTP/1.1 200 OK\r\n\nDette er en side\r\n";
                    else
                        response = "HTTP/1.1 404 Not Found\r\n\n";

                    cout << "Message from a connected client: " << message << endl
                        << "Response sent: " << response << endl;

                    auto write_buffer = make_shared<boost::asio::streambuf>();
                    ostream write_stream(write_buffer.get());

                    // Add message to be written to client:
                    write_stream << response;

                    // Write to client
                    async_write(connection->socket, 
                                *write_buffer,
                                [this, connection, write_buffer]
                                (const boost::system::error_code &ec, size_t) {
                        // If not error:
                        if (!ec)
                            handle_request(connection);
                        else
                            cout << "Error in async_write: " << ec << endl;
                    });
                }
            } else
                cout << "Error in async_read_until: " << ec << endl;
        });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, 
                            [this, connection]
                            (const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec)
                handle_request(connection);
            else
                cout << "Error in async_accept: " << ec << endl;
        });
    }

    public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};

int main() {
  EchoServer echo_server;

  cout << "Starting echo server" << endl
       << "Connect in a browser at: localhost:8080" << endl;

  echo_server.start();
}