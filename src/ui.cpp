#include <iostream>
#include <string>
#include <cstdint>

#define TRANSMISSION_SUCCESS 0
#define TRANSMISSION_FAILURE 1

/*
This is a high-level UI, and it roughly models how any UI could be laid out whether it's low-level or not
This CAN NOT be programmed onto the freedom board or other microcontrollers, it takes up way way way too much memory
But it's a good starting point AND it can be used as the UI if it's running on your laptop/PC
*/

int send_message(std::string& input);

int main()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (input == "exit") break;     // putting this here for now. it won't be necessary if sigint (ctrl + c) is supported wherever this program is running
        send_message(input);
    }
    return 0;
}

int send_message(std::string& input)
{
    uint8_t ascii;
    std::cout << "the string is " << input << std::endl;
    for (char ch : input)
    {
        ascii = static_cast<uint8_t>(ch);
        // TODO: transmit the ascii character to pi. it is an 8 bit value
    }
    return TRANSMISSION_FAILURE;
}
