#include "client.h"

constexpr auto dbPublicMessagesFileName = "publicmessages.db";
constexpr auto dbPrivateMessagesFileName = "privatemessages.db";

bool ChatClient::signUp(const std::string& login, const std::string& username, const std::string& password)
{
    grpc::ClientContext cc;
    net_service::Token t;
    net_service::CredentialsSignUp credentials;
    grpc::Status status;
    credentials.set_login(login);
    credentials.set_username(username);
    credentials.set_hash(password);
    status = _stub->signUp(&cc, credentials, &t);
    if (status.ok())
    {
        if (t.result())
        {
            _token = t;
            _username = username;
            return true;
        }
        return false;
    }
    return false;
}

bool ChatClient::signIn(const std::string& login, const std::string& password)
{
    grpc::ClientContext cc;
    net_service::Token t;
    net_service::CredentialsSignIn credentials;
    grpc::Status status;
    credentials.set_login(login);
    credentials.set_hash(password);
    status = _stub->signIn(&cc, credentials, &t);
    if (status.ok() && t.result())
    {
        _token = t;
        status = _stub->getUsername(&cc, t, &t);
        if (t.result())
        {
            _username = t.token();
            return true;
        }
        return false;
    }
    return false;

}

void ChatClient::signOff()
{
    grpc::ClientContext cc;
    net_service::Token t;

    _stub->signOff(&cc, t, &t);
}

bool ChatClient::sendPublicMessage(const std::string& messageContent) const
{
    grpc::ClientContext cc;
    net_service::Token t;
    net_service::PublicMessageSave publicMesssage;
    grpc::Status status;
    publicMesssage.set_content(messageContent);
    publicMesssage.set_sender(_username);
    publicMesssage.set_token(_token.token());
    

    status = _stub->savePublicMessage(&cc, publicMesssage, &t);

    if (status.ok() && t.result())
    {
        return true;
    }
    return false;
}

bool ChatClient::sendPrivateMessage(const std::string& messageContent, const std::string& recieverUsername) const
{
    grpc::ClientContext cc;
    net_service::Token t;
    net_service::PrivateMessageSave privateMessage;
    grpc::Status status;
    privateMessage.set_content(messageContent);
    privateMessage.set_reciever(recieverUsername);
    privateMessage.set_sender(_username);
    privateMessage.set_token(_token.token());

    status = _stub->savePrivateMessage(&cc, privateMessage, &t);

    if (status.ok() && t.result())
    {
        return true;
    }
    return false;
}

bool ChatClient::loadMessages() const
{
    grpc::ClientContext cc;
    grpc::Status status1;
    grpc::Status status2;
    net_service::PrivateMessageLoad privateMessages;
    net_service::PublicMessageLoad publicMessages;
    status1 = _stub->getPublicMessages(&cc, _token, &publicMessages);
    status1 = _stub->getPrivateMessages(&cc, _token, &privateMessages);

    if (
        publicMessages.content_size() == publicMessages.sender_size()
        && privateMessages.sender_size() == privateMessages.content_size()
        && privateMessages.sender_size() == privateMessages.reciever_size())
    {
        for (size_t i = 0; i < publicMessages.sender_size(); ++i)
        {

        }
    }
    return false;
}

ChatGUI::ChatGUI()
    :_client(grpc::CreateChannel("localhost:55777", grpc::InsecureChannelCredentials()))
{

}

void ChatGUI::start()
{
    std::cout << "1. SignIn\n2. SignUp\n3. Close\n";
    char choice;
    std::cin >> choice;
    switch (choice)
    {
    case '1':
        trySignIn();
        break;
    case '2':
        trySignUp();
        break;
    case '3':
        return;
    default:
        break;
    }
    start();
}

void ChatGUI::trySignIn()
{
    std::cout << "Please, enter your credentials (login,password)\n";
    std::cout << "login: ";
    std::string login;
    std::getline(std::cin, login);
    std::getline(std::cin, login);// because first time call gets empty string autimatically
    std::cout << "password: ";
    std::string password;
    std::getline(std::cin, password);
    //std::cin >> login >> password;
    if (_client.signIn(login,password))
    {
        std::cout << "Login successful!\n";
        _client.loadMessages();
        logged();
    }
    else
    {
        std::cout << "Login/password is incorrect! Try again.\n";
    }
    return;
}

void ChatGUI::trySignUp()
{
    std::cout << "Please, enter your credentials (login,password,username)\n";
    std::string login = "";
    do
    {
        std::cout << "login: ";
        std::cin >> login;
        if (login.size() > 4)
            break;
        std::cout << "\nLogin is too short. Try again!\n";
    } while (true);
    std::string password = "";
    do
    {
        std::cout << "password: ";
        std::cin >> password;// because first time call gets empty string autimatically
        if (password.size() > 4)
            break;
        std::cout << "\nPassword is too short. Try again!\n";
    } while (true);
    std::string username = "";
    do
    {
        std::cout << "username: ";
        std::cin >> username;
        if (username.size() > 4)
            break;
        std::cout << "Username is too short. Try again!\n";
    } while (true);
    {
        if (!_client.signUp(login, password, username))
        {
            std::cout << "Signup failed!\n";
            return;
        }
        std::cout << "Signup successfull!\n";
        logged();
    }
    return;
}

void ChatGUI::logged()
{
    static char choice;
    static std::string message;
    std::cout << "\nWhat to do:\n1.Write a message to everyone\n2.Write a message to a user\n3.Display public messages\n4.Display private messages\n5.Logout\n";
    std::cin >> choice;
    switch (choice)
    {
    case '1':
    {
        std::cout << "Enter your message:";
        std::getline(std::cin, message);
        std::getline(std::cin, message);// because first time call gets empty string autimatically
        if (!_client.sendPublicMessage(message))
        {
            std::cout << "Message was not sent for unknown reason! Try again!\n";
        }
        else
        {
            std::cout << "Message was sent successfully!\n";
        }
        break;
    }
    case '2':
    {
        std::cout << "Enter your message:";
        std::getline(std::cin, message);
        std::getline(std::cin, message);// because first time call gets empty string autimatically
        std::cout << "Enter the reciever's username:";
        std::string reciever;
        std::getline(std::cin, reciever);
        if (!_client.sendPrivateMessage(message,reciever))
        {
            std::cout << "Message was not sent for unknown reasons!.\n";
            break;
        }
        else
        {
            std::cout << "Message was sent successfully!\n";
        }

        break;
    }
    case '3':
        //m_db.getMessages();
        break;
    case '4':
        //m_db.getMessages(m_db.getUsername(m_currentUser));
        break;
    case '5':
        return;
    default:
        break;
    }

    logged();
}
