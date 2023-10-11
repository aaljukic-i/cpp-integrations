#include <string>

std::string caesar_encrypt(const std::string& data, int shift) {
    std::string encrypted = data;
    for (char &c : encrypted)
    {
        if ('a' <= c && c <= 'z')
        {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z')
        {
            c = (c - 'A' + shift) % 26 + 'A';
        }        
    }
    return encrypted;
}

extern "C" {
    const char* encrypt(const char* data, int shift) {
        std::string encrypted = caesar_encrypt(data, shift);
        char* result = new char[encrypted.size() + 1];
        std::copy(encrypted.begin(), encrypted.end(), result);
        result[encrypted.size()] = '\0';
        return result;
    }
}